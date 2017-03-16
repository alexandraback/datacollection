import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.StringTokenizer;

public class A implements Runnable {

	final static String file = "C-small-attempt0";
	boolean local = true;

	class Node {
		public Set<Long> set = new HashSet<Long>();
		public long sum = 0;

		public Node() {
			// TODO Auto-generated constructor stub
		}

		public Node(Node a, Node b) {
			set.addAll(a.set);
			set.addAll(b.set);
			sum += a.sum;
			sum += b.sum;
		}

		@Override
		public boolean equals(Object obj) {
			Node node = (Node) obj;
			return set.equals(node.set);
		}

		@Override
		public int hashCode() {
			return set.hashCode();
		}

		@Override
		public String toString() {
			return "Node [set=" + set + ", sum=" + sum + "]";
		}

	}

	public void solve(int test) throws IOException {
		out.print("Case #" + (test + 1) + ": ");
		// ****************************************************************************************************
		int numberofcase = nextInt();
		Set<Node> nodes = new HashSet<A.Node>();
		for (int i = 0; i < numberofcase; i++) {
			Node a = new Node();
			Set<Long> h = new HashSet<Long>();
			long l = nextLong();
			h.add(l);
			a.set = h;
			a.sum = l;
			nodes.add(a);
		}
		Node ans1 = null;
		Node ans2 = null;
		boolean ansFound = false;
		while (true) {
			// check for sums
			for (Node outer : nodes) {
				for (Node inner : nodes) {
					if (inner.equals(outer))
						continue;
					if (outer.sum == inner.sum) {
						ans1 = outer;
						ans2 = inner;
						ansFound = true;
						break;
					}
				}
				if (ansFound) {
					break;
				}
			}
			if (ansFound) {
				break;
			}
			int oldNodesSize = nodes.size();
			Set<Node> newNodes = new HashSet<A.Node>();
			for (Node outer : nodes) {
				for (Node inner : nodes) {
					if (inner.equals(outer))
						continue;
					newNodes.add(new Node(inner, outer));
				}
			}
			
			nodes.addAll(newNodes);
			if(oldNodesSize == nodes.size())
				break;
		}
		// ****************************************************************************************************
		if (!ansFound || ans1.set.size() == 0 || ans2.set.size() == 0) {
			out.println("Impossible");
			return;
		}
		out.println("");
		String ans1Str = "";
		for (Long node : ans1.set) {
			ans1Str = ans1Str.concat(node + " ");
		}
		ans1Str = ans1Str.trim();
		String ans2Str = "";
		for (Long node : ans2.set)
			ans2Str = ans2Str.concat(node + " ");

		ans2Str = ans2Str.trim();
		out.println(ans1Str);
		out.println(ans2Str);
	}

	private long add(Set<Long> temp) {
		long retval = 0L;
		for (Long integer : temp) {
			retval += integer;
		}
		return retval;
	}

	public void run() {
		try {
			String inFile = file + ".in";
			String outFile = file + ".out";
			if (local) {
				in = new BufferedReader(new FileReader(
						"C:\\Vinay\\gcj\\1B\\src\\" + inFile));
				out = new PrintWriter("C:\\Vinay\\gcj\\1B\\src\\" + outFile);
			} else {
				in = new BufferedReader(new FileReader(inFile));
				out = new PrintWriter(outFile);
			}
			eat("");
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test);
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
	}

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

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

	static boolean failed = false;

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new A());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
}