package Q;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		// String input = "B-small-attempt0.in";
		// String output = "B-small-attempt0.out";
		String input = "B-large.in";
		String output = "B-large.out";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			int D = Integer.parseInt(scan.nextLine());
			String[] info = scan.nextLine().split(" ");
			int[] P = new int[D];
			for (int i = 0; i < D; i++)
				P[i] = Integer.parseInt(info[i]);
			int min = 1000;
			for (int left = 1; left <= 1000; left++) {
				int special = 0;
				for (int i = 0; i < D; i++)
					special += (P[i] - 1) / left;
				min = Math.min(min, left + special);
			}
			pw.println("Case #" + t + ": " + min);
		}

		scan.close();
		pw.close();
	}

}
