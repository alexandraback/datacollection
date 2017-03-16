package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class BoxFactory {

	private static int inputLength = 3;
	
	private static long[][] boxes;
	private static long[][] toys;

	private static ArrayList<ArrayList> lists;
	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) {
		String filename = "BoxFactory/input.txt";
		if (args.length > 0) {
			filename = args[0];
		}

		try {
			Scanner sc = new Scanner(new File(filename));

			String input;
			int testCount = Integer.parseInt(sc.nextLine());
			String out = "";

			// Split the input into separate tests and collect the output.
			for (int i = 0; i < testCount; i++) {
				input = "";
				for (int row = 0; row < inputLength; row++) {
					input += sc.nextLine() + System.lineSeparator();
				}
				out += "Case #" + (i + 1) + ": ";
				out += runTest(input);
				out += System.lineSeparator();
			}
			System.out.println(out);
			BufferedWriter output = new BufferedWriter(new FileWriter(
							"BoxFactory/output.txt"));
			output.write(out);
			output.close();
		} catch (FileNotFoundException ex) {
			System.err.println("Input file not found");
			System.exit(1);
		} catch (IOException ex) {
		}
	}

	public static String runTest(String input) {
		Scanner sc = new Scanner(input);
		boxes = new long[sc.nextInt()][2];
		toys = new long[sc.nextInt()][2];
		for (int i = 0; i < boxes.length; i++) {
			boxes[i][1] = sc.nextLong();
			boxes[i][0] = sc.nextLong();
		}
		for (int i = 0; i < toys.length; i++) {
			toys[i][1] = sc.nextLong();
			toys[i][0] = sc.nextLong();
		}
		System.out.println(input);
		
		long max = tryRun(0, 0, 0, 0);
		System.out.println("res:"+ max);
		return String.valueOf(max);
	}
	
	public static long tryRun(int boxPos, long boxCount,int toyPos, long toyCount) {
		if (boxPos >= boxes.length || toyPos >= toys.length) {
			return 0;
		}
		long count = 0;
		if (boxes[boxPos][0] == toys[toyPos][0]) {
			long boxesLeft = boxes[boxPos][1] - boxCount;
			long toysLeft = toys[toyPos][1] - toyCount;
			count += boxesLeft < toysLeft ? boxesLeft : toysLeft;
			toyCount += count;
			boxCount += count;
		}
		long nextBox = tryRun(boxPos + 1, 0, toyPos, toyCount);
		long nextToy = tryRun(boxPos, boxCount, toyPos + 1, 0);
		count += nextBox > nextToy ? nextBox : nextToy;
		return count;
	}
	
}
