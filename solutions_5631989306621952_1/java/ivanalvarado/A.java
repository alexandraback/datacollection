




















import java.io.*;
import java.util.*;
import java.math.*;
import java.util.regex.*;
import java.text.*;

public class A {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new File("A-large.in"));

		int cases = scanner.nextInt();
		int n, val, last_val = 0;
		String word, output;


		// Iterate through test cases
		for (int t = 0; t < cases; t++) {
			word = scanner.next();
			output = "";

			for (int j = 0; j < word.length(); j++) {

				if (j == 0) {
					output += word.charAt(j);
					continue;
				}

				if (j > 0) {
					last_val = output.charAt(0);
				}

				val = word.charAt(j);
				if (val >= last_val) {
					output = word.charAt(j) + output;
				} else {
					output += word.charAt(j);
				}
			}

			System.out.printf("Case #%d: %s\n", t+1, output);
		}
	}
}