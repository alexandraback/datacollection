import java.awt.Container;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.LinkedBlockingDeque;

import javax.swing.border.Border;

public class a {

	public static long mod = (long) Math.pow(10, 9) + 7;

	private static class node implements Comparable<node> {
		int to;
		int R;
		int L;

		node(int a, int b, int c) {
			to = a;
			R = b;
			L = c;

		}

		@Override
		public int compareTo(node o) {
			if (o.R < R)
				return 1;
			else if (o.R > R)
				return -1;
			else if (o.L < L)
				return 1;
			else if (o.L > L)
				return -1;
			return 0;
		}

	}

	public static class point {
		int screen;
		int order;

		point(int x, int y) {
			screen = x;
			order = y;

		}

	}

	public static int ch(long y) {
		int r = Long.bitCount(y);
		return r;
	}

	public static long gcd(long x, long y) {
		if (y == 0)
			return x;

		return gcd(y, x % y);
	}

	public static boolean ch[] = new boolean[10000005];
	public static ArrayList<Integer> prime;

	// public static Queue<Integer> pp;

	public static void sieve(int k) {
		ch[0] = ch[1] = true;

		for (int i = 2; i <= k; i++) {
			if (!ch[i]) {
				prime.add(i);
				// pp.add(i);
				for (long j = (long) i * (long) i; j <= k; j += i) {
					ch[(int) j] = true;
				}
			}
		}

	}

	public static long pw(int x, int power, int mod) {
		if (power == 1)
			return x % mod;
		else if (power % 2 == 0)
			return pw((x % mod * x % mod) % mod, power / 2, mod);
		else
			return (pw(x, power - 1, mod) % mod * x % mod) % mod;

	}

	public static String addToString(String a, int index, char b) {
		String ans = "";
		for (int i = 0; i < a.length(); i++) {
			if (i == index) {
				ans += b;
				index = -1;
				i--;
				continue;
			}
			ans += a.charAt(i);
		}
		return ans;
	}

	public static int bit[][];

	public static void add(int idx, int n, int cost) {
		while (idx < bit.length) {
			bit[idx][n] += cost;
			idx += (idx & -idx);
		}

	}

	public static int get(int idx, int n) {
		int res = 0;
		while (idx > 0) {
			res += bit[idx][n];
			idx -= (idx & -idx);
		}
		return res;
	}

	public static int dx[] = { 0, 1, 0, -1 };
	public static int dy[] = { 1, 0, -1, 0 };
	public static long arr[];
	public static int n;
	public static int limit;
	public static long max;

	public static long solve(int p) {
		if (p >= limit)
			return 0;
		long a = solve(p * 2) + arr[p * 2];
		long b = solve(p * 2 + 1) + arr[p * 2 + 1];

		return Math.max(a, b);
	}

	public static long ans = 0;

	public static int binarySearch(int target, ArrayList<Integer> a) {
		int l = 0;
		int h = a.size();
		int mid = (l + h) / 2;
		while (h - l > 1) {

			if (a.get(mid) == target) {
				h = mid;
				break;
			}
			if (a.get(mid) < target)
				l = mid;
			else
				h = mid;

			mid = (l + h) / 2;
		}
		return h;

	}

	public static void main(String[] args) throws IOException {
		// BufferedReader in = new BufferedReader(new
		// InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(
				"B-large.in"));

		StringBuilder qq = new StringBuilder();
		// PrintWriter out = new PrintWriter(new
		// OutputStreamWriter(System.out));
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		// System.out.println('a' - 'A');
		prime = new ArrayList();
		// sieve(1005);

		int tc = Integer.parseInt(in.readLine());
		for (int i = 0; i < tc; i++) {
			int n = Integer.parseInt(in.readLine());
			String y[] = in.readLine().split(" ");
			TreeSet<Integer> mp = new TreeSet();
			long ans = -1;
			int ok[] = new int[1005];
			for (int j = 0; j < n; j++) {
				int k = Integer.parseInt(y[j]);

				ans = Math.max(ans, k);
				if (ok[k] == 0)
					mp.add(k);
				ok[k]++;
			}
			int min = 0;
			while (!mp.isEmpty()) {
				int top = mp.last();
				if (top <= 3)
					break;
				min += ok[top];
				mp.remove(top);
				int num1;
				int num2;
				if (top == 9) {
					if (ok[9]>1||ok[5] > 0) {
						num1 = 4;
						num2 = 5;
					} else {
						num1 = 3;
						num2 = 6;
					}
				} else {
					num1 = top / 2;
					num2 = top - num1;

				}

				ok[num1] += ok[top];
				ok[num2] += ok[top];
				ok[top] = 0;
				mp.add(num1);
				mp.add(num2);

				ans = Math.min(ans, min + mp.last());

			}
			// System.out.println("Case #" + (i + 1) + ": " + ans);
			out.println("Case #" + (i + 1) + ": " + ans);

		}

		out.close();

	}
}