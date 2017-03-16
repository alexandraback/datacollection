package com.zkgcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B_Pogo {
	
	private static final String inputPath = "B-small-attempt0.in";
	private static final String outputPath = "B-small-attempt0.out";

	/**
	 * @param args
	 */
	public static void main(String[] args) {		
		// Create input reader
		Scanner sc = null;
		try {
			sc = new Scanner(new File(inputPath));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		
		
		// Create output writer
		File outputFile = new File(outputPath);
		PrintWriter pw = null;
		try {
			pw = new PrintWriter(outputFile);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			return;
		}

		// Read number of test cases
		int T = sc.nextInt();
		sc.nextLine();
		
		// Process test cases
		int X;
		int Y;
		String res;
		for (int i = 0; i < T; i++) {
			// Read input
			X = sc.nextInt();
			Y = sc.nextInt();
			
			// Compute answer for this test case
			res = computePath(X, Y);
			
			// Move scanner to next line
			sc.nextLine();

			System.out.println("Case #" + (i + 1) + ": " + res);
			pw.println("Case #" + (i + 1) + ": " + res);
		}
		
		// Close
		sc.close();
		pw.close();
		System.out.println("Program finished");
	}
	
	private static String computePath(int X, int Y) {
		String path = "";
		int posX = 0, posY = 0;
		int dx = Math.abs(X), dy = Math.abs(Y);
		
		int stepSize = 1;
		char dir;
		
		while (dx != 0 || dy != 0) {
			
			if (dx > dy) {
				if (dx >= stepSize) {
					// Move closer
					dir = (posX < X) ? 'E' : 'W';
					posX += (posX < X) ? stepSize : -stepSize;
				} else {
					// Move away
					dir = (posX < X) ? 'W' : 'E';
					posX += (posX < X) ? -stepSize : stepSize;
				}
			} else {
				if (dy >= stepSize) {
					// Move away
					dir = (posY < Y) ? 'N' : 'S';
					posY += (posY < Y) ? stepSize : -stepSize;
				} else {
					// Move closer
					dir = (posY < Y) ? 'S' : 'N';
					posY += (posY < Y) ? -stepSize : stepSize;
				}
			}
			
			// Update position
			path += dir;
			
			// Update distance
			dx = Math.abs(X - posX);
			dy = Math.abs(Y - posY);
			
			// Increase step size
			stepSize++;
		}
		
		return path;
	}

}
