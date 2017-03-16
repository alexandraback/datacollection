import java.io.*;
import java.util.*;
public class Salesman
{
	static String bestZip;
	static int N, M;
	static boolean [][] paths = new boolean [51][51];
	static boolean [] outboundAlready = new boolean[51];
	static boolean [][]returns= new boolean[51][51];
	static String []zips = new String[51];
	
	public static boolean checkReturns ()
	{
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=N;j++)
			{
				if (returns[i][j])
					return false;
			}
		}
		return true;
	}
	
	public static void travel (int curCity, String curZip, int citiesVisited)
	{
		if (citiesVisited==N)
		{
			//Are there outstanding flights?
			if (checkReturns())
			{
				if (curZip.compareTo(bestZip)<0)
					bestZip = curZip;
				return;
			}
		}
		
		//Try to visit every city
		for (int i=1;i<=N;i++)
		{
			if (i==curCity)
				continue;
				
			if (paths[curCity][i])
			{
				if (!outboundAlready[i])
				{
					//Travel to i!
					returns[i][curCity] = true;
					outboundAlready[i] = true;
					//System.out.println ("Going " + curCity + " to " + i);
					travel (i, curZip + zips[i], citiesVisited +1);
					returns[i][curCity] = false;
					outboundAlready[i] = false;
				}
				else if (returns[curCity][i])
				{
					returns[curCity][i] = false;
					//System.out.println ("Going " + curCity + " to " + i);
					travel(i,curZip,citiesVisited);
					returns[curCity][i] = true;
				}
			}
		}
		
	}

	public static void main (String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader (new FileReader ("C-small.txt"));
		PrintWriter out = new PrintWriter (new FileWriter ("Coutput.txt"));
		
		
		int trials = Integer.parseInt (br.readLine ());
		for (int t=1;t<=trials;t++)
		{
			//System.out.println ("Trial " + t);
		
			StringTokenizer st = new StringTokenizer (br.readLine ());
			N = Integer.parseInt (st.nextToken());
			M = Integer.parseInt (st.nextToken());
			bestZip = "9999999";
			
			for (int i=1;i<=N;i++)
			{
				zips[i] = br.readLine ();
				
				for (int j=1;j<=N;j++)
				{
					paths[i][j] = false;
					returns[i][j] = false;
				}
				outboundAlready [i] = false;
			}
			
			//Get paths
			for (int i=0;i<M;i++)
			{
				st = new StringTokenizer (br.readLine ());
				int cityA = Integer.parseInt (st.nextToken ());
				int cityB = Integer.parseInt (st.nextToken ());
				paths[cityA][cityB] = true;
				paths[cityB][cityA] = true;
			}
			
			//Try starting from each of the N cities
			for (int i=1;i<=N;i++)
			{
				outboundAlready[i] = true;
				travel (i,zips[i],1);
				outboundAlready[i] = false;
			}
			
			out.println ("Case #" + t + ": " + bestZip);
			
		}
		out.close();
	}
}

