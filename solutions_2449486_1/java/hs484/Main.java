package gcj.Qual2013B;

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
//		if (true) { filename = "B-small-attempt0.in"; THREAD_NUMBER = 7; }
		if (true) { filename = "B-large.in"; THREAD_NUMBER = 7; }

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

		int R, C;
		int[][] a;

		void read(Scanner sc) {
			// TODO: write input code here.
			R = sc.nextInt();
			C = sc.nextInt();
			a = new int[R][C];
			for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
				a[r][c] = sc.nextInt();
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
			int R = io.R;
			int C = io.C;
			int[][] a = io.a;


			int[][] b = new int[R][C];
			for (int i = 0; i < R; i++) fill(b[i], 100);

			for (int h = 99; h >= 1; h--) {

				for (int i = 0; i < R; i++) {
					boolean cut = true;
					for (int j = 0; j < C; j++) {
						if (a[i][j] > h) {
							cut = false;
						}
					}
					if (cut) {
						for (int j = 0; j < C; j++) {
							b[i][j] = h;
						}
					}
				}

				for (int j = 0; j < C; j++) {
					boolean cut = true;
					for (int i = 0; i < R; i++) {
						if (a[i][j] > h) {
							cut = false;
						}
					}
					if (cut) {
						for (int i = 0; i < R; i++) {
							b[i][j] = h;
						}
					}
				}
			}


			boolean res = true;
			for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (a[i][j] != b[i][j]) res = false;
			io.writeln(res ? "YES":"NO");
		}

	}
}
