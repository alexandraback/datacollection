package com.lewis.codeJamInJava;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class DancingWithTheGooglers {

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

				int numGooglers = Integer.parseInt(st.nextToken());
				int numSurprisingScores = Integer.parseInt(st.nextToken());
				int passingScore = Integer.parseInt(st.nextToken());

				int scores[] = new int[numGooglers];

				for (int j = 0; j < numGooglers; j++) {
					scores[j] = Integer.parseInt(st.nextToken());
				}

				int passingGrades = getNumPassingScores(scores, passingScore,
						numSurprisingScores);

				bufferedWriter
						.write("Case #" + i + ": " + passingGrades + "\r\n");

			}
			bufferedWriter.flush();
			bufferedWriter.close();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	/**
	 * Given scores, passing score and surpising scores, generates the number of
	 * passes.
	 * 
	 * @param scores
	 * @param passingScore
	 * @param numSurprisingScores
	 * @return
	 */
	public static int getNumPassingScores(int[] scores, int passingScore,
			int numSurprisingScores) {

		int numPassing = 0;
		int easyPass = passingScore * 3 - 2;
		int surprisingPass = passingScore * 3 - 4;

		if (easyPass < 0) {
			surprisingPass = 0;
			easyPass = 0;
		} else if(surprisingPass < 0){
			surprisingPass = 0;
		}

		for (int i = 0; i < scores.length; i++) {
			if(scores[i] < passingScore){
				
			} else if (scores[i] >= easyPass) {
				numPassing++;
			} else if (numSurprisingScores > 0 && scores[i] >= surprisingPass) {
				numSurprisingScores--;
				numPassing++;
			}

		}

		return numPassing;
	}

}
