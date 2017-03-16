import java.util.*;

public class A{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int nCases = sc.nextInt();
		for(int caseN = 1; caseN <= nCases; caseN++){
			int numClasses = sc.nextInt();
			//LinkedList<Node> classes = new LinkedList<Node>();
			Node[] classes = new Node[numClasses];
			for(int i = 0; i < numClasses; i++){
				classes[i] = new Node();
			}
			for(int i = 0; i < numClasses; i++){
				int numInherited = sc.nextInt();
				for(int j = 0; j < numInherited; j++){
					int num = sc.nextInt() - 1;
					classes[i].out.add(classes[num]);
					classes[num].in.add(classes[i]);
				}
			}
			LinkedList<Node> sources = new LinkedList<Node>();
			for(int i = 0; i < numClasses; i++){
				if(classes[i].in.size() == 0){
					sources.add(classes[i]);
				}
			}
			String msg = "No";
			for(Node n : sources){
				if(dfs(n, classes)){
					msg = "Yes";
					break;
				}
				for(Node n2 : classes){
					n2.reset();
				}
			}
			System.out.printf("Case #%d: %s\n", caseN, msg);
		}
	}
	public static boolean dfs(Node n, Node[] nodes){
		if(n.visited){
			return true;
		}
		else{
			n.visited = true;
			for(Node n2 : n.out){
				boolean tmp = dfs(n2, nodes);
				if(tmp){
					return true;
				}
			}
			return false;
		}
	}
}
class Node{
	boolean visited;
	LinkedList<Node> out;
	LinkedList<Node> in;
	public Node(){
		visited = false;
		out = new LinkedList<Node>();
		in = new LinkedList<Node>();
	}
	public void reset(){
		visited = false;
	}
}