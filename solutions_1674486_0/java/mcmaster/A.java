package Round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

import Round1B.C;

public class A {

	private int N;
	private ArrayList<ArrayList<Integer>> edges;

	public A(int N, ArrayList<ArrayList<Integer>> edges) {
		this.N = N;
		this.edges = edges;
	}
	
	/**
	 * Whether exists Y that is reachable on multiple paths from X
	 * @param X
	 * @return
	 */
	private boolean isMultiPath(int X) {
		HashSet<Integer> reach = new HashSet<Integer>();
		LinkedList<Integer> queue = new LinkedList<Integer>();
		
		reach.add(X);
		queue.push(X);
		
		while (!queue.isEmpty()) {
			int from = queue.pop();
			ArrayList<Integer> outLinks = edges.get(from);
			// outlinks from from
			for (int i = 0; i < outLinks.size(); i++) {
				int to = outLinks.get(i);
				if (!reach.contains(to)) {
					reach.add(to);
					queue.push(to);
				}
				else {
					return true;
				}
			}
		}
		
		return false;
	}
	
	public boolean solve() {
		for (int i = 0; i < N; i++) {
			if (isMultiPath(i)) {
				return true;
			}
		}
		return false;
	}
	
	public void debug() {
		for (int i = 0; i < N; i++) {
			System.out.print((i+1) + ": ");
			for (int j = 0; j < edges.get(i).size(); j++) {
				System.out.print((edges.get(i).get(j) + 1) + " ");
			}
			System.out.println();
		}
	}
	
	// get all nodes that are reachable from X
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String inFile = "Round1C/A-small-attempt0.in";
		String outFile = "Round1C/A-small-attempt0.out";

		try {
			BufferedReader input = new BufferedReader(new FileReader(inFile));
			Writer output = new BufferedWriter(new FileWriter(outFile));
			Scanner scanner = new Scanner(input);
			String line = null;
			int T = scanner.nextInt();

			for (int i = 0; i < T; i++) {
				ArrayList<ArrayList<Integer>> edges = new ArrayList<ArrayList<Integer>>();
				
				int N = scanner.nextInt();
				for (int j = 0; j < N; j++) {
					ArrayList<Integer> outEdges = new ArrayList<Integer>();
					int M = scanner.nextInt();
					for (int k = 0; k < M; k++) {
						int L = scanner.nextInt();
						outEdges.add(L-1); // index edges from 0
					}
					edges.add(outEdges);
				}
				A a = new A(N, edges);
				//a.debug();
				String outtext = a.solve() ? "Yes" : "No";
								
				System.out.println("Case #" + (i + 1) + ": " + outtext);
				output.write("Case #" + (i + 1) + ": " + outtext + "\n");
			}
			input.close();
			output.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

}
