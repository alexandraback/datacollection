package com.nolmecolindor.gcj2012.round1c;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Problem_A_0 {

	private class Node {
		final List<Node> ancestors = new ArrayList<Node>();
		
		short undoneChildren = 0;
		
		final Set<Node> successors = new HashSet<Node>();
		
		public void checkAncestors() {
			successors.add(this);
			for (Node ancestor: ancestors) ancestor.acceptSuccessor(successors);
			done++;
		}

		private void acceptSuccessor(final Set<Node> newSuccessors) {
			for (Node s: newSuccessors) hasDiamond |= successors.contains(s);
			successors.addAll(newSuccessors);
			undoneChildren--;
			if (undoneChildren == 0) todo.add(this);
		}
		
	}
	
	int N;
	Node[] classes;
	boolean hasDiamond;
	
	final Queue<Node> todo = new LinkedList<Node>();
	short done;
	
	public void cleanUp() {
		for (Node current: classes) {
			current.ancestors.clear();
		}
	}
	
	private String solve(final Scanner input) {
		N = input.nextShort();
		classes = new Node[N];
		for (int i = 0; i < N; i++) classes[i] = new Node();
		
		short m;
		Node ancestor;
		
		for (Node current: classes) {
			m = input.nextShort();
//			System.out.println("m is " + m);
			for (int j = 0; j < m; j++) {
				ancestor = classes[input.nextShort() - 1];
				ancestor.undoneChildren ++;
				current.ancestors.add(ancestor);
			}
		}
		
		done = 0;
		todo.clear();
		for (Node current: classes) if (current.undoneChildren == 0) todo.add(current);
		
		hasDiamond = false;
		
		while (!hasDiamond && !todo.isEmpty()) {
			final Node current = todo.remove();
			current.checkAncestors();
		}

//		if (!hasDiamond) System.out.println("Done " + done + " classes.");
		return hasDiamond ? "Yes" : "No";
	}
	
	
	private void solveAll(final Scanner input) throws NumberFormatException, IOException {
		final int cases = input.nextInt();
		input.nextLine();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.println("Case #" + caseNum + ": " + solve(input));
		}
	}
	
	public static void main(final String[] args) {
		try {
			final Scanner input = new Scanner(((args.length == 2) && args[0].equals("--input")) ? new FileInputStream(args[1]) : System.in);
			new Problem_A_0().solveAll(input);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
