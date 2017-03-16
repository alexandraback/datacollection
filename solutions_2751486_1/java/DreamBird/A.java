import java.io.*;
import java.util.*;
import java.math.*;

public class A
{
	public static void main (String args []) throws IOException
	{
		BufferedReader br = new BufferedReader (new FileReader ("A-large.in"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("ALoutput.out")));
		
		int t = Integer.parseInt (br.readLine ());
		
		for (int trial = 1; trial <= t; trial ++)
		{
			//System.out.println ("Case " + trial);
		
			StringTokenizer line = new StringTokenizer (br.readLine ());
			
			String word = line.nextToken ();
			int N = Integer.parseInt (line.nextToken ());
			int L = word.length();
			
			int [] starts = new int [L+1];
			int [] ends = new int [L+1];
			starts[0] = -1;
			int subs = 1;
			
			int counter = 0;
			for (int i=0;i<L;i++)
			{
				char c = word.charAt(i);
				if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
				{
					counter++;
					//System.out.println (i + ", " + counter);
					if (counter >= N)
					{
						ends[subs] = i;
						starts[subs] = i-N+1;
						subs++;
					}
				}
				else
					{
						counter = 0;
					}
			}
			
			BigInteger answer = new BigInteger (""+0);
			
			for (int i=1;i<subs;i++)
			{
				//System.out.println (i);
				//System.out.println ((starts[i] - starts[i-1]) + " x " + (L - ends[i]));
				answer = answer.add(new BigInteger(""+ (starts[i] - starts[i-1]) * (L - ends[i])));
			}
			
			out.println ("Case #" + trial + ": " + answer);
		}
		
		out.close();
		br.close();
	}
}