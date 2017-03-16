import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream(new FileOutputStream(new File(
				"c-large.out")));
		Scanner in = new Scanner(new File("C-large.in"));

		int T = in.nextInt();

		for (int i = 1; i <= T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();

			int count = 0;

			// boolean[] visited = new boolean[B - A + 1];
			for (int n = A; n <= B; n++) {
				// if (!visited[n]) {
				String origstr = Integer.valueOf(n).toString();
				String str = shift(origstr);
				while (!str.equals(origstr)) {
					int shifted = Integer.parseInt(str);

					// System.out.printf("n: %d, shift: %s, shifted: %d, valid: %b\n",
					// n, str, shifted, shifted > n);

					if (shifted > n && shifted <= B)
						count++;

					str = shift(str);
				}
				// }
			}

			out.printf("Case #%d: %d\n", i, count);
		}

		in.close();
		out.close();
	}

	public static String shift(String num) {
		return num.charAt(num.length() - 1)
				+ num.substring(0, num.length() - 1);
	}
}
