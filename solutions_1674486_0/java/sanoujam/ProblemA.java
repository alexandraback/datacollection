package mar2012.round1c;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws Exception {
		PrintStream out = new PrintStream(new File(
				"/Users/asingh/Desktop/gcj2012/round1c/prob.a.out.txt"));
		ProblemA prob = new ProblemA();
		String input = "/Users/asingh/Desktop/gcj2012/round1c/prob.a.in.txt";
		InputStream in = new FileInputStream(new File(input));
		prob.solveAll(in, out);
	}

	private void solveAll(InputStream in, PrintStream out) {
		Scanner scanner = new Scanner(in);
		int numTestCases = Integer.parseInt(scanner.nextLine());

		for (int testCase = 1; testCase <= numTestCases; testCase++) {
			int numNodes = scanner.nextInt();
			Node[] nodesArr = new Node[numNodes];
			for (int index = 1; index <= numNodes; index++) {
				nodesArr[index - 1] = new Node(index);
			}
			Nodes nodes = new Nodes(nodesArr);

			for (int index = 1; index <= numNodes; index++) {
				Node node = nodes.get(index);
				int numParents = scanner.nextInt();
				for (int k = 0; k < numParents; k++) {
					int parentId = scanner.nextInt();
					node.addParent(nodes.get(parentId));
				}
				if (testCase < numTestCases) {
					scanner.nextLine();
				}
			}
			solveTestCase(testCase, nodes, out, numNodes);
		}
	}

	private void solveTestCase(int testCase, Nodes nodes, PrintStream out,
			int numNodes) {
		boolean diamondExists = false;
		for (Node node : nodes.nodes) {
			diamondExists = doDfs(node, numNodes);
			if (diamondExists) {
				break;
			}
		}
		out.println("Case #" + testCase + ": " + (diamondExists ? "Yes" : "No"));
	}

	private boolean doDfs(Node root, int numNodes) {
		LinkedList<Node> stack = new LinkedList<ProblemA.Node>();
		boolean[] visited = new boolean[numNodes + 1];
		stack.addFirst(root);
		while (!stack.isEmpty()) {
			Node node = stack.removeFirst();
			for (Node p : node.parents) {
				if (visited[p.id]) {
					return true;
				} else {
					visited[p.id] = true;
					stack.addFirst(p);
				}
			}
		}
		return false;
	}

	public static void debug(String msg) {
		System.out.println(msg);
	}

	private static class Nodes {

		private final Node[] nodes;
		private final int numNodes;

		public Nodes(Node[] nodes) {
			this.nodes = nodes;
			this.numNodes = nodes.length;
		}

		/**
		 * 1-based index
		 */
		public Node get(int index) {
			return nodes[index - 1];
		}

		@Override
		public String toString() {
			return "Nodes [numNodes=" + numNodes + ", nodes="
					+ Arrays.toString(nodes) + "]";
		}

	}

	private static class Node {
		private final int id;
		private final LinkedList<Node> parents = new LinkedList<Node>();

		public Node(int id) {
			this.id = id;
		}

		public void addParent(Node p) {
			this.parents.add(p);
		}

		@Override
		public String toString() {
			return "Node [id=" + id + ", parents=" + parents + "]";
		}

	}
}
