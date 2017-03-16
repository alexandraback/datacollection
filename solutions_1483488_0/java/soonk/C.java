package codejam.qual2012;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;

public class C {

	public int count(int start, int end) {
		int count = 0;

		for (int i = start; i <= end; i++) {
			String a = Integer.toString(i);

			Set<String> unique = new HashSet<String>();

			String b = a;
			for (int j = 0; j < a.length() - 1; j++) {
				b = b.substring(a.length() - 1, a.length())
						+ b.substring(0, a.length() - 1);

				if (unique.contains(b)) {
					continue;
				} else {
					unique.add(b);
				}

				// System.out.println(b);

				int bi = Integer.parseInt(b);
				if (bi > i && bi <= end) {
					// System.out.println(a + ": " + b);
					count++;
				}
			}

		}

		return count;
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));

		String line = in.readLine();
		int testCases = Integer.parseInt(line);

		C c = new C();

		// Read in all test cases
		for (int testCase = 1; testCase <= testCases; testCase++) {
			line = in.readLine();
			String[] data = line.split(" ");

			int start = Integer.parseInt(data[0]);
			int end = Integer.parseInt(data[1]);

			out.println("Case #" + testCase + ": " + c.count(start, end));
		}

		out.flush();
	}
}
