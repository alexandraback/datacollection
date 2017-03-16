import java.util.*;
import java.io.*;

public class CMinesweeperMaster
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("C-small-attempt3.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small.out")));
		
		int t = in.nextInt();
		for (int i = 1; i <= t; i++)
		{
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			
			out.println("Case #" + i + ": ");

			if (r == 1)
			{
				out.print('c');
				for (int j = 1; j < c - m; j++)
					out.print('.');
				for (int j = 0; j < m; j++)
					out.print('*');
				out.println();
				continue;
			}
			if (c == 1)
			{
				out.println('c');
				for (int j = 1; j < r - m; j++)
					out.println('.');
				for (int j = 0; j < m; j++)
					out.println('*');
				continue;
			}
			
			m = r * c - m;
			if (m != 1 && ((m % 2 == 0 && m < 4) || (m % 2 == 1 && m < 9 && m > 1) || ((r == 2 || c == 2) && m % 2 == 1)))
			{
				out.println("Impossible");
				continue;
			}
			int[] array = new int[r];
			
			int temp = m;
			int currRow = 0;
			while (temp > 2)
			{
				if (currRow == 0)
				{
					if (array[0] == c)
					{
						currRow = 2;
						continue;
					}
					array[0]++;
					array[1]++;
					temp -= 2;
					continue;
				}
				if (array[currRow] == c)
					currRow++;
				array[currRow]++;
				temp--;
			}
			if (temp == 1)
			{
				if (array[currRow] == c)
				{
					if (currRow == 0)
					{
						if (array[0] == 0)
							array[0] = 1;
						else
						{
							array[0]--; array[1]--; array[2] = 3;
						}
					}
					else
					{
						array[currRow]--;
						array[currRow + 1] = 2;
					}
				}
				else
				{
					if (currRow == 0)
					{
						if (array[0] == 0)
							array[0] = 1;
						else
						{
							array[0]--; array[1]--; array[2] = 3;
						}
					}
					else
						array[currRow]++;
				}
			}
			else if (temp != 0)
			{
				if (currRow == 0)
				{
					if (array[0] == c)
						array[2] = 2;
					else
					{
						array[0]++;
						array[1]++;
					}
				}
				else if (array[currRow] + 2 <= c)
					array[currRow] += 2;
				else
					array[currRow + 1] = 2;
			}

			for (int r1 = 0; r1 < r; r1++)
			{
				for (int c1 = 0; c1 < array[r1]; c1++)
				{
					if (r1 == 0 && c1 == 0)
						out.print('c');
					else
						out.print('.');
				}
				for (int c1 = array[r1]; c1 < c; c1++)
					out.print('*');
				out.println();
			}
		}
		out.flush();
		out.close();
	}
}
