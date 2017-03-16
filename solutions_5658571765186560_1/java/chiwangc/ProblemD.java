package com.google.code.qualification_round_2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

enum Winner {
	RICHARD("RICHARD"),
	GABRIEL("GABRIEL");

	private final String winner;
	
	Winner(String winner) {
		this.winner = winner;
	}
	
	public String toString() {
		return winner;
	}
};

public class ProblemD {
	
	private static String inputFilePath = "/home/chiwang/Downloads/CodeJam/D-large.in";
	private static String outputFilePath = "/home/chiwang/Downloads/CodeJam/Solution/";
	private static BufferedReader br;
	private static BufferedWriter bw;
		
	private static int X;
	private static int R;
	private static int C;
	
	private static void compute() throws IOException {
	/*
	 * Fill in the implementation details
	 */
		final int T = Integer.parseInt(br.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String[] parts = br.readLine().split(" ");
			
			X = Integer.parseInt(parts[0]);
			R = Integer.parseInt(parts[1]);
			C = Integer.parseInt(parts[2]);
			
			String winner = findWinner().toString();	

			String result = String.format("Case #%d: %s%n", caseNum, winner);
			System.out.println(result);
			bw.write(result);
		}				
	}
	
	private static Winner findWinner() {
		if (R * C % X != 0) {
			return Winner.RICHARD;
		} else {
			if (X <= 2) {				
				return Winner.GABRIEL;
			} else if (X == 3) {
				if (R == 1 || C == 1) {
					return Winner.RICHARD;
				} else {
					return Winner.GABRIEL;
				}				
			} else if (X == 4) {
				if (R == 1 || C == 1) {
					return Winner.RICHARD;
				}
				if (R == 2 || C == 2) {
					return Winner.RICHARD;
				}
				if (R == 2 && C == 2) {
					return Winner.RICHARD;
				}
				if (R >= 4 && C >= 4) {
					return Winner.GABRIEL;
				}
				if (R == 3 || C == 3) {
					return Winner.GABRIEL;
				}
			} else if (X == 5) {
				if (R <= 2 || C <= 2) {
					return Winner.RICHARD;
				} else if ((R == 3 && C == 5) || (R == 5 && C == 3)) {
					return Winner.RICHARD;
				} else if ((R >= 3 && C >= 5) || (R >= 5 && C >= 3)) {
					return Winner.GABRIEL;
				}
			} else if (X == 6) {
				if (R <= 3 || C <= 3) {
					return Winner.RICHARD;
				} else if (R >= 4 && C >= 4) {
					return Winner.GABRIEL;
				}
			} else if (X >= 7) {
				return Winner.RICHARD;
			}
			System.err.println("This should not happen! R = " + R + ", C = " + C);
		}		
		System.err.println("This should not happen!");
		return Winner.RICHARD;		
	}
		
	
	public static void main(String[] args) {
		
		long startTime = System.currentTimeMillis();
		
		// Initialisation
		try {
			outputFilePath += inputFilePath.substring(inputFilePath.lastIndexOf("/") + 1, inputFilePath.length() - 3) + ".out";
			
			br = new BufferedReader(new FileReader(inputFilePath));
			bw = new BufferedWriter(new FileWriter(outputFilePath));
			
			compute();		
			
		} catch (IOException ioe) {
			ioe.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
				if (bw != null)
					bw.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
		
		System.out.println("========================================");
		System.out.println("Done! :)");
		
		long endTime = System.currentTimeMillis();;
		System.out.printf("Finished in %d seconds.%n", (endTime - startTime) / 1000);
	}

}

