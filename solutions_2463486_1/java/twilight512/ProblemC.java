package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProblemC {

	public static long[] listFS = {1*1L,2*2L,3*3L,11*11L,22*22L,101*101L,111*111L,121*121L,202*202L,212*212L,1001*1001L,1111*1111L,2002*2002L,
			10001*10001L,10101*10101L,10201*10201L,11011*11011L,11111*11111L,11211*11211L,20002*20002L,20102*20102L,
			100001*100001L,101101*101101L,110011*110011L,111111*111111L,200002*200002L,
			1000001*1000001L,1001001*1001001L,1002001*1002001L,1010101*1010101L,1011101*1011101L,1012101*1012101L,1100011*1100011L,
			1101011*1101011L,1102011*1102011L,1110111*1110111L,1111111*1111111L,2000002*2000002L,2001002*2001002L,
			10000001*10000001L,10011001*10011001L,10100101*10100101L,10111101*10111101L,11000011*11000011L,
			11011011*11011011L,11100111*11100111L,11111111*11111111L,20000002*20000002L};
	
	public ProblemC() {
		long[] myList = new long[listFS.length];
		System.arraycopy(listFS,0,myList,0,listFS.length);
		Arrays.sort(myList);
		for(int i=0; i<listFS.length; i++) {
			if(myList[i]!=listFS[i]) {
				System.out.println("ERROR! Need debug");
			}
		}
	}
	
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
	
	public static int getFS10e14(long a, long b) {
		int startPoint = Arrays.binarySearch(listFS, a);
		int endPoint = Arrays.binarySearch(listFS, b);
		if(startPoint<0 && endPoint<0) {
			return Math.abs(startPoint-endPoint);
		}
		if(startPoint>=0 && endPoint>=0) {
			return endPoint-startPoint+1;
		}
		if(startPoint<0) {
			return endPoint + startPoint + 2;
		}
		return -endPoint - startPoint - 1;
		
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("C-large-1.in"));
			FileWriter fw = new FileWriter("outputClarge_1.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				long a, b; 
				line = br.readLine();
				String[] endpoints = line.split(" ");
				a = Long.decode(endpoints[0]);
				b = Long.decode(endpoints[1]);
				bw.write("Case #"+i+": "+ProblemC.getFS10e14(a,b)+"\n");
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
