

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Using the Google Collections library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-large.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int c = 1; c <= cases; c++) {
			int a = in.nextInt();
			int b = in.nextInt();
			double [] p = new double[a];
			for (int i = 0; i < a; i++)
				p[i] = in.nextDouble();
			// enter right away
			double minKeyStrokes = 2 + b;
			double pCorrect = 1;
			for (int i = 0; i <= a; i++) {
				double expected = pCorrect * (a - i + b - i + 1) + (1 - pCorrect) * (b + 2 + a - i + b - i);
				if (i < a)
					pCorrect *= p[i];
//				System.out.println(i + " " + expected);
				minKeyStrokes = Math.min(minKeyStrokes, expected);
			}
			
			out.print("Case #"+c+": " + String.format("%.6f", minKeyStrokes));
			out.println();
		}
		out.close();
	}
}
