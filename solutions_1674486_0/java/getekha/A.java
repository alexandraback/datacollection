package a;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {
	
	static class Node{
		int id;
		
		Set<A.Node> parents = new HashSet<A.Node>();
		Set<A.Node> directParents = new HashSet<A.Node>();
		
		ArrayList<Integer> children = new ArrayList<Integer>();
		
		public Node(int id, int size, List<Integer>childs){
			this.id = id;
			children.addAll(childs);
			parents.add(this);
		}
		
		public void tellChildren(){
			for (Integer child: children){
				Node node = nodes[child];
				node.directParents.add(this);
			}
		}
		
		public boolean addParent(Node n){
			if (parents.contains(n.parents)){
//				System.out.println(parents + " " + n.parents);
				return false;
			} else {
				parents.addAll(n.parents);
				return true;
			}
		}
		
		@Override
		public String toString() {
			return id+ " ";
		}
		
	}

	private static Node[] nodes;
	private static boolean done = false;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();

		int nbr = 1;
		
		LinkedList<Node> workQue = new LinkedList<A.Node>();
		
		while (t-- > 0) {
			int n = sc.nextInt();
			nodes =  new Node[n];
			for (int i = 0; i < n; i++) {
				int m = sc.nextInt();
				List<Integer> list =  new LinkedList<Integer>();
				for (int j = 0; j < m; j++) {
					list.add(sc.nextInt() - 1);
				}
				nodes[i] = new Node(i, n, list);
				workQue.add(nodes[i]);
			}
			
			for (int i = 0; i < nodes.length; i++) {
				nodes[i].tellChildren();
			}

			while (!workQue.isEmpty()){
				Node node = workQue.poll();
				for (Integer i: node.children){
					if (nodes[i].addParent(node)){
						workQue.add(nodes[i]);
					}
				}
				if (done){
					break;
				}
				
			}
			
			
			boolean path = false;
			for (Node node:nodes){
//				System.out.println(node.id + " " + node.parents + " " + node.children);
				for (Node parent: node.directParents){
					for (Node parent2: node.directParents){
						if (parent.id == parent2.id){
							continue;
						}
						Set<Node> intersection = new HashSet<Node>(parent.parents);
						intersection.retainAll(parent2.parents);
						if (!intersection.isEmpty()){
							path = true;
							break;
						}
					}
					if (path){
						break;
					}
				}
				if (path){
					break;
				}
			}
			System.out.printf("Case #%d: %s\n", nbr++, path ? "Yes" : "No");
		}
	}
}
