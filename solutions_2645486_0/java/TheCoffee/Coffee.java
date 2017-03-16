import java.io.*;
import java.util.*;

public class Coffee
{
	public static int maxGain = 0;
	
	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.txt")));
			
			int cases = Integer.parseInt(br.readLine());
			
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			for(int i = 0; i < cases; i++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				maxGain = 0;
				int e = Integer.parseInt(st.nextToken()); // Max energy
				int r = Integer.parseInt(st.nextToken()); // Regain value
				int n = Integer.parseInt(st.nextToken()); // Number of activities
				
				st = new StringTokenizer(br.readLine());
				int[] v = new int[n];
				for(int j = 1; j <= n; j++)
				{
					v[n-j] = Integer.parseInt(st.nextToken());
				}
				
				process(e, e, r, v, 0);
				
				System.out.println("Case #" + (i+1) + ": " + maxGain);
				
				//writer.println("Case #" + (i+1) + ": " + process(r, t) );
			}
			writer.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static void process(int max, int current, int r, int[] v, int gain)
	{
		
		if(gain > maxGain)
		{
			maxGain = gain;
		}
		
		if(v.length != 0)
		{
			for(int i = 0; i <= current; i++)
			{
				/*
				System.out.println("Max " + max
				  		+ "   Current " + Math.min(current-i+r, max)
				  		+ "   r " + r
				  		+ "   v " + Arrays.toString( Arrays.copyOfRange(v, 0, v.length-1) )
				  		+ "   gain " +  i * v[v.length-1] 
				  		+ "   i " + i );
				*/
				
				process(
					max,
					Math.min(current-i+r, max),
					r,
					Arrays.copyOfRange(v, 0, v.length-1),
					gain + (i * v[v.length-1])
					);
			}
		}
	}
}