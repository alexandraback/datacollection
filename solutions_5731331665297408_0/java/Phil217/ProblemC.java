package Round1B;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

public class ProblemC {

	static BufferedWriter out;
	static String sol;
	
	static class Node implements Comparable<Node> {
		int zip;
		int id;
		boolean visited = false;
		int reachable = 0;
		HashSet<Node> neighbours = new HashSet<>();;
		
		@Override
		public int compareTo(Node o) {
			return zip - o.zip;
		}
		
		@Override
		public String toString() {
			return id + "-" + zip;
		}
	}

	public static void solve(Scanner sc) throws IOException {
		int N = sc.nextInt();
		int M = sc.nextInt();
		Node[] nodes = new Node[N];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = new Node();
			nodes[i].id = i;
			nodes[i].zip = sc.nextInt();
		}
		for (int i = 0; i < M; i++) {
			int start = sc.nextInt() - 1;
			int end = sc.nextInt() - 1;
			nodes[start].neighbours.add(nodes[end]);
			nodes[end].neighbours.add(nodes[start]);
		}
		Arrays.sort(nodes);
		Node start = nodes[0];
		start.visited = true;
		for(Node n : start.neighbours) {
			n.reachable = 1;
		}
		
		sol = "";
		Stack<Node> stack = new Stack<>();
		stack.push(start);
		backtrack(start, nodes, stack);
		sol = start.zip + sol;
		System.out.println(sol);
		out.write(sol + "\n");
	}

	
	public static boolean backtrack(Node start, Node[] nodes, Stack<Node> dfsStack) {
		PriorityQueue<Node> avail = new PriorityQueue<>();
		int done = 0;
		for (Node n : nodes) {
			if (n.visited == true) {
				done++;
			}
			if (n.reachable > 0) {
				avail.add(n);
			}
		}
		if (done == nodes.length) {
			return true;
		}
		while (!avail.isEmpty()) {
			Node n = avail.poll();
			// go back until you can reach n
			Stack<Node> temp = new Stack<>();
			while (!dfsStack.peek().neighbours.contains(n)) {
				Node node = dfsStack.pop();
				for (Node nei : node.neighbours) {
					if (!nei.visited) {
						nei.reachable--;
					}
				}
				temp.push(node);
			}
			// do stuff with n
			n.visited = true;
			int tmp = n.reachable;
			n.reachable = 0;
			for (Node nei : n.neighbours) {
				if (!nei.visited) {
					nei.reachable++;
				}
			}
			dfsStack.push(n);
			if (backtrack(n, nodes, dfsStack)) {
				sol = n.zip + sol;
				return true;
			}
			dfsStack.pop();
			for (Node nei : n.neighbours) {
				if (!nei.visited) {
					nei.reachable--;
				}
			}
			n.reachable = tmp;
			n.visited = false;
			// go forward again
			while (!temp.isEmpty()) {
				Node node = temp.pop();
				for (Node nei : node.neighbours) {
					if (!nei.visited) {
						nei.reachable++;
					}
				}
				dfsStack.push(node);
			}
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
//		String name = "C-practice";
		String name = "C-small-attempt1";
//		String name = "C-large";
		Scanner sc = new Scanner(new File(name + ".in")); 
		sc.useLocale(Locale.US);
		 
		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);
		
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
		out.close();
	}
}
