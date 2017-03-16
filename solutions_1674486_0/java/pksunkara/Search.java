import java.util.LinkedList;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;
import java.util.Scanner;

public class Search {

    public static void main(String[] args) throws Exception {
				Scanner scan = new Scanner(System.in);
    
    		int t = scan.nextInt();

				for (int i=0; i<t; i++) {
					boolean r = false;
					Graph g = new Graph();
					int n = scan.nextInt();
					for (int j=0; j<n; j++) {
						int m = scan.nextInt();
						for (int k=0; k<m; k++) {
							int l = scan.nextInt();
							g.addEdge(Integer.toString(j), Integer.toString(l-1));
						}
					}
					for (int j=0; j<n; j++) {
						for (int k=0; k<n; k++) {							
			        LinkedList<String> visited = new LinkedList();
			        visited.add(Integer.toString(j));
			        int paths = Search.breadthFirst(g, 0, visited, Integer.toString(k));
			        if (paths > 1) {
			        	r = true;
			        	break;
			        }
						}
					}
					System.out.println("Case #" + (i+1) + ": " + (r?"Yes":"No"));
				}
    }

    private static void printPath(LinkedList<String> visited) {
        for (String node : visited) {
            System.out.print(node);
            System.out.print(" ");
        }
        System.out.println();
    }

    public static int breadthFirst(Graph graph, int paths, LinkedList<String> visited, String end) {
        LinkedList<String> nodes = graph.adjacentNodes(visited.getLast());
        // examine adjacent nodes
        for (String node : nodes) {
            if (visited.contains(node)) {
                continue;
            }
            if (node.equals(end)) {
                visited.add(node);
                paths++;
                visited.removeLast();
                break;
            }
        }
        // in breadth-first, recursion needs to come after visiting adjacent nodes
        for (String node : nodes) {
            if (visited.contains(node) || node.equals(end)) {
                continue;
            }
            visited.addLast(node);
            paths = Search.breadthFirst(graph, paths, visited, end);
            visited.removeLast();
        }
        return paths;
    }
}
