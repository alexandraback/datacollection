package cz.phx.gcj2014.round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TaskB {

	private final int t;

	public TaskB(String inFile, String outFile) throws IOException {
		Scanner scanner = new Scanner(new File(inFile));

		FileWriter fw = new FileWriter(outFile);
		BufferedWriter writer = new BufferedWriter(fw);

		t = scanner.nextInt();

		for (int i = 0; i < t; i++) {
			processOne(i + 1, scanner, writer);
		}

		scanner.close();
		writer.close();
	}

	private void processOne(int T, Scanner scanner, BufferedWriter writer) throws IOException {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int K = scanner.nextInt();

		int result = 0;
		if (A > B) {
			int temp = A;
			A = B;
			B = temp;
		}
		for (int a = 0; a < A; a++) {
			for (int b = a; b < B; b++) {
//				System.out.println(a + " & " + b + " = " + (a&b));
				if ((b & a) < K) {
//					System.out.println(true);
					result++;

					if (b < A && a < B && a != b) {
						result++;
//						System.out.println(true);
					}
				}
			}
		}

		writer.write("Case #"+T+": "+result+"\n");
		System.out.println("Case #"+T+": "+result);

	}

	public static void main(String[] args) throws IOException{
//		String fileName = "B-test.in";
		String fileName = "B-small-attempt1.in";
//		String fileName = "B-large";
		new TaskB(fileName, fileName + ".out");
	}

}
