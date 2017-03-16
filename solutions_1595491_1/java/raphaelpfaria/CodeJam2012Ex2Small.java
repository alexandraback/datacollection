import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CodeJam2012Ex2Small {

	public static void main(String arg[]) throws FileNotFoundException {
		File file = new File("B-large.in");
		Scanner scanner = new Scanner(file);
		String output;
		int numTestCases = scanner.nextInt();
		for (int i = 0; i < numTestCases; i++) {
			StringBuffer buffer = new StringBuffer("Case #" + (i + 1) + ": ");
			int N = scanner.nextInt();
			int S = scanner.nextInt();
			int p = scanner.nextInt();
			int[] googlersPoints = new int[N];
			int bestResults = 0;
			for (int j = 0; j < N; j++) {
				googlersPoints[j] = scanner.nextInt();
				if ((googlersPoints[j] >= (p * 3 - 2))){
					bestResults++;

				} else if ((googlersPoints[j] >= (p * 3 - 4))
						 && S > 0 && googlersPoints[j] != 0) {
					
					bestResults++;
					S--;
				}
			}
			buffer.append(bestResults);
			if (i != numTestCases - 1) {
				buffer.append("\n");
			}
			output = buffer.toString();

			System.out.print(output);
		}

	}
}
