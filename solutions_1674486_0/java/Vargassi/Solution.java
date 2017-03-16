package gjc.diamondinheritance;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

class Node {
	private int id;
	private List<Node> inbound = new ArrayList<Node>(), 
			outbound = new ArrayList<Node>(),
			intersections= new ArrayList<Node>();
	
	public Node(int _id) {
		id = _id;
	}
	
	public int getId() {
		return id;
	}

	public List<Node> getInbound() {
		return inbound;
	}

	public void setInbound(List<Node> inbound) {
		this.inbound = inbound;
	}

	public List<Node> getOutbound() {
		return outbound;
	}

	public void setOutbound(List<Node> outbound) {
		this.outbound = outbound;
	}

	public List<Node> getIntersections() {
		return intersections;
	}

	public void setIntersections(List<Node> intersections) {
		this.intersections = intersections;
	}

	public String toString() {
		return id+"";
	}
}

public class Solution {

	static boolean goUp(Node nodeObj, Set<Node> backpack, Node lastNode) {
		backpack.add(nodeObj);
		boolean temp = false;
		if (nodeObj.getInbound().size()>1) {
			List<Node> inboundNodes = nodeObj.getInbound();
			for (Node inboundNode: inboundNodes) {
				if (inboundNode!=lastNode) {
					temp = goDown(inboundNode, backpack, nodeObj);
					if (temp) return true;
				}
			}
		}
		List<Node> outboundNodes = nodeObj.getOutbound();
		for (Node outboundNode: outboundNodes) {
			temp = goUp(outboundNode, backpack, nodeObj);
			if (temp) return true;
		}
		return temp;
	}
	
	static boolean goDown(Node nodeObj, Set<Node> backpack, Node lastNode) {
		if (nodeObj.getOutbound().size()>1) {
			if (backpack.contains(nodeObj)) {
				return true;
			}
		}

		boolean temp = false;
		List<Node> inboundNodes = nodeObj.getInbound();
		for (Node inboundNode: inboundNodes) {
			if (inboundNode!=lastNode) {
				temp = goDown(inboundNode, backpack, nodeObj);
				if (temp) return true;
			}
		}
		return temp;
	}
	
	static boolean mark(Node nodeObj, List<Node> intersections, Node lastNode) {
		List<Node> currentIntersections = nodeObj.getIntersections();
		
		// Check if there is any diamond pattern.
		for (Node intersection: intersections) {
			if (intersection!=nodeObj && intersection!=lastNode && 
					currentIntersections.contains(intersection)) {
				return true;
			} else {
				currentIntersections.add(intersection);
			}
		}
		// traverse through all its parents.
		for (Node parent: nodeObj.getOutbound()) {
			List<Node> newIntersections = new ArrayList<Node>();
			newIntersections.add(nodeObj);
			newIntersections.addAll(currentIntersections);
			boolean temp = mark(parent, newIntersections, nodeObj);
			if (temp) return true;
		}
		return false;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-small-attempt1.txt"));
		int nTestCases = Integer.parseInt(br.readLine());
		for (int i=0; i<nTestCases; i++) {
			String line = br.readLine();
			StringTokenizer st = new StringTokenizer(line);
			int nClasses = Integer.valueOf(st.nextToken());
			Node[] classes = new Node[nClasses];
			for (int j=0; j<nClasses; j++) {
				classes[j] = new Node(j+1);
			}
			
			// Initiate the tree
			for(int j=0; j<nClasses; j++) {
				st = new StringTokenizer(br.readLine());
				int nSubClasses = Integer.valueOf(st.nextToken());
				Node classObj = classes[j];
				for (int k=0; k<nSubClasses; k++) {
					Node targetClass = classes[Integer.valueOf(st.nextToken())-1];
					classObj.getOutbound().add(targetClass);
					targetClass.getInbound().add(classObj);
				}
			}
			
			// Find the sources.
			List<Node> sources = new ArrayList<Node>();
			for (int j=0; j<nClasses; j++) {
				if (classes[j].getInbound().size()==0) {
					sources.add(classes[j]);
				}
			}
			
			// Traverse the tree from the sources.
			boolean result = false;
			for (Node source: sources) {
				for (Node parent: source.getOutbound()) {
					Set<Node> backpack = new HashSet<Node>();
					backpack.add(source);
					result = goUp(parent, backpack, source);
					if (result) break;
				}
				if (result) break;
			}
			
			String str = "No";
			if (result) str = "Yes";
			// Display the results.
			bw.write("Case #"+(i+1)+": ");
			bw.write(str+"\n");
		}
		bw.close();
	}

}
