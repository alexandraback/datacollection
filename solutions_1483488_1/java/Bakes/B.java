package com.bakes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class B {
	public static void main(String[] args) {
		B park = new B();
		park.calculate();

	}	

	private void calculate() {
		BufferedReader in;
		String strLine1;
		String strLine2;
		String strLine3;
		PrintWriter out;
		try {
			in = new BufferedReader(new FileReader("C-large.in"));
			in.readLine();
			FileWriter outFile = new FileWriter("output.txt");
			out = new PrintWriter(outFile);
			int n = 0;

			while ((strLine1 = in.readLine()) != null) {
				n++;
				
				String[] data = strLine1.split(" ");
				
				int int1 = Integer.parseInt(data[0]);
				int int2 = Integer.parseInt(data[1]);
				int count = 0;
				for (int i = int1; i < int2; i++)
				{
					String s = ""+i;
					int[] sorteds = new int[s.length()-1];
					for (int k = 0; k < s.length()-1; k++)
					{
						s = permute(s);
						int j = Integer.parseInt(s);
						sorteds[k] = j;
						if (j > i && j <= int2)
						{
							boolean unique = true;
							for (int l = 0; l < k; l++)
							{
								if (sorteds[l] == j)
								{
									unique = false;
								}
							}
							if (unique)
							{
								count++;
							}
						}
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
	
	String permute(String s)
	{
		if (s.length() == 1)
		{
			return s;
		}
		s = s.substring(1) + s.charAt(0);
		return s;
	}
}
