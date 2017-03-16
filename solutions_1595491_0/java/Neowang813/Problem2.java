import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Problem2 {
	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "B-small-attempt0.in";
		Scanner inputScanner = new Scanner(new FileInputStream("d:\\input\\"
				+ inputFile));
		PrintStream ps = new PrintStream(new FileOutputStream(
				"d:\\output\\pro2.txt"));
		int totalCaseNum = inputScanner.nextInt();
		inputScanner.nextLine();
		// -----------------------------------------------

		// -----------------------------------------------
		for (int caseNum = 1; caseNum <= totalCaseNum; caseNum++) {
			String line = inputScanner.nextLine();
			String prefix = "Case #" + caseNum + ": ";
			StringBuilder output = new StringBuilder(prefix);
			// -----------------------------------------------

			Scanner in = new Scanner(line);
			int N = in.nextInt();
			int S = in.nextInt();
			int P = in.nextInt();
			int[] T = new int[N];

			int count = 0;

			if (0 == P) {
				count = N;
			} else {
				int minScore = Math.max(0, (P - 2)) * 2 + P;
				int maxScore = Math.max(0, (P - 1) * 3);
				for (int i = 0; i < T.length; i++) {
					int ti = in.nextInt();
					if (ti > maxScore) {
						count++;
						continue;
					}
					if (ti < minScore) {
						continue;
					}
					if (S > 0 && 2 <= ti && ti <= 28) {
						count++;
						S--;
					}

				}
			}
			output.append(count);
			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}
}
