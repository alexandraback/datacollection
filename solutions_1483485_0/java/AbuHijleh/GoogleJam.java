package com.abuhijleh.googlejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GoogleJam {
	static final String code = "yhesocvxduiglbkrztnwjpfmaq";

	public static void main(String[] args) {
		File input = new File("inputFile");
		File output = new File("outputFile");
		Scanner scan;
		try {
			scan = new Scanner(input);
			String[] decodedCases = new String[scan.nextInt()];
			scan.nextLine();
			for (int i = 0; i < decodedCases.length; i++)
				decodedCases[i] = "Case #" + (i + 1) + ": "
						+ decode(scan.nextLine());
			System.out.println("Output");
			for (int i = 0; i < decodedCases.length; i++)
				System.out.println(decodedCases[i]);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String decode(String nextLine) {
		String decoded = "";
		for (int i = 0; i < nextLine.length(); i++) {
			int index = Character.toLowerCase(nextLine.charAt(i)) - 'a';
			if (index >= 0 && index < code.length())
				decoded += code.charAt(index);
			else
				decoded += nextLine.charAt(i);
		}
		return decoded;
	}
}
