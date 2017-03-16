import java.io.*;
import java.util.*;

public class template {
	public static void main(String[] args) throws IOException {		
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		PrintWriter out = new PrintWriter("output.txt");

		
		int cases = in.nextInt();
		
		outer: for(int c = 1 ; c <= cases ; c++) {
			ArrayList<Node> nodes = new ArrayList<Node>();
			Set<Node> roots = new HashSet<Node>();
			
			int classCount = in.nextInt();
			for (int i = 0 ; i <= classCount ; i++) {
				nodes.add(new Node(i));
			}
			
			for (int i = 1 ; i <= classCount ; i++) {
				int connectionsCount = in.nextInt();
				for (int j = 0 ; j < connectionsCount ; j++) {
					int parent = in.nextInt();
					nodes.get(i).parents.add(nodes.get(parent));
					nodes.get(parent).children.add(nodes.get(i));
				}
			}
			
			// work out the different trees...
			for (int i = 1 ; i <= classCount ; i++) {
				Node n = nodes.get(i);	
				if (n.parents.size() == 0) {
					roots.add(n);
				}
			}
			
			
			for(Iterator<Node> it = roots.iterator() ; it.hasNext() ; ) {
				Node n = it.next();
				if (!bfs(n, new HashSet<Node>())) {
					out.println("Case #" + c + ": Yes");
					continue outer;
				} 
			}
			out.println("Case #" + c + ": No");
			
		}
		
		
		
		out.flush();
		out.close();
	}
	
	static boolean bfs(Node n , HashSet<Node> s) {
		//System.out.print("bfsing " + n.name);
		if (!s.add(n)) {
			//System.out.print("Shit");
			return false;
		}
		
		for(Iterator<Node> it = n.children.iterator() ; it.hasNext() ; ) {
			Node n2 = it.next();
			if (n2.inTreeSeen) continue;
			if (!bfs(n2, s)) {
				return false;
			}
		}
		return true;
	}
	
}



class Node {
	int name;
	boolean coloured = false;
	boolean inTreeSeen = false;
	ArrayList<Node> children = new ArrayList<Node>();
	ArrayList<Node> parents = new ArrayList<Node>();
	
	public Node(int _name) {
		name = _name;
	}
}