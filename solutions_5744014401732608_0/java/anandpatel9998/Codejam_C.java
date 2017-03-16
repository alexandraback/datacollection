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

	static int n, m;

	static void function(int test) {
//		System.out.println("test "+test);
		n = inputReader.nextInt();
		m = inputReader.nextInt();
		int[][] a = new int[n][n];
		
		if(go(a, 0, 0)){
			outputWriter.println("Case #"+test+": POSSIBLE");
			for(int i =0 ;i < n ; i++){
				for(int j = 0 ;j < n; j++)
					outputWriter.print(a[i][j]);
				outputWriter.println();
			}
		}
		else{
			outputWriter.println("Case #"+test+": IMPOSSIBLE");
		}
	}

	static boolean go(int[][] a, int i ,int j){
//		System.out.println(i+" "+j);
		j++;
		if(j == n){
			i++;
			j = i+1;
		}
		if(i == n-1)
			if(check(a))
				return true;
			else 
				return false;
		a[i][j] = 0;
		if(go(a,i,j))
			return true;
		a[i][j] = 1;
		if(go(a,i,j))
			return true;
		return false;
	}

	public static boolean check(int[][] a) {
		int[][] b =matrixPowSum(a, n);
		if(b[0][n-1] == m)
			return true;
		else 
			return false;
	}

	public static int[][] matrixAdd(int[][] a, int[][] b) {
		int n = a.length;
		int m = a[0].length;
		int[][] res = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] = a[i][j] + b[i][j];
			}
		}
		return res;
	}

	public static int[][] matrixMul(int[][] a, int[][] b) {
		int n = a.length;
		int m = a[0].length;
		int k = b[0].length;
		int[][] res = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				for (int p = 0; p < m; p++) {
					res[i][j] = res[i][j] + a[i][p] * b[p][j];
				}
			}
		}
		return res;
	}

	public static int[][] matrixPow(int[][] a, int p) {
		if (p == 0) {
			return matrixUnit(a.length);
		} else if (p % 2 == 0) {
			return matrixPow(matrixMul(a, a), p / 2);
		} else {
			return matrixMul(a, matrixPow(a, p - 1));
		}
	}

	public static int[][] matrixPowSum(int[][] a, int p) {
		int n = a.length;
		if (p == 0) {
			return new int[n][n];
		}
		if (p % 2 == 0) {
			return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
		} else {
			return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
		}
	}

	public static int[][] matrixUnit(int n) {
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i) {
			res[i][i] = 1;
		}
		return res;
	}

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