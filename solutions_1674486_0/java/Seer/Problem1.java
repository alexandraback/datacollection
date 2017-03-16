package com.google.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Problem1 {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		new Problem1().run();
	}

	private void run() throws FileNotFoundException {
		Problem[] data = parseInput("input-problem1");
		Boolean[] result = solve(data);
		printResult(result, "output-problem1");
	}
	
	private Boolean[] solve(Problem[] data) {
		Boolean[] result = new Boolean[data.length];
		for (int i = 0; i < data.length; i++)
		{
			System.out.println(data[i]);
			result[i] = data[i].hasDiamond();
		}
		return result;
	}
	
	private static class Node {
		Set<Node> inheritsFrom = new HashSet<Node>();
		Integer value;
		public Node(Integer value) {
			this.value = value;
		} 
	}
	
	private static class Problem {
		Map<Integer,List<Integer>> map = new HashMap<Integer, List<Integer>>();
		Map<Integer, Node> nodes = new HashMap<Integer, Node>();
		
		@Override
		public String toString() {
			return "Problem [map=" + map + "]";
		}
		
		private Set<Integer> visited;

		public Boolean hasDiamond() {
			for (Node node : nodes.values()) {
				visited = new HashSet<Integer>();
				if (dfs(node)) {
					return true;
				}
			}
			return false;
		}

		private Boolean dfs(Node node) {
			if (visited.contains(node.value)) {
				return true;
			}
			visited.add(node.value);
			for (Node inheritsFrom : node.inheritsFrom) {
				if (dfs(inheritsFrom)) {
					return true;
				}
			}
			return false;
		}

		public void parse(Scanner scanner) {
			int classes = scanner.nextInt();
			init(classes);
			
			for (int i = 1; i <= classes; i++) {
				int inheritsFromNo = scanner.nextInt();
				for (int j = 0; j < inheritsFromNo; j++) {
					Integer inheritsFrom = scanner.nextInt();
					map.get(inheritsFrom).add(i);
					nodes.get(i).inheritsFrom.add(nodes.get(inheritsFrom));
				}
			}
		}

		private void init(int classes) {
			for (int i = 1; i <= classes; i++ ) {
				map.put(i, new ArrayList<Integer>());
				nodes.put(i, new Node(i));
			}
		}
	}

	private Problem[] parseInput(String path) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(path));
		try {
			Problem[] input = new Problem[scanner.nextInt()];
			scanner.nextLine(); // skip to the next line
			
			for (int i = 0; i < input.length; i++) {
				input[i] = new Problem();
				input[i].parse(scanner);
			}
			return input;
		} finally {
			scanner.close();
		}
	}

	private void printResult(Boolean[] result, String path) throws FileNotFoundException {
		PrintWriter p = new PrintWriter(new File(path));
		try { 
			for (int i = 1; i < result.length+1; i++) {
				p.format("Case #%d: %s\n", i, result[i-1]?"Yes":"No");
			}
		} finally {
			p.close();
		}
	}
}
