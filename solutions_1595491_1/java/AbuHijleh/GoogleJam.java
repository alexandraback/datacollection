package com.abuhijleh.googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GoogleJam {
	static final String code = "yhesocvxduiglbkrztnwjpfmaq";

	public static void main(String[] args) {
		File input = new File("inputFile");
		String[] result;
		Scanner scan;
		try {
			scan = new Scanner(input);
			result = new String[scan.nextInt()];
			scan.nextLine();
			for (int i = 0; i < result.length; i++) {
				int N, S, P;
				int[] val;
				N = scan.nextInt();
				S = scan.nextInt();
				P = scan.nextInt();
				val = new int[N];
				for (int j = 0; j < val.length; j++)
					val[j] = scan.nextInt();
				scan.nextLine();
				result[i] = "Case #" + (i + 1) + ": " + solve(S, P, val);
			}
			System.out.println("Output");
			for (int i = 0; i < result.length; i++)
				System.out.println(result[i]);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static int solve(int s, int p, int[] val) {
		int count = 0;
		for (int i = 0; i < val.length; i++) {
			if ((val[i] - p) >= 0)
				if (((val[i] - p) / 2) < (p - 1)) {
					if (s > 0 && (((val[i] - p) / 2)+2) >= p) {
						s--;
						count++;
					}
				} else
					count++;
		}
		return count;
	}
}
