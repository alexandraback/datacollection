package com.lewis.codeJamInJava;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

/**
 * @author patrick
 * 
 */
public class RecycledNumers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {

			File outpuFile = new File("output.txt");
			FileWriter fileWriter = new FileWriter(outpuFile);
			BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

			BufferedReader bufferedReader;
			File inputFile = new File("input.txt");
			FileReader fileReader = new FileReader(inputFile);
			bufferedReader = new BufferedReader(fileReader);

			int numTestCases = Integer.parseInt(bufferedReader.readLine());

			for (int i = 1; i <= numTestCases; i++) {

				StringTokenizer st = new StringTokenizer(
						bufferedReader.readLine());

				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				int recycledPairs = recycle(A, B);

				bufferedWriter.write("Case #" + i + ": " + recycledPairs
						+ "\r\n");
			}

			bufferedWriter.flush();
			bufferedWriter.close();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	private static int recycle(int a, int b) {
		int recycledPairs = 0;

		for (int i = a; i < b; i++) {

			String tmp = Integer.toString(i);
			int digits = tmp.length();
			int currentPairs[] = new int[digits];

			for (int j = 0; j < digits; j++) {
				// move digits and check

				int movedInt = Integer.parseInt(tmp.substring(j + 1)
						+ tmp.substring(0, j + 1));
				CHECKPAIR: if (movedInt <= b && movedInt > i) {
					for (int k = 0; k < digits; k++) {
						if (movedInt == currentPairs[k]) {
							break CHECKPAIR;
						}
					}
					currentPairs[j] = movedInt;
					recycledPairs++;
				}
			}
		}

		return recycledPairs;
	}

}
