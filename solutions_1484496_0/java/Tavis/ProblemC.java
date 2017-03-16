package gcj2012.round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;

public class ProblemC
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		PrintStream out = new PrintStream("out.txt");
//		out = System.out;
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 0; t < T; t++)
		{
			String ans1 = "", ans2 = "";
			String[] tok = in.readLine().split(" ");
			int N = Integer.parseInt(tok[0]);
			int[] S = new int[N];
			for (int i = 0; i < N; i++)
			{
				S[i] = Integer.parseInt(tok[i+1]);
			}
			HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
			for (int bb = (1<<20)-1; bb > 0; bb--)
			{
				int sum = 0, b = bb;
				for (int i = 0; b>0; i++,b>>=1)
				{
					if(b%2==1) sum += S[i];
				}
				if (count.containsKey(sum))
				{
					ans1 = subset(S, count.get(sum));
					ans2 = subset(S, bb);
				}
				else
				{
					count.put(sum, bb);
				}
			}
			if (ans1.length() > 0)
			{
				out.printf("Case #%d:\n%s\n%s\n", t+1, ans1, ans2);
			}
			else
			{
				out.printf("Case #%d:\nImpossible\n", t+1);
			}
		}
		out.close();
	}
	
	static String subset(int[] S, int b)
	{
		String ss = "";
		for (int i = 0; b>0; i++,b>>=1)
		{
			if (b%2==1) ss += " " + S[i];
		}
		return ss.substring(1);
	}
}
