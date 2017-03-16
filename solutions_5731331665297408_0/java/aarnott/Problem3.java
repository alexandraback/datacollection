import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class Problem3 {
	static int N;
	static int M;
	static Node[] nodes;
	static List<Node> visited;
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new FileReader("problem3.txt"));
		
		int tests = scanner.nextInt();
		for(int x = 1; x <= tests; x++) {
			//Get the constants
			N = scanner.nextInt();
			M = scanner.nextInt();
			
			nodes = new Node[N];
			for(int i = 0; i < N; i++) {
				int zip = scanner.nextInt();
				nodes[i] = new Node();
				nodes[i].zip = zip;		
				nodes[i].idx = i;
			}
			for(int i = 0; i < M; i++) {
				int a = scanner.nextInt() - 1;
				int b = scanner.nextInt() - 1;
				nodes[a].edges.add(b);
				nodes[b].edges.add(a);
			}
			
			//Sort the edges in order from smallest zip to largest
			for(int i = 0; i < N; i++) {				
				Collections.sort(nodes[i].edges, new Comparator<Integer>() {
					@Override
					public int compare(Integer a, Integer b) {
						if(nodes[a].zip < nodes[b].zip) return -1;
						if(nodes[a].zip > nodes[b].zip) return 1;
						return 0;
					}			
				});
			}
			
			System.out.printf("Case #%d: ", x);
			dfs();
			for(Node n : visited) {
				System.out.print(n.zip);	
			}
			System.out.println();
		}
		
		scanner.close();
		
		System.exit(0);
	}
	
	private static class Node {
		int idx;
		int zip;
		List<Integer> edges = new ArrayList<Integer>();
	
		public String toString() {
			return "#" + zip;
		}
		
	}
	
	/**
	 * Depth first search based on min zip value
	 * 
	 */
	private static void dfs() {
		List<Node> sortedNodes = new ArrayList<Node>();
		for(int i = 0; i < N; i++) {
			sortedNodes.add(nodes[i]);
		}
		Collections.sort(sortedNodes, new Comparator<Node>() {
			@Override
			public int compare(Node a, Node b) {
				if(a.zip < b.zip) return -1;
				if(a.zip > b.zip) return 1;
				return 0;
			}			
		});
		
		
		visited = new ArrayList<Node>();		
		visited.add(sortedNodes.get(0));	
		for(Integer e : sortedNodes.get(0).edges) {						
			recurse(e);
		}
		
		
		
		//System.out.println("No path found");
	}
	
	private static void recurse(int index) {		
		Node n = nodes[index];
		if(visited.contains(n)) return;
		
		visited.add(n);
		
		//System.out.println("** Recurse " + n.zip);
		
		List<Integer> remaining = new ArrayList<Integer>();
		for(int e : n.edges) {
			if(!visited.contains(nodes[e])) {
				remaining.add(e);
			}
		}		
		
		//Recursion
		for(Integer i : remaining) {
			recurse(i);		
		}

	}
	
	private static int getMinNeighborIndex(int u) {
		int min = Integer.MAX_VALUE;
		int idx = -1;
		for(int i : nodes[u].edges) {
			if(nodes[i].zip < min) {
				min = nodes[i].zip;
				idx = i;
			}
		}
		return idx;
	}

}
