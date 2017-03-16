package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class Prob1A {
	
	public static int getAns(int r, int t) {
		Double n = Math.floor(Math.sqrt(t/2.0 + (2.0*r-1.0)*(2.0*r-1.0)/16)-(2.0*r-1.0)/4);
		return n.intValue();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
			FileWriter fw = new FileWriter("outputAsmall.txt");
			//BufferedReader br = new BufferedReader(new FileReader("input1.txt"));
			//FileWriter fw = new FileWriter("output.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				line = br.readLine();
				String[] inVals = line.split(" ");
				//BigInteger r = new BigInteger(inVals[0]);
				//BigInteger t = new BigInteger(inVals[1]);
				int r = Integer.parseInt(inVals[0]);
				int t = Integer.parseInt(inVals[1]);
				bw.write("Case #"+i+": "+Prob1A.getAns(r, t)+"\n");
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
