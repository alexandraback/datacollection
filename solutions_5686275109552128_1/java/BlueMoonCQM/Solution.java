package test;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
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
				ArrayList<Integer> list = new ArrayList<Integer>();
				int max = 0;
				for (int j = 0; j < S; ++j)
				{
					int in = stdin.nextInt();
					if (max < in)
						max = in;
					list.add(in);
				}
				int mincount = -1;
				for (int k = 1; k <= max; ++k)
				{
					int count = 0;
					for (int j = 0; j < S; ++j)
					{
						count += (list.get(j)-1) / k;
					}
					count += k;
					if (count < mincount || mincount == -1)
						mincount = count;
				}
				if (mincount == -1)
					mincount = 1;
				writer.println("Case #" + (i+1) + ": " + mincount);
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
