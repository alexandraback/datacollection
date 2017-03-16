import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;


public class C {
	
	public static void print(HashSet<Integer> hs) {
		String s = "";
		for (int i : hs) s += i + ",";
//		System.out.println(s);
	}

	public static int solve(int c, int d, int v, int[] vals) {
		HashSet<Integer> hs = new HashSet<>(89);
		hs.add(0);
		for (int i = 0; i < vals.length; i++) {
			HashSet<Integer> newhs = new HashSet<Integer>(89);
			for (int other : hs) {
				if (other + vals[i] <= v) {
					newhs.add(other + vals[i]);
				}
			}
			hs.addAll(newhs);
		}
		print(hs);
		int prev = 0;
		int count = 0;
		while (hs.size() < v + 1) {
			for (int i = prev + 1; i <= v; i++) {
				if (hs.contains(i)) {
					continue;
				}
				prev = i;
				count++;
				HashSet<Integer> newhs = new HashSet<Integer>(89);
				for (int other : hs) {
					if (other + i <= v) {
						newhs.add(other + i);
					}
				}
				hs.addAll(newhs);
				print(hs);
				break;
			}
		}
		return count;
	}
	
	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0_myr.in"));
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt2.in"));
//		BufferedReader in = new BufferedReader(new FileReader("c_test.in"));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] cdv = in.readLine().split(" ");
			int c = Integer.parseInt(cdv[0]);
			int d = Integer.parseInt(cdv[1]);
			int v = Integer.parseInt(cdv[2]);
			String[] coins = in.readLine().split(" ");
			int[] vals = new int[d];
			for (int i = 0; i < d; i++) {
				vals[i] = Integer.parseInt(coins[i]);
			}
			
			pw.format("Case #%d: %d\n", t, solve(c, d, v, vals));
			pw.flush();
		}
		pw.close();
		in.close();
	}

}
