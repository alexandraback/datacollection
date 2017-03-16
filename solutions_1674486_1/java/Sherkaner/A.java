package assignmentA;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.InputMismatchException;
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
		List<Integer> visited = new ArrayList<Integer>();
		for (int k = 0; k < connections.size(); k++) {
			if (visited.contains(k + 1)) {
				continue;
			}
			List<Integer> connection = connections.get(k);
			if (connection.size() > 1) {
				Set<Integer> total = new HashSet<Integer>();
				for (int i : connection) {
					try {
						Set<Integer> reachable = getReachable(i, connections);
						for (int j : reachable) {
							if (!total.add(j)){
								return true;
							}
						}
					} catch(Exception e) {
						return true;
					}
				}
				visited.addAll(total);
			}
		}
		return false;
	}

	private Set<Integer> getReachable(int i, List<List<Integer>> connections) {
		Set<Integer> result = new HashSet<Integer>();
		result.add(i);
		for (int j: connections.get(i - 1)) {
			Set<Integer> reachable = getReachable(j, connections);
			for (int k : reachable) {
				if (!result.add(k)){
					throw new InputMismatchException();
				}
			}
		}
		return result;
	}
}