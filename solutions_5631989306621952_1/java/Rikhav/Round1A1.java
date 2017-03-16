import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Round1A1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			String s1 = in.next();
			String s2 = getLastWord(s1);
			System.out.println("Case #" + i + ": " + s2);

		}
		in.close();
	}

	public static String getLastWord(String input) {
		String output = "";
		for (int i = 0; i < input.length(); i++) {
			if (output.equals("")) {
				output = output + input.charAt(i);
			} else {
				if ((int) output.charAt(0) > (int) input.charAt(i)) {
					output = output + input.charAt(i);
				} else {
					output = input.charAt(i) + output;
				}

			}
		}
		return output;
	}

}
