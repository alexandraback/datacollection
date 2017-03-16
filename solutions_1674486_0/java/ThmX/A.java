/*
 * Google Code Jam 2012 - Round 1B (05.05.2012)
 * Thomas "ThmX" Denoréaz - thmx.2k7@gmail.com
 */

package codejam._2012.roundC;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class A {

	static final String FILENAME = "roundC/A-small";
	
	public static class Node {
		
		static Set<Node> connected = new HashSet<Node>();
		
		Set<Node> prec = new HashSet<Node>();
		
		int name = 0;
		
		public Node(int name) {
			this.name = name;
		}
		
		public void add(Node node) {
			if (node != null) {
				prec.add(node);				
			}
		}
		
		public static void clear() {
			connected = new HashSet<Node>();
		}
		
		public int connect(Node node) {
			
			connected.add(node);
			if (node.equals(this)) return 0;
			
			int count = 0;
			for (Node n : prec) {
				if (n.equals(node)) {
					++count;
				}
				
				if (!connected.contains(n)) {
					count += n.connect(node);
				}
			}
			
			return count;
		}

		@Override
		public int hashCode() {
			return this.name;
		}

		@Override
		public boolean equals(Object obj) {
			try {
				Node n = (Node) obj;
				return n.name == this.name;
			} catch (ClassCastException e) {
				return false;
			}
		}
		
		@Override
		public String toString() {
			return "" + name;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException, CloneNotSupportedException {
		
		BufferedReader reader = new BufferedReader(new FileReader(FILENAME + ".in"));
		PrintWriter writer = new PrintWriter(FILENAME + ".out");
		
		int T = Integer.valueOf(reader.readLine());
		for (int t=1; t<=T; t++) {
			
			int N = Integer.valueOf(reader.readLine());			

			Node[] nodes = new Node[N];
			
			for (int i = 0; i < N; i++) {
				nodes[i] = new Node(i);
			}
				
			for (int i = 0; i < N; i++) {
				Node node = nodes[i];

				String[] nums = reader.readLine().split(" ");
				for (int j = 1; j <= Integer.valueOf(nums[0]); j++) {
					int n_num = Integer.valueOf(nums[j]);
					node.add(nodes[n_num-1]);
				}
			}
			
			boolean stop = false;
			
			for (Node n: nodes) {
				if (stop) break;
				
				for (Node n2: nodes) {
					if (n.equals(n2)) continue;
					
					Node.clear();
					stop = n.connect(n2) > 1;
					
					if (stop) break;
				}
			}
			
			
			String answer = "Case #" + t + ": ";
			if (stop) {
				answer += "Yes";
			} else {
				answer += "No";
			}
			
			System.out.println(answer);
			writer.println(answer);
		}
		
		writer.flush();
		writer.close();
		reader.close();
	}
}
