package gs.taral.gcj2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;
import java.util.Stack;

public class Diamond {
	public static void main(String[] args) throws NumberFormatException, IOException {
		List<Problem> input = readInput(args[0]);
		List<String> output = solve(input);
		writeOutput(args[1], output);
	}

	private static List<String> solve(List<Problem> input) {
		List<String> output = new ArrayList<String>();
		for (Problem line : input)
			output.add(solveCase(line));
		return output;
	}

	private static String solveCase(Problem problem) {
		List<Node> nodes = problem.nodes;
		for (int i = 0; i < nodes.size(); i++) {
			Node start = nodes.get(i);
			BitSet visited = new BitSet();
			Stack<Node> stack = new Stack<Node>();
			stack.push(start);
			while (!stack.isEmpty()) {
				Node node = stack.pop();
				for (Integer childId : node.children) {
					if (visited.get(childId))
						return "Yes";
					visited.set(childId);
					Node child = nodes.get(childId);
					stack.push(child);
				}
			}
		}
		return "No";
	}

	private static void writeOutput(String filename, List<String> output) throws IOException {
		PrintWriter out = new PrintWriter(new FileWriter(filename));
		for (int i = 0; i < output.size(); i++) {
			int caseNumber = i + 1;
			String line = output.get(i);
			out.println("Case #" + caseNumber + ": " + line);
		}
		out.close();
	}

	private static List<Problem> readInput(String filename) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(filename));
		List<Problem> input = new ArrayList<Problem>();
		int t = Integer.parseInt(in.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(in.readLine());
			List<Node> nodes = new ArrayList<Node>();
			for (int j = 0; j < n; j++) {
				String line = in.readLine();
				nodes.add(new Node(j, line));
			}
			input.add(new Problem(nodes));
		}
		if (input.size() != t)
			throw new IllegalArgumentException();
		return input;
	}

	static class Problem {
		public Problem(List<Node> nodes) {
			this.nodes = nodes;
		}

		List<Node> nodes;
	}

	static class Node {
		public Node(int n, String line) {
			String[] s = line.split(" ");
			int count = Integer.parseInt(s[0]);
			children = new ArrayList<Integer>();
			for (int i = 1; i < s.length; i++)
				children.add(Integer.parseInt(s[i]) - 1);
			if (children.size() != count)
				throw new IllegalArgumentException();
			id = n;
		}

		final int id;

		List<Integer> children;
	}
}
