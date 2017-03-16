import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class DiamondInheritance {
	static List<Node> nodes;
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		s.nextLine();
		for (int c = 0; c < numCases; c++) {
			int numClasses = s.nextInt();
			s.nextLine();
			nodes = new ArrayList<>(numClasses); //note offset by 1
			for (int n = 0; n < numClasses; n++) {
				Node node = new Node();
				int numInherited = s.nextInt();
				//System.out.print("Node " + (n+1) + " inherits from ");
				//System.out.flush();
				node.inheritsFrom = new ArrayList<>(numInherited);
				for (int i = 0; i < numInherited; i++) {
					node.inheritsFrom.add(s.nextInt());
					//System.out.print(" " + node.inheritsFrom.get(i));
				}
				//System.out.println("");
				nodes.add(node);
				s.nextLine();
			}
			
			boolean found = false;
			for (Node n : nodes) {
				found = dfs(n);
				if (found) {
					break;
				}
			}
			if (found) {
				System.out.println("Case #" + (c+1) + ": Yes");
			} else {
				System.out.println("Case #" + (c+1) + ": No");
			}
		}
		
	}
	
	static boolean dfs(Node n) {
		if (n.allInherited == null) {
			List<Integer> open = new ArrayList<>();
			n.allInherited = new TreeSet<>();
			n.allInherited.addAll(n.inheritsFrom);
			open.addAll(n.inheritsFrom);
			while (!open.isEmpty()) {
				Integer i = open.remove(open.size()-1);
				Node other = nodes.get(i-1);
				if (other.allInherited == null) {
					boolean found = dfs(other);
					if (found) {
						return true;
					}
				}
				// other.allInherited != null
				for (Integer otherI : other.allInherited) {
					boolean unseen = n.allInherited.add(otherI);
					if (!unseen) {
						return true;
					}
				}
			}
			return false;
		} else {
			return false;
		}
	}
	
	
	static class Node {
		List<Integer> inheritsFrom = null;
		Set<Integer> allInherited = null;
	}

}
