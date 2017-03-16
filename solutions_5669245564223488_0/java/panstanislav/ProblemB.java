import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {

	final static int ALPHABET_SIZE = 'z' - 'a' + 1;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

		int T = sc.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
			int N = sc.nextInt();
			String[] cars = new String[N];
			for (int i = 0; i < N; i++) {
				cars[i] = sc.next();
			}
			boolean used[] = new boolean[cars.length];
			printAnswer(out, testCase, "" + countVariants("", cars, used, 0));
		}

		out.close();
	}

	private static long countVariants(String current, String[] cars, boolean[] used, int usedCount) {
		if(usedCount == used.length)
			return 1;
		long sum = 0;
		for (int i = 0; i < cars.length; i++) {
			if (used[i])
				continue;
			used[i] = true;
			String variant = current + cars[i];
			if (isValidTrain(variant)) {
				sum += countVariants(variant, cars, used, usedCount + 1);
			}
			used[i] = false;
		}
		return sum;
	}

	private static int indexOfChar(char character) {
		return character - 'a';
	}

	private static boolean isValidTrain(String string) {
		boolean[] chars = new boolean[ALPHABET_SIZE];
		char current = string.charAt(0);
		chars[indexOfChar(current)] = true;
		for (int i = 1; i < string.length(); i++) {
			char item = string.charAt(i);
			if (item == current)
				continue;
			if (chars[indexOfChar(item)])
				return false;
			current = item;
			chars[indexOfChar(item)] = true;
		}
		return true;
	}

	private static void printAnswer(PrintWriter printer, int testCase, String answer) {
		System.out.println("Case #" + testCase + ": " + answer);
		printer.println("Case #" + testCase + ": " + answer);
	}

}
