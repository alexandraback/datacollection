import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;
import java.util.function.LongToIntFunction;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new FileInputStream("input.txt"))){
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int k = scanner.nextInt();
				int c = scanner.nextInt();
				int s = scanner.nextInt();
				if (s*c < k) {
					out.write("Case #" + (i + 1) + ":IMPOSSIBLE\n");
				}
				else {
					out.write("Case #" + (i + 1) + ":");
					int digit = 0;
					for (int j = 0; j < s; j++) {
						long number = 0;
						for (int counter = 0; counter < c; counter++) {
							number = number*k;
							if (digit < k) {
								number += digit;
							}
							digit++;
						}
						number++;
						out.write(" " + number);
						if (digit >= k) {
							break;
						}
					}
					out.write("\n");
				}
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}