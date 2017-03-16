package round1B;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class CloseMatch {

	public static void main(String[] args) throws Exception
	{
		String path = "C:\\Users\\Ziming\\Downloads\\";
		String input = path + "B-small-attempt0.in";
		String output = path + "B-small-attempt0.out";

		Scanner scanner = new Scanner(new FileReader(input));
		PrintWriter writer = new PrintWriter(output);
		int T = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < T; i++) 
		{
			String coder = scanner.next();
			String jammer = scanner.next();
			int max = 1, len = coder.length();
			for (int j=0;j<len;j++)
				max *= 10;
			
			int min = Integer.MAX_VALUE, minj=Integer.MAX_VALUE, mink=Integer.MAX_VALUE;
			for (int j=0;j<max;j++)
			{
				for (int k=0;k<max;k++)
				{
					String jString = padLeft(j, len);
					String kString = padLeft(k, len);
					
					if (isValid(jString, coder)&&isValid(kString, jammer))
					{
						int diff = Math.abs(j-k);
						if (diff<min)
						{
							min = diff;
							minj = j;
							mink = k;
						}
						if (diff==min && j<minj)
						{
							minj = j;
						}
						if (diff==min && j==minj && k<mink)
						{
							mink = k;
						}
					}
				}
			}
			
			writer.println("Case #" + (i + 1) + ": " + padLeft(minj, len) + " " + padLeft(mink, len));
		}
		
		writer.flush();
		writer.close();
		scanner.close();
		System.out.println("program finished :)");
	}
	
	private static boolean isValid(String input, String pattern)
	{
		for (int i=0;i<input.length();i++)
		{
			if (pattern.charAt(i)=='?')
				continue;
			
			if (input.charAt(i)!=pattern.charAt(i))
				return false;
		}
		
		return true;
	}
	
	private static String padLeft(int i, int len)
	{
		String r = Integer.toString(i);
		while (r.length()<len)
			r = "0" + r;
		
		return r;
	}
}
