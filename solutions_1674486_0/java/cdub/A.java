package cw.codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

class A {
	List<TestCase> cases = new ArrayList<>();

	private static class TestCase {
		String ans = "No";
		List<Node> nodelist = new ArrayList<>();
	}

	private static class Node {
		 int id;
		List<Integer> edges = new ArrayList<>();
		
		Node(int id){
			this.id = id;
		}
		
		@Override
		public String toString() {
			return "" + id;
		}
	}

	public static void main(String[] args) {
		A puzzle = new A();

		File infile = new File(args[0]);
		File outfile = new File(infile.getParent(), infile.getName()
				+ ".OUT.txt");

		puzzle.parse(infile);
		puzzle.solve();
		puzzle.output(outfile);
	}

	void parse(File infile) {
		try (Scanner scanner = new Scanner(infile)) {
			int totalCases = Integer.parseInt(scanner.nextLine());
			for (int i = 0; i < totalCases; i++) {
				TestCase tcase = new TestCase();
				final int n = scanner.nextInt();
				for (int x = 0; x < n; x++) {
					Node node = new Node(x + 1);
					int numParents = scanner.nextInt();
					for (int y = 0; y < numParents; y++) {
						node.edges.add(scanner.nextInt());
					}
					tcase.nodelist.add(node);
				}
				cases.add(tcase);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	void output(File outfile) {
		try (BufferedWriter bw = new BufferedWriter(new FileWriter(outfile))) {
			int i = 1;
			for (TestCase tcase : cases) {
				bw.write(String.format("Case #%d: %s", i++, tcase.ans));
				bw.newLine();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	void solve() {
		for (TestCase tCase : cases) {
			List<Node> nodelist = tCase.nodelist;
			for(Node node : nodelist){
				//only diamond if multiple inheritance
				if(node.edges.size() > 1){
					//walk each possible direction, return a set of possible parents
					List<Integer> parentNodes = walkParents(node, nodelist);
					
					//attempt to remove dupes, if any we have diamond
					if(parentNodes.size() != new HashSet<>(parentNodes).size()){
						//diamond found
						tCase.ans= "Yes";
					}
					
				} 
			}
		}
	}

	private List<Integer> walkParents(Node node, List<Node> nodelist) {
		List<Integer> parents = new ArrayList<>();
		for(Integer index : node.edges){
			parents.add(index);
			Node parent = nodelist.get(index - 1);
			parents.addAll( walkParents(parent, nodelist));
		}
		return parents;
	}
}
