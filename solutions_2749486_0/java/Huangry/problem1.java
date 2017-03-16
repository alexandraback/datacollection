import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class problem1
{
	public static String minMoves(int x, int y, int moveNo)
	{
		if (moveNo > 500)
			return "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN";
		String minString = "w" + minMoves(x - moveNo, y, moveNo + 1);
		int minLength = minString.length();

		String str1 = "e" + minMoves(x + moveNo, y, moveNo + 1);
		int length1 = str1.length();

		if (length1 < minLength)
		{
			minLength = length1;
			minString = str1;
		}
		String str2 = "n" + minMoves(x, y + moveNo, moveNo + 1);
		int length2 = str1.length();
		if (length2 < minLength)
		{
			minLength = length2;
			minString = str2;
		}
		String str3 = "s" + minMoves(x, y - moveNo, moveNo + 1);
		int length3 = str1.length();
		if (length1 < minLength)
		{
			minLength = length3;
			minString = str3;
		}
		return minString;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		BufferedWriter out;
		out = new BufferedWriter(new FileWriter("diamonds.txt"));
		File inFile = new File("B-small-attempt0.in");
		Scanner scan = new Scanner(inFile);

		int T = scan.nextInt();

		for (int test = 1; test <= T; test++)
		{
			int x = scan.nextInt();
			int y = scan.nextInt();
			String str = "";
			
			int index = 1;
			if (x>0)
			while (x!=0)
			{
				if (index%2 == 1)
					{x+=index;
					str = str+"W";
					}
				else
				{
					x-=index;
					str = str+"E";
				}
				index++;
				
			}
			else
			{
				while (x!=0)
				{
					if (index%2 == 1)
						{
						x-=index;
						str = str+"E";
						}
					else
					{
						x+=index;
						str = str+"W";
						
					}
					index++;
					
				}
			}
			
			if (y>0)
			while (y!=0)
			{
				if (index%2 == 1)
					{y+=index;
					str = str+"S";
					}
				else
				{
					y-=index;
					str = str+"N";
				}
				index++;
				
			}
			else
				while (y!=0)
				{
					if (index%2 == 1)
						{
						y-=index;
						str = str+"N";
						}
					else
					{
						y+=index;
						str = str+"S";
						
					}
					index++;
					
				}
				
			
			 System.out.println("Case #" + test + ": " + str);
		}
		out.close();

	}

}
