package codejam.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Digits {

	private static final String FILE = "C:\\temp\\A-small-attempt0";

	//////////////////////////////////////////////////
	public static void remove(Map<Character, Integer> letters, char c, int count) {
		Integer cc = letters.get(c);
		if (cc == count) {
			letters.remove(c);
			return;
		}
		letters.put(c, cc - count);
	}

	//////////////////////////////////////////////////
	public static void main(String[] args) throws Exception {

		Scanner in = null;
		PrintStream out = null;

		try {

			in = new Scanner(new BufferedReader(new FileReader(new File(FILE + ".in"))));
			out = new PrintStream(new File(FILE + ".out"));

			// in = new Scanner(new BufferedReader(new
			// InputStreamReader(System.in)));
			// out = System.out;

			int t = in.nextInt();
			// Finish the line.
			in.nextLine();
			for (int i = 1; i <= t; ++i) {
				String s = in.nextLine();
				Map<Character, Integer> letters = new HashMap<>();
				for (int j = 0; j < s.length(); j++) {
					char c = s.charAt(j);
					Integer count = letters.get(c);
					letters.put(c, count == null ? 1 : count + 1);
				}
				int[] digits = new int[10];
				// zero
				Integer count = letters.get('Z');
				if (count != null) {
					digits[0] = count;
					remove(letters, 'Z', count);
					remove(letters, 'E', count);
					remove(letters, 'R', count);
					remove(letters, 'O', count);
				}
				// two
				count = letters.get('W');
				if (count != null) {
					digits[2] = count;
					remove(letters, 'T', count);
					remove(letters, 'W', count);
					remove(letters, 'O', count);
				}
				// four
				count = letters.get('U');
				if (count != null) {
					digits[4] = count;
					remove(letters, 'F', count);
					remove(letters, 'O', count);
					remove(letters, 'U', count);
					remove(letters, 'R', count);
				}
				// six
				count = letters.get('X');
				if (count != null) {
					digits[6] = count;
					remove(letters, 'S', count);
					remove(letters, 'I', count);
					remove(letters, 'X', count);
				}
				// eight
				count = letters.get('G');
				if (count != null) {
					digits[8] = count;
					remove(letters, 'E', count);
					remove(letters, 'I', count);
					remove(letters, 'G', count);
					remove(letters, 'H', count);
					remove(letters, 'T', count);
				}
				// eight
				count = letters.get('G');
				if (count != null) {
					digits[8] = count;
					remove(letters, 'E', count);
					remove(letters, 'I', count);
					remove(letters, 'G', count);
					remove(letters, 'H', count);
					remove(letters, 'T', count);
				}
				// one
				count = letters.get('O');
				if (count != null) {
					digits[1] = count;
					remove(letters, 'O', count);
					remove(letters, 'N', count);
					remove(letters, 'E', count);
				}
				// three
				count = letters.get('T');
				if (count != null) {
					digits[3] = count;
					remove(letters, 'T', count);
					remove(letters, 'H', count);
					remove(letters, 'R', count);
					remove(letters, 'E', count);
					remove(letters, 'E', count);
				}
				// five
				count = letters.get('F');
				if (count != null) {
					digits[5] = count;
					remove(letters, 'F', count);
					remove(letters, 'I', count);
					remove(letters, 'V', count);
					remove(letters, 'E', count);
				}
				// seven
				count = letters.get('S');
				if (count != null) {
					digits[7] = count;
					remove(letters, 'S', count);
					remove(letters, 'E', count);
					remove(letters, 'V', count);
					remove(letters, 'E', count);
					remove(letters, 'N', count);
				}
				// nine
				count = letters.get('I');
				if (count != null) {
					digits[9] = count;
					remove(letters, 'N', count);
					remove(letters, 'I', count);
					remove(letters, 'N', count);
					remove(letters, 'E', count);
				}
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < digits.length; j++) {
					for (int j2 = 0; j2 < digits[j]; j2++) {
						sb.append(j);
					}
				}
				out.println("Case #" + i + ": " + sb.toString());
			}
		} finally {
			if (in != null) {
				in.close();
			}
			if (out != null) {
				out.close();
			}
		}
	}
}
