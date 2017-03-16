package com.bakes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class A {

	public char[] mappings = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	
	public static void main(String[] args) {
		A park = new A();
		park.calculate();

	}
	
	/*
	 * 
	 * p > r
	 * j > u
	 * e > o
	 */

	private void calculate() {
		BufferedReader in;
		String strLine1;
		String strLine2;
		String strLine3;
		PrintWriter out;
		try {
			in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			in.readLine();
			FileWriter outFile = new FileWriter("output.txt");
			out = new PrintWriter(outFile);
			int n = 0;

			while ((strLine1 = in.readLine()) != null) {
				n++;
				char[] stline = strLine1.toCharArray();;
				for (int i = 0; i < strLine1.length(); i++)
				{
					if (stline[i] != ' ')
					{
						stline[i] = mappings[stline[i]-'a'];
					}
				}
				String result = "Case #"+n+": "+ (new String(stline));
				System.out.println(result);
				out.println(result);
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
