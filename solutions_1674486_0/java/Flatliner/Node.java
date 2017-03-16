package codejam.round2C.problemA;

import java.util.ArrayList;
import java.util.List;

public class Node {
	List<Node> inheritsFrom;
	int id;

	public Node(int id) {
		this.id = id;
		inheritsFrom = new ArrayList<Node>();
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + id;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Node other = (Node) obj;
		if (id != other.id)
			return false;
		return true;
	}

	public boolean hasTwoPathsInheritingFrom(Node other) {
		int count = 0;
		for (Node inherits : inheritsFrom) {
			if (inherits.equals(other)) {
				count++;
			} else {
				if (inherits.inheritsFrom(other)) {
					count++;
				}
			}
			if (count == 2) {
				return true;
			}
		}
		return false;
	}

	public boolean inheritsFrom(Node other) {
		if (this.inheritsFrom.contains(other)) {
			return true;
		}
		for (Node inherits : inheritsFrom) {
			if (inherits.inheritsFrom(other)) {
				return true;
			}
		}
		return false;
	}

}
