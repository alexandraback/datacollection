package gcj.Qual2013C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

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
		if (true) { filename = "C-small-attempt0.in"; THREAD_NUMBER = 7; }
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

		String A, B;

		void read(Scanner sc) {
			// TODO: write input code here.
			A = sc.next();
			B = sc.next();
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

		boolean ready = false;

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

		BigInteger A, B;
		Set<BigInteger> L;

		void solve() {
			// TODO: write your solution here

			if (!ready) {
				L = new HashSet<BigInteger>();
				for (int k = 1; k <= 10; k++) {
					char[] buf = new char[k];
					dfs(0, buf);
				}
				ready = true;
			}
			A = new BigInteger(io.A);
			B = new BigInteger(io.B);

			long ans = 0;
			for (BigInteger x : L) {
				if (A.compareTo(x) <= 0 && x.compareTo(B) <= 0) {
					ans++;
				}
			}
			io.print(ans);
		}

		void dfs(int depth, char[] buf) {
			int k = buf.length;
			if (depth + depth >= k) {
				BigInteger x = new BigInteger(new String(buf));
				x = x.multiply(x);

				if (isPalin(x.toString().toCharArray())) {
					L.add(x);
				}

				return;
			}
			for (int i = 0; i < 10; i++) {
				if (depth == 0 && i == 0) continue;
				buf[depth] = buf[k - 1 - depth] = (char)('0' + i);
				dfs(depth + 1, buf);
			}
		}

		boolean isPalin(char[] s) {
			int n = s.length;
			for (int i = 0; i + i < n; i++) {
				if (s[i] != s[n-1-i])
					return false;
			}
			return true;
		}

	}
}
