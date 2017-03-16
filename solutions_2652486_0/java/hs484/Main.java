package gcj.Round1A2013.C;

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
		if (true) { filename = "C-small-1-attempt0.in"; THREAD_NUMBER = 1; }
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
			String res = "Case #" + caseNumber + ":\n"; // TODO: use NEW_LINE instead of SPACE.
			res += sb.toString();
			res = res.replaceAll("\\s+$", "");
			return res;
		}

		// ================================================
		//               input parameters
		// ================================================

		int R,N,M,K;
		int[][] P;

		void read(Scanner sc) {
			// TODO: write input code here.
			R = sc.nextInt();
			N = sc.nextInt();
			M = sc.nextInt();
			K = sc.nextInt();
			P = new int[R][K];
			for (int r = 0; r < R; r++) {
				for (int k = 0; k < K; k++) {
					P[r][k] = sc.nextInt();
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

		int R,N,M,K;

		void solve() {
			// TODO: write your solution here

			int[][] P;

			R = io.R;
			N = io.N;
			M = io.M;
			K = io.K;
			P = io.P;

			fact = new double[16];
			fact[0] = 1.0;
			for (int i = 1; i < fact.length; i++) fact[i] = fact[i-1] * i;

			sel = new int[N];
			count = new int[M + 1];

			for (int i = 0; i < P.length; i++) {
				pick = P[i];
				bestScore = -1;
				gen(0, 2);
				for (int x : ans)
					io.write(x);
				io.writeln("");
			}

		}

		int[] pick;

		double[] fact;
		int[] sel;
		int[] count;

		double bestScore;
		int[] ans;

		void gen(int d, int start) {
			if (d == sel.length) {
				double prob = fact[sel.length] / pow(M - 2 + 1, N);
				for (int i = 2; i <= M; i++) {
					prob /= fact[count[i]];
				}

				double q = 1.0;
				for (int i = 0; i < pick.length; i++) {
					q *= getProb(pick[i]);
				}

				double score = prob * q;

//				tr(sel, prob, score);
				if (bestScore < score) {
					bestScore = score;
					ans = sel.clone();
				}

				return;
			}

			for (int i = start; i <= M; i++) {
				sel[d] = i;
				count[i]++;
				gen(d + 1, i);
				count[i]--;
			}
		}

		double getProb(int mul) {
			double hit = 0;

			for (int set = 0; set < (1 << sel.length); set++) {
				int cur = 1;
				for (int i = 0; i < sel.length; i++) {
					if ((set >> i & 1) == 1) {
						cur *= sel[i];
					}
				}
				if (mul == cur) hit += 1;
			}
			return hit;
		}
	}
}
