package assignmentA;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("test"));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		Solver s = new Solver(in, out);
		s.solveCases();
		out.flush();
		out.close();
		in.close();
	}
}

class Solver {
	Scanner in;
	PrintWriter out;
	public Solver(Scanner scanner, PrintWriter printStream) {
		in = scanner;
		out = printStream;
	}

	public void solveCases() {
		int numCases = in.nextInt();
		in.nextLine();
		for(int i=0;i<numCases;i++) {
			out.println("Case #"+(i+1)+": " + solveNextCase());
		}

	}

	public String solveNextCase() {
		int numberOfClasses = in.nextInt();
		in.nextLine();
		List<List<Integer>> connections = new ArrayList<List<Integer>>();
		for (int i = 0; i < numberOfClasses; i++) {
			List<Integer> connection = new ArrayList<Integer>();
			int amount = in.nextInt();
			for (int j = 0; j < amount; j++) {
				connection.add(in.nextInt());
			}
			connections.add(connection);
		}
		return isDiamond(connections)?"Yes":"No";
	}

	private boolean isDiamond(List<List<Integer>> connections) {
		for (List<Integer> connection : connections) {
			if (connection.size() > 1) {
				Set<Integer> total = new HashSet<Integer>();
				for (int i : connection) {
					Set<Integer> reachable = getReachable(i, connections);
					for (int j : reachable) {
						if (!total.add(j)){
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	private Set<Integer> getReachable(int i, List<List<Integer>> connections) {
		Set<Integer> result = new HashSet<Integer>();
		System.out.println(i);
		result.add(i);
		result.addAll(connections.get(i - 1));
		for (int j: connections.get(i - 1)) {
			result.addAll(getReachable(j, connections));
		}
		return result;
	}
}