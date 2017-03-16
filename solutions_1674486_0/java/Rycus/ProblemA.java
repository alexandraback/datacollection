import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class ProblemA {
	
	static final String 	ID 			= ProblemA.class.getSimpleName().replaceFirst("Problem([A-Z])", "$1");
	static final boolean 	SMALL_SET 	= true;
	
	static Map<Integer, Node> nodes = new HashMap<>();
	class Node {
		final int MAX_CHILDREN;
		Node(int id, int maxc) { 
			this.id = id; this.MAX_CHILDREN = maxc;
			children = new Node[MAX_CHILDREN];
			visited = new boolean[MAX_CHILDREN];
		}
		int id;
		int childCount = 0;
		final Node[] children;
		final boolean[] visited;
//		boolean nodeVisited = false;
		Set<Integer> visitIDs = new HashSet<>();
		@Override public String toString() {
			return "N" + id;
		}
	}
	
	static void solve(Scanner scanner, StringBuilder builder) {
		nodes.clear();
		
		int N = scanner.nextInt();
		System.out.println("N: " + N);
		
		ProblemA A = new ProblemA();
		
		for(int nodeID = 0; nodeID < N; nodeID++) {
			scanner.nextLine();
			
			int cnt = scanner.nextInt();
			if(N < 10) System.out.print("#" + nodeID + "| Count: " + cnt + " |");
			
			Node node = nodes.containsKey(nodeID) ? nodes.get(nodeID) : A.new Node(nodeID, N);
			if(!nodes.containsKey(nodeID)) nodes.put(nodeID, node);
			
			for(int i = 0; i < cnt; i++) {
				int parentID = scanner.nextInt() - 1;
				if(N < 10) System.out.print(" " + parentID);
				Node parent = nodes.containsKey(parentID) ? nodes.get(parentID) : A.new Node(parentID, N);
				if(!nodes.containsKey(parentID)) nodes.put(parentID, parent);
				parent.children[parent.childCount++] = node;
			}
			if(N < 10) System.out.println();
		}
		
//		System.out.println("Visiting " + nodes.size() + " nodes");
		int vid = 0;
		for(Node node : nodes.values()) {
			if(visit(node, vid++)) {
				System.out.println(", " + node.id);
				builder.append("Yes");
				return;
			}
		}
		
		builder.append("No");
	}
	
	static boolean visit(Node node, int visitID) {
		System.out.println("#" + visitID + "| Visit " + node.id + " " + Arrays.toString(node.children));
//		node.nodeVisited = true;
		for(int idx = 0 ; idx < node.childCount; idx++) {
			Node child = node.children[idx];
			if(child == null) break;
//			if(node.visited[idx]) continue;
			
			if(child.visitIDs.contains(visitID)) {
				System.out.print("Found: " + child.id + ", ");
				return true;
			} else {
//				child.nodeVisited = true;
				child.visitIDs.add(visitID);
//				node.visited[idx] = true;
				
				if(visit(child, visitID)) {
					System.out.print(child.id + ", ");
					return true;
				}
			}
		}
		
		return false;
	}
	
	static String problemName()	{ return ID + "-" + (SMALL_SET ? "small" : "large"); }
	static String inFilename() 	{ return problemName() + ".in"; }
	static String outFilename()	{ return problemName() + ".out"; }
	
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new File(inFilename()))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter(outFilename()))) {
				int numCases = scanner.nextInt();
						
				StringBuilder builder = new StringBuilder();
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					builder.setLength(0);
					scanner.nextLine();
					
					solve(scanner, builder);
					
					String caseOutput = String.format("Case #%d: %s", caseIdx + 1, builder.toString());
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}				
			}
		} catch(Throwable scannerEx) {
			scannerEx.printStackTrace();
		}
	}

}
