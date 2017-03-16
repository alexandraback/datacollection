package com.bakes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class A {

	public static void main(String[] args) {
		A park = new A();
		park.calculate();

	}

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
				String[] split = strLine1.split(" ");
				int A = Integer.parseInt(split[0]);
				int B = Integer.parseInt(split[1]);
				
				String line = in.readLine();
				split = line.split(" ");
				double[] data = new double[split.length];
				for (int i = 0; i < split.length; i++)
				{
					data[i] = Double.parseDouble(split[i]);
				}
				
				double estimated = getEstimatedProbability(data, A)*(B-A+1) + (1-getEstimatedProbability(data, A))*(2*B-A+2);
				double backspace1 = getEstimatedProbability(data, A-1)*(B-A+3) + (1-getEstimatedProbability(data, A-1))*(2*B-A+4);
				double backspace2 = getEstimatedProbability(data, A-2)*(B-A+5) + (1-getEstimatedProbability(data, A-2))*(2*B-A+6);
				double enter = B+2;
				
				if (backspace1 < estimated)
				{
					estimated=backspace1;
				}
				if (backspace2 < estimated)
				{
					estimated = backspace2;
				}
				if (enter < estimated)
				{
					estimated = enter;
				}
				
				
				String result = "Case #"+n+": "+ estimated;
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
	
	double getEstimatedProbability(double[] data, int max)
	{
		double result = 1;
		for (int i = 0; i < max; i++)
		{
			result *= data[i];
		}
		return result;
	}
}
