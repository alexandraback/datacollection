import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter("A-small-attempt0.out");

		int T = Integer.parseInt(in.nextLine());

		for (int cn = 1; cn <= T; cn++) {
			String s = in.nextLine().trim().toUpperCase();
			int[] counts = new int[26];
			for (int i = 0; i < s.length(); i++)
				counts[ind(s.charAt(i))]++;

			int[] number = new int[10];
			while (counts[ind('G')] > 0) {
				decrement(counts, "EIGHT");
				number[8]++;
			}
			while (counts[ind('Z')] > 0) {
				decrement(counts, "ZERO");
				number[0]++;
			}
			while (counts[ind('W')] > 0) {
				decrement(counts, "TWO");
				number[2]++;
			}
			while (counts[ind('U')] > 0) {
				decrement(counts, "FOUR");
				number[4]++;
			}
			while (counts[ind('X')] > 0) {
				decrement(counts, "SIX");
				number[6]++;
			}
			while (counts[ind('F')] > 0) {
				decrement(counts, "FIVE");
				number[5]++;
			}
			while (counts[ind('O')] > 0) {
				decrement(counts, "ONE");
				number[1]++;
			}
			while (counts[ind('H')] > 0) {
				decrement(counts, "THREE");
				number[3]++;
			}
			while (counts[ind('V')] > 0) {
				decrement(counts, "SEVEN");
				number[7]++;
			}
			while (counts[ind('N')] > 0) {
				decrement(counts, "NINE");
				number[9]++;
			}

			out.printf("Case #%d: ", cn);
			for (int i = 0; i < number.length; i++)
				for (int j = 0; j < number[i]; j++)
					out.print(i);
			out.println();
		}

		out.close();
		in.close();
	}

	private static int ind(char c) {
		return (int) (c - 'A');
	}

	private static void decrement(int[] arr, String s) {
		for (char c : s.toCharArray()) {
			arr[ind(c)]--;
		}
	}
}
