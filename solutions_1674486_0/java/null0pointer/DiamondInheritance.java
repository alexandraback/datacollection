import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

public class DiamondInheritance {

	private static String infile = "A-small-attempt1.in";
	private static String outfile = "out.txt";
	private static String encoding = "UTF-8";
	
	public DiamondInheritance() {
		
	}
	
	public void run() {
		try {
			runTests();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public void runTests() throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(infile), encoding);
		BufferedWriter writer = new BufferedWriter(new FileWriter(outfile));
		int nCases = Integer.parseInt(scanner.nextLine());

		for (int i = 0; i < nCases; i++) {
			String val = testCase(scanner);
			System.out.print("Case #" + (i + 1) + ": " + val + "\n");
			writer.write("Case #" + (i + 1) + ": " + val + "\n");
		}

		writer.close();
	}
	
	public String testCase(Scanner scanner) {
		int nNodes = Integer.parseInt(scanner.nextLine());
		ArrayList<Node> nodes = new ArrayList<Node>(nNodes);
		ArrayList<Node> zeroNodes = new ArrayList<Node>();
		
		for (int i = 0; i < nNodes; i++) {
			nodes.add(new Node());
		}
		
		for (int i = 0; i < nNodes; i++) {
			String[] vals = scanner.nextLine().split(" ");
			int nChildren = Integer.parseInt(vals[0]);
			if (nChildren == 0) {
				zeroNodes.add(nodes.get(i));
			} else {
				for (int j = 1; j < vals.length; j++) {
					int node = Integer.parseInt(vals[j]);
					nodes.get(node - 1).children.add(nodes.get(i));
				}
			}
		}
		
		boolean result = false;
		
		for (int i = 0; i < zeroNodes.size() && !result; i++) {
//			LinkedList<Node> currentNodes = new LinkedList<Node>();
//			currentNodes.push(zeroNodes.get(0));
//			
//			while (currentNodes.size() > 0 && !result) {
//				Node node = currentNodes.pop();
//				if (node.seen) {
//					result = true;
//				} else {
//					node.seen = true;
//					
//					for (int j = 0; j < node.children.size(); j++) {
//						currentNodes.push(node.children.get(j));
//					}
//				}
//			}
			
			result = dfs(zeroNodes.get(i));
			
			if (!result)
				resetNodes(nodes);
		}
		
		if (result)
			return "Yes";
		else
			return "No";
	}
	
	public boolean dfs(Node n) {
		if (n.seen) {
			return true;
		} else {
			n.seen = true;
			
			for (int i = 0; i < n.children.size(); i++) {
				if (dfs(n.children.get(i)))
					return true;
			}
		}
		
		return false;
	}
	
	public void resetNodes(ArrayList<Node> nodes) {
		for (int i = 0; i < nodes.size(); i++) {
			nodes.get(i).seen = false;
		}
	}
	
	public class Node {
		public ArrayList<Node> children;
		public boolean seen = false;
		
		public Node() {
			children = new ArrayList<Node>();
		}
	}

}
