package com.test;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Test4 {

	public static void main (String[] args)  throws Exception
	{
		FileWriter writer=new FileWriter("d:/A-little-output3.txt");
		Scanner scanner=new Scanner(new FileInputStream("d:/A-small-attempt1.in"));
	    
		double count_case_d = scanner.nextDouble();
		
		long count_case = (long)count_case_d;
		
		//System.out.println("case count "+count_case);
		 
		int[][] count_a;
		for (long i =0;i<count_case;i++)
		{
			String tmp = scanner.next();
			int index = tmp.indexOf('/');
			String A_s = tmp.substring(0,index);
			String B_s = tmp.substring(index+1);
			long A = Long.parseLong(A_s);
			long B = Long.parseLong(B_s);
			boolean check = false; 
			double value = (double)A/(double)B;
			double seed = 1;
			double closetSeed = 0;
			long closetGen = 0;
			double limit = 1.0f / Math.pow(2,40);
			while (value > 0)
			{
				if (value - seed >= 0)
				{
					value -= seed;
					if (closetSeed == 0)
					{
						closetSeed = seed;
					}
				}
				else
				{
					seed /= 2;
				}
				if (seed <= limit )
				{
					break;
				}
				
			}
			
			if (value == 0)
			{
				check = true;
			}
			if (closetSeed == 1)
			{
				closetGen = 1;
			}
			while (closetSeed != 1)
			{
				closetSeed *= 2;
				closetGen += 1;
			}
			if (check == true)
			{
				writer.write("Case #"+(i+1)+": "+closetGen+"\n");
			}
			else
			{
				writer.write("Case #"+(i+1)+": impossible\n");
			}
		}
		
		writer.close();
	}
	
}
