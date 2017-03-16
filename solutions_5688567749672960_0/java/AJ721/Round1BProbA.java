import java.util.*;
import java.io.*;
public class Round1BProbA 
{
	//public static HashMap<String,Long> cache = new HashMap<String,Long>();
	public static void main(String[] args) throws Exception
	{
		String file = "Round1B/A-small-attempt1.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1B/outAsm2.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			long N = Long.parseLong(br.readLine());
			writer.println("Case #" + (test+1) + ": "+count(N));
			System.out.println(test);
		}
		writer.close();
	}
	
	public static long reverse(long N)
	{
		String str = Long.toString(N);
		if(str.length()<=1) return N;
		StringBuilder out = new StringBuilder();
		boolean trailing = true;
		for(int i=str.length()-1;i>=0;i--)
		{
			if(str.charAt(i)!='0' || !trailing)
			{
				out.append(str.charAt(i));
				trailing = false;
			}
		}
		return Long.parseLong(out.toString());
	}

	public static long count(long to)
	{
		int len = (Long.toString(to)).length();
		long MAX = (long)Math.pow(10,len);
		//long[] cache = new long[(int)MAX];
		HashMap<Long,Long> cache = new HashMap<Long,Long>();
		cache.put(to, 1L);
		Queue<Long> q = new LinkedList<Long>();
		q.add(to);
		while(!q.isEmpty())
		{
			long next = q.remove();
			long cn = cache.get(next);
			if(next<MAX)
			{
				if(next==1)
				{
					return cn;
				}
				long rev = reverse(next);
				if(reverse(rev)==next)
				{
					if(!cache.containsKey(rev))
					{
						cache.put(rev, cn+1);
						q.add(rev);
					}
				}
				if(next>1)
				{
					
					if(!cache.containsKey(next-1))
					{
						cache.put(next-1, cn + 1);
						if(next-1==1)
						{
							return cn+1;
						}
						q.add(next-1);
					}
				}
				
			}
		}
		return -1;
	}
	/*public static long count(long from, long to, boolean revved)
	{
		System.out.println(from);
		if(from==to)
		{
			return 1;
		}
		if(from>to*10)
		{
			return -1;
		}
		if(cache.containsKey(from+","+to))
		{
			return cache.get(from+","+to);
		}
		long plusDist = count(from+1,to,false) + 1;
		long revDist = -1;
		long rev = reverse(from);
		if(!revved && rev!=from)
			revDist = revved ? -1 : count(rev,to,true)+1;
		
		long ans = 0;
		if(plusDist ==-1 && revDist == -1)
		{
			ans = -1;
		}
		else if(revDist == -1)
		{
			ans = plusDist;	
		}
		else if(plusDist == -1)
		{
			ans = revDist;
		}
		else
		{
			ans = Math.min(plusDist,revDist);
		}
		cache.put(from+","+to,ans);
		return ans;
	}*/
	/*public static long counter(long N)
	{
		if(cache.containsKey(N))
		{
			return cache.get(N);
		}
			
		int len = Long.toString(N).length();//(int)(Math.log(N)/Math.log(10))+1;
		if(len<=1)
		{
			return N;
		}
		
		long NR = reverse(N);
		
		long ans = Math.min(counter2(N),counter2(NR)+1);
		cache.put(N,ans);
		return ans;
	}
	
	public static long counter2(long N)
	{
		long refNum = Math.pow(10,len-1)*9+1;
		long revNumR = Math.pow(10,len-1)*1+0;
		if(N==refNum)
		{
			long prevRef = Math.pow(10,len-2)*9+1;
			return counter(prevRef) + (revNumR-prevRef) + 1;
		}
		else if(N>refNum)
		{
			counter(refNum)+(N-refNum);
		}
		else
		{
			
		}
	}*/
}
			