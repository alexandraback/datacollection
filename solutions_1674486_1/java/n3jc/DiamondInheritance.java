import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;


public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Path path = Paths.get(args[0]);
		Path file = Paths.get("inheritance.txt");
		int numberOfCases;
		try (Scanner scanner = new Scanner(Files.newInputStream(path), "UTF-8");
				OutputStreamWriter output = new OutputStreamWriter(Files.newOutputStream(file), "UTF-8")) {
			Formatter f = new Formatter(output);
			numberOfCases = scanner.nextInt();
			for (int i = 1; i <= numberOfCases; i++) {
				int numberOfNodes = scanner.nextInt();
				List<List<Integer>> connections = new LinkedList<>();
				for (int j = 1; j<= numberOfNodes; j++) {
					int up = scanner.nextInt();
					List<Integer> l = new LinkedList<>();
					for (int k = 0; k < up; k++) {
						l.add(scanner.nextInt());
					}
					connections.add(l);
				}
				boolean result = solve(connections);
				f.format("Case #%d: %s\n", i, result ? "Yes" : "No");
			}
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static boolean solve(List<List<Integer>> connections) {
		Map<Integer, Node> graph = new HashMap<>();
		List<Node> startingPoint = new LinkedList<>();
		for (int i = 0; i < connections.size(); i++) {
			int nodeID = i+1;
			if (!graph.containsKey(nodeID)) {
				Node node = new Node(nodeID);
				graph.put(nodeID, node);
				startingPoint.add(node);
			}
			Node n = graph.get(nodeID);
			for (Integer connection : connections.get(i)) {
				if (!graph.containsKey(connection)) {
					graph.put(connection, new Node(connection));
				}
				Node next = graph.get(connection);
				n.otherNodes.add(next);
				startingPoint.remove(next);
			}
		}
		
		for (Node p : startingPoint) {
			for (Node n : graph.values()) {
				n.visited = false;
			}
			
			Queue<Node> queue = new LinkedList<>();
			p.visited = true;
			queue.add(p);
			while (!queue.isEmpty()) {
				Node n = queue.poll();
				for (Node next : n.otherNodes) {
					if (next.visited) {
						return true;
					} else {
						next.visited = true;
						queue.add(next);
					}
				}
			}
		}
		
		return false;
	}
	
	private static class Node {
		int nodeID;
		List<Node> otherNodes;
		boolean visited;
		
		public Node(int nodeID) {
			this.nodeID = nodeID;
			this.otherNodes = new LinkedList<>();
		}
	}
}
