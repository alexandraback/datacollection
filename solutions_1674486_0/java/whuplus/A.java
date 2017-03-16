package round1c;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class A {
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("in.txt"));
		out = new PrintStream(new File("out.txt"));

		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			solve();
			out.println();
		}
	}

	public static class Node {
		int number;
		List<Node> children;

		public Node(int i) {
			this.number = i;
			this.children = new ArrayList<Node>();
		}
		
		public String toString() {
			return (number + 1) + "";
		}
	}
	
	static void traverse(int[] counter, Node n) {
		counter[n.number]++;
		for (Node ch : n.children) {
			traverse(counter, ch);
		}
	}

	public static void solve() {
		int N;

		N = in.nextInt();

		List<Node> roots = new ArrayList<Node>();
		Map<Integer, Node> nodes = new HashMap<Integer, Node>();

		for (int i = 0; i < N; i++) {
			int M = in.nextInt();

			Node n = null;
			if (nodes.containsKey(i)) {
				n = nodes.get(i);
			} else {
				n = new Node(i);
				roots.add(n);
				nodes.put(i, n);
			}

			for (int j = 0; j < M; j++) {
				int x = in.nextInt() - 1;

				if (nodes.containsKey(x)) {
					n.children.add(nodes.get(x));
				} else {
					Node temp = new Node(x);
					n.children.add(temp);
					nodes.put(x, temp);
				}
			}
		}
		
		for (Node root : roots) {
			int[] counter = new int[N];
			traverse(counter, root);
			
			System.out.println(Arrays.toString(counter));
			
			for (int i = 0; i < N; i++) {
				if (counter[i] > 1) {
					out.print("Yes");
					return;
				}
			}
		} 
		out.print("No");
	}
}
