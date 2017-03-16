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
	
	final long MAX = 1000L * 1000L * 1000L * 1000L - 1;
	final Random rnd = new Random(56392659031651L);
	
	long[] generateRandomArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = 1 + abs(rnd.nextLong() % MAX);
		}
		return a;
	}
	
	private void printList(List<Long> list) {
		for (int i = 0; i < list.size(); i++) {
			out.print(list.get(i));
			if (i == list.size()-1) out.println(); else out.print(" ");
		}
	}
	
	void solveTest() throws IOException {
		int n = readInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = readLong();
		}
		//int n = 500; long[] a = generateRandomArray(n);
		Map<Long, Integer> map = new HashMap<Long, Integer>();
		for (int it = 0; it < 12; it++) {
			randomShuffle(a, n);
			map.clear();
			for (int mask = 1; mask < (1 << BITS); mask++) {
				long s = 0;
				for (int bit = 0; bit < BITS; bit++) {
					if ((mask & (1 << bit)) != 0) {
						s += a[bit];
					}
				}
				if (map.containsKey(s)) {
					List<Long> list1 = getList(a, map.get(s));
					List<Long> list2 = getList(a, mask);
					printList(list1);
					printList(list2);
					List<Long> total = new ArrayList<Long>();
					total.addAll(list1);
					total.addAll(list2);
					checkList(list1, list2);
					return;
				} else {
					map.put(s, mask);
				}
			}
			
		}
		out.println("Impossible");
	}

	private List<Long> getList(long[] a, int mask) {
		List<Long> list = new ArrayList<Long>();
		for (int bit = 0; bit < BITS; bit++) {
			if ((mask & (1 << bit)) != 0) {
				list.add(a[bit]);
			}
		}
		return list;
	}

	final int BITS = 20;
	
	private void randomShuffle(long[] a, int n) {
		for (int i = 0; i < n; i++) {
			int j = i + rnd.nextInt(n - i);
			long t = a[i]; a[i] = a[j]; a[j] = t;
		}
	}

	private void checkList(List<Long> a, List<Long> b) {
		long sum1 = 0, sum2 = 0;
		for (long x : a) {
			sum1 += x;
		}
		for (long x : a) {
			sum2 += x;
		}
		if (sum1 != sum2) {
			throw new RuntimeException("sum is not 0");
		}
	}

}
