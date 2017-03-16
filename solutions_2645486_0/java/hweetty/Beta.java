import java.io.*;
import java.util.*;

public class Beta implements Comparable <Beta>
{
	int height, col;
	public Beta (int h, int c)
	{
		height = h;
		col = c;
	}

	public int compareTo (Beta other)
	{
		return height - other.height;
	}


	static BufferedReader in;
	static StringTokenizer st;
	public static int ni () throws IOException
	{
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer (in.readLine());
			
		int r = Integer.parseInt(st.nextToken());
		// System.out.println(r);
		return r;
	}
	
	public static int [] values;
	public static int _e, _r, _v;
	public static int check (int gain, int energy, int n)
	{
		if (energy > _e)
			energy = _e;
			
		if (n == _v)
			return gain;
		
		int best = 0;
		for (int i = 0; i <= energy; i++)
		{
			int g = i * values[n];
			int x = check(gain + g, energy-i+_r, n+1);
			if (x > best)
				best = x;
		}
		
		return best;
	}
	
	public static void main(String[] args) throws IOException
	{
		in = new BufferedReader (new FileReader("input.txt"));
		PrintWriter out = new PrintWriter ("output.txt");
		
		int numCases = ni();
		for (int testCase = 1; testCase <= numCases; testCase++)
		{
			_e = ni();
			_r = ni();
			_v = ni();
			values = new int[_v];
			
			for (int r = 0; r < _v; r++)
			{
				values[r]= ni();
			}
			
			
			String result = "" + check(0, _e, 0);
			
			String print = String.format("Case #%d: %s", testCase, result);
			out.println(print);
			System.out.println(print);
		} // end test cases
		
		in.close();
		out.close();
	}
}

