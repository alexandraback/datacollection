package codejam.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemB {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		PrintStream out = new PrintStream(args[1]);

		int testsCount = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= testsCount; test++) {
			String input = reader.readLine();
			StringTokenizer tokenizer = new StringTokenizer(input);
			int N = Integer.parseInt(tokenizer.nextToken());
			int S = Integer.parseInt(tokenizer.nextToken());
			int p = Integer.parseInt(tokenizer.nextToken());
			List<Integer> nonSurprisingExceedingP = new ArrayList<Integer>();
			List<Integer> suprisingExceedingP = new ArrayList<Integer>();
			for (int i = 0; i < N; i++) {
				int ti = Integer.parseInt(tokenizer.nextToken());
				if (bestNonSuprisingSolution(ti) >= p) {
					nonSurprisingExceedingP.add(i);
				}else if(hasSuprisingSolution(ti) && bestSuprisingSolution(ti) >=p) {
					suprisingExceedingP.add(i);
				}
			}
			int googlersCount = nonSurprisingExceedingP.size() + Math.min(S, suprisingExceedingP.size());
			out.println(String.format("Case #%s: %s", test, googlersCount));
		}

		out.close();
		reader.close();
	}

	private static int nearestUpperMultipleOfThree(int a) {
		if (a == 0 || a % 3 == 0) {
			return a;
		}
		return a + (3 - (a % 3));
	}

	private static int nearestMultipleOfThree(int a) {
		if (a == 0 || a % 3 == 0) {
			return a;
		}
		if (a % 3 == 1) {
			return a - 1;
		}
		return a + 1;
	}

	private static int bestNonSuprisingSolution(int total) {
		return nearestUpperMultipleOfThree(total) / 3;
	}

	private static boolean hasSuprisingSolution(int total) {
		return total > 1;
	}

	private static int bestSuprisingSolution(int total) {
		return (nearestMultipleOfThree(total) / 3) + 1;
	}
}
