package com.seol.codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class SolutionA{

	private static boolean solveCase(Map<Integer, Node> nodes) {
//		int res = 0;
		boolean res = false;
		for (Node n : nodes.values()) {
			if (n.numOfDirectChild == 0) {
				res = res || traverse(n, n);
			}
		}
		
		return res;
	}
	
	static boolean traverse(Node node, Node root) {
		if(node.childrens.contains(root)) {
			return true;
		}
		if(!node.equals(root)) {
			node.childrens.add(root);
		}
		
		boolean res = false;
		for(Node next : node.nextNodes) {
				res = res || traverse(next, root);
		}
		
		return res;
	}
	
	public static String IN = ".in";
	public static String OUT = ".out";
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
//		solveAllCases("F:/workspaces/google_codejam/test_data/solA2");
		solveAllCases("F:/workspaces/google_codejam/test_data/A-small-attempt1");
		 
	}

	public static void solveAllCases(String fileName) throws Exception {
		 out = new PrintStream(new File(fileName + OUT));
//		out = System.out;
		Scanner sc = new Scanner(new File(fileName + IN));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int N = sc.nextInt();
			
			Map<Integer, Node> nodes = new HashMap<Integer, SolutionA.Node>();
			
			for(int cN = 0; cN < N; cN++) {
				int num = cN+1;
				Node n = nodes.get(num);
				if(n == null) {
					n = new Node(num);
					nodes.put(n.num, n);
				}
				
				int parentsNum = sc.nextInt();
				for(int cP = 0; cP < parentsNum; cP++) {
					int par = sc.nextInt();
					Node parNode = nodes.get(par);
					if (parNode == null) {
						parNode = new Node(par);
						nodes.put(par, parNode);
					}
					n.nextNodes.add(parNode);
					parNode.numOfDirectChild=parNode.numOfDirectChild+1;
				}
			}
			
			boolean res = solveCase(nodes);

			out.println("Case #" + (i + 1) + ": " + (res ? "Yes": "No"));
		}
	}
	
	public static class Node {
		
		int num = 0;
		
		List<Node> nextNodes = new ArrayList<SolutionA.Node>();
		int numOfDirectChild = 0;
		Set<Node> childrens = new HashSet<SolutionA.Node>(); 
		
		public Node(int num) {
			this.num = num;
		}
		
		@Override
		public String toString() {
			return "Node [num=" + num + ", numOfDirectChild="
					+ numOfDirectChild + "]";
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + num;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Node other = (Node) obj;
			if (num != other.num)
				return false;
			return true;
		}
	}
}

