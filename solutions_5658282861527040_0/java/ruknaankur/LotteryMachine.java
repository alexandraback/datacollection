package com.self.code.jam.fourteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;

public class LotteryMachine {
	
	public static void main(String[] argv)
	{
		try
		{
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\self\\code\\jam\\fourteen\\lm\\B-small-attempt0.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int x = Integer.parseInt(bufReader.readLine().trim());
			int count = 0;

			File file = new File("D:\\workspace\\Learn\\src\\com\\self\\code\\jam\\fourteen\\lm\\B-small-attempt0.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 0; i < x ; i++)
			{
				count++;
				String res = LotteryMachine.winningCases(bufReader);
				writer.write("Case #"+count+": " + res + "\n");
			}
			writer.close();
			System.out.println("Total time = " +( System.currentTimeMillis() - startTime));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String winningCases(BufferedReader bufReader) throws IOException {
		String[] arr = bufReader.readLine().trim().split(" ");
		int A = Integer.parseInt(arr[0]);
		int B = Integer.parseInt(arr[1]);
		int K = Integer.parseInt(arr[2]);
		
		int wins = 0;
		
		for (int i=0; i< A;i++)
		{
			for (int j=0; j<B;j++) {
				int val = (i&j);
				if (val < K) wins++;
			}
		}
		
		return String.valueOf(wins);
		
	}
}
