import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					int n = Integer.valueOf(br.readLine());
					int[][] tribes = new int[n][9];
					PriorityQueue<int[]> attacks = new PriorityQueue<int[]>(new TreeSet<int[]>(new Comparator<int[]>() {
						@Override
						public int compare(int[] o1, int[] o2) {
							int delta = o1[0] - o2[0];
							if (delta != 0) {
								return delta;
							}
							else return o1[1] - o2[1];
						}
					})); 
					for (int j = 0; j < n; j++) {
						String[] vals = br.readLine().split(" ");
						for (int k = 0; k < vals.length; k++) {
							tribes[j][k] = Integer.valueOf(vals[k]);
						}
						attacks.add(new int[] {tribes[j][0], j});
					}
					TreeSet<int[]> successfull_attacks = new TreeSet<int[]>(new Comparator<int[]>() {
						@Override
						public int compare(int[] o1, int[] o2) {
							return o2[2] - o1[2];
						}
					});
					int result = 0;
					while(true) {
						int[] attack = attacks.poll();
						if (attack == null) {
							break;
						}
						int[] tribe = tribes[attack[1]];
						int w = tribe[2];
						int e = tribe[3];
						for (int[] suc_at : successfull_attacks) {
							if ((w - suc_at[0])*(w - suc_at[1]) < 0) {
								w = suc_at[1] + 1;
							}
							if ((e - suc_at[0])*(e - suc_at[1]) < 0) {
								e = suc_at[0] - 1;
							}
						}
						if (w <= e) {
							result++;
							successfull_attacks.add(new int[]{tribe[2], tribe[3], tribe[4]});
							tribe[4] += tribe[7];
						}
						else {
							tribe[4] -= tribe[7];
						}
						tribe[0] += tribe[5];
						tribe[1]--;
						tribe[2] += tribe[6];
						tribe[3] += tribe[6];
						if (tribe[1] > 0 && tribe[4] > 0) {
							attack[0] = tribe[0];
							attacks.add(attack);
						}
					}
					
					out.write("Case #"+ (i + 1) +": " + result + "\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
	
	private static long divideOnModule(long value, long divider, long module) {
		long res = 0;
		long left = value;
		while(true) {
			res = (res+left/divider) % module;
			left = left % divider;
			if (left == 0) {
				break;
			}
			else {
				left += module;
			}
		}
		return res;
	}
}