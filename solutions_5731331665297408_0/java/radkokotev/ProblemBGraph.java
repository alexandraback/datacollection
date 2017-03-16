import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class ProblemBGraph {
	
	String min;
	ArrayList<Node> nodes;
	ArrayList<String> codes;
	
	class Node {
		public int id;
		public AdjList adjlist;
		public Node(int id) {
			this.id = id;
			adjlist = new AdjList();
		}
	}
	class AdjList {
		public ArrayList<Integer> list;
		public AdjList () {
			this.list = new ArrayList<Integer>();
		}
	}
	
	
	
	
	
	public void solve(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(System.in);
		String filename = sc.nextLine();
		sc.close();
		
		PrintWriter pw = 
				//new PrintWriter(System.out);
				new PrintWriter(new File(filename + ".out"));
		Scanner scanner = new Scanner(new File(filename));
		int testCases = Integer.parseInt(scanner.nextLine());
		for(int currTest=1; currTest<=testCases; currTest++){
			String[] nm = scanner.nextLine().split(" ");
			int n = Integer.parseInt(nm[0]);
			int m = Integer.parseInt(nm[1]);
			nodes = new ArrayList<ProblemBGraph.Node>(n);
			codes = new ArrayList<String>(n);
			for (int i = 0; i < n; i++) {
				codes.add(scanner.nextLine());
				nodes.add(new Node(i));
			}
			System.out.println(Arrays.toString(codes.toArray()));
			for (int i = 0; i < m; i++) {
				String[] route = scanner.nextLine().split(" ");
				int one = Integer.parseInt(route[0]) - 1;
				int two = Integer.parseInt(route[1]) - 1;
				Node node1 = nodes.get(one);
				Node node2 = nodes.get(two);
				node1.adjlist.list.add(two);
				node2.adjlist.list.add(one);
			}
			ArrayList<Integer> lst = new ArrayList<Integer>(n);
			for (int i = 0; i < n; i++) {
				lst.add(i);
			}
			traverse(lst, new ArrayList<Integer>(), "", new HashSet<Integer>());
			
			
			pw.println(String.format("Case #%d: %s", currTest, min));
			min = null;
			
		}
		scanner.close();
		pw.close();
	}
	
	public void traverse(List<Integer> list, List<Integer> prev, String s, Set<Integer> visited) {
		if (s.length() == 5 * nodes.size()) {
			if (min == null) {
				min = s;
				return;
			}
			if (s.compareTo(min) < 0) {
				min = s;
				return;
			}
			return;
		}
		for (Integer num : list) {
			if (visited.contains(num)) {
				continue;
			}
			Node n = nodes.get(num);
			List<Integer> l1 = new ArrayList<Integer>(n.adjlist.list);
			//l.addAll(list);
			visited.add(n.id);
			
			List<Integer> l2 = new ArrayList<Integer>(prev);
			l2.addAll(n.adjlist.list);
			traverse(l1, l2, s + codes.get(n.id), visited);
			visited.remove(n.id);
		}
		
		for (Integer num : prev) {
			if (visited.contains(num)) {
				continue;
			}
			Node n = nodes.get(num);
			List<Integer> l1 = new ArrayList<Integer>(n.adjlist.list);

			visited.add(n.id);
			
			List<Integer> l2 = new ArrayList<Integer>();
			traverse(l1, l2, s + codes.get(n.id), visited);
			visited.remove(n.id);
		}
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		ProblemBGraph pbg = new ProblemBGraph();
		pbg.solve(args);
	}
	

}
