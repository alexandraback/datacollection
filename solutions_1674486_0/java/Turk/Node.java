import java.util.LinkedList;



public class Node {
	Node from;
	LinkedList<Node> inherit;
	
	Node() {
		inherit = new LinkedList<Node>();
		from = null;
	}
}
