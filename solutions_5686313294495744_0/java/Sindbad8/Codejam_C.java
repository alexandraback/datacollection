package cj16;

import java.io.*;
import java.math.*;
import java.util.*;

public class Codejam_C {

	static int mod = (int) 1e9 + 7;
	static int MAX = (int) 1e9;
	static ArrayList<Integer>[] g;
	static int[] a;
	static boolean[] done;
	static FasterScanner inputReader;
	static PrintWriter outputWriter;

	public static void main(String[] args) {
		inputReader = new FasterScanner();
		outputWriter = new PrintWriter(System.out);
		int testecases = inputReader.nextInt();
		int test = 0;
		while (testecases-- > 0) {
			test++;
			function(test);
		}
		outputWriter.close();
	}

	static void function(int test) {
		int n = inputReader.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		HashMap<String, Integer> mapA = new HashMap<>();
		HashMap<String, Integer> mapB = new HashMap<>();
		int countA = 0;
		int countB = 0;
		for (int i = 0; i < n; i++) {
			String x = inputReader.nextString();
			String y = inputReader.nextString();
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
		int min = (int)1e7;
		loop:
		for(int val = 0; val < (1<<n); val++){
			boolean[] doneA = new boolean[countA];
			boolean[] doneB = new boolean[countB];
			int count = 0;
			for(int i = 0 ; i < n ; i ++ ){
				if((val & (1<<i)) != 0){
					doneA[a[i]] = true;
					doneB[b[i]] = true;
					count++;
				}
			}
			for(int i = 0 ; i < countA;i++){
				if(!doneA[i])
					continue loop;
			}
			for(int i = 0 ; i < countB;i++){
				if(!doneB[i])
					continue loop;
			}
			min = Math.min(min, count);
		}
		outputWriter.println("Case #"+test+": "+(n - min));
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

	static void markPath(int[] match, int[] base, boolean[] blossom, int[] p, int v, int b, int children) {
		for (; base[v] != b; v = p[match[v]]) {
			blossom[base[v]] = blossom[base[match[v]]] = true;
			p[v] = children;
			children = match[v];
		}
	}

	static int findPath(List<Integer>[] graph, int[] match, int[] p, int root) {
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
					boolean[] blossom = new boolean[n];
					markPath(match, base, blossom, p, v, curbase, to);
					markPath(match, base, blossom, p, to, curbase, v);
					for (int i = 0; i < n; ++i)
						if (blossom[base[i]]) {
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

	public static int maxMatching(List<Integer>[] graph) {
		int n = graph.length;
		int[] match = new int[n];
		Arrays.fill(match, -1);
		int[] p = new int[n];
		for (int i = 0; i < n; ++i) {
			if (match[i] == -1) {
				int v = findPath(graph, match, p, i);
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

	static void dfs(int u, int parent) {
		done[u] = true;
		for (int v : g[u]) {
			if (v != parent && !visited[v]) {
				dfs(v, u);
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