import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

	private static class EnormousNumber {
		private final String digits;

		EnormousNumber(final String digits) {
			this.digits = digits;
		}

		boolean isPalindrome() {
			for (int i = 0; i < digits.length() / 2; i++) {
				if (digits.charAt(i) != digits.charAt(digits.length() - 1 - i)) {
					return false;
				}
			}
			return true;
		}

		EnormousNumber square() {
			final Integer[] vector = new Integer[2 * digits.length() + 1];
			for (int i = 0; i < vector.length; i++) {
				vector[i] = 0;
			}
			int l = 0;
			for (int i = digits.length() - 1; i >= 0; i--) {
				final Integer currentDigit = Integer
						.parseInt(((Character) digits.charAt(i)).toString());
				int rest = 0;
				int k = 0;
				for (int j = digits.length() - 1; j >= 0; j--, k++) {
					final Integer newDigit = Integer
							.parseInt(((Character) digits.charAt(j)).toString());
					int product = currentDigit * newDigit;
					vector[l + k] += rest + product % 10;
					rest = product / 10;
					rest += vector[l + k] / 10;
					vector[l + k] = vector[l + k] % 10;
				}
				while (rest > 0) {
					vector[l + k] = rest % 10;
					rest = rest / 10;
					k++;
				}
				l++;
			}
			String square = "";
			for (l = vector.length - 1; vector[l] == 0; l--)
				;
			for (; l >= 0; l--) {
				square = square + vector[l];
			}
			//System.out.println(digits+"       "+square);
			return new EnormousNumber(square);
		}

		boolean less(final EnormousNumber other) {
			return digits.length() < other.digits.length()
					|| (digits.length() == other.digits.length() && digits
							.compareTo(other.digits) < 0);
		}

		boolean lessEq(final EnormousNumber other) {
			return less(other) || equals(other);
		}

		@Override
		public boolean equals(final Object o) {
			if (o instanceof EnormousNumber) {
				return digits.equals(((EnormousNumber) o).digits);
			}
			return false;
		}

	}

	private static final List<EnormousNumber> allNumbers = new ArrayList<EnormousNumber>();

	public static void main(String[] args) {
		try {
			//solvefromInputToOutPut("test.in", "test.out");
			solvefromInputToOutPut("C-small-attempt0.in", "C-small-attempt0.out");
			//solvefromInputToOutPut("B-large.in", "B-large.out");
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void solvefromInputToOutPut(final String inputFileName,
			final String outputFileName) throws NumberFormatException,
			IOException {
		final BufferedReader reader = new BufferedReader(new FileReader(
				inputFileName));
		final int testCases = Integer.parseInt(reader.readLine());
		final List<String[]> numbers = new ArrayList<String[]>(testCases);
		for (int i = 0; i < testCases; i++) {
			final String[] range = new String[2];
			String[] line = reader.readLine().split(" ");
			range[0] = line[0];
			range[1] = line[1];
			numbers.add(i, range);
		}
		reader.close();
		final List<Integer> result = numberOfFairSquare(numbers);
		final BufferedWriter writer = new BufferedWriter(new FileWriter(
				outputFileName));
		for (int i = 0; i < testCases; i++) {
			writer.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
		}
		writer.close();
	}

	private static List<Integer> numberOfFairSquare(
			final List<String[]> numbers) {
		precalculateAll();
		final List<Integer> result = new ArrayList<Integer>(numbers.size());
		for (int i = 0; i < numbers.size(); i++) {
			result.add(i,
					numberOfFairSquare(numbers.get(i)[0], numbers.get(i)[1]));
		}
		return result;
	}

	private static Integer numberOfFairSquare(final String a, final String b) {
		final EnormousNumber first = new EnormousNumber(a);
		final EnormousNumber last = new EnormousNumber(b);
		Integer result = 0;
		for(EnormousNumber number: allNumbers){
			if( first.lessEq(number) && number.lessEq(last)){
				result++;
			}
		}
		return result;
	}
	
	private static void precalculateAll(){
		allNumbers.add(new EnormousNumber("1"));
		allNumbers.add(new EnormousNumber("4"));
		allNumbers.add(new EnormousNumber("9"));
		for(int i = 2; i < 8; i++){
			precalculate(i);
		}
	}

	private static void precalculate(int n) {
		for (Integer i = 1; i <= 9; i++) {
			precalculate(i.toString(), n);
		}
	}

	private static void precalculate(final String s, int n) {
		if (2 * s.length() == n) {
			final EnormousNumber number = new EnormousNumber(s + revert(s))
					.square();
			if (number.isPalindrome()) {
				allNumbers.add(number);
			}
		} else if (s.length() == n / 2) {
			for (int i = 0; i <= 9; i++) {
				final EnormousNumber number = new EnormousNumber(s + i
						+ revert(s)).square();
				if (number.isPalindrome()) {
					allNumbers.add(number);
				}
			}
		} else {
			for (int i = 0; i <= 9; i++) {
				precalculate(s + i, n);
			}
		}
	}

	private static String revert(final String s) {
		String result = "";
		for (int i = 0; i < s.length(); i++) {
			result = s.charAt(i) + result;
		}
		return result;
	}

	/*
	 * (non-Java-doc)
	 * 
	 * @see java.lang.Object#Object()
	 */
	public Main() {
		super();
	}

}