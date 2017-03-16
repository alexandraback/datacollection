import java.io.*;
import java.util.*;

public class R1BA {
	public static void main(String[] args) throws Exception {
		final String[] names = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

		Scanner scan = new Scanner(System.in);
		int nCases = scan.nextInt();
		for (int z = 0; z < nCases; z++) {
			String s = scan.next();

			int[] counts = new int[26];
			for (int i = 0; i < s.length(); i++) {
				counts[s.charAt(i) - 'A']++;
			}

			int[] digits = new int[10];
			digits[0] = counts['Z' - 'A'];
			digits[2] = counts['W' - 'A'];
			digits[4] = counts['U' - 'A'];
			digits[6] = counts['X' - 'A'];
			digits[8] = counts['G' - 'A'];
			for (int d = 0; d <= 8; d += 2) {
				String name = names[d];
				for (int i = 0; i < name.length(); i++) {
					counts[name.charAt(i) - 'A'] -= digits[d];
				}
			}
			digits[1] = counts['O' - 'A'];
			digits[3] = counts['T' - 'A'];
			digits[5] = counts['F' - 'A'];
			digits[7] = counts['S' - 'A'];
			for (int d = 1; d <= 7; d += 2) {
				String name = names[d];
				for (int i = 0; i < name.length(); i++) {
					counts[name.charAt(i) - 'A'] -= digits[d];
				}
			}
			digits[9] = counts['E' - 'A'];

			StringBuilder answer = new StringBuilder();
			for (int d = 0; d < 10; d++) {
				char digit = (char)('0' + d);
				for (int i = 0; i < digits[d]; i++) {
					answer.append(digit);
				}
			}
			System.out.printf("Case #%d: %s\n", z + 1, answer.toString());
		}
		scan.close();
	}
}
