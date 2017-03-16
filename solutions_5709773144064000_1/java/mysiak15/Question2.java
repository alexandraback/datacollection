package round_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Question2 
{
	public static void main(String args[])
	{
		readFile();
	}

	private static void readFile()
	{
		try 
		{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Marek\\Desktop\\B-large.in"));
			int count = Integer.parseInt(br.readLine());
			String [] as = new String[count];
			
			for (int i = 0; i < count; i++) 
			{
				double[] d = split(br.readLine());
				as[i] = ""+win(d[0], d[1], d[2]);
			}
			printToFile(as);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
	
	private static double win(double farmPrice, double farmExtra, double toWin)
	{
		double rate = 2d;
		double totalTime = 0d;
		
		while (toWin/rate > (farmPrice/rate + toWin/(rate+farmExtra)))
		{
			totalTime += farmPrice/rate;
			rate += farmExtra;
		}
		totalTime += toWin/rate;
		
		return totalTime;
	}
	
	private static double[] split(String s)
	{
		String [] a = s.split(" ");
		double[] r = new double [3];
		for (int i = 0; i < 3; i++)
			r[i] = Double.parseDouble(a[i]);
		return r;
	}
	
	private static void printToFile(String[] s)
	{
		try 
		{
			PrintWriter br = new PrintWriter(new FileWriter("C:\\Users\\Marek\\Desktop\\B-large.out"));

			for (int i = 1; i <= s.length; i++)
				br.println("Case #"+i+": "+s[i-1]);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
}


