package codeJam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class SpeakTongues {
	private static int inputLength = 1;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "SpeakTongues/input.txt";
		if (args.length > 0) {
			filename = args[0];
		}
		
		try {
			Scanner sc = new Scanner (new File(filename));
		
			String input;
			int testCount = Integer.parseInt(sc.nextLine());
			String out = "";
			
			// Split the input into separate tests and collect the output.
			for (int i = 0; i < testCount; i++) {
				input = "";
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i+1) + ": ";
				out += runTest(input);
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"SpeakTongues/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}


	/**
	 * Compares the input to a conversion array generated from the question's
	 * example. Returns the converted text.
	 * 
	 * @param input
	 * @return 
	 */
	public static String runTest(String input) {
		// Use the conversion table given in the question
		// googlerese to english
		char[] conversions = new char[255];
		conversions['a'] = 'y';
		conversions['b'] = 'h';
		conversions['c'] = 'e';
		conversions['d'] = 's';
		conversions['e'] = 'o';
		conversions['f'] = 'c';
		conversions['g'] = 'v';
		conversions['h'] = 'x';
		conversions['i'] = 'd';
		conversions['j'] = 'u';
		conversions['k'] = 'i';
		conversions['l'] = 'g';
		conversions['m'] = 'l';
		conversions['n'] = 'b';
		conversions['o'] = 'k';
		conversions['p'] = 'r';
		conversions['q'] = 'z';
		conversions['r'] = 't';
		conversions['s'] = 'n';
		conversions['t'] = 'w';
		conversions['u'] = 'j';
		conversions['v'] = 'p';
		conversions['w'] = 'f';
		conversions['x'] = 'm';
		conversions['y'] = 'a';
		conversions['z'] = 'q';
		

		String output = "";
		for (int i = 0; i < input.length(); i++) {
			if (input.charAt(i) < 'a' || input.charAt(i) > 'z') {
				output += input.charAt(i);
			} else {
				output += conversions[input.charAt(i)];
			}
		}
		return output;
		
	}
}
