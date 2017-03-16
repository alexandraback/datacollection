import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.security.interfaces.DSAKey;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class a {

	public static class in {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		static void init(InputStream input) throws FileNotFoundException {
			 reader = new BufferedReader(new FileReader("A-large.in"));
			//reader = new BufferedReader(new InputStreamReader(input));
			tokenizer = new StringTokenizer("");
		}

		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens())
				tokenizer = new StringTokenizer(reader.readLine());
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}

	public static long comp(int n, int r) {
		r = Math.min(r, n - r);
		long ans = 1;
		for (int i = 1; i <= r; i++) {
			ans = ans * (long) (n - r + i) / (long) i;
		}
		return ans;

	}

	public static class node {

		int a;
		int b;
		int pos;

		node(int a, int b, int pos) {
			this.a = a;
			this.b = b;
			this.pos = pos;

		}

	}

	public static long gcd(int x, int y) {
		if (y == 0)
			return x;
		return gcd(y, x % y);
	}

	public static int tree[];

	public static void add(int idx, long val, int n) {

		while (idx <= n) {
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}

	public static int get(int idx) {
		int g = 0;
		while (idx > 0) {

			g += tree[idx];
			idx -= (idx & -idx);
		}

		return g;
	}

	public static class point implements Comparable<point> {
		int min;
		int a;
		int b;

		point(int min, int a, int b) {
			this.min = min;
			this.a = a;
			this.b = b;
		}

		@Override
		public int compareTo(point o) {
			if (o.min > min)
				return 1;
			else if (o.min < min)
				return -1;
			return 0;
		}
	}

	public static int LCS(String a, String b) {
		int max = 0;
		int dp[][] = new int[a.length() + 1][b.length() + 1];
		for (int i = 1; i <= a.length(); i++) {
			for (int j = 1; j <= b.length(); j++) {
				if (a.charAt(i - 1) == b.charAt(j - 1))
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

				max = Math.max(max, dp[i][j]);
			}
		}

		return max;
	}

	// for bad input
	static String ReadLn(int maxLg) {
		byte lin[] = new byte[maxLg];
		int lg = 0, car = -1;
		String line = "";

		try {
			while (lg < maxLg) {
				car = System.in.read();
				if ((car < 0) || (car == '\n'))
					break;
				lin[lg++] += car;
			}
		} catch (IOException e) {
			return (null);
		}

		if ((car < 0) && (lg == 0))
			return (null);
		return (new String(lin, 0, lg));
	}

	public static void main(String[] args) throws IOException {
		// StringBuilder qq = new StringBuilder();
		in.init(System.in);
		 PrintWriter out = new PrintWriter("output.txt");
		//PrintWriter out = new PrintWriter(System.out);

		// source code
		// String hostNamee = "http://";
		// System.out.println(hostNamee.length());
		// int a[] = { 1, 2, 4 };
		// System.out.println(Arrays.binarySearch(a, 3));
		String arr[] = { "ZERO", "TWO", "FOUR", "EIGHT", "SIX", "ONE", "FIVE",
				"NINE", "SEVEN", "THREE" };
		int num[] = { 0, 2, 4, 8, 6, 1, 5, 9, 7, 3 };
		int tc = in.nextInt();
		for (int i = 1; i <= tc; i++) {
			String a = in.next();
			int count[] = new int[100];
			for (int j = 0; j < a.length(); j++) {
				count[a.charAt(j) - 'A']++;
			//	System.out.println(count[a.charAt(j)-'A']);
			}

			PriorityQueue<Integer> q = new PriorityQueue<>();

			for (int j = 0; j < 10; j++) {
				int min = Integer.MAX_VALUE;
				for (int j2 = 0; j2 < arr[j].length(); j2++) {
					min = Math.min(min, count[arr[j].charAt(j2)-'A']);
				}
				if (min != 0) {
					for (int k = 0; k < min; k++) {
						q.add(num[j]);
					}
					
					for (int j2 = 0; j2 < arr[j].length(); j2++) {
						count[arr[j].charAt(j2)-'A'] -= min;
					}
				}
			}
			out.print("Case #" + i + ": ");
			while (!q.isEmpty()) {
				out.print(q.poll());
			}
			out.println();
		}

		out.close();

	}
}
