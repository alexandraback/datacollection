import java.io.*;
import java.util.*;
import java.math.*;

public class Salesman implements Runnable {
	public static void main(String[] args) {
		new Thread(new Salesman()).start();
	}

	int findRoot(int[] father, int u) {
		if (father[u] == -1) {
			return u;
		}
		int v = findRoot(father, father[u]);
		father[u] = v;
		return v;
	}

	void merge(int[] father, int u, int v) {
		int p = findRoot(father, u);
		int q = findRoot(father, v);
		if (p != q) {
			father[p] = q;
		}
	}

	boolean connect(int n, Edge[] head, int[] stamp) {
		int[] father = new int[n];
		int count = 0;
		Arrays.fill(father, -1);
		for (int index = 0; index < n; ++index) {
			if (stamp[index] != 2) {
				++count;
				for (Edge e = head[index]; e != null; e = e.next) {
					int v = e.to;
					if (stamp[v] != 2) {
						merge(father, index, v);
					}
				}
			}
		}
		for (int index = 0; index < n; ++index) {
			if (father[index] == -1) {
				++count;
			}
		}
		return count == n + 1;
	}

	int encode(int[] code, int value) {
		for (int index = 0; index < code.length; ++index) {
			if (value == code[index]) {
				return index;
			}
		}
		return -1;
	}
	void addEdge(Edge[] head, int u, int v) {
		head[u] = new Edge(v, head[u]);
	}
	public void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int task = in.nextInt();
		for (int taskIndex = 1; taskIndex <= task; ++taskIndex) {
			int n = in.nextInt(), m = in.nextInt();
			int[] zip = new int[n];
			int[] copy = new int[n];
			for (int index = 0; index < n; ++index) {
				zip[index] = in.nextInt();
				copy[index] = zip[index];
			}
			Arrays.sort(copy);
			Edge[] head = new Edge[n];
			for (int index = 0; index < m; ++index) {
				int u = in.nextInt(), v = in.nextInt();
				addEdge(head, encode(copy, zip[u - 1]), encode(copy, zip[v - 1]));
				addEdge(head, encode(copy, zip[v - 1]), encode(copy, zip[u - 1]));
			}
			int[] path = new int[n];
			int[] stack = new int[n + 1];
			int[] stamp = new int[n];
			int[] dep = new int[n];
			int top = 1;
			stack[top] = 0;
			stamp[0] = 1;
			dep[0] = 1;
			path[0] = 0;
			for (int len = 1; len < n; ++len) {
				int[] adj = new int[n];
				Arrays.fill(adj, -1);
				for (int index = 0; index < n; ++index) {
					if (stamp[index] == 1) {
						for (Edge e = head[index]; e != null; e = e.next) {
							if (adj[e.to] == -1) {
								adj[e.to] = index;
							}
							else if (dep[index] > dep[adj[e.to]]) {
								adj[e.to] = index;
							}
						}
					}
				}
				for (int index = 0; index < n; ++index) {
					if (adj[index] != -1 && stamp[index] == 0) {
						int x = adj[index];
						int t = top;
						int[] mem = Arrays.copyOf(stamp, n);
						while (top > dep[x]) {
							stamp[stack[top]] = 2;
							--top;
						}
						if (connect(n, head, stamp)) {
							stack[++top] = index;
							stamp[index] = 1;
							dep[index] = top;
							path[len] = index;
							break;
						}
						else {
							top = t;
							stamp = mem;
						}
					}
				}
			}

			out.print("Case #" + taskIndex + ": ");
			for (int index = 0; index < n; ++index) {
				out.print(copy[path[index]]);
			}
			out.println();
		}

		out.close();
	}
}

class Edge {
	int to;
	Edge next;
	Edge(int to, Edge next) {
		this.to = to;
		this.next = next;
	}
}

class InputReader {
	BufferedReader buff;
	StringTokenizer tokenizer;

	InputReader(InputStream stream) {
		buff = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(buff.readLine());
			}
			catch (Exception e) {
				return false;
			}
		return true;
	}
	String next() {
		if (!hasNext())
			throw new RuntimeException();
		return tokenizer.nextToken();
	}
	int nextInt() { return Integer.parseInt(next()); }
	long nextLong() { return Long.parseLong(next()); }
}

