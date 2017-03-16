import java.util.*;
import java.io.*;
public class Round1CProbB
{
	public static HashMap<String,Integer> cache = new HashMap<String,Integer>();
	public static void main(String[] args) throws Exception
	{
		String file = "Round1C/B-large.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("Round1C/outLargeB.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		for(int test=0;test<T;test++)
		{
			String[] parts = br.readLine().split(" ");
			int K = Integer.parseInt(parts[0]);
			int L = Integer.parseInt(parts[1]);
			int S = Integer.parseInt(parts[2]);
			String keys = br.readLine();
			String word = br.readLine();
			writer.println("Case #" + (test+1) + ": "+bananas(K,L,S,keys,word));
			System.out.println(test);
		}
		writer.close();
	}
	public static double bananas(int K, int L, int S, String keys, String word)
	{
		if(!canType(keys,word) || L>S)
		{
			return 0.0;
		}
		int max = maxBananas(K,L,S,keys,word);
		double ex = expectedSpent(K,L,S,keys,word);
		System.out.println(max+"/"+ex);
		return max-ex;
	}
	
	public static boolean canType(String keys, String word)
	{
		HashSet<Character> w = new HashSet<Character>();
		HashSet<Character> k = new HashSet<Character>();
		for(int i=0;i<word.length();i++)
		{
			w.add(word.charAt(i));
		}
		for(int i=0;i<keys.length();i++)
		{
			k.add(keys.charAt(i));
		}
		return k.containsAll(w);
	}
	
	public static int maxBananas(int K, int L, int S, String keys, String word)
	{
		int bestOverlap = 0;
		for(int i=1;i<word.length();i++)
		{
			if(word.endsWith(word.substring(0,i)))
			{
				bestOverlap = i;
			}
		}
		int restartEvery = L - bestOverlap;
		int ending = bestOverlap;
		System.out.println(bestOverlap+"*"+restartEvery);
		return (S-L)/restartEvery+1;
	}
	
	public static double expectedSpent(int K, int L, int S, String keys, String word)
	{
		double prob = 1.0;
		for(int i=0;i<word.length();i++)
		{
			int numKeys = 0;
			for(int k=0;k<keys.length();k++)
			{
				if(keys.charAt(k)==word.charAt(i))
				{
					numKeys++;
				}
			}
			prob = (prob * numKeys) / K;
		}
		return (S - L+1)*prob;
	}
}