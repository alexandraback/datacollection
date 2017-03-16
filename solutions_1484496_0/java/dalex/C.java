import java.io.*;
import java.util.*;

import static java.lang.Math.*;

/**
 * Google Code Jam 2012
 * Round 1B
 * Problem C
 * @author dalex
 */
public class C implements Runnable {
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new C(), "", 256 * (1L << 20)).start();
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			Locale.setDefault(Locale.US);
			tok = new StringTokenizer("");
			int tests = readInt();
			int p = tests / 10;
			long startTime = System.currentTimeMillis();
			for (int test = 1; test <= tests; test++) {
				out.printf("Case #%d:\n", test);
				solveTest();
				if (p == 0 || test % p == 0 || test == tests) {
					long newTime = System.currentTimeMillis();
					System.err.printf("Test %d of %d completed, time = %d\n", test, tests, newTime - startTime);
				}
			}
			in.close();
			out.close();
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	// solution
	
	void solveTest() throws IOException {
		int n = readInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
		}
		int[] have = new int[100000 * n + 1];
		Arrays.fill(have, -1);
		for (int mask = 1; mask < (1 << n); mask++) {
			int s = 0;
			for (int bit = 0; bit < n; bit++) {
				if ((mask & (1 << bit)) != 0) {
					s += a[bit];
				}
			}
			if (have[s] != -1) {
				List<Integer> list1 = get(a, n, have[s]);
				List<Integer> list2 = get(a, n, mask);
				printList(list1);
				printList(list2);
				return;
			}
			have[s] = mask;
		}
		out.println("Impossible");
	}

	private void printList(List<Integer> list) {
		for (int i = 0; i < list.size(); i++) {
			out.print(list.get(i));
			if (i == list.size()-1) out.println(); else out.print(" ");
		}
	}

	private List<Integer> get(int[] a, int n, int mask) {
		List<Integer> list = new ArrayList<Integer>();
		for (int bit = 0; bit < n; bit++) {
			if ((mask & (1 << bit)) != 0) {
				list.add(a[bit]);
			}
		}
		return list;
	}

}
