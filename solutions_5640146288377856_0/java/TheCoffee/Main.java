import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		int cases = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < cases; i++)
		{
			System.out.print("Case #" + (i+1) + ": ");
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int r = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			process(r, t, w);
		}
	}
	
	// r = 1
	// t = columns
	// w = width
	public static void process(int r, int t, int w)
	{
		//System.out.println( "" + r + " " + t + " " + w );
		int answer = -1;
		
		int movesForFirstHit = 0;
		int hitPosition = w;
		for(int i = w; i <= t; i += w )
		{
			movesForFirstHit++;
			hitPosition = i;
		}
		
		if(hitPosition == t)
		{
			//System.out.println("LAST");
			answer = movesForFirstHit + (w-1);
		}
		else
		{
			answer = movesForFirstHit + w;
		}
		
		//System.out.println(hitPosition);
		//System.out.println(movesForFirstHit);
		System.out.println("" + answer);
		
	}
}
	