package com.dten.cj.r1c;

import java.util.HashSet;
import java.util.Scanner;

import com.dten.cj.Problem;

public class A extends Problem {

	boolean[][]	graph;

	@Override
	public String solveProblem(Scanner scanner) {

		int nodeCount = scanner.nextInt();

		graph = new boolean[nodeCount][];

		for (int i = 0; i < nodeCount; i++) {
			graph[i] = new boolean[nodeCount];
		}

		for (int i = 0; i < nodeCount; i++) {
			int pathCount = scanner.nextInt();
			for (int j = 0; j < pathCount; j++) {
				int inheritsFrom = scanner.nextInt();
				graph[inheritsFrom - 1][i] = true;
			}
		}

		for (int i = 0; i < nodeCount; i++) {
			for (int j = 0; j < nodeCount; j++) {
				if (i == j) continue;
				HashSet<String> pathsFrom = pathsFrom(i, j);
				if (pathsFrom.size() > 1) return "Yes";

			}
		}

		return "No";
	}

	public HashSet<String> pathsFrom(int i, int terminal) {
		HashSet<String> paths = new HashSet<String>();
		if (i == terminal) {
			paths.add("" + terminal);
			return paths;
		}

		for (int j = 0; j < graph[i].length; j++) {
			if (graph[i][j]) {
				for (String string : pathsFrom(j, terminal)) {
					paths.add("" + i + string);
				}
			}
		}

		return paths;
	}
}
