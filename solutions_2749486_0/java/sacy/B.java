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

public class B {

	public void solve() throws IOException {
		System.out.println("Started...");
		String fileName = "B-small-attempt0";
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
			int OX = Integer.parseInt(scanner.next());
			int OY = Integer.parseInt(scanner.next());
			int X = Math.abs(OX);
			int Y = Math.abs(OY);

			StringBuilder answer = new StringBuilder();
			for (int i = 0; i < X; i++) {
				answer.append(OX < 0 ? "EW" : "WE");
			}
			for (int i = 0; i < Y; i++) {
				answer.append(OY < 0 ? "NS" : "SN");
			}

			fileWriter.write("Case #" + (testNum + 1) + ": " + answer + "\n");
		}
		// Close streams
		fileReader.close();
		fileWriter.flush();
		fileWriter.close();
		System.out.println("Done.");
	}

	public static void main(String[] args) throws IOException {
		new B().solve();
	}

}
