package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class MainClass {

	public static String trivialSolution(int k, int c) {
		String solution = "1";
		for(int i = 2;i<= k; i++)
			solution += " " + i;
		return solution;
	}

	public static void main(String[] args) throws FileNotFoundException {

		File fin = new File("input.in");
		File fout = new File("output.out");

		Scanner in = new Scanner(fin);
		PrintWriter out = new PrintWriter(fout);

		int T = in.nextInt();
		int k, c, s;

		for (int cT = 1; cT <= T; cT++) {
			k = in.nextInt();
			c = in.nextInt();
			s = in.nextInt();
			if (k != s)
				System.out.println("Shit!");

			out.println("Case #" + cT + ": " + trivialSolution(k, c));
		}
		in.close();
		out.close();
	}

}
