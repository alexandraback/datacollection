import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Round 1C 2012
// Problem

public class ProblemA {

	public static final String file = "A-small";
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File(file + ".in"));
		PrintStream output = new PrintStream(new File(file + ".out"));
		
		int cases = sc.nextInt();
		
		for(int c = 0; c < cases; c++){
			int N = sc.nextInt();
			Node[] nodes = new Node[N];
			boolean diamond = false;
			
			for(int i = 0; i < N; i++)
				nodes[i] = new Node(i + 1);
			
			for(int i = 0; i < N; i++){
				int parents = sc.nextInt();
				Node currentNode = nodes[i];

				for(int p = 0; p < parents; p++){
					int parent = sc.nextInt();
					currentNode.parents.add(nodes[parent - 1]);
				}
			}
			
			for(int i = 0; i < N; i++){
				Node currentNode = nodes[i];
				for(Node parent : currentNode.parents){
					ArrayList<Node> allParents = currentNode.getParents();
					Set<Node> parentSet = new HashSet<Node>(allParents);
					if(parentSet.size() < allParents.size())
						diamond = true;
				}
			}

			System.out.printf("Case #%d: %s\n", c + 1, diamond ? "Yes" : "No");
			output.printf("Case #%d: %s\n", c + 1, diamond ? "Yes" : "No");
		}

	}
}

class Node{
	Set<Node> parents;
	int id;
	
	public Node(int id){
		parents = new HashSet<Node>();
		this.id = id;
	}
	
	public ArrayList<Node> getParents(){
		ArrayList<Node> allParents = new ArrayList<Node>();
		
		for(Node parent : parents){
			allParents.add(parent);
			for(Node p : parent.getParents())
				allParents.add(p);
		}
		
		return allParents;
	}
//	public boolean addChildren(Node p){
//		if(children.add(p)){
//			for(Node child : p.children)
//				if(!children.add(child))
//					return false;
//			return true;
//		}
//		return false;
//	}
	
	public String toString(){
		return id + "";
	}
}