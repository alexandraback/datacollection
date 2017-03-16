package code.jam.round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class DiamondInheritance {

	protected static final String RESULT_FILE = "result.out";

	public static void main(String[] args) throws IOException {
		new DiamondInheritance().run();
	}

	private void run() throws IOException {
		final Scanner in = new Scanner(System.in);
		final int testCases = in.nextInt();
		final File result = new File(RESULT_FILE);

		if (!result.exists())
			result.createNewFile();
		try (FileOutputStream stream = new FileOutputStream(result, false)) {
			try (BufferedWriter writer = new BufferedWriter(
					new OutputStreamWriter(stream))) {
				for (int i = 0; i < testCases;) {
					String res = "Case #" + ++i + ": " + testCase(in) + '\n';
					writer.write(res);
					System.out.println(res);
				}
				writer.flush();
			}
			stream.flush();
		} catch (IOException e) {
			throw new IOException(e);
		}
	}

	private String testCase(Scanner in) {
		int N = in.nextInt();
		final List<Node> nodes = new ArrayList<>();
		for (int i = 0; i < N; ++i) {
			int n = in.nextInt();
			final Node tmp = new Node(n);
			tmp.classId = i + 1;
			for (int j = 0; j < n; ++j) {
				tmp.inherits[j] = in.nextInt();
			}
			nodes.add(tmp);
		}
		return result(nodes) ? "Yes" : "No";
	}

	private boolean result(List<Node> nodes) {
		Set<Integer> set;
		for (Node node : nodes) {
			set = new HashSet<>();
			if (searchTillEnd(set, node, nodes)) {
				return true;
			}
		}
		return false;
	}

	private boolean searchTillEnd(Set<Integer> parents, Node node, List<Node> nodes) {
		boolean result = false;
		for (int parent : node.inherits) {
			if (parents.contains(parent)) {
				return true;
			} else {
				parents.add(parent);
				result = result || searchTillEnd(parents, nodes.get(parent - 1), nodes);
			}
		}
		return result;
	}

	/* Helper classes */
	private class Node {

		public int[] inherits;
		public int classId;
		
		public Node(int n) {
			inherits = new int[n];
		}
	}
}
