package com.yapark.codejam20131B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Arrays;

public class ProbB {

	public ProbB() {
		
	}
	
	public static double c(int n, int m) {
		double k = 1;
		for(int i=n; i>n-m; i--) {
			k = k*i;
		}
		for(int i=2; i<=m; i++) {
			k = k / i;
		}
		return k;
	}
	
	public static int getCount(int rail) {
		return rail + 4*(rail*(rail-1)/2);
	}
	public static double getResult(int n, int x, int y) {
		double prob;
		int rail = (Math.abs(x)+y)/2+1;
		if(n>=getCount(rail)) {
			return 1.0;
		}
		if(n<=getCount(rail-1)) {
			return 0.0;
		}
		if(x==0) {
			return 0.0;
		}
		
		int fill = n - getCount(rail-1);
		if(fill>=(rail-1)*2+y+1) {
			return 1;
		}
		if(fill<y) {
			return 0;
		}
		prob = 0;
		double baseProb = Math.pow(0.5, fill);
		for(int i=y+1; i<=fill; i++) {
			prob = baseProb * c(fill,i) + prob;
		}
		return prob;
		
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			//BufferedReader br = new BufferedReader(new FileReader("test.txt"));
			//FileWriter fw = new FileWriter("output.txt");
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
			FileWriter fw = new FileWriter("outputB_small.txt");
			//BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			//FileWriter fw = new FileWriter("outputB_large.txt");
			
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			String[] inVals;
			DecimalFormat df = new DecimalFormat("#.#######");
			for(int i = 1; i<=numOfGames; i++) {
				int n, x, y;
				line = br.readLine();
				inVals = line.split(" ");
				n = Integer.decode(inVals[0]);
				x = Integer.decode(inVals[1]);
				y = Integer.decode(inVals[2]);
				bw.write("Case #"+i+": "+df.format(ProbB.getResult(n,x,y))+"\n");
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
