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
				int n = scanner.nextInt();
				if (n == 0) {
					out.write("Case #" + (i + 1) + ": INSOMNIA\n");
					continue;
				}
				int k = n;
				Set<Integer> digits = new HashSet<>();
				while(true) {
					int remainder = k;
					while(remainder != 0) {
						digits.add(remainder % 10);
						remainder /= 10;
					}
					if (digits.size() == 10) {
						break;
					}
					k += n;
				}
				out.write("Case #" + (i + 1) + ": " + k + "\n");
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
}