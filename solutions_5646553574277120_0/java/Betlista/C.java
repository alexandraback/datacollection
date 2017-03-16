import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class C {

	static int MB = 1 << 20;
	static BufferedReader br = new BufferedReader( new InputStreamReader(System.in, StandardCharsets.US_ASCII), 30*MB);
	static StringTokenizer st;
	
	static String NL() throws Exception {
		String line = br.readLine();
		st = new StringTokenizer(line);
		return line;
	}
	
	static String NT() {
		return st.nextToken();
	}
	
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(NL());
		for (int ii = 1; ii <= T; ii++) {
			NL();
			int C, D, W;
			C = Integer.parseInt(NT());
			D = Integer.parseInt(NT());
			W = Integer.parseInt(NT());
			NL();
			int[] d = new int[D];
			for (int i = 0; i < D; i++) {
				d[i] = Integer.parseInt(NT());
			}
			int sol = solve(C, D, W, d);
			print(ii, sol);
		}
	}

	private static void print(int ii, int sol) {
		System.out.printf("Case #%d: %d%n", ii, sol);
	}

	private static int solve(int C, int D, int V, int[] d) {
		ArrayList<Integer> denom = new ArrayList<>();
		for (int i = 0; i < D; i++) {
			denom.add(d[i]);
		}
		for (int val = 1; val <= V; ++val) {
			if (possible(val, denom)) {
				// do nothing
			} else {
				denom.add(val);
			}
		}
		return denom.size() - D;
	}

	private static boolean possible(int val, ArrayList<Integer> denom) {
		int S = denom.size();
		for (int mask = 1; mask < 1 << S; mask++) {
			int sum = 0;
			for (int i = 0; i < S; i++) {
				if ((mask & (1 << i)) > 0) {
					sum += denom.get(i);
				}
			}
			if (sum == val ) return true;
		}
		return false;
	}
	
}
