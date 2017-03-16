package gcj1C;

import java.io.*;
import java.util.*;

public class A {
	static PrintWriter writer;
	static Scanner sc;

	public static void main(String[] args) throws FileNotFoundException {
		writer = new PrintWriter("output");
		solveAllTests();
		writer.close();
		sc.close();
	}

	private static void solveAllTests() throws FileNotFoundException {
		sc = new Scanner(new File("input"));
		int nbTest = sc.nextInt();
		for (int i = 1; i <= nbTest; i++) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int W = sc.nextInt();
			int res = solveOneTest(R, C, W);
			writer.println("Case #" + i + ": " + res);
		}
	}

	private static int solveOneTest(int r, int c, int w) {
		int beforeFirstTouched = r * c / w;
		int remainingShot;
		if (c % w == 0) {
			remainingShot = w - 1;
		} else {
			remainingShot = w;
		}
		return beforeFirstTouched + remainingShot;
	}
}