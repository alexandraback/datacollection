import java.io.*;
import java.util.*;

class Node {
	Set<Node> children;
	Set<Node> parent;
	int NodeNumber;
	boolean isVisited;
	
	public Node(int number) {
		this.NodeNumber = number;
		this.isVisited = false;
		this.children = new HashSet<Node>();
		this.parent = new HashSet<Node>();
	}
}

public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
	
		Scanner console = new Scanner(System.in);
		
		// gets the filename to work with
		Scanner input = getInput(console);
		// gets the name of file to output to
		PrintStream output = getOutput(console);
		
		int numOfCases = input.nextInt();
		
		for (int i = 1; i <= numOfCases; i++) {
			int totalNodes = input.nextInt();
			
			Map<Integer, Node> nodeBag = new HashMap<Integer, Node>();
			
			Set<Integer> startingNodes = new HashSet<Integer>();
			
			for (int currNode = 1; currNode <= totalNodes; currNode++) {
				int inherits = input.nextInt();
				
				if (inherits == 0) {
					startingNodes.add(currNode);
					
					if (!nodeBag.containsKey(currNode)) {
						Node curr = new Node(currNode);
						nodeBag.put(currNode, curr);
					}
					
				} else {
					Node curr;
					if (nodeBag.containsKey(currNode)) {
						curr = nodeBag.get(currNode);
					} else {
						curr = new Node(currNode);
						nodeBag.put(currNode, curr);
					}
					
					
					for (int parents = 0; parents < inherits; parents++) {
						int parentNum = input.nextInt();
						
						Node parent;
						if (nodeBag.containsKey(parentNum)) {
							parent = nodeBag.get(parentNum);
						} else {
							parent = new Node(parentNum);
							nodeBag.put(parentNum, parent);
						}
						
						curr.parent.add(parent);
						parent.children.add(curr);
					}
				}
			}
			
			
			
			boolean foundDiamond = false;
			while (startingNodes.size() > 0) {
				int ancestorNum = startingNodes.iterator().next();
				
				startingNodes.remove(ancestorNum);
				
				Node ancestor = nodeBag.get(ancestorNum);
				
				ancestor.isVisited = true;
				
				Queue<Node> nodeQ = new LinkedList<Node>();
				nodeQ.addAll(ancestor.children);
				
				/*
				for (Node child : ancestor.children) {
					child.isVisited = true;
				}*/
				
				while(!nodeQ.isEmpty()) {
					Node currNode = nodeQ.remove();
					if (currNode.isVisited) {
						foundDiamond = true;
						break;
					} else {
						currNode.isVisited = true;
						nodeQ.addAll(currNode.children);
					}
					
				}
				if (foundDiamond) {
					break;
				}
				turnFalse(nodeBag);
			}
			output.print("Case #" + i +": ");
			if (foundDiamond) {
				output.println("Yes");
			} else {
				output.println("No");
			}
		}
	}
	
	public static void turnFalse(Map<Integer, Node> nodeBag) {
		for (Node n : nodeBag.values()) {
			n.isVisited = false;
		}
	}
	
	public static int lineSearcher(String sentence, String welcomeString) {
		if (welcomeString.length() == 0) {
			return 1;
		} else if (sentence.length() == 0) {
			return 0;
		} else {
			if (sentence.substring(0,1).equals(welcomeString.substring(0,1))){
				return lineSearcher(sentence.substring(1), welcomeString.substring(1))
							+ lineSearcher(sentence.substring(1), welcomeString);
			} else {
				return lineSearcher(sentence.substring(1), welcomeString);
			}
		}
	}
	
	public static Scanner getInput(Scanner console) {
		Scanner input = null;
		while(input == null) {
			System.out.print("Input file name: ");
			String name = console.nextLine();
			try {
				input = new Scanner(new File(name));
			} catch (FileNotFoundException e) {
			}
		}
		return input;
	}
	
	// gets the filename to output to (if blank, outputs to console)
	public static PrintStream getOutput(Scanner console) throws FileNotFoundException{
		System.out.print("Output file name: ");
		String output = console.nextLine();
		if (output.equals("")) {
			return new PrintStream(System.out);
		} else {
			return new PrintStream(new File(output));
		}
	}
}