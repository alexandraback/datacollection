import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Techno {

	private static int maxflow(Node source, Node target, int n) {//n: number of nodes
		//find distances
		source.d = n; 
		target.d = 0;
		Queue<Node> bfs = new LinkedList<Node>();
		bfs.add(target);
		while(!bfs.isEmpty()) {
			Node t = bfs.poll();
			for(Edge e: t.adj) {
				Node x = e.otherNode(t);
				if(e.b == t && x.d == Integer.MAX_VALUE) {
					x.d = t.d+1;
					bfs.add(x);
				}
			}
		}
		
		//initialize
		Queue<Node> active = new LinkedList<Node>();
		for(Edge e: source.adj) {
			if(e.a == source) {
				e.addFlow(e.c);
				active.add(e.otherNode(source));
			}
		}
		
		//loop
		while(!active.isEmpty()) {
			Node t = active.poll();

			//push
			for(Edge e: t.adj) {
				Node x = e.otherNode(t);
				
				if(t.d == x.d+1) {
					//starts at t
					if(e.a == t) {
						int v = Math.min(t.e, e.c - e.x);
						if(v > 0 && !active.contains(x) && x != source && x != target) {
							active.add(x);
						}
						e.addFlow(v);
					}
					//ends at t
					else {
						int v = Math.min(t.e, e.x);
						if(v > 0 && !active.contains(x) && x != source && x != target) {
							active.add(x);
						}
						e.addFlow(-v);
					}
				}
			}
			
			//relabel
			if(t.e > 0) {
				int newLabel = Integer.MAX_VALUE;
				for(Edge e: t.adj) {
					Node x = e.otherNode(t);
					
					//starts at t
					if(e.a == t) {
						if(e.x < e.c) {
							newLabel = Math.min(newLabel, x.d+1);
						}
					}
					//ends at t
					else {
						if(0 < e.x) {
							newLabel = Math.min(newLabel, x.d+1);
						}
					}
				}
				t.d = newLabel;
				active.add(t);
			}
		}

		return target.e;
	}
	
	static class Edge {
		int c;//capacity
		int x;//value
		Node a, b;//start, end

		public Edge(Node a, Node b, int c) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
			x = 0;
		}
		
		public void addFlow(int t) {
			x += t;
			a.e -= t;
			b.e += t;
		}

		public Node otherNode(Node x) {
			return x == a ? b : a;
		}
	}

	static class Node {
		int d;//distance label
		int e;//flow excess
		List<Edge> adj;//incident edges

		public Node() {
			super();
			adj = new LinkedList<Edge>();
			d = Integer.MAX_VALUE;
			e = 0;
		}
	}
	
	static class SS {
		String first;
		String second;
		public SS(String f, String s) {
			first = f;
			second = s;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		String filename = "C-small-attempt0";
		Scanner sc = new Scanner(new File(filename + ".in"));
		System.setOut(new PrintStream(new File(filename + ".out")));
//		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();

		for (int c = 1; c <= t; c++) {

			ArrayList<String> firsts = new ArrayList<>();
			ArrayList<String> seconds = new ArrayList<>();

			int words = sc.nextInt();
			
			ArrayList<SS> topics = new ArrayList<SS>();
			for (int i = 0; i < words; i++) {
				String first = sc.next();
				if (!firsts.contains(first)) {
					firsts.add(first);
				}
				String second = sc.next();
				if (!seconds.contains(second)) {
					seconds.add(second);
				}
				topics.add(new SS(first, second));
			}
			
			//create nodes
			Node s = new Node();
			Node e = new Node();
			Node[][] nodes = new Node[2][Math.max(firsts.size(), seconds.size())];
			for (int j = 0; j < nodes[0].length; j++) {
				for (int k = 0; k < 2; k++) {
					nodes[k][j] = new Node();
				}
			}
			
			//add edges from s/to t
			for (int j = 0; j < nodes[0].length; j++) {
				Edge e1 = new Edge(s, nodes[0][j], 1);
				s.adj.add(e1);
				nodes[0][j].adj.add(e1);

				Edge e2 = new Edge(nodes[1][j], e, 1);
				e.adj.add(e2);
				nodes[1][j].adj.add(e2);
			}
			
			for (SS ss : topics) {
				int from = firsts.indexOf(ss.first);
				int to = seconds.indexOf(ss.second);
				
				Edge et = new Edge(nodes[0][from], nodes[1][to], 1);
				nodes[0][from].adj.add(et);
				nodes[1][to].adj.add(et);
			}
			
			int matched = maxflow(s, e, 2+2*nodes[0].length);
			
			int reals = firsts.size() + seconds.size() - matched;
			int result = words - reals;
			
			System.out.println("Case #" + c + ": " + result);
		}
	}
}
