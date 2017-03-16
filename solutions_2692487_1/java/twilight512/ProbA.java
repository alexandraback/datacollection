package com.yapark.codejam20131B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProbA {

	public ProbA() {
		
	}
	
	public static int getResult(int myMote, int numOfMotes, int[] otherMotes) {
		if(myMote==1) {
			return numOfMotes;
		}
		Arrays.sort(otherMotes);
		int adds = 0;
		int best = numOfMotes;
		int curSize = myMote;
		for(int i=0; i<numOfMotes; i++) {
			if(curSize>otherMotes[i]) {
				curSize = otherMotes[i] + curSize;
			}
			else {
				while(curSize<=otherMotes[i]) {
					curSize = curSize*2-1;
					adds = adds+1;
				}
				curSize = otherMotes[i] + curSize;
			}
			best = Math.min(best, adds+numOfMotes-i-1);
		}
		return best;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			//BufferedReader br = new BufferedReader(new FileReader("test.txt"));
			//FileWriter fw = new FileWriter("output.txt");
			//BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			//FileWriter fw = new FileWriter("outputA_small.txt");
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			FileWriter fw = new FileWriter("outputA_large.txt");
			
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			String[] inVals;
			for(int i = 1; i<=numOfGames; i++) {
				int myMote;
				int numOfMotes;
				int[] otherMotes;
				line = br.readLine();
				inVals = line.split(" ");
				myMote = Integer.decode(inVals[0]);
				numOfMotes = Integer.decode(inVals[1]);
				line = br.readLine();
				inVals = line.split(" ");
				otherMotes = new int[numOfMotes];
				for(int j=0; j<numOfMotes; j++) {
					otherMotes[j] = Integer.decode(inVals[j]);
				}
				bw.write("Case #"+i+": "+ProbA.getResult(myMote, numOfMotes, otherMotes)+"\n");
			}
			br.close();
			bw.flush();
			bw.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("ERROR: Cannot find file.");
			return;
		}
		catch (IOException e) {
			
		}
	}

}
