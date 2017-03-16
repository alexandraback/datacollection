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
	//	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		 BufferedReader in = new BufferedReader(new FileReader(
		 "C-large.in"));

		StringBuilder qq = new StringBuilder();
		//PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		 PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		// System.out.println('a' - 'A');
		int k[][] = new int[128][128];
		k[1][1] = 1;
		k[1]['i'] = 'i';
		k[1]['j'] = 'j';
		k[1]['k'] = 'k';
		// ...............

		k['i'][1] = 'i';
		k['i']['i'] = -1;
		k['i']['j'] = 'k';
		k['i']['k'] = -1 * 'j';
		// ...............
		k['j'][1] = 'j';
		k['j']['i'] = -'k';
		k['j']['j'] = -1;
		k['j']['k'] = 'i';
		// ...............
		k['k'][1] = 'k';
		k['k']['i'] = 'j';
		k['k']['j'] = -'i';
		k['k']['k'] = -1;

		int tc = Integer.parseInt(in.readLine());
		for (int i = 0; i < tc; i++) {

			String y[] = in.readLine().split(" ");
			int n = Integer.parseInt(y[0]);
			long m = Long.parseLong(y[1]);

			String a = in.readLine();
			out.print("Case #" + (i + 1) + ": ");
			if (n * m < 3) {
				out.println("NO");
				continue;
			}
			int pre = 1;
			int presign = 0;
			for (int j = 0; j < n; j++) {
				pre = k[pre][a.charAt(j)];
				if (pre < 0) {
					presign ^= 1;
					pre *= -1;
				}
			}
			int ans = 1;
			int sign = 0;
			int res = 0;
			int r = 0;
			int j;

			for (j = 0; j < m; j++) {
				for (int j2 = 0; j2 < n; j2++) {
					ans = k[ans][a.charAt(j2)];
					if (ans < 0) {
						sign ^= 1;
						ans = Math.abs(ans);
					}
					if (res == 0) {
						if (ans == 'i') {
							res++;
							ans = 1;
							r = 0;
						}
					} else if (res == 1) {
						if (ans == 'j') {
							res++;
							ans = 1;
							r = 0;
						}
					} else if (res == 2) {
						if (ans == 'k') {
							res++;
							ans = 1;
							r = 0;
						}
					}
				}
				r++;
				if (r >= 2) {
					j++;
					break;
				}
			}

			if (res == 3) {
				long mod = ((long) m - (long) j) % 4;
				int answer = 1;
				int ansSign = 0;
				if (mod == 1) {
					answer = pre;
					ansSign = presign;
				} else if (mod == 2) {
					answer = k[pre][pre];
					if (answer < 0)
						ansSign = 1;
					answer=Math.abs(answer);
				} else if (mod == 3) {
					ansSign = presign;
					answer = k[pre][pre];
					if (answer < 0)
						ansSign ^= 1;
					answer = Math.abs(answer);
					answer = k[answer][pre];
					if (answer < 0)
						ansSign ^= 1;
					answer = Math.abs(answer);
				}
				if (sign == 1)
					ansSign ^= 1;
				answer = k[ans][answer];
				if (answer < 0)
					ansSign ^= 1;
				answer = Math.abs(answer);
				
				if(ansSign==0&&answer==1){
					out.println("YES");
				}
				else
					out.println("NO");

			} else {
				out.println("NO");
			}

		}

		out.close();

	}
}