package pl.mpisarek.gcj2016.round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ProblemA {

	private enum Digit {
		ZERO(0), ONE(1), TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7), EIGHT(8), NINE(9);

		private int dig;

		private List<Character> chars = new ArrayList<Character>();

		private Digit(int dig) {
			this.dig = dig;

			for (int i = 0; i < this.name().length(); i++) {
				chars.add(this.name().charAt(i));
			}
		}

		public boolean find(char[] letters) {
			Set<Integer> positions = new HashSet<>();
			for (Character c : chars) {
				for (int i = 0; i < letters.length; i++) {
					if (c == letters[i]) {
						if (positions.add(i))
							break;
					}
				}
			}

			if (positions.size() == chars.size()) {
				for (Integer pos : positions) {
					letters[pos] = 0;
				}

				return true;
			}

			return false;
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

		List<Integer> result = new ArrayList<>();
		char[] chars;
		int k = 0;
		do {
			chars = line.toCharArray();
			result.clear();
			for (Digit digit : getDigits(k)) {
				while (digit.find(chars)) {
					result.add(digit.dig);
				}
			}
			k++;
		} while (checkLetters(chars));

		Collections.sort(result);

		for (Integer i : result) {
			sb.append(i);
		}
		return sb.toString();
	}

	private static boolean checkLetters(char[] chars) {
		for (char c : chars) {
			if (c != 0)
				return true;
		}

		return false;
	}

	private static Digit[] getDigits(int k) {
		Digit[] result = new Digit[10];

		for (Digit digit : Digit.values()) {
			result[k] = digit;
			if (++k == 10) {
				k = 0;
			}
		}

		return result;
	}
}
