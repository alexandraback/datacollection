package com.google.code.jam.thirteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.math.BigInteger;

public class Bullseye {
	
	public final int PI = 1; // paint required per pi cm2 
	
	public static void main(String[] args) {
		
		try
		{
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\input\\bullseye\\A-large.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int totalCases = Integer.parseInt(bufReader.readLine().trim());

			File file = new File("D:\\workspace\\Learn\\src\\com\\google\\code\\jam\\thirteen\\output\\bullseye\\A-large.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 1; i <= totalCases; i++)
			{
				String x = bufReader.readLine();
				String[] numbers = x.split(" ");
				BigInteger A = new BigInteger(numbers[0]);
				BigInteger B = new BigInteger(numbers[1]);
				
				String res = Bullseye.getNoOfBlackCircles(A, B);
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

	private static String getNoOfBlackCircles(BigInteger r, BigInteger t) {
		// r is radius of inner white circle
		// t is black ink
		
		// area of first black ring is pi.((r+1)2-r2) = pi * ((r+1)+r) * ((r+1)-r) = pi*(2r+1)
		
		// area of second black ring is pi. (2(r+2) + 1) = pi. (2r+5)
		
		// area of third black ring is pi. (2r + 9);
		
		// SUM of AP S = n/2 * (2*a1 + (n-1)*d)
		// n2*d + (2a1 - d)*n - 2S = 0
		
		// bigger root of equation
		// -(2a1-d) + sqrt((2a1-d)2-4*d*(-2S) / 2d
		
		BigInteger aOne = r.multiply(new BigInteger("2")).add(new BigInteger("1")); 
		BigInteger d = new BigInteger("4");
		
		BigInteger b = aOne.multiply(new BigInteger("2")).subtract(new BigInteger("4"));
		BigInteger root = (sqrt(b.multiply(b).add(d.multiply(t).multiply(new BigInteger("8")))).subtract(b)).divide(new BigInteger("8"));
		
		// double root = (-(2*aOne - d) + Math.sqrt( (2*aOne - d)*(2*aOne - d) + 4*d*(2*S)))/(2*d) ;
		// System.out.println("root:"+root);
		// blackRingsCount = (int)root/1;
		/*
		while (t >= paintRequired) {
			
			paintRequired = paintRequired + 2*r + 4*blackRingsCount + 1;
			blackRingsCount++;
		}
		
		blackRingsCount --;
		*/
		return root.toString();
	}
	
	private static final BigInteger TWO = BigInteger.valueOf(2);


	/**
	 * Computes the integer square root of a number.
	 *
	 * @param n  The number.
	 *
	 * @return  The integer square root, i.e. the largest number whose square
	 *     doesn't exceed n.
	 */
	public static BigInteger sqrt(BigInteger n)
	{
	    if (n.signum() >= 0)
	    {
	        final int bitLength = n.bitLength();
	        BigInteger root = BigInteger.ONE.shiftLeft(bitLength / 2);
	
	        while (!isSqrt(n, root))
	        {
	            root = root.add(n.divide(root)).divide(TWO);
	        }
	        return root;
	    }
	    else
	    {
	        throw new ArithmeticException("square root of negative number");
	    }
	}
	
	private static boolean isSqrt(BigInteger n, BigInteger root)
	{
	    final BigInteger lowerBound = root.pow(2);
	    final BigInteger upperBound = root.add(BigInteger.ONE).pow(2);
	    return lowerBound.compareTo(n) <= 0
	        && n.compareTo(upperBound) < 0;
	}
}
