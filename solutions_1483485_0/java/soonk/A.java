package codejam.qual2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class A {

	char[] input = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z', ' ' };

	char[] outpu = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i',
			'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm',
			'a', 'q', ' ' };

	public A() {

	}

	public String translate(String in) {
		StringBuilder out = new StringBuilder();

		for (char c : in.toCharArray()) {
			int i = Arrays.binarySearch(input, c);

			if (i >= 0) {
				out.append(outpu[i]);
			} else {
				out.append(c);
			}
		}

		return out.toString();
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		A a = new A();

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();

			out.println("Case #" + testCase + ": " + a.translate(line));
		}

		out.flush();
	}

}
