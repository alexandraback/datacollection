import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					String[] elems = br.readLine().split(" ");
					int e = Integer.valueOf(elems[0]);
					int r = Integer.valueOf(elems[1]);
					int n = Integer.valueOf(elems[2]);
					int[][] vals = new int[n][2];
					int[] possible = new int[n];
					int[] count = new int[n];
					elems = br.readLine().split(" ");
					for (int j = 0; j < n; j++) {
						vals[j][0] = Integer.valueOf(elems[j]);
						vals[j][1] = j;
						possible[j] = e;
					}
					Arrays.sort(vals, new Comparator<int[]>() {@Override
    					public int compare(int[] o1, int[] o2) {
	    					// TODO Auto-generated method stub
		     				return Integer.compare(o2[0], o1[0]);
			     		}
					});
					int result = 0;
					for (int j = 0; j < n; j++) {
						result += vals[j][0]*possible[vals[j][1]];
						int idx = vals[j][1];
						int val = possible[vals[j][1]];
						while(true) {
							idx--;
							if (idx < 0 || idx >= n) {
								break;
							}
							if (count[idx] < 2) {
								val -=r;
							}
							if (val < 0) {
								break;
							}
							if (val > possible[idx]) {
								possible[idx] = 0;
								break;
							}
							possible[idx] -= val;
							count[idx] += 1;
						}
						idx = vals[j][1];
						val = possible[vals[j][1]];
						while(true) {
							idx++;
							if (idx < 0 || idx >= n) {
								break;
							}
							if (count[idx] < 2) {
								val -=r;
							}
							if (val < 0) {
								break;
							}
							if (val > possible[idx]) {
								possible[idx] = 0;
								break;
							}
							possible[idx] -= val;
							count[idx] += 1;
						}
						possible[vals[j][1]] = 0;
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
	
	private static void addDot(Map<Integer, Set<Integer>> dots, int[] dot) {
		if (!dots.containsKey(dot[0])) {
			dots.put(dot[0], new TreeSet<Integer>());
		}
		dots.get(dot[0]).add(dot[1]);
	}
}