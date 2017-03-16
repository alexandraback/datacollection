import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Q3 {
	public static Problem[] probs;

	static class Problem {
		public int N;
		public int M;
		public int[] zips;
		public ArrayList<int[]> flights;
	}
	
	
	static class Node {
		public int city;
		public int zip;
		public ArrayList<Node> children = new ArrayList<Node>();
		public ArrayList<Node> parents = new ArrayList<Node>();
	}
	
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	private static Node buildTree(Problem p) {
		int smallest_zip_city = 0;
		int smallest_zip = 100000;
		for (int i=0; i<p.N; i++) {
			if (p.zips[i]<smallest_zip) {
				smallest_zip = p.zips[i];
				smallest_zip_city = i+1;
			}
		}
		HashMap<Integer, Node> nodeMap = new HashMap<Integer, Node>();
		for (int i=0; i<p.N; i++) {
			Node newNode = new Node();
			newNode.city = i+1;
			newNode.zip = p.zips[newNode.city-1];
			nodeMap.put(newNode.city, newNode);
		}
		
		Node root = nodeMap.get(smallest_zip_city);
		ArrayList<int[]> tmpFlights = new ArrayList<int[]>(p.flights);
		ArrayList<Node> workingList = new ArrayList<Node>();
		ArrayList<Node> nextWorkingList = new ArrayList<Node>();
		workingList.add(root);
		while (tmpFlights.size()>0) {
			int index = 0;
			while (index<tmpFlights.size()) {
				if (workingList.contains(nodeMap.get(tmpFlights.get(index)[0]))) {
					nodeMap.get(tmpFlights.get(index)[0]).children.add(nodeMap.get(tmpFlights.get(index)[1]));
					nodeMap.get(tmpFlights.get(index)[1]).parents.add(nodeMap.get(tmpFlights.get(index)[0]));
					nextWorkingList.add(nodeMap.get(tmpFlights.get(index)[1]));
					tmpFlights.remove(index);
				} else if (workingList.contains(nodeMap.get(tmpFlights.get(index)[1]))) {
					nodeMap.get(tmpFlights.get(index)[1]).children.add(nodeMap.get(tmpFlights.get(index)[0]));
					nodeMap.get(tmpFlights.get(index)[0]).parents.add(nodeMap.get(tmpFlights.get(index)[1]));		
					nextWorkingList.add(nodeMap.get(tmpFlights.get(index)[0]));
					tmpFlights.remove(index);
				} else {
					index++;
				}
			}
			workingList.clear();
			for (int i=0; i<nextWorkingList.size(); i++) {
				workingList.add(nextWorkingList.get(i));
			}
			nextWorkingList.clear();
		}

		return root;
	}
	
	private static String traverseTree(Node parent, Node node) {
		if (node.children.size()==0) {
			for (Node p : node.parents) {
				if (p.city!=parent.city) {
					p.children.remove(node);
				}
			}
			return "" + node.zip;
		}
		ArrayList<String> branchResults = new ArrayList<String>();
		ArrayList<Node> tmpChildren = new ArrayList<Node>(node.children);
		StringBuffer sb = new StringBuffer("");
		while (tmpChildren.size()>0) {
			int smallest_child = 100000;
			int smallest_child_ind = 100;
			for (int i=0; i<tmpChildren.size(); i++) {
				if (tmpChildren.get(i).city<smallest_child) {
					smallest_child = tmpChildren.get(i).zip;
					smallest_child_ind = i;
				}
			}
			sb.append(traverseTree(node, tmpChildren.get(smallest_child_ind)));
			tmpChildren.remove(smallest_child_ind);
		}
		
		return node.zip + sb.toString();
	}
	
	
	private static String solveSmall(Problem p) {
		Node root = buildTree(p);
		return traverseTree(null, root);
	}
	
	private static String solveProblem(Problem p) {
		return solveSmall(p);
	}

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].N = Integer.parseInt(pieces[0]);
				probs[i].M = Integer.parseInt(pieces[1]);
				probs[i].zips = new int[probs[i].N];
				line = br.readLine();
				for (int j=0; j<probs[i].N; j++) {
					probs[i].zips[j] = Integer.parseInt(line);
					line = br.readLine();
				}
				probs[i].flights = new ArrayList<int[]>();
				for (int j=0; j<probs[i].M; j++) {
					pieces = line.split(" ");
					probs[i].flights.add(new int[]{Integer.parseInt(pieces[0]), Integer.parseInt(pieces[1])});
					line = br.readLine();
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}