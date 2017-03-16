package round_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Question3
{
	public static void main(String args[])
	{
		readFile();
	}

	private static void readFile()
	{
		try 
		{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Marek\\Desktop\\C-small-attempt3.in"));
			int count = Integer.parseInt(br.readLine());
			String [] as = new String[count];
			
			for (int i = 0; i < count; i++) 
			{
				int[] d = split(br.readLine());
				as[i] = ""+minesweeper(d[0], d[1], d[2]);
				System.out.println(as[i]);
				System.out.println("------------------");
			}
			printToFile(as);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
	
	private static String minesweeper(int x, int y, int n)
	{
		char [][] a = new char [x][y];
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				a[i][j] = '.';
		
		a[0][0] = 'c';
		
		if (n == 0)
			return printArray(a);
		
		if (x*y-n == 1)
		{
			for (int i = 0; i < x; i++)
				for (int j = 0; j < y; j++)
				{
					a[i][j] = '*';
				}
			a[0][0] = 'c';
			return printArray(a);
		}
		
		if (x == 1)
		{
			for (int i = 0; i < n; i++)
			{
				a[0][y-i-1] = '*';
			}
			return printArray(a);
		}

		if (y == 1)
		{
			for (int i = 0; i < n; i++)
			{
				a[x-i-1][0] = '*';
			}
			return printArray(a);
		}
		
		while((n >= x || n >= y) && (x > 2 || y > 2))
		{
			while (n >= x && y > 2 && y >= x)
			{
				for (int i = 0; i < x; i++)
				{
					a[i][y-1] = '*';
				}
				
				y -= 1;
				n -= x;
			}
			
			while (n >= y && x > 2 && x >= y)
			{
				for (int i = 0; i < y; i++)
				{
					a[x-1][i] = '*';
				}
				
				x -= 1;
				n -= y;
			}
		}
		
		if (n > 0)
		{
			if (n <= x-2 && y > 2)
				for (int i = 0; i < n; i++)
				{
					a[x-1-i][y-1] = '*';
				}
			else if (n <= y-2 && x>2)
				for (int i = 0; i < n; i++)
				{
					a[x-1][y-1-i] = '*';
				}
			else if (x == y && x-1 == n && x > 3)
			{
				for (int i = 0; i < n-1; i++)
				{
					a[x-1][y-1-i] = '*';
				}
				a[x-2][y-1] = '*';
			}
			else
				//return "Impossible - n = "+n+"\n"+printArray(a);
				return "Impossible\n";
		}
				
		return printArray(a);
	}
	
	private static int[] split(String s)
	{
		String [] a = s.split(" ");
		int[] r = new int [3];
		for (int i = 0; i < 3; i++)
			r[i] = Integer.parseInt(a[i]);
		return r;
	}
	
	private static String printArray(char[][] a)
	{
		String res = "";
		for (int i = 0; i < a.length; i++)
		{
			for (int j = 0; j < a[0].length; j++)
				res += a[i][j];
			res += "\n";
		}
		return res;
	}
	
	private static void printToFile(String[] s)
	{
		try 
		{
			PrintWriter br = new PrintWriter(new FileWriter("C:\\Users\\Marek\\Desktop\\C-small-attempt3.out"));

			for (int i = 1; i <= s.length; i++)
				br.print("Case #"+i+":\n"+s[i-1]);
			
	    	br.close();
		}catch(IOException ioe){System.out.println("File not found!");}
	}
}


