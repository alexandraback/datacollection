
import java.awt.Point;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class KingdomRush {

	public static int stars = 0;
	public static int totalLevels = 0;
	public static boolean two = true;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("kingdom.out")));
		
		int numberCases = Integer.parseInt(f.readLine());
		int levels;
		String log;
		StringTokenizer st;
		MyPoint[] needed;
		
		for (int i = 1; i <= numberCases; i++)
		{
			log = "Case #" + i + ": ";
			//System.out.println(log);
			levels = Integer.parseInt(f.readLine());
			
			needed = new MyPoint[levels];
			
			for (int j = 0; j < levels; j++)
			{
				st = new StringTokenizer(f.readLine());
				needed[j] = new MyPoint(Integer.parseInt(st.nextToken()), 
										Integer.parseInt(st.nextToken()));
			}
			Arrays.sort(needed);
			
			int x = minLevels(levels, needed);
			
			if (x == -1)
				log += "Too Bad";
			else
				log += x;
			
			out.println(log);
			stars = 0;
			totalLevels = 0;
			two = true;
		}
		
		out.close();
		System.exit(0);
	}

	private static int minLevels(int levels, MyPoint[] needed)
	{
		boolean b;
		
		while (stars != 2*levels)
		{
			if (two)
				twoStar(needed);
			else
			{
				b = oneStar(needed);
				
				if (!b && (stars != 2*levels))
				{
					return -1;
				}
			}
		}
		return totalLevels;
	}
	
	//INDEX
	//MAX Y MIN X
	public static int maxYIndex(MyPoint[] a)
	{
		int bestIndex = 0;
		int bestY = a[0].y;
		int bestX = a[0].x;
		
		for (int i = 1; i < a.length; i++)
		{
			if (a[i].y >= bestY)
			{
				if (a[i].x < bestX)
				{
					bestX = a[i].x;
					bestY = a[i].y;
					bestIndex = i;
				}
			}
		}
		
		return bestIndex;
	}
	
	//stop when all possible two star exhausted
	public static void twoStar(MyPoint[] needed)
	{
		two = true;
		
		while (two)
		{
			two = false;
			
			for (int i = 0; i < needed.length; i++)
			{
				if ((needed[i].y != -1) && (stars >= needed[i].y))
				{
					//System.out.println("S" + stars + " " + needed[i].y);
					//System.out.println(needed[i]);
					
					if (needed[i].x == -1)
					{
						stars++;
					}
					else
					{
						stars += 2;
					}
					
					needed[i].setLocation(-1,-1);
					totalLevels++;
					//System.out.println(totalLevels);
					two = true;
				}
			}
		}
	}
	
	//stop after the first one star, then check for two
	public static boolean oneStar(MyPoint[] needed)
	{
		for (int i = needed.length - 1; i >= 0; i--)
		{
			if ((needed[i].x != -1) && (stars >= needed[i].x))
			{
				//System.out.println("S" + stars + " " + needed[i].x);
				//System.out.println(needed[i]);
				needed[i].setLocation(-1, needed[i].y);
				stars++;
				totalLevels++;
				//System.out.println(totalLevels);
				two = true;
				return true;
			}
		}
		return false;
	}
}
