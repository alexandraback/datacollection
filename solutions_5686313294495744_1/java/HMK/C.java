package round2;

import java.io.*;
import java.math.*;
import java.util.*;

public class C {

	static int mod = (int) 1e9 + 7;
	static int MAX = (int) 1e9;
	static ArrayList<Integer>[] graph;
	static int[] a;
	static boolean[] done;

	public static void mian(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		while (t-- > 0) {
			char[] a = in.nextLine().toCharArray();
			char[] b = in.nextLine().toCharArray();
			int n1 = a.length;
			int n2 = b.length;
			int[][] L1 = new int[n1][n1];
			int[][] L2 = new int[n2][n2];
			int[][] c1 = new int[n1][n1];
			int[][] c2 = new int[n2][n2];
			int i, j, cl;
			for (i = 0; i < n1; i++) {
				L1[i][i] = 1;
				c1[i][i] = 1 << (a[i] - 'a');
			}

			// Build the table. Note that the lower diagonal values of table are
			// useless and not filled in the process. The values are filled in a
			// manner similar to Matrix Chain Multiplication DP solution (See
			// http://www.geeksforgeeks.org/archives/15553). cl is length of
			// substring
			for (cl = 2; cl <= n1; cl++) {
				for (i = 0; i < n1 - cl + 1; i++) {
					j = i + cl - 1;
					if (a[i] == a[j] && cl == 2)
						L1[i][j] = 2;
					else if (a[i] == a[j]) {
						L1[i][j] = L1[i + 1][j - 1] + 2;
						c1[i][j] = c1[i + 1][j - 1];
					} else {
						// L1[i][j] = Math.max(L1[i][j - 1], L1[i + 1][j]);
						if (L1[i][j - 1] > L1[i + 1][j]) {
							L1[i][j] = L1[i][j - 1];
							c1[i][j] = c1[i][j - 1];
						} else if (L1[i][j - 1] < L1[i + 1][j]) {
							L1[i][j] = L1[i + 1][j];
							c1[i][j] = c1[i + 1][j];
						} else {
							L1[i][j] = L1[i + 1][j];
							c1[i][j] = c1[i + 1][j] | c1[i][j - 1];
						}
					}
				}
			}

			for (i = 0; i < n2; i++) {
				L2[i][i] = 1;
				c2[i][i] = 1 << (b[i] - 'a');
			}

			for (cl = 2; cl <= n2; cl++) {
				for (i = 0; i < n2 - cl + 1; i++) {
					j = i + cl - 1;
					if (b[i] == b[j] && cl == 2)
						L2[i][j] = 2;
					else if (b[i] == b[j]) {
						L2[i][j] = L2[i + 1][j - 1] + 2;
						c2[i][j] = c2[i + 1][j - 1];
					} else {
						// L1[i][j] = Math.max(L1[i][j - 1], L1[i + 1][j]);
						if (L2[i][j - 1] > L2[i + 1][j]) {
							L2[i][j] = L2[i][j - 1];
							c2[i][j] = c2[i][j - 1];
						} else if (L2[i][j - 1] < L2[i + 1][j]) {
							L2[i][j] = L2[i + 1][j];
							c2[i][j] = c2[i + 1][j];
						} else {
							c2[i][j] = c2[i + 1][j] | c2[i][j - 1];
							L2[i][j] = L2[i + 1][j];
						}
					}
				}
			}

			if (L1[0][n1 - 1] % 2 == 0 || L2[0][n2 - 1] % 2 == 0) {
				int ans = L1[0][n1 - 1] + L2[0][n2 - 1];
				System.out.println(ans);
			} else {

			}
		}
	}

	public static void main(String[] args) {
		FasterScanner in = new FasterScanner();
		PrintWriter out = new PrintWriter(System.out);
		int T = in.nextInt();

		for (int t = 1; t <= T; t++) {
			int n = in.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			HashMap<String, Integer> mapA = new HashMap<>();
			HashMap<String, Integer> mapB = new HashMap<>();
			int countA = 0;
			int countB = 0;
			for (int i = 0; i < n; i++) {
				String x = in.nextString();
				String y = in.nextString();
				if (!mapA.containsKey(x)) {
					mapA.put(x, countA++);
				}
				a[i] = mapA.get(x);
				if (!mapB.containsKey(y)) {
					mapB.put(y, countB++);
				}
				b[i] = mapB.get(y);
			}
			int total = countA + countB;
			ArrayList<Integer> g[] = new ArrayList[total];
			for (int i = 0; i < total; i++)
				g[i] = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				g[a[i]].add(b[i] + countA);
				g[b[i] + countA].add(a[i]);
			}

			int ans = n - total + bipartiteMatching(g);
			out.println("Case #" + t + ": " + ans);
		}
		out.close();
	}

	// System.out.println(+ + " " + countB);
	// int total = countA + countB;
	// List<Edge>[] graph = createGraph(total+2);
	// for (int i = 0; i < n; i++)
	// addEdge(graph, a[i], b[i]+ countA, 1);
	// for(int i = 0 ; i < countA;i++)
	// addEdge(graph, total, i, (int)1e5);
	// for(int i = 0; i < countB ;i++)
	// addEdge(graph, i+countA, total+1, (int)1e5);
	// long ans = n - maxFlow(graph, total, total+1);

	static int lca(int[] match, int[] base, int[] p, int a, int b) {
		boolean[] used = new boolean[match.length];
		while (true) {
			a = base[a];
			used[a] = true;
			if (match[a] == -1)
				break;
			a = p[match[a]];
		}
		while (true) {
			b = base[b];
			if (used[b])
				return b;
			b = p[match[b]];
		}
	}

	static void markEdges(int[] match, int[] base, boolean[] buttercup, int[] p, int v, int b, int children) {
		for (; base[v] != b; v = p[match[v]]) {
			buttercup[base[v]] = buttercup[base[match[v]]] = true;
			p[v] = children;
			children = match[v];
		}
	}

	static int findEdges(List<Integer>[] graph, int[] match, int[] p, int root) {
		int n = graph.length;
		boolean[] used = new boolean[n];
		Arrays.fill(p, -1);
		int[] base = new int[n];
		for (int i = 0; i < n; ++i)
			base[i] = i;

		used[root] = true;
		int qh = 0;
		int qt = 0;
		int[] q = new int[n];
		q[qt++] = root;
		while (qh < qt) {
			int v = q[qh++];

			for (int to : graph[v]) {
				if (base[v] == base[to] || match[v] == to)
					continue;
				if (to == root || match[to] != -1 && p[match[to]] != -1) {
					int curbase = lca(match, base, p, v, to);
					boolean[] bubbles = new boolean[n];
					markEdges(match, base, bubbles, p, v, curbase, to);
					markEdges(match, base, bubbles, p, to, curbase, v);
					for (int i = 0; i < n; ++i)
						if (bubbles[base[i]]) {
							base[i] = curbase;
							if (!used[i]) {
								used[i] = true;
								q[qt++] = i;
							}
						}
				} else if (p[to] == -1) {
					p[to] = v;
					if (match[to] == -1)
						return to;
					to = match[to];
					used[to] = true;
					q[qt++] = to;
				}
			}
		}
		return -1;
	}

	public static int bipartiteMatching(List<Integer>[] graph) {
		int n = graph.length;
		int[] match = new int[n];
		Arrays.fill(match, -1);
		int[] p = new int[n];
		for (int i = 0; i < n; ++i) {
			if (match[i] == -1) {
				int v = findEdges(graph, match, p, i);
				while (v != -1) {
					int pv = p[v];
					int ppv = match[pv];
					match[v] = pv;
					match[pv] = v;
					v = ppv;
				}
			}
		}

		int matches = 0;
		for (int i = 0; i < n; ++i)
			if (match[i] != -1)
				++matches;
		return matches / 2;
	}

	static int len[];
	static boolean visited[];

	static void depthfirstsearch(int u, int parent) {
		done[u] = true;
		for (int v : graph[u]) {
			if (v != parent && !visited[v]) {
				depthfirstsearch(v, u);
				len[u] = Math.max(len[u], len[v]);
			}
		}
		len[u]++;
	}

	static class FasterScanner {
		private byte[] buf = new byte[1024];
		private int curChar;
		private int snumChars;

		public int read() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = System.in.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public String nextLine() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public String nextString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public long nextLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int nextInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			return arr;
		}

		public long[] nextLongArray(int n) {
			long[] arr = new long[n];
			for (int i = 0; i < n; i++) {
				arr[i] = nextLong();
			}
			return arr;
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
	}
}
