import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		try {
			// so eclipse can read file from system in
			System.setIn(new FileInputStream(new File("small.in")));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		Scanner scanner = new Scanner(System.in);
		long T = scanner.nextLong();
		scanner.nextLine();
		for (int i = 0; i < T; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			scanner.nextLine();
			double prob[] = new double[A];
			double cum[] = new double[A];
			for (int j = 0; j < A; j++) {
				prob[j] = scanner.nextDouble();
				if (j > 0) {
					cum[j] = cum[j - 1] * prob[j];
				} else {
					cum[j] = prob[j];
				}
			}
			int charactersLeft = B - A + 1;
			double typing = cum[A - 1] * charactersLeft + (1 - cum[A - 1]) * (charactersLeft + B + 1);
			double enter =  1+ B + 1;
			double best = Math.min(typing, enter);
			for (int j = 1; j < A - 1; j++) {
				double backspace = cum[A - j - 1] * (j + charactersLeft + j) + (1 - cum[A - j - 1]) * (j + charactersLeft + j + B + 1);
				best = Math.min(best,  backspace);
			}
			System.out.printf("Case #%d: %.6f%n", i + 1, best);
			if (scanner.hasNext()) {
				scanner.nextLine();
			}
		}

	}

}
