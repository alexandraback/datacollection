import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader f;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws Exception {

		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new java.io.InputStreamReader(System.in));

		// input file name goes above
		out = new PrintWriter(new BufferedWriter(new FileWriter("out.out")));

		long unixTime = System.currentTimeMillis();

		long[] summation = new long[100001];
		long summ = 0;
		for (int i = 0; i <= 100000; i++) {
			summ += i;
			summation[i] = summ;
			// System.out.println(i+" "+summ);
		}

		int Tests = nextInt();
		for (int test = 0; test < Tests; test++) {
			String s = next();
			int n = nextInt();

			long ans = 0;
			int prevEnd = 0;
			int numCons = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == 'a' || s.charAt(i) == 'o'
						|| s.charAt(i) == 'e' || s.charAt(i) == 'i'
						|| s.charAt(i) == 'u') {// Vowel
					if (numCons >= n) {
						long left = (i - numCons - prevEnd);
						long right = s.length() - i;
						for (int l = 0; l < numCons; l++) {
							for (int r = l + n; r <= numCons; r++) {
								System.out.println(l + " " + r + " " + left
										+ " " + right);
								if (l == 0 && r == numCons) {
									ans += (left + l + 1)
											* (right + numCons - r + 1);
								} else {
									ans++;
									if (l == 0) {
										ans += left + l;
									}
									if (r == numCons) {
										ans += right + numCons - r;
									}
								}
								System.out.println(ans);
							}
						}
						prevEnd = i -n+1;
						
					}
					numCons = 0;
				} else {
					numCons++;
				}
			}
			if (numCons >= n) {
				long left = (s.length() - numCons - prevEnd);
				long right = 0;
				for (int l = 0; l < numCons; l++) {
					for (int r = l + n; r <= numCons; r++) {
					System.out.println(l + " " + r + " " + left
								+ " " + right+" "+ans);
						if (l == 0 && r == numCons) {
							ans += (left + l + 1)
									* (right + numCons - r + 1);
						} else {
							ans++;
							if (l == 0) {
								ans += left + l;
							}
							if (r == numCons) {
								ans += right + numCons - r;
							}
						}
					}
				}
			}

			System.out.println(s + " " + n + " " + ans);

			out.println("Case #" + (test + 1) + ": " + ans);
		}
		out.close();

		System.err.println("Time elapsed (ms): "
				+ (System.currentTimeMillis() - unixTime));

		System.exit(0); // don't omit this!
	}

	// Library

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static String next() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(f.readLine());
		}
		return st.nextToken();
	}

}

class ii {
	int a;
	int b;

	public ii(int a, int b) {
		this.a = a;
		this.b = b;
	}
}