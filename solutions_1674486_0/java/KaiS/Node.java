package me.stapel.kai.google.codejam2012.round1c.A;

import java.util.HashSet;
import java.util.Set;

public class Node implements Comparable {

	public int name;
	
	public Set<Node> edges;
	
	public Node(int i) {
		name = i;
		edges = new HashSet<Node>();
	}

	@Override
	public boolean equals(Object obj) {
		if(obj instanceof Node) {
			Node n = (Node)obj;
			return this.name == n.name;
		}
		
		return false;
	}

	@Override
	public String toString() {
		String ret = name + " -> (";
		
		for (Node n : edges) {
			ret += n.name + ", ";
		}
		
		ret += ")";
		
		return ret;
	}

	@Override
	public int compareTo(Object o) {
		if(this.name > ((Node)o).name)
			return 1;
		else if(this.name < ((Node)o).name)
			return -1;
		return 0;
	}
	
	
}
