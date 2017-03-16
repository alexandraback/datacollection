package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

public class Prob1A {
	
	public static long getAns(double r, double t, BigInteger rbi, BigInteger tbi) {
		System.out.println(Math.sqrt(t/2.0 + (2.0*r-1.0)*(2.0*r-1.0)/16)-(2.0*r-1.0)/4);
		Double n = Math.floor(Math.sqrt(t/2.0 + (2.0*r-1.0)*(2.0*r-1.0)/16)-(2.0*r-1.0)/4);
		Long check = n.longValue();
		BigInteger checkOriginal = new BigInteger(check.toString());
		BigInteger checkPlusOne = new BigInteger(check.toString()).add(BigInteger.ONE);
		BigInteger b2 = new BigInteger("2");
		if ( checkOriginal.multiply(checkOriginal).multiply(b2).subtract(checkOriginal).add(checkOriginal.multiply(b2).multiply(rbi)).subtract(tbi).compareTo(BigInteger.ZERO) > 0 )
			return check-1;
		if ( checkPlusOne.multiply(checkPlusOne).multiply(b2).subtract(checkPlusOne).add(checkPlusOne.multiply(b2).multiply(rbi)).subtract(tbi).compareTo(BigInteger.ZERO) <= 0 )
			return check+1;
		return check;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			FileWriter fw = new FileWriter("outputAlarge.txt");
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
				double r = Double.parseDouble(inVals[0]);
				double t = Double.parseDouble(inVals[1]);
				BigInteger rbi = new BigInteger(inVals[0]);
				BigInteger tbi = new BigInteger(inVals[1]);
				bw.write("Case #"+i+": "+Prob1A.getAns(r, t, rbi, tbi)+"\n");
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
