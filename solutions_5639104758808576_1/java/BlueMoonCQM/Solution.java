package test;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution
{
	public static void main(String[] args)
	{
		try
		{
			Scanner stdin = new Scanner(new File("/Users/chenqiming/Desktop/in.txt"));
			PrintWriter writer = new PrintWriter("/Users/chenqiming/Desktop/out.txt", "UTF-8");
			
			int T = stdin.nextInt();
			for (int i = 0; i < T; ++i)
			{
				int S = stdin.nextInt();
				int add = 0;
				int all = 0;
				String s = stdin.nextLine().trim();
				for (int j = 0; j <= S; ++j)
				{
					all += s.charAt(j) - '0';
					if (all <= j)
					{
						add += j+1-all;
						all = j+1;
					}
					if (all > S)
						break;
				}
				writer.println("Case #" + (i+1) + ": " + add);
			}
			stdin.close();
			writer.close();
		} 
		catch (Exception e)
		{
			e.printStackTrace();
		}
		
	}
}
