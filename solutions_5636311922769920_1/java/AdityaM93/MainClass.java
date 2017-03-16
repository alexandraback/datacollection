package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class MainClass {

	public static String trivialSolution(int k, int c) {
		String solution = "1";
		for (int i = 2; i <= k; i++)
			solution += " " + i;
		return solution;
	}

	public static String nonTrivialSolution(int k, int c, int s) {
		String solution = "";
		int min = (int) Math.ceil((double)k / (double)c);
		if (s < min)
			return "IMPOSSIBLE";
		int[][] structure = new int[min][c];
		int counter = 1;
		for (int i = 0; i < min && counter <= k; i++)
			for (int j = 0; j < c && counter <= k; j++)
				structure[i][j] = counter++;
		for (int i = 0; i < min; i++) {
			BigInteger offset = BigInteger.valueOf(1);
			for (int j = 0; j < c; j++) 
				if(structure[i][j] != 0){
				offset = offset
						.add(BigInteger.valueOf(structure[i][j] - 1).multiply(BigInteger.valueOf(k).pow(j)));
			}
			solution += offset + " ";
		}
		return solution.trim();
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
			out.println("Case #" + cT + ": " + nonTrivialSolution(k, c, s));
		}
		in.close();
		out.close();
	}

}
