package com.bakes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class C {
	public static void main(String[] args) {
		C park = new C();
		park.calculate();

	}	
	
	private long lcm(long a, long b)
	{
		return (a*b)/gcd(a,b);
	}
	
	public static long gcd(long i1, long i2) { 
		// using Euclid's algorithm 
		long a=i1, b=i2, temp; 
		while (b!=0) { 
		temp=b; 
		b=a%temp; 
		a=temp; 
		} 
		return a; 
		}
	
	private void calculate() {
		BufferedReader in;
		String strLine1;
		String strLine2;
		String strLine3;
		PrintWriter out;
		try {
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			in.readLine();
			FileWriter outFile = new FileWriter("output.txt");
			out = new PrintWriter(outFile);
			int n = 0;

			while ((strLine1 = in.readLine()) != null) {
				n++;
				
				String[] data = strLine1.split(" ");
				
				int N = Integer.parseInt(data[0]);
				int s = Integer.parseInt(data[1]);
				int p = Integer.parseInt(data[2]);
				int count = 0;
				for (int i = 3; i < 3 + N; i++)
				{
					int d = Integer.parseInt(data[i]);
					if ((d - 3*p) >= -2)
					{
						count++;
					}
					else if ((d-3*p) >= -4 && s >0 && d >=2)
					{
						count++;
						s--;
					}
				}
				String result = "Case #"+n+": "+count;
				out.println(result);
				System.out.println(result);
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
		

}
