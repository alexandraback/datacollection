import java.io.*;
import java.util.*;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"B-large.in")));
		tokenizer = null;
		writer = new PrintWriter("B-large2.out");

		pre();

		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #" + i + ": ");
			banana();
		}

		reader.close();
		writer.close();
	}

	 static double C(long n, long k, double d) {
	 double res = d;
	 for (long i = 1; i <= k; ++i)
	 res = res * (n - k + i) / i;
	 return res;
	 }

	// static long C(long n, long k) {
	// double res = 1;
	// for (long i = 1; i <= k; ++i)
	// res = res * (n - k + i) / i;
	// return (long) (res + 0.01);
	// }

	static ArrayList<Integer> al;
	static ArrayList<Integer> side;

	static void pre() {
		al = new ArrayList<Integer>();
		side = new ArrayList<Integer>();
		int sum = 0;
		for (int i = 0; i <= 1488; i += 2) {
			int j = 2 * i + 1;
			al.add(sum);
			side.add(i + 1);
			sum += j;
		}
	}

	static boolean isgood(int left, int right, int sz, int y) {
		if (right > sz - 1) {
			left += right - (sz - 1);
			right = sz - 1;
		}

		if (y + 1 <= left) {
			return true;
		}
		return false;
	}

	private static void banana() throws IOException {
		int a = nextInt();
		int x = nextInt();
		int y = nextInt();
		int n = al.size();
		int sz = -1;
		int curr = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (a >= al.get(i)) {
				a -= al.get(i);
				sz = side.get(i);
				curr = i;
				break;
			}
		}
		int xy = (Math.abs(x) + Math.abs(y)) / 2;

		if (xy > curr) {
			writer.println(0.0);
			return;
		}

		if (xy < curr) {
			writer.println(1.0);
			return;
		}

		// System.out.println("x " + x + " y " + y + " a " + a + " sz " + sz);

		if (y == sz - 1) {
			if (a == 2 * sz - 1) {
				writer.println(1.0);
			} else {
				writer.println(0.0);
			}
			return;
		}

		double res = 0.0;
		for (int left = 0; left <= a; left++) {
			int right = a - left;
			if (isgood(left, right, sz, y)) {
				res += C(a, left, Math.pow(0.5, a));
			}
		}
		writer.println(res);
	}
}