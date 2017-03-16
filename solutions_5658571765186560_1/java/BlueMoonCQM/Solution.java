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
				boolean flag = true;
				int X = stdin.nextInt();
				int R = stdin.nextInt();
				int C = stdin.nextInt();
				if (R > C)
				{
					int tmp = R;
					R = C;
					C = tmp;
				}
				if (R*C % X != 0)
					flag = false;
				if (X >= 7)
					flag = false;
				if (X == 3)
				{
					if (R <= 1)
						flag = false;
				}
				if (X == 4)
				{
					if (R <= 2)
						flag = false;
				}
				if (X == 5)
				{
					if (R <= 2)
						flag = false;
					if (R == 3 && C == 5)
						flag = false;
				}
				if (X == 6)
				{
					if (R <= 3)
						flag = false;
				}
				if (flag)
					writer.println("Case #" + (i+1) + ": GABRIEL");
				else
					writer.println("Case #" + (i+1) + ": RICHARD");
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
