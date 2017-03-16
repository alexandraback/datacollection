package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

public class B {

	static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new PrintWriter(new FileWriter("out"));
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			System.out.println(tc);
			int D = reader.nextInt();
			int sum = 0;
			ArrayList<Integer> P = new ArrayList<Integer>();
			for(int i = 0; i < D; i++) {
				P.add(reader.nextInt());
				sum += P.get(i);
			}
			memo = new SequenceSet(sum + 1);
			int min = brute(P);
			writer.printf("Case #%d: %d\n", tc, min);
		}
		writer.close();
		reader.close();
	}

	static SequenceSet memo;

	static int brute(ArrayList<Integer> P) {
		if(P.size() == 0) {
			return 0;
		}

		if(memo.contains(P)) {
			return memo.getValue(P);
		}

		ArrayList<Integer> wait = new ArrayList<>();
		for(int x : P) {
			if(x > 1) {
				wait.add(x - 1);
			}
		}
		Collections.sort(wait);
		int min = brute(wait);

		for(int i = 0; i < P.size(); i++) {
			if(P.get(i) > 1) {
				for(int s = 1; s < P.get(i); s++) {
					ArrayList<Integer> split = new ArrayList<>();
					for(int j = 0; j < P.size(); j++) {
						if(i != j) split.add(P.get(j));
					}
					split.add(s);
					split.add(P.get(i) - s);
					Collections.sort(split);
					int t = brute(split);
					min = Math.min(min, t);
				}
			}
		}

		memo.add(P, 1 + min);
		return 1 + min;
	}

	static class SequenceSet {

		public int V;
		public Node root;

		public SequenceSet(int V) {
			this.V = V;
			root = new Node();
		}

		public void add(ArrayList<Integer> path, int value) {
			Node cur = root;
			for(int i = 0; i < path.size(); i++) {
				int v = path.get(i);
				if(cur.hasChild(v)) {
					cur = cur.getChild(v);
				} else {
					cur = cur.addChild(v);
				}
			}
			cur.setTerminal(true);
			cur.value = value;
		}

		public boolean contains(ArrayList<Integer> path) {
			Node cur = root;
			for(int i = 0; i < path.size(); i++) {
				int v = path.get(i);
				if(!cur.hasChild(v)) {
					return false;
				}
				cur = cur.getChild(v);
			}
			return cur.isTerminal;
		}

		public int getValue(ArrayList<Integer> path) {
			Node cur = root;
			for(int i = 0; i < path.size(); i++) {
				int v = path.get(i);
				cur = cur.getChild(v);
			}
			return cur.value;
		}

		private class Node {
			Node[] children;
			boolean isTerminal;
			int value;
			public Node() {
				children = new Node[V];
				isTerminal = false;
			}
			public void setTerminal(boolean isTerminal) {
				this.isTerminal = isTerminal;
			}
			public Node addChild(int v) {
				children[v] = new Node();
				return children[v];
			}
			public boolean hasChild(int v) {
				return children[v] != null;
			}
			public Node getChild(int v) {
				return children[v];
			}
			public String toString() {
				StringBuilder sb = new StringBuilder();
				for(int v = 0; v < V; v++) {
					if(hasChild(v)) {
						sb.append(v + " ");
					}
				}
				return sb.toString();
			}
		}
	}
}
