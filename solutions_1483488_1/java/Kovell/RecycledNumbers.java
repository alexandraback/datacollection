package codeJam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class RecycledNumbers {
	private static int inputLength = 1;

	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "RecycledNumbers/input.txt";
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
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"RecycledNumbers/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}


	public static String runTest(String input) {
		boolean[] found = new boolean[2000000];
		Scanner sc = new Scanner(input);
		int lowest = sc.nextInt();
		int highest = sc.nextInt();
		int recycled = 0;
		int length = 0;
		long current = 0;
		int inRange = 0;
		ArrayList<Integer> permutations = new ArrayList<Integer>();
		for (long i = lowest; i <= highest; i++) {
			if(found[(int)i] == true) {
				continue;
			}
			length = getLength(i);
			permutations.clear();
			current = i;
			inRange = 1;
			found[(int)current] = true;
			while (rotate(current, length) != i) {
				current = rotate(current, length);
				if (current <= highest && current >= lowest) {
					inRange++;
					found[(int)current] = true;
				}
			}
			recycled += combinations(inRange);
		}
		
		return String.valueOf(recycled);
	}
	
	public static long rotate(Long in, int length) {
		if (length < 2) {
			return in;
		}
		return in / 10 + ((in % 10) * (int)(java.lang.Math.pow(10.0, (double)length - 1)));
		
	}
	public static int getLength(Long in) {
		return (int)java.lang.Math.floor(java.lang.Math.log10((double)in))+ 1;
	}
	public static int combinations(int count) {
		if (2 == count) {
			return 1;
		}

		// We don't go high enough to worry about overflow (< 8)
		long answer = 1;
		for (int i = count - 2 + 1; i <= count; i++) {
			answer = answer * i;
		}
		for (int j = 2; j > 1; j--) {
			answer = answer / j;
		}
		return (int)answer;
	}
	
}
