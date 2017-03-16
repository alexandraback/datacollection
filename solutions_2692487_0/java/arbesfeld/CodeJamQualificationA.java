import java.io.*;
import java.util.*;

public class CodeJamQualificationA 
{
	private static void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++) {
			int A = nextInt();
			int N = nextInt();
			int[] motes = new int[N];
			for(int i = 0; i < N; i++) {
				motes[i] = nextInt();
			}
			Arrays.sort(motes);
			int ops = 0;
			int finAmt = Integer.MAX_VALUE;
			for(int i = 0; i < N; i++) {
				// first suppose we just delete all the other motes
				finAmt = Math.min(finAmt, ops + N - i);
				if(A > motes[i]) {
					A += motes[i];

					// first suppose we just delete all the other motes
					finAmt = Math.min(finAmt, ops + N - i - 1);
					continue;
				} else {
					
					// now iterate until we can kill it
					if(A == 1) {
						break;
					}
					while(A <= motes[i]) {
						A += A - 1;
						ops++;
					}
					A += motes[i];
				} 
			}
			int res = finAmt;
			out.println("Case #" + t + ": " + res);
		}
	}
	
	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}