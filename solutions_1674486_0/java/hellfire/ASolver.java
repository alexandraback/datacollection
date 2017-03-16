package com.google.codejam;

import java.util.ArrayList;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class ASolver {

	public static boolean checkDiamondInheritance(List<Set<Integer>> graph, LinkedList<Integer> root) {
		
		for (int p : root) {
			boolean[] check = new boolean[graph.size()];
			LinkedList<Integer> bfs = new LinkedList<Integer>();
			bfs.add(p);
			while(bfs.isEmpty() == false) {
				int current = bfs.poll();
				for (int c : graph.get(current)) {
					if (check[c] == true) {
						return true;
					} else {
						check[c] = true;
						bfs.add(c);
					}
				}
			}
			
		}
		
		return false;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		final int total = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < total; i++) {
			int N = Integer.parseInt(scanner.nextLine());
			List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
			LinkedList<Integer> root = new LinkedList<Integer>();
			for (int j = 0; j < N; j++) {
				Set<Integer> link = new TreeSet<Integer>();
				graph.add(link);
			}
			for (int j = 0; j < N; j++) {
				int M = scanner.nextInt();
				for (int k = 0; k < M; k++) {
					int p = scanner.nextInt() - 1;
					graph.get(p).add(j);
				}
				if (M == 0) {
					root.add(j);
				}
				scanner.nextLine();
			}
			
			boolean answer = ASolver.checkDiamondInheritance(graph, root);
			
			System.out.printf("Case #%d: %s%n", i+1, (answer ? "Yes" : "No"));
		}
	}

}
