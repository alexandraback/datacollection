import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
	public static void main(String[] args) {
		String filename = "src/A-large.in";
		String output = "output.txt";
		Scanner scanner = null;
		PrintWriter printer = null;

		try {
			scanner = new Scanner(new FileReader(filename));
			printer = new PrintWriter(new FileWriter(output));

			int tests = scanner.nextInt();
			for (int test = 1; test <= tests; test++) {

				Set<Character> digits = new HashSet<>();
				long value = scanner.nextLong();

				if (value == 0) {
					printer.println(String.format("Case #%d: %s", test, "INSOMNIA"));
				} else {
					long last = 0;
					for (int i = 1; digits.size() < 10; i++) {
						last = value * i;
						String str = String.valueOf(last);
						char[] strArr = str.toCharArray();
						addAll(digits, strArr);
					}
					printer.println(String.format("Case #%d: %d", test, last));
				}
			}

		} catch (FileNotFoundException e) {
			System.out.println(filename + " not found.");
		} catch(IOException e) {
			System.out.println(e.getMessage());
		} finally {
			if (scanner != null) {
				scanner.close();
			}
			if (printer != null) {
				printer.flush();
				printer.close();
			}
		}
	}

	private static void addAll(Set<Character> set, char[] input) {
		for (char c : input) {
			set.add(c);
		}
	}
}
