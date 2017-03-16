package round1c;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

class Graph {
	private Map<String, LinkedHashSet<String>> map = new HashMap();

	public void addEdge(String node1, String node2) {
		LinkedHashSet<String> adjacent = map.get(node1);
		if (adjacent == null) {
			adjacent = new LinkedHashSet();
			map.put(node1, adjacent);
		}
		adjacent.add(node2);
	}

	public void addTwoWayVertex(String node1, String node2) {
		addEdge(node1, node2);
		addEdge(node2, node1);
	}

	public boolean isConnected(String node1, String node2) {
		Set adjacent = map.get(node1);
		if (adjacent == null) {
			return false;
		}
		return adjacent.contains(node2);
	}

	public LinkedList<String> adjacentNodes(String last) {
		LinkedHashSet<String> adjacent = map.get(last);
		if (adjacent == null) {
			return new LinkedList();
		}
		return new LinkedList<String>(adjacent);
	}
}

public class ProblemA2 {
	private static void breadthFirst(Graph graph, LinkedList<String> visited,
			String end, LinkedList<String> paths) {
		LinkedList<String> nodes = graph.adjacentNodes(visited.getLast());
		// examine adjacent nodes
		for (String node : nodes) {
			if (visited.contains(node)) {
				continue;
			}
			if (node.equals(end)) {
				visited.add(node);
				printPath(visited, paths);
				visited.removeLast();
				break;
			}
		}
		// in breadth-first, recursion needs to come after visiting adjacent
		// nodes
		for (String node : nodes) {
			if (visited.contains(node) || node.equals(end)) {
				continue;
			}
			visited.addLast(node);
			breadthFirst(graph, visited, end, paths);
			visited.removeLast();
		}
	}

	private static void printPath(LinkedList<String> visited, LinkedList<String> paths) {
        String path = "";
		for (String node : visited) {
			path = path + node + " ";
          //  System.out.print(node);
           // System.out.print(" ");
        }
        //System.out.println();
        paths.add(path);
    }

	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int N = sc.nextInt();

			Graph graph = new Graph();

			for (int j = 1; j <= N; j++) {
				int classes = sc.nextInt();

				for (int k = 0; k < classes; k++) {
					int c = sc.nextInt();
					graph.addEdge("" + j, "" + c);
					
				}
			}
			
			/*graph.addEdge("A", "B");
	        graph.addEdge("A", "C");
	        graph.addEdge("B", "A");
	        graph.addEdge("B", "D");
	        graph.addEdge("B", "E"); // this is the only one-way connection
	        graph.addEdge("B", "F");
	        graph.addEdge("C", "A");
	        graph.addEdge("C", "E");
	        graph.addEdge("C", "F");
	        graph.addEdge("D", "B");
	        graph.addEdge("E", "C");
	        graph.addEdge("E", "F");
	        graph.addEdge("F", "B");
	        graph.addEdge("F", "C");
	        graph.addEdge("F", "E");
	        LinkedList<String> visited = new LinkedList();
	        LinkedList<String> paths = new LinkedList<String>();
	        visited.add("B");
	        breadthFirst(graph, visited, "E", paths);*/

			boolean found = false;

			outer: for (int j = 1; j <= N; j++) {
				for (int k = j + 1; k <= N; k++) {
					LinkedList<String> visited = new LinkedList<String>();
					LinkedList<String> paths = new LinkedList<String>();
					visited.add("" + j);
					breadthFirst(graph, visited, "" + k, paths);
					if (paths.size() > 1) {
						found = true;
						break outer;
					}
				}

			}

			System.out.println("Case #" + (i + 1) + ": "
					+ (found ? "Yes" : "No"));
		}
	}

}
