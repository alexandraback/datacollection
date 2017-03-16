package round1c;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class A {
	public static void main(String args[]) {
		new A();
	}

	boolean b;

	public A() {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int x=1; x<=T; x++) {

			// read data
			int N = scan.nextInt();
			Node[] nodes = new Node[N];
			for(int i=0; i<N; i++) {
				nodes[i] = new Node();
				int M = scan.nextInt();
				for(int j=0; j<M; j++) {
					int f = scan.nextInt();
					nodes[i].add(f-1);
				}
			}

			b = false;
			solve(nodes);
			System.out.printf("Case #%d: ", x);
			System.out.println(b ? "Yes" : "No");
		}
	}

	public void solve(Node[] nodes) {
		int n = nodes.length;

		for(int i=0; i<n; i++) {
			if(b) return;

			int s = nodes[i].size();
			if(s < 2) continue;

			Set<Integer> set = new TreeSet<Integer>();
			for(int k=0; k<s; k++) {
				int p = nodes[i].get(k);
				search(p, nodes, set);
			}
		}
	}

	public void search(int p, Node[] nodes, Set<Integer> set) {
		if(set.contains(p)) {
			b = true;
			return;
		}

		if(b) return;

		set.add(p);

		int n = nodes[p].size();
		for(int i=0; i<n; i++) {
			int q = nodes[p].get(i);
			search(q, nodes, set);
		}
	}

	public static class Node {
		private List<Integer> list;

		public Node() {
			list = new ArrayList<Integer>();
		}

		public void add(int from) {
			list.add(from);
		}

		public int size() {
			return list.size();
		}

		public int get(int i) {
			return list.get(i);
		}
	}
}
