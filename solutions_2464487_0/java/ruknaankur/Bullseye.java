package com.google.code.jam.thirteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;

public class Bullseye {
	
	public final int PI = 1; // paint required per pi cm2 
	
	public static void main(String[] args) {
		
		try
		{
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\bullseye\\A-small-attempt0.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int totalCases = Integer.parseInt(bufReader.readLine().trim());

			File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\bullseye\\A-small-attempt0.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 1; i <= totalCases; i++)
			{
				String x = bufReader.readLine();
				String[] numbers = x.split(" ");
				long  A = Long.parseLong(numbers[0]);
				long B = Long.parseLong(numbers[1]);
				
				int res = Bullseye.getNoOfBlackCircles(A, B);
				// System.out.println("Result:"+res);
				if (i == 1)
					writer.write("Case #"+i+": " + res);
				else
					writer.write("\nCase #"+i+": " + res);
			}
			
			writer.close();
			System.out.println("Total time = " +( System.currentTimeMillis() - startTime));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

private static int getNoOfBlackCircles(long r, long t) {
	// r is radius of inner white circle
	// t is black ink
	
	// area of first black ring is pi.((r+1)2-r2) = pi * ((r+1)+r) * ((r+1)-r) = pi*(2r+1)
	
	// area of second black ring is pi. (2(r+2) + 1) = pi. (2r+5)
	
	// area of third black ring is pi. (2r + 9);
	
	int blackRingsCount = 1;
	long paintRequired = 2*r + 1;
	
	// SUM of AP S = n/2 * (2*a1 + (n-1)*d)
	// n2*d + (2a1 - d)*n - 2S = 0
	
	// bigger root of equation
	// -(2a1-d) + sqrt((2a1-d)2-4*d*(-2S) / 2d
	
	long aOne = 2*r + 1;
	int d = 4;
	long S = t;
	
	double root = (-(2*aOne - d) + Math.sqrt( (2*aOne - d)*(2*aOne - d) + 4*d*(2*S)))/(2*d) ;
	// System.out.println("root:"+root);
	blackRingsCount = (int)root/1;
	/*
	while (t >= paintRequired) {
		
		paintRequired = paintRequired + 2*r + 4*blackRingsCount + 1;
		blackRingsCount++;
	}
	
	blackRingsCount --;
	*/
	return blackRingsCount;
}
}
