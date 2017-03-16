package pl.mpisarek.gcj2016.round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ProblemB {

	private static class Result {
		private long diff = Long.MAX_VALUE;

		private Long coders = 0L;

		private Long jammers = 0L;

		private void check(long codersScore, long jammersScore) {
			final long abs = Math.abs(jammersScore - codersScore);
			if (abs < diff
					|| (abs == diff && (codersScore < coders || (codersScore == coders && jammersScore < jammers)))) {
				diff = abs;
				coders = codersScore;
				jammers = jammersScore;
			}

		}
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {
		String input = args[0];
		String output = input.replace(".in", ".out");
		StringBuffer sb = new StringBuffer();

		try (BufferedReader br = new BufferedReader(new FileReader(input))) {
			String line = br.readLine();
			int number = Integer.valueOf(line);
			int i = 1;

			while ((line = br.readLine()) != null && i <= number) {
				sb.append(process(line, i++));
				sb.append("\n");
			}
		}

		try (BufferedWriter bw = new BufferedWriter(new FileWriter(output))) {
			bw.append(sb);
		}

		System.out.println("FInished");
	}

	private static String process(String line, int caseNum) {
		StringBuffer sb = new StringBuffer("Case #");
		sb.append(caseNum).append(": ");
		Result result = new Result();
		final String[] splitted = line.split(" ");
		char[] coders = splitted[0].toCharArray();
		char[] jammers = splitted[1].toCharArray();
		final int size = coders.length;

		List<Integer> nulls = new ArrayList<>();
		for (int i = 0; i < size; i++) {
			if (coders[i] == '?')
				nulls.add(i);
			if (jammers[i] == '?')
				nulls.add(size + i);
		}
		Collections.sort(nulls);
		char[] checks = new char[nulls.size()];
		for (int i = 0; i < checks.length; i++) {
			checks[i] = 48;
		}

		int i = 0;
		while (i != checks.length) {
			check(result, jammers, coders, checks, nulls);

			i = 0;
			boolean increasing = true;
			while (increasing && i < checks.length) {
				checks[i]++;
				if (checks[i] == 58) {
					checks[i] = 48;
					i++;
				} else {
					increasing = false;
				}
			}
		}
		String format = "%0" + size + "d";
		sb.append(String.format(format, result.coders)).append(" ").append(String.format(format, result.jammers));
		return sb.toString();
	}

	private static void check(Result result, char[] jammers, char[] coders, char[] checks, List<Integer> nulls) {
		for (Integer n : nulls) {
			int index = nulls.indexOf(n);
			if (n < coders.length) {
				coders[n] = checks[index];
			} else {
				jammers[n - jammers.length] = checks[index];
			}
		}

		result.check(Long.valueOf(String.valueOf(coders)), Long.valueOf(String.valueOf(jammers)));
	}
}
