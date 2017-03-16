package gcj1C;

import java.io.*;
import java.util.*;

public class C {
	static PrintWriter writer;
	static Scanner sc;

	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
		sc.close();
	}

	private static void solveAllTests() throws FileNotFoundException {
		sc = new Scanner(new File("input"));
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();
			// System.out.println(c + " " + d + " " + v);
			int[] pieces = new int[d];
			for (int j = 0; j < d; j++) {

				pieces[j] = sc.nextInt();
			}
			int res = solveOneTest(c, d, v, pieces);
			writer.println("Case #" + i + ": " + res);
		}
	}

	private static int solveOneTest(int c, int d, int v, int[] pieces) {
		Set<Integer> possible = computePos(pieces);

		int res = 0;
		for (int i = 1; i <= v; i++) {
			if (possible.contains(i)) {
				continue;
			}
			res++;
			Set<Integer> tobeAdded = updatePos(i, possible);
			possible.addAll(tobeAdded);
		}
		return res;
	}

	private static Set<Integer> updatePos(int i, Set<Integer> possible) {
		Set<Integer> res = new HashSet<>();
		for (int p : possible) {
			res.add(p + i);
		}
		return res;
	}

	private static Set<Integer> computePos(int[] pieces) {
		Set<Integer> res = new HashSet<>();
		res.add(0);
		res.add(pieces[0]);
		for (int i = 1; i < pieces.length; i++) {
			Set<Integer> tobeAdded = new HashSet<>();
			for (int p : res) {
				tobeAdded.add(p + pieces[i]);
			}
			res.addAll(tobeAdded);
		}
		return res;
	}
}