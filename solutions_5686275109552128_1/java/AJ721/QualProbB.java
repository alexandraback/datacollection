import java.util.*;
import java.io.*;
public class QualProbB {
	
	//private static HashMap<Integer,Integer> cache = new HashMap<Integer,Integer>();
	//private static HashMap<Integer,Integer> cache = new HashMap<Integer,Integer>();
	private static int[][] cache;
	public static void main(String[] args) throws Exception
	{
		String file = "B-large.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			//cache.clear();
			int MAX = 1000;
			cache = new int[MAX][MAX];
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					cache[i][j]=-1;
				}
			}
			line=br.readLine();
			int D = Integer.parseInt(line);
			int[] P = new int[D];
			line=br.readLine();
			String[] parts = line.split(" ");
			for(int i=0;i<parts.length;i++)
			{
				P[i] = -Integer.parseInt(parts[i]);
			}
			Arrays.sort(P);
			int best = MAX;
			for(int moves=0;moves<-P[0];moves++)
			{
				int current = moves+bestMax(0,moves,P);
				best = Math.min(best,current);
			}
			
			writer.println("Case #"+(test+1)+": " + best);
			System.out.println(test);
		}
		writer.close();
	}
	
	public static int bestMax(int eater, int movesLeft, int[] P)
	{
		if(eater>=P.length)
			return 0;
		int current = -P[eater];
		if(current<=2 || movesLeft<=0)
		{
			return current;
		}
		if(cache[eater][movesLeft]>=0)
		{
			return cache[eater][movesLeft];
		}
		int best = current;
		for(int div=2;div<=current/2 && div<=movesLeft+1;div++)
		{
			int transferTime = div-1;
			int ourMax = (int)Math.ceil((double)current/div);
			int otherMax = bestMax(eater+1, movesLeft-transferTime, P);
			int fullMax = Math.max(ourMax,otherMax);
			if(fullMax<best)
			{
				best = fullMax;
			}
		}
		cache[eater][movesLeft]=best;
		return best;
	}
	
	/*public static int bestTime(int eater, int[] P)
	{
		
		
		if(eater>=P.length)
		{
			return 0;
		}
		int current = -P[eater];
		if(current<=2)
		{
			return current;
		}
		if(cache.containsKey(eater))
		{
			return cache.get(eater);
		}
		
		int best = current;
		for(int div=2;div<=current;div++)
		{
			int transferTime = div-1;
			int afterSplit = (int)Math.ceil((double)current/div);
			int ourTime = afterSplit;
			int othersTime = bestTime(eater+1,P);
			int fullTime = Math.max(ourTime,othersTime)+transferTime;
			if(fullTime<best)
			{
				best = fullTime;
			}
		}
		cache.put(eater,best);
		return best;
	}*/

}