package round1c;

import java.io.*;
import java.util.*;

public class A {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	final String file = "round1c\\A-small-attempt0";

	class Node {
		int value;
		int[] inherits;

		public Node(int value) {
			this.value = value;
		}
	}

	private static Node[] nodes;

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		int N = nextInt();
		nodes = new Node[N];
		int maxM = -1;
		for (int i = 0; i < N; i++) {
			nodes[i] = new Node(i);
			int M = nextInt();
			if (M > maxM) {
				maxM = M;
			}
			nodes[i].inherits = new int[M];
			for (int j = 0; j < M; j++) {
				nodes[i].inherits[j] = nextInt() - 1;
			}
		}
		
		boolean found = false;
		if (maxM < 2) {
			found = true;
			out.print("No");
		}
		// Find paths.
		ArrayList<ArrayList<Node>> paths = new ArrayList<ArrayList<Node>>();
		if (!found)
		for (int i = 0; i < N; i++) {
			findAllPaths(nodes[i], paths);
		}
		
		if (!found)
		for (int i=0; i<paths.size(); i++) {
			ArrayList<Node> x = paths.get(i);
			for (int j=0; j<paths.size(); j++) {
				if (i==j)
					continue;
				ArrayList<Node> y = paths.get(j);
				if (x.get(0)==y.get(0) && x.get(x.size()-1)==y.get(y.size()-1)) {
					found = true;
					out.print("Yes");
					break;
				}
			}
			if (found)
				break;
		}
		if (!found)
			out.print("No");
		System.out.println();

		out.println();
	}

	private static Stack<Node> stack = new Stack<Node>();

	private void findAllPaths(Node node, ArrayList<ArrayList<Node>> paths) {
		stack.push(node);
		if (node.inherits.length > 0) {
			for (int i = 0; i < node.inherits.length; i++) {
				findAllPaths(nodes[node.inherits[i]], paths);
			}
		}

		if (node.inherits.length==0) {
			ArrayList<Node> path = new ArrayList<Node>();
			for (Node aNode : stack) {
				path.add(aNode);
			}
			if (path.size()!=1)
				paths.add(path);
		}
		stack.pop();
	}

	public void run() throws IOException {
		in = new BufferedReader(new FileReader(file + ".in"));
		out = new PrintWriter(file + ".out");
		eat("");

		int tests = nextInt();
		for (int test = 0; test < tests; ++test) {
			solve(test);
		}

		out.close();
	}

	void eat(String s) {
		st = new StringTokenizer(s);
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new A().run();
	}

}
