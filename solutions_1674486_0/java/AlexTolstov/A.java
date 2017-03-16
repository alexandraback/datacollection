import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	static PrintWriter out;
	
	static final String problem = "A";
	static final String path = "C:/gcj/";
	
	
	static class Node {
		ArrayList <Node> next = new ArrayList<Main.Node>();
		int idx;
		int count = -1;
		boolean inh = false;
		
		Node(int idx) {
			this.idx = idx;
		}
		
		void add(Node x) {
			next.add(x);
			x.inh = true;
		}
		
		int getCount(int finish) {
			if (idx == finish) {
				return 1;
			}
			if (count != -1) {
				return count;
			}
			count = 0;
			
			for (Node n : next) {
				count += n.getCount(finish);
				if (count > 2) {
					count = 2;
				}
			}
			return count;
		}
	}
	
	void solveOne(int test) {
		out.print("Case #"+test+": ");
		
		int n = in.nextInt();
		Node nodes[] = new Node[n];
		for (int i = 0; i < nodes.length; i++) {
			nodes[i] = new Node(i + 1);
		}
		for (int i = 0; i < n; i++) {
			int count = in.nextInt();
			for (int j = 0; j < count; j++) {
				int idx = in.nextInt() - 1;
				nodes[i].add(nodes[idx]);
			}
		}
		
		ArrayList <Integer> starts = new ArrayList<Integer>();
		ArrayList <Integer> ends = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			if (!nodes[i].inh) {
				starts.add(i);
			} else if (nodes[i].next.size() == 0) {
				ends.add(i);
			}
		}
		
		for (int i = 0; i < ends.size(); i++) {
			int finish = ends.get(i) + 1;
			
			for (Node nn : nodes) {
				nn.count = -1;
			}
			
			for (int j = 0; j < starts.size(); j++) {
				int start = starts.get(j);
				
				int cnt = nodes[start].getCount(finish);
				if (cnt >= 2) {
					out.print("Yes");
					return;
				}
			}
		}
		
		out.print("No");
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			solveOne(i);
			out.println();
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}