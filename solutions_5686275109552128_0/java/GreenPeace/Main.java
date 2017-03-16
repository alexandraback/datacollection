import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int n = scanner.nextInt();
				int[] values = new int[n];
				int max = 0;
				for (int j = 0; j < n; j++) {
					values[j] = scanner.nextInt();
					max = Math.max(max, values[j]);
				}

				int bestResult = max;
				for (int k = 1; k < max; k++) {
					int current = k;
					for (int j = 0; j < values.length; j++) {
						current += values[j]/k - 1;
						if (values[j] % k != 0) {
							current++;
						}
					}
					bestResult = Math.min(bestResult, current);
				}
				out.write("Case #" + (i + 1) + ": " + bestResult + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}