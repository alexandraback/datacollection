package y2014.qualification;

import template.Runner;
import template.Solver;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Created by raggzy on 4/12/14.
 */
public class D extends Solver {
	public D(Scanner in, PrintStream out, int TC) {
		super(in, out, TC);
	}

	private TreeSet<Integer> readNValues(int N) {
		TreeSet<Integer> result = new TreeSet<Integer>();
		for (int i = 0; i < N; i++) {
			result.add((int) (100000 * in.nextDouble()));
		}
		return result;
	}

	private int deceitWarScore(TreeSet<Integer> Naomi, TreeSet<Integer> Ken, int N) {
		int deceitWarScore = 0;
		for (int i = 0; i < N; i++) {
			if (Ken.first() < Naomi.pollFirst()) {
				deceitWarScore++;
				Ken.pollFirst();
			} else {
				Ken.pollLast();
			}
		}
		return deceitWarScore;
	}

	private int warScore(TreeSet<Integer> Naomi, TreeSet<Integer> Ken, int N) {
		int warScore = 0;
		for (int i = 0; i < N; i++) {
			int naomi = Naomi.pollFirst();
			if (Ken.ceiling(naomi) != null) {
				Ken.remove(Ken.ceiling(naomi));
			} else {
				warScore++;
				Ken.pollFirst();
			}
		}
		return warScore;
	}

	@Override
	public void solve() {
		int N = in.nextInt();
		TreeSet<Integer> Naomi = readNValues(N);
		TreeSet<Integer> Ken = readNValues(N);
		println("Case #%d: %d %d", TC,
				deceitWarScore((TreeSet<Integer>) Naomi.clone(), (TreeSet<Integer>) Ken.clone(), N),
				warScore((TreeSet<Integer>) Naomi.clone(), (TreeSet<Integer>) Ken.clone(), N));
	}

	public static void main(String[] args) throws Exception {
		Runner.main(D.class);
	}
}
