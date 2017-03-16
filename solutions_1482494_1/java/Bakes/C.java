package com.bakes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

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
			//in = new BufferedReader(new FileReader("input.in"));
			in = new BufferedReader(new FileReader("B-large.in"));
			in.readLine();
			FileWriter outFile = new FileWriter("output.txt");
			out = new PrintWriter(outFile);
			int n = 0;

			while ((strLine1 = in.readLine()) != null) {
				n++;
				int N = Integer.parseInt(strLine1);
				int[][] levels = new int[N][3];
				for (int i = 0; i < N; i++)
				{
					String line = in.readLine();
					String[] split = line.split(" ");
					levels[i][0] = Integer.parseInt(split[0]);
					levels[i][1] = Integer.parseInt(split[1]);
				}
		        Arrays.sort(levels, new Comparator<int[]>() {
		            @Override
		            public int compare(final int[] entry1, final int[] entry2) {
		                final int time1 = entry2[1];
		                final int time2 = entry1[1];
		                return new Integer(time1).compareTo(new Integer(time2));
		            }
		        });

				boolean hasNotFailed = true;
				int score = 0;
				int goes = 0;
				while (hasNotFailed && score < 2*N)
				{
					goes++;
					hasNotFailed=false;
					for (int i = 0; i < levels.length; i++)
					{
						if (levels[i][1] <= score && levels[i][2] == 0 && !hasNotFailed)
						{
							score += 2;
							levels[i][2] = 2;
							hasNotFailed = true;
							
						}
					}
					for (int i = 0; i < levels.length; i++)
					{
	
						if (levels[i][1] <= score && levels[i][2] == 1 && !hasNotFailed)
						{
							score++;
							levels[i][2] = 2;
							hasNotFailed = true;
							
						}
					}
					for (int i = 0; i < levels.length; i++)
					{
						if (levels[i][0] <= score && levels[i][2] == 0 && !hasNotFailed)
						{
							score++;

							levels[i][2] = 1;
							hasNotFailed = true;
						}
								
					}
					
				}
				String result;
				
				if (score >= 2*N)
				{
					result = "Case #"+n+": "+goes;
				}
				else
				{
					result = "Case #"+n+": "+"Too Bad";
				}
				
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
