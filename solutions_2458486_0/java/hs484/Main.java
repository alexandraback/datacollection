package gcj.Qual2013D;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class Main {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		// TODO: choose input file.
		String filename = "";
		int THREAD_NUMBER = 1;

//		if (true) { filename = "sample.in"; THREAD_NUMBER = 1; }
		if (true) { filename = "D-small-attempt1.in"; THREAD_NUMBER = 2; }
//		if (true) { filename = "A-large-practice.in"; THREAD_NUMBER = 7; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		TNO = sc.nextInt();
		tno = 0;

		ios = new IO[TNO];
		for (int i = 0; i < TNO; i++) {
			ios[i] = new IO(i + 1);
			ios[i].read(sc);
		}

		Thread[] threads = new Thread[THREAD_NUMBER];
		for (int i = 0; i < threads.length; i++) {
			threads[i] = new Thread(new Solve());
			threads[i].start();
		}
		for (int i = 0; i < threads.length; i++) {
			threads[i].join();
		}

		tr("!!!!!! ALL FINISHED !!!!!!!");
		for (int i = 0; i < TNO; i++) {
			// System.out.println(ios[i]);
			fout.println(ios[i]);
			fout.flush();
		}
		fout.close();
	}

	static int TNO;
	static Integer tno;
	static IO[] ios;

	static class IO {
		int caseNumber;
		private StringBuilder sb = new StringBuilder();
		IO(int caseNumber) {
			this.caseNumber = caseNumber;
		}
		public <T> void print(T o) {sb.append(o);}
		public <T> void println(T o) {sb.append(o + "\n");}
		public <T> void write(T o) {sb.append(o);}
		public <T> void writeln(T o) {sb.append(o + "\n");}
		public <T> void printArray(int[] as) {sb.append(as[0]);for (int i = 1; i < as.length; i++) { sb.append(" "); sb.append(as[i]); }}
		public <T> void printArray(long[] as) {sb.append(as[0]);for (int i = 1; i < as.length; i++) { sb.append(" "); sb.append(as[i]); }}

		public String toString() {
			String res = "Case #" + caseNumber + ": "; // TODO: use NEW_LINE instead of SPACE.
			res += sb.toString();
			res = res.replaceAll("\\s+$", "");
			return res;
		}

		// ================================================
		//               input parameters
		// ================================================

		int N, K;
		int[] key;
		int[] t;
		int[][] chest;

		void read(Scanner sc) {
			// TODO: write input code here.
			K = sc.nextInt();
			N = sc.nextInt();
			key = new int[201];
			for (int i = 0; i < K; i++) {
				int x = sc.nextInt();
				key[x]++;
			}
			t = new int[N];
			chest = new int[N][201];
			for (int i = 0; i < N; i++) {
				t[i] = sc.nextInt();
				int kk = sc.nextInt();
				while (kk-->0) {
					chest[i][sc.nextInt()]++;
				}
			}

		}

		int[] nextIntArray(Scanner sc, int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = sc.nextInt();
			return a;
		}
		long[] nextLongArray(Scanner sc, int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++) a[i] = sc.nextLong();
			return a;
		}


		//=================================================

	}

	static class Solve implements Runnable {

		IO io;

		@Override
		public void run() {
			for (;;) {
				synchronized (tno) {
					if (tno < TNO)
						io = ios[tno++];
					else
						break;
				}
				solve();
				tr(io);
			}
		}

		// ================================================
		//               SOLUTION
		// ================================================

		void solve() {
			// TODO: write your solution here
			int N = io.N;

			int[] dp = new int[1 << N];
			int[] possible = new int[1 << N];

			fill(dp, 0);
			dp[0] = -1;
			for (int set = 0; set < (1 << N); set++) {
				if (dp[set] == 0) continue;
//				tr(dp);
				int[] have = new int[201];
				for (int i = 0; i < 201; i++) have[i] += io.key[i];
				for (int i = 0; i < N; i++) if ((set >> i & 1) == 1) {
					have[ io.t[i] ]--;
					for (int j = 0; j < 201; j++) have[j] += io.chest[i][j];
				}

				for (int i = 0; i < N; i++) if ((set >> i & 1) == 0) {
					if ( have[io.t[i]] > 0 ) {
						int ns = set | (1 << i);
						dp[ns] |= (1 << i);
					}
				}
			}

			if (dp[(1 << N) - 1] == 0) {
				io.print("IMPOSSIBLE");
				return;
			}

			int s = (1 << N) - 1;
			possible[s] = 1;
			for (; s > 0; s--) {
				if (1 == possible[s]) {
					for (int i = 0; i < N; i++) if ((dp[s] >> i & 1) == 1) {
						possible[s - (1 << i)] = 1;
					}
				}
			}

			s = 0;
			int[] ans = new int[N];
			for (int p = 0; p < N; ++p) {
				loop:
				for (int i = 0; i < N; i++) if ((s >> i & 1) == 0) {
					int ns = s | (1 << i);
					if (possible[ns] == 1 && ((dp[ns] >> i & 1) == 1)) {
						ans[p] = i + 1;
						s = ns;
						break loop;
					}
				}
			}

			io.print(ans[0]);
			for (int i = 1; i < N; i++)
				io.print(" " + ans[i]);

		}

	}
}
