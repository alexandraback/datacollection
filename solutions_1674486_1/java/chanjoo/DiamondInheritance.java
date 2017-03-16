package codejam;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class DiamondInheritance extends Solver {

	public static void main(String...args) {
		DiamondInheritance solver = new DiamondInheritance();
//		solver.solveSample();
//		solver.solveSmall(0);
		solver.solveLarge();
	}
	
	public DiamondInheritance() {
		super('A');
	}
	
	int count = 0;
	
	@Override
	public void read(Scanner in) {
		map = new HashMap<Integer, Node>();
		count = in.nextInt();
		for(int i=0; i<count; i++) {
			Node node = node(i+1);
			int nn = in.nextInt();
			for(int n = 0; n<nn; n++) {
				Node nd = node(in.nextInt());
				node.from.add(nd);
			}
//			System.out.println(node);
		}
	}
	
	@Override
	public String evaluate() {
		for(int i=1; i<=count; i++) {
			Node node = node(i);
			node.family();
			
			if(node.from.size()<2) continue;
			
			List<Set<Node>> path = new ArrayList<Set<Node>>();
			for(Node f: node.from) {
				path.add(f.family());
			}
			
			int size = path.size();
			for(int j=0; j<size-1; j++) {
				Set<Node> pathj = path.get(j);
				for(int k=j+1; k<size; k++) {
					Set<Node> pathk = path.get(k);
					for(Node nodek: pathk) {
						if(pathj.contains(nodek)) return "Yes";
					}
				}
			}
		}
		return "No";
	}
	
	private Node node(int id) {
		Node node = map.get(id);
		if(node==null) {
			node = new Node(id);
			map.put(id, node);
		}
		return node;
	}
	
	Map<Integer, Node> map;
	class Node {
		int id;
		List<Node> from;
		Set<Node> family;
		
		public Node(int id) {
			this.id = id;
			this.from = new ArrayList<Node>();
		}
		
		public Set<Node> family() {
			if(family==null) {
				family = new HashSet<Node>();
				family.add(this);
				for(Node child: from) {
					family.addAll(child.family());
				}
			}
			return family;
		}
		
		public String toString() {
			StringBuilder buf = new StringBuilder("Node#");
			buf.append(id).append(":");
			for(Node f: from) {
				buf.append('<').append(f.id);
			}
			return buf.toString();
		}
	}
}
