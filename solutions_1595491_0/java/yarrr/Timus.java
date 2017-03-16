import java.io.*;
import java.util.*;
import java.math.*;

public class Timus implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	Random rnd;
	
	boolean[][][] canBe;
	int[][] d;
	int[] scores;
	
	void precalc() {
		canBe = new boolean[30 + 1][10 + 1][2];
		
		for(int a = 0; a <= 10; a++) {
			for(int b = 0; b <= 10; b++) {
				for(int c = 0; c <= 10; c++) {
					int sum = a + b + c, max = Math.max(a, Math.max(b, c));
					int maxDiff = Math.max(Math.abs(a - b), Math.max(Math.abs(a - c), Math.abs(b - c)));
					int flag = 0;
					
					if(maxDiff > 2) {
						continue;
					} else if(maxDiff == 2) {
						flag = 1;
					}
					
					for(int lower = 0; lower <= max; lower++) {
						canBe[sum][lower][flag] = true;
					}
				}
			}
		}
	}
	
	int solveOne(int n, int s, int p) throws IOException {
		d = new int[n + 1][s + 1];
		
		for(int i = 0; i < d.length; i++) {
			Arrays.fill(d[i], Integer.MIN_VALUE / 2);
		}
		
		d[0][0] = 0;
		
		scores = new int[n];
		
		for(int i = 0; i < n; i++) {
			scores[i] = nextInt();
		}
		
		for(int i = 0; i < n; i++) {
			int curScore = scores[i];
			
			for(int j = 0; j <= s; j++) {
				if(canBe[curScore][p][0]) {
					d[i + 1][j] = Math.max(d[i + 1][j], d[i][j] + 1);
				} else {
					d[i + 1][j] = Math.max(d[i + 1][j], d[i][j]);
				}
				
				if(j < s) {
					
					if(canBe[curScore][p][1]) {
						d[i + 1][j + 1] = Math.max(d[i + 1][j + 1], d[i][j] + 1);
					} else {
						d[i + 1][j + 1] = Math.max(d[i + 1][j + 1], d[i][j]);
					}
					
					
				}
			}
		}
		
		return d[n][s];
	}
	
	void solve() throws IOException {
		precalc();
		
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.printf("Case #%d: %d\n", test, solveOne(nextInt(), nextInt(), nextInt()));
		}
	}

	public static void main(String[] args) {
		new Timus().run();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null) {
				return null;
			}

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}