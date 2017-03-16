import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.HashSet;

public class Palindrome {

	public static void main(String[] args) throws Exception {
		Palindrome object = new Palindrome();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			long a = Long.parseLong(st.sval);

			st.nextToken();
			long b = Long.parseLong(st.sval);

			int output = object.solve(a, b);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private int solve(long a, long b) {

		for (int i = 1; i <= 7; i++) {
			generate(i, 0, new int[i]);
		}

		int counter = 0;

		for (Long pal : palindromes) {
			long square = pal * pal;

			if (a <= square && square <= b)
				if (checkPal(String.valueOf(square))) {
					counter++;
				}
		}

		return counter;
	}

	public static boolean checkPal(String string) {
		int length = string.length();
		for (int i = 0; i < string.length() / 2; i++) {
			if (string.charAt(i) != string.charAt(length - i - 1))
				return false;
		}

		return true;
	}

	public HashSet<Long> palindromes = new HashSet<Long>();

	public void generate(int digits, int pp, int[] set) {

		if (pp >= digits) {

			long gen = 0;

			for (int z = 0; z < digits; z++) {
				gen *= 10L;
				gen += set[z];
			}

			palindromes.add(gen);
			return /* void */;
		}

		if (pp >= (digits + 1) / 2) {
			set[pp] = set[digits - pp - 1];
			generate(digits, pp + 1, set);
			return;
		}

		if (pp == 0) {
			for (int i = 1; i <= 9; i++) {
				set[pp] = i;
				generate(digits, pp + 1, set);
			}

			return;
		}

		for (int i = 0; i <= 9; i++) {
			set[pp] = i;
			generate(digits, pp + 1, set);
		}
	}
}
