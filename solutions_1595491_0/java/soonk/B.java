package codejam.qual2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class B {

	public int count(int target, int surprise, int[] scores) {

		int a = target;
		int b = target - 1;
		int c = target - 2;

		if (b < 0)
			b = 0;
		if (c < 0)
			c = 0;

		int good = a + b + b;
		int goodWSurprize = a + c + c;

		int count = 0;

		for (int i : scores) {
			if (i >= good) {
				count++;
			} else if (i >= goodWSurprize && surprise > 0) {
				count++;
				surprise--;
			}
		}

		return count;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		B b = new B();

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();
			String[] data = line.split(" ");

			int target = Integer.parseInt(data[2]);
			int surprise = Integer.parseInt(data[1]);
			int[] scores = new int[data.length - 3];

			for (int i = 3; i < data.length; i++) {
				scores[i - 3] = Integer.parseInt(data[i]);
			}

			out.println("Case #" + testCase + ": "
					+ b.count(target, surprise, scores));
		}

		out.flush();
	}

}
