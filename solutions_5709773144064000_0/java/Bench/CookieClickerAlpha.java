import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CookieClickerAlpha {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = scanner.nextInt();
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		for (int trial = 1; trial <= T; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			try {
				solveTrial(scanner, writer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				writer.write("\n");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		double C = scanner.nextDouble();
		double F = scanner.nextDouble();
		double X = scanner.nextDouble();

		int n = Math.max((int) Math.ceil(X / C - 2 / F) - 1, 0);
		double sum = 0;
		for (int i = 0; i < n; i++)
			sum += C/ (2.0 + i * F);
		writer.write("" + (sum + X / (2 + n * F)));
		//System.out.println("n=" + n);
	}
}
