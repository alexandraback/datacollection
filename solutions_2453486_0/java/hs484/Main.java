package gcj.Qual2013A;

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
		if (true) { filename = "A-small-attempt0.in"; THREAD_NUMBER = 2; }
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

		char[][] table;

		void read(Scanner sc) {
			// TODO: write input code here.
			table = new char[4][4];
			for (int i = 0; i < 4; i++) table[i] = sc.next().toCharArray();
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

			if (check(io.table,'X')) {
				io.print("X won");
			}
			else if (check(io.table,'O')) {
				io.print("O won");
			} else {
				boolean dot = false;
				for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
					if (io.table[i][j] == '.') {
						dot = true;
					}
				}
				if (dot) {
					io.print("Game has not completed");
				} else {
					io.print("Draw");
				}
			}

		}

		boolean check(char[][] table, char t) {
			for (int i = 0; i < 4; i++) {
				boolean match = true;
				for (int j = 0; j < 4; j++) {
					if (table[i][j] == t || table[i][j] == 'T') {
						;
					} else {
						match = false;
					}
				}
				if (match) return true;
			}
			for (int i = 0; i < 4; i++) {
				boolean match = true;
				for (int j = 0; j < 4; j++) {
					if (table[j][i] == t || table[j][i] == 'T') {
						;
					} else {
						match = false;
					}
				}
				if (match) return true;
			}

			{
				boolean match = true;
				for (int i = 0; i < 4; i++) {
					if (table[i][i] == t || table[i][i] == 'T')
						;
					else
						match = false;
				}
				if (match) return true;
			}
			{
				boolean match = true;
				for (int i = 0; i < 4; i++) {
					if (table[i][3 - i] == t || table[i][3 - i] == 'T')
						;
					else
						match = false;
				}
				if (match) return true;
			}
			return false;
		}

	}
}
