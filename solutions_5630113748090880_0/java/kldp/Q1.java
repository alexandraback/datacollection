package cj16;

import java.io.*;
import java.math.*;
import java.util.*;

public class Q1 {

	static int mod = (int) 1e9 + 7;
	static int MAX = (int) 1e9;
	static ArrayList<Integer>[] g;
	static int n, m;
	static long k;
	static int[][] a;
	static int nodes = 0;
	static int edges = 0;
	static boolean[][] done;
	static int[][] ans;

	public static void main(String[] args) {
		FasterScanner s = new FasterScanner();
		PrintWriter out = new PrintWriter(System.out);
		int test = s.nextInt();
		for (int tt = 1;tt <= test; tt++) {
			int n  = s.nextInt();
			int[] count = new int[2501];
			for(int j= 0 ; j <2*n-1;j++){
				for(int i=0 ;i<n;i++)
					count[s.nextInt()]++;
			}
			int[] ans = new int[n];
			int j = 0;
			for(int i=0;i<2501;i++){
				if(count[i]%2==1)
					ans[j++] = i;
			}
			Arrays.sort(ans);
			out.print("Case #"+tt+": ");
			for(int i=0;i<n;i++)
				out.print(ans[i]+" ");
			out.println();
		}
		out.close();
	}

	static class Component implements Comparable<Component> {
		int id;
		int size;

		Component(int id, int size) {
			this.id = id;
			this.size = size;
		}

		@Override
		public int compareTo(Component o) {
			return size - o.size;
		}
	}

	static class Point {
		int x, y;

		Point(int xx, int yy) {
			x = xx;
			y = yy;
		}
	}

	static void dfs(int x, int y, int rem, int val) {
		if (rem <= 0)
			return;
		rem--;
		done[x][y] = true;
		if (check(x + 1, y) && !done[x + 1][y] && a[x + 1][y] >= val)
			dfs(x + 1, y, rem, val);
		if (check(x - 1, y) && !done[x - 1][y] && a[x - 1][y] >= val)
			dfs(x - 1, y, rem, val);
		if (check(x, y + 1) && !done[x][y + 1] && a[x][y + 1] >= val)
			dfs(x, y + 1, rem, val);
		if (check(x, y - 1) && !done[x][y - 1] && a[x][y - 1] >= val)
			dfs(x, y - 1, rem, val);
	}

	static boolean check(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	}

	static class Player implements Comparable<Player> {
		String name;
		int score;

		Player(String n, int v) {
			name = n;
			score = v;
		}

		@Override
		public int compareTo(Player o) {
			return o.score - score;
		}
	}

	static class Edge {
		int t, rev, f;
		long cap;

		public Edge(int t, int rev, long cap) {
			this.t = t;
			this.rev = rev;
			this.cap = cap;
		}
	}

	public static List<Edge>[] createGraph(int nodes) {
		List<Edge>[] graph = new List[nodes];
		for (int i = 0; i < nodes; i++)
			graph[i] = new ArrayList<>();
		return graph;
	}

	public static void addEdge(List<Edge>[] graph, int s, int t, long cap) {
		graph[s].add(new Edge(t, graph[t].size(), cap));
		graph[t].add(new Edge(s, graph[s].size() - 1, 0));
	}

	static boolean dinicBfs(List<Edge>[] graph, int src, int dest, int[] dist) {
		Arrays.fill(dist, -1);
		dist[src] = 0;
		int[] Q = new int[graph.length];
		int sizeQ = 0;
		Q[sizeQ++] = src;
		for (int i = 0; i < sizeQ; i++) {
			int u = Q[i];
			for (Edge e : graph[u]) {
				if (dist[e.t] < 0 && e.f < e.cap) {
					dist[e.t] = dist[u] + 1;
					Q[sizeQ++] = e.t;
				}
			}
		}
		return dist[dest] >= 0;
	}

	static long dinicDfs(List<Edge>[] graph, int[] ptr, int[] dist, int dest, int u, long l) {
		if (u == dest)
			return l;
		for (; ptr[u] < graph[u].size(); ++ptr[u]) {
			Edge e = graph[u].get(ptr[u]);
			if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
				long df = dinicDfs(graph, ptr, dist, dest, e.t, Math.min(l, e.cap - e.f));
				if (df > 0) {
					e.f += df;
					graph[e.t].get(e.rev).f -= df;
					return df;
				}
			}
		}
		return 0;
	}

	public static long maxFlow(List<Edge>[] graph, int src, int dest) {
		long flow = 0;
		int[] dist = new int[graph.length];
		while (dinicBfs(graph, src, dest, dist)) {
			int[] ptr = new int[graph.length];
			while (true) {
				long df = dinicDfs(graph, ptr, dist, dest, src, Integer.MAX_VALUE);
				if (df == 0)
					break;
				flow += df;
			}
		}
		return flow;
	}

	static int ans(ArrayList<Character>[] l, char a, int n) {
		if (n == 1)
			return 1;
		int sum = 0;
		for (int i = 0; i < l[a - 'a'].size(); i++) {
			sum += ans(l, l[a - 'a'].get(i), n - 1);
		}
		return sum;
	}

	static void dfs1(List<Integer>[] graph, boolean[] used, List<Integer> order, int u) {
		used[u] = true;
		for (int v : graph[u])
			if (!used[v])
				dfs1(graph, used, order, v);
		order.add(u);
	}

	static void dfs2(List<Integer>[] reverseGraph, int[] comp, int u, int color) {
		comp[u] = color;
		for (int v : reverseGraph[u])
			if (comp[v] == -1)
				dfs2(reverseGraph, comp, v, color);
	}

	public static boolean[] solve2Sat(List<Integer>[] graph) {
		int n = graph.length;
		boolean[] used = new boolean[n];
		List<Integer> order = new ArrayList<>();
		for (int i = 0; i < n; ++i)
			if (!used[i])
				dfs1(graph, used, order, i);

		List<Integer>[] reverseGraph = new List[n];
		for (int i = 0; i < n; i++)
			reverseGraph[i] = new ArrayList<>();
		for (int i = 0; i < n; i++)
			for (int j : graph[i])
				reverseGraph[j].add(i);

		int[] comp = new int[n];
		Arrays.fill(comp, -1);
		for (int i = 0, color = 0; i < n; ++i) {
			int u = order.get(n - i - 1);
			if (comp[u] == -1)
				dfs2(reverseGraph, comp, u, color++);
		}

		for (int i = 0; i < n; ++i)
			if (comp[i] == comp[i ^ 1])
				return null;

		boolean[] res = new boolean[n / 2];
		for (int i = 0; i < n; i += 2)
			res[i / 2] = comp[i] > comp[i ^ 1];
		return res;
	}

	public static int[] createSets(int size) {
		int[] p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = i;
		return p;
	}

	public static int root(int[] p, int x) {
		return x == p[x] ? x : (p[x] = root(p, p[x]));
	}

	public static void unite(int[] p, int a, int b) {
		a = root(p, a);
		b = root(p, b);
		if (a != b)
			p[a] = b;
	}

	public static boolean nextPermutation(int[] p) {
		for (int a = p.length - 2; a >= 0; --a)
			if (p[a] < p[a + 1])
				for (int b = p.length - 1;; --b)
					if (p[b] > p[a]) {
						int t = p[a];
						p[a] = p[b];
						p[b] = t;
						for (++a, b = p.length - 1; a < b; ++a, --b) {
							t = p[a];
							p[a] = p[b];
							p[b] = t;
						}
						return true;
					}
		return false;
	}

	public static boolean isPrime(long n) {
		if (n <= 1)
			return false;
		for (long i = 2; i * i <= n; i++)
			if (n % i == 0)
				return false;
		return true;
	}

	static class SegTree {
		int[] val;
		int n;

		SegTree(int n) {
			val = new int[2 * n];
			this.n = n;
		}

		void upd(int p, int l) {
			p += n;
			val[p] = l;
			for (; (p >>= 1) != 0;) {
				val[p] = Math.max(val[2 * p], val[2 * p + 1]);

			}
		}

		int query(int l, int r) { // sum on interval [l, r)
			// System.out.println(l+" "+r);
			int res = 0;
			for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
				if ((l & 1) != 0)
					res = Math.max(res, val[l++]);
				if ((r & 1) != 0)
					res = Math.max(res, val[--r]);
			}
			return res;
		}
	}

	static boolean check(int i, int j, int n) {
		if (i >= 0 && j >= 0 && i < n && j < n)
			return true;
		return false;
	}

	public static int[] generateDivisorTable(int n) {
		int[] divisor = new int[n + 1];
		for (int i = 1; i <= n; i++)
			divisor[i] = i;
		for (int i = 2; i * i <= n; i++)
			if (divisor[i] == i)
				for (int j = i * i; j <= n; j += i)
					divisor[j] = i;
		return divisor;
	}

	public static int[][] matrixMul(int[][] a, int[][] b) {
		int n = a.length;
		int m = a[0].length;
		int k = b[0].length;
		int[][] res = new int[n][k];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				for (int p = 0; p < m; p++) {
					res[i][j] = (res[i][j] + (int) ((a[i][p] * 1l * b[p][j]) % mod)) % mod;
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

	public static int[][] matrixUnit(int n) {
		int[][] res = new int[n][n];
		for (int i = 0; i < n; ++i) {
			res[i][i] = 1;
		}
		return res;
	}

	static int[] modInv(int n, int mod) {
		int[] ans = new int[n];
		for (int i = 1; i < n; i++)
			ans[i] = (int) pow(i, mod - 2, mod);
		return ans;
	}

	static int[] primes;

	public static long ncr(int n, int r) {
		if (n < r)
			return 0;
		if (n == r)
			return 1;
		if (r == 0)
			return 1;
		if (r < 0)
			return 0;
		long ans = 1;
		for (int i = 0; i < primes.length; i++) {
			long power = count(n, primes[i]) - count(n - r, primes[i]) - count(r, primes[i]);
			ans *= pow(primes[i], power, mod);
			ans %= mod;
		}
		return ans;
	}

	public static long pow(long x, long n, int mod) {
		long res = 1;
		for (long p = x; n > 0; n >>= 1, p = (p * p) % mod) {
			if ((n & 1) != 0) {
				res = (int) (res * p % mod);
			}
		}
		return res;
	}

	public static long count(int n, int p) {
		long count = 0;
		long z = p;
		while (z <= n) {
			count += n / z;
			z *= p;
		}
		return count;

	}

	public static int[] generatePrimes(int n) {
		boolean[] prime = new boolean[n + 1];
		Arrays.fill(prime, 2, n + 1, true);
		for (int i = 2; i * i <= n; i++)
			if (prime[i])
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;
		int[] primes = new int[n + 1];
		int cnt = 0;
		for (int i = 0; i < prime.length; i++)
			if (prime[i])
				primes[cnt++] = i;

		return Arrays.copyOf(primes, cnt);
	}

	static class Pairxy implements Comparable<Pairxy> {
		int x;
		int y;

		Pairxy(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Pairxy o) {
			return Integer.compare(this.x, o.x);
		}

	}

	static class Pair implements Comparable<Pair> {
		long val;
		int ind;

		Pair(long v, int i) {
			val = v;
			ind = i;
		}

		public int compareTo(Pair o) {
			if (this.val != o.val)
				return Long.compare(this.val, o.val);
			return Integer.compare(this.ind, o.ind);
		}
	}

	public static long C(int n, int r) {
		long ans = 1;
		int x = 1;
		while (x <= r) {
			ans *= n;
			ans /= x;
			x++;
			n--;
		}
		return ans;
	}

	static class DisjointSetsRank {

		int[] p;
		int[] rank;
		int[] size;

		public DisjointSetsRank(int size) {
			p = new int[size];
			this.size = new int[size];
			for (int i = 0; i < size; i++) {
				p[i] = i;
				this.size[i] = 1;
			}
			rank = new int[size];
		}

		public int root(int x) {
			return x == p[x] ? x : (p[x] = root(p[x]));
		}

		public int sameSet(int x, int y) {
			if (root(x) == root(y))
				return 1;
			return 0;

		}

		public int unite(int a, int b) {
			a = root(a);
			b = root(b);
			if (a == b)
				return -1;

			if (rank[a] < rank[b]) {
				p[a] = b;
				size[b] += size[a];
				return a;
			} else {
				p[b] = a;
				size[a] += size[b];
				if (rank[a] == rank[b])
					++rank[a];
				return b;
			}
		}

	}

	static int gcd(long m, long n) {
		long x;
		long y;
		while (m % n != 0) {
			x = n;
			y = m % n;
			m = x;
			n = y;
		}
		return (int) n;
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