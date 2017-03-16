import static java.util.Arrays.deepToString;

import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	static class Worker implements Runnable {
		static volatile int left;
		int id;

		int n;
		int[] a;

		Worker(int id) {
			this.id = id;
			n = nextInt();
			a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
		}

		void solveSingle() {
			HashMap<Integer, Integer> map = new HashMap<>();
			for (int msk = 0; msk < (1 << n); msk++) {
				int sum = 0;
				for (int i = 0; i < n; i++) {
					if (((msk >> i) & 1) != 0) {
						sum += a[i];
					}
				}
				if (map.containsKey(sum)) {
					found = true;
					mskA[0] = map.get(sum);
					mskA[1] = msk;
					break;
				}
				map.put(sum, msk);
			}
			debug("Done: " + id);
		}

		boolean found = false;
		int[] mskA = new int[2];

		void printOutput() {
			writer.printf("Case #%d:\n", id + 1);
			if (!found) {
				writer.println("Impossible");
			} else {
				for (int subset = 0; subset < 2; subset++) {
					for (int i = 0; i < n; i++) {
						if (((mskA[subset] >> i) & 1) != 0) {
							writer.print(a[i] + " ");
						}
					}
					writer.println();
				}
			}
		}

		public void run() {
			try {
				Worker.left++;
				solveSingle();
				Worker.left--;
			} catch (Exception e) {
				debug("Failed on " + id);
				e.printStackTrace();
				System.exit(1);
			}
		}

	}

	static void solveParallel() throws Exception {
		int T = nextInt();
		Worker[] workers = new Worker[T];
		for (int i = 0; i < T; i++) {
			workers[i] = new Worker(i);
		}
		for (int i = 0; i < T; i++) {
			for (; Worker.left >= 4; Thread.sleep(20))
				;
			new Thread(workers[i]).start();
		}
		for (; Worker.left > 0; Thread.sleep(20))
			;
		for (int i = 0; i < T; i++) {
			workers[i].printOutput();
		}
	}

	public static void main(String[] args) throws Exception {
		reader = new BufferedReader(new FileReader("c.in"));
		writer = new PrintWriter("c.out");

		setTime();
		solveParallel();
		printTime();
		printMemory();

		writer.close();
	}

	static BufferedReader reader;
	static PrintWriter writer;
	static StringTokenizer tok = new StringTokenizer("");
	static long systemTime;

	static void debug(Object... o) {
		System.err.println(deepToString(o));
	}

	static void setTime() {
		systemTime = System.currentTimeMillis();
	}

	static void printTime() {
		System.err.println("Time consumed: " + (System.currentTimeMillis() - systemTime));
	}

	static void printMemory() {
		System.err.println("Memory consumed: " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1000 + "kb");
	}

	static String next() {
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = reader.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}