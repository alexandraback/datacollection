import java.util.*;
import java.io.*;
public class Round1CProbA 
{
	public static HashMap<String,Integer> cache = new HashMap<String,Integer>();
	public static void main(String[] args) throws Exception
	{
		String file = "Round1C/A-small-attempt1.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1C/outASmall-1.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			String[] parts = br.readLine().split(" ");
			int R = Integer.parseInt(parts[0]);
			int C = Integer.parseInt(parts[1]);
			int W = Integer.parseInt(parts[2]);
			writer.println("Case #" + (test+1) + ": "+battleship(R,C,W));
			System.out.println(test);
		}
		writer.close();
	}
	public static int battleship(int R, int C, int W)
	{
		int eliminateRows = (R-1)*(C/W);
		return battleship(C,W) + eliminateRows;
	}
	
	public static int optimalMiss(int C, int W)
	{
		return C/W;
	}
	/*
	public static int battleship(int C, int W, int[] guesses)
	{
		if(C==W)
		{
			return W;
		}
		if(C<W)
		{
			return -1;
		}
		if(W==1)
		{
			return C;
		}
		if(C<W*2)
		{
			return 1+W;
		}
		for(int i=0;i<C;i++)
		{
			
		}
	}*/
	
	public static int battleship(int C, int W)
	{
		String key = C+":"+W;//left+":"+C+":"+W;
		if(cache.containsKey(key))
		{
			return cache.get(key);
		}
		if(C==W)
		{
			return W;
		}
		if(C<W)
		{
			return -1;
		}
		if(W==1)
		{
			return C;
		}
		if(C<W*2)
		{
			return 1+W;
		}
		/*int best = -1;
		
		for(int i=0;i<C;i++)
		{
			int hitTime = 1+W;
			
			int missTime = -1;
			

			int leftTime = battleship(i,W);
			if(leftTime!=-1)
			{
				leftTime+=optimalMiss(C-i-1,W);
			}
			
			int rightTime = battleship(C-i-1,W);
			if(rightTime!=-1)
			{
				rightTime+=optimalMiss(i,W);
			}
			
			int optTime = -1;
			if(leftTime==-1)
			{
				optTime = Math.max(rightTime,hitTime);
			}
			else if(rightTime==-1)
			{
				optTime = Math.max(leftTime,hitTime);
			}
			else
			{
				optTime = Math.max(Math.min(rightTime,leftTime),hitTime);
			}
			if(optTime!=-1)
			{
				if(best==-1 || optTime<best)
				{
					best = optTime;
				}
			}
		}*/
		//best = Math.min(best,C/W+1+W-1);
		int best = C/W+1+W-1;
		if(C%W==0)
		{
			best = Math.min(best,C/W+W-1);
		}
		cache.put(key,best);
		return best;
	}
}