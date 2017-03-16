package codejam.round2C.problemA;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Graph {
	Map<Integer, Node> nodes;

	public Graph() {
		nodes = new HashMap<Integer, Node>();
	}

	public Node getNode(int id) {
		Node node = nodes.get((Integer) id);
		if (node == null) {
			node = new Node(id);
			nodes.put(id, node);
		}
		return node;
	}

	public List<Node> getAllNodes() {
		return new ArrayList<Node>(nodes.values());
	}

}
