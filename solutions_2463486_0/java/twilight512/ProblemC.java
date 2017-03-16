package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemC {

	public static int getFS1000(int a, int b) {
		int[] smallFS = new int[]{1,4,9,121,484};
		int count = 0;
		for(int i=0; i<smallFS.length; i++) {
			if(smallFS[i]>=a&&smallFS[i]<=b) {
				count++;
			}
		}
		return count;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
			FileWriter fw = new FileWriter("outputCsmall.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				int a, b; 
				line = br.readLine();
				String[] endpoints = line.split(" ");
				a = Integer.decode(endpoints[0]);
				b = Integer.decode(endpoints[1]);
				bw.write("Case #"+i+": "+ProblemC.getFS1000(a,b)+"\n");
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
