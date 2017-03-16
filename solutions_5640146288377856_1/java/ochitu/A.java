package jam1a15;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {
//	private static final String FILE = "A-small-attempt0";
	private static final String FILE = "A-large";
	

	public static void main(String[] args) throws IOException {
		new A().start();
	}

	private void start() throws IOException {
		Scanner scanner = new Scanner(new File(FILE + ".in"));
		BufferedWriter writer = new BufferedWriter(
				new FileWriter(FILE + ".out"));
		int tests = scanner.nextInt();

		for (int i = 0; i < tests; i++) {
			String result = "Case #" + (i + 1) + ": " + runTest(scanner);
			System.out.println(result);
			writer.write(result + "\n");
		}

		writer.close();
		scanner.close();
	}

	private String runTest(Scanner scanner) {
		int r = scanner.nextInt();
		int c = scanner.nextInt();
		int w = scanner.nextInt();
		
		int count = 0;
		for (int i = 0; i < r; i++) {
			count += c / w;
		}
		//daca se imparte exact la w atunci mai adaugi w-1 si iesi
		if (c % w ==0) {
			count += w-1;
			return count + "";
		}
		
		count += w;
		return count + "";
	}
}
