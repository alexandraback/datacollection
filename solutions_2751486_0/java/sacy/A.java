package codejam.R1C2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public void solve() throws IOException {
		System.out.println("Started...");
		String fileName = "A-small-attempt0";
		BufferedReader fileReader = new BufferedReader(new FileReader(
				"C:\\dev\\workspace-sts\\Contests\\src\\codejam\\R1C2013\\"
						+ fileName + ".in"));
		BufferedWriter fileWriter = new BufferedWriter(new FileWriter(
				"C:\\dev\\workspace-sts\\Contests\\src\\codejam\\R1C2013\\"
						+ fileName + ".out"));

		long T = Long.parseLong(fileReader.readLine());
		for (long testNum = 0; testNum < T; testNum++) {
			// Input
			String input = fileReader.readLine();
			Scanner scanner = new Scanner(input);
			StringBuilder name = new StringBuilder(scanner.next());
			int L = name.length();
			int n = Integer.parseInt(scanner.next());

			int answer = 0;
			for (int i = 0; i < L; i++) {
				for (int j = i + 1; j <= L; j++) {
//					String substring = name.substring(i, j);
//					System.out.println(name.substring(i, j));
					int consCount = 0;
					for (int k = i; k < j; k++) {
						if (isCons(name.charAt(k))) {
							consCount++;
							if (consCount == n) {
								answer++;
//								 System.out.println(name.substring(i, j));
								break;
							}
						} else {
							consCount = 0;
						}
					}
				}
			}

			fileWriter.write("Case #" + (testNum + 1) + ": " + answer + "\n");
		}
		// Close streams
		fileReader.close();
		fileWriter.flush();
		fileWriter.close();
		System.out.println("Done.");
	}

	private boolean isCons(char c) {
		// a, e, i, o, and u
		if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
			return true;
		}
		return false;
	}

	private boolean check(String substring, int n) {

		return false;
	}

	public static void main(String[] args) throws IOException {
		new A().solve();
	}

}
