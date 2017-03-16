package round1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class P1 {
	static Scanner sc;
	static FileWriter fw;
	static DecimalFormat format = new DecimalFormat("0.000000");   

	public static void main(String[] args) throws IOException {
		sc = new Scanner(new FileReader("A-large.in"));
		fw = new FileWriter("out.txt");
		int t = sc.nextInt();
		for (int c = 1; c <= t; ++c) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			for (int i = 0; i < A; ++i)
				p[i] = sc.nextDouble();

			double min = B + 2.0;
			int index = 0;
			for (int i = 0; i <= A; ++i) {
				int right = B - A + 2 * i + 1;
				int wrong = right + B + 1;
				double correct = 1.0;
				for (int j = 0; j < A - i; ++j)
					correct *= p[j];
				double error = 1.0 - correct;

				double expected = (double) right * correct + (double) wrong
						* error;
				if (expected < min)
					min = expected;
			}
			fw.append("Case #" + c + ": " + format.format(min) + "\n");
		}
		sc.close();
		fw.close();
	}
}
