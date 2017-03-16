import java.io.*;
import java.util.*;

public class C
{
	static final int FAIL=-100000;
	static int[] bff;
	static boolean[] used;
	static int n, start;
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int numRuns=in.nextInt();
		for (int run=1; run<=numRuns; run++)
		{
			n=in.nextInt();
			bff=new int[n];
			for (int i=0; i<n; i++)
			{
				bff[i]=in.nextInt()-1;
			}
			
			int max=0;
			used=new boolean[n];
			for (start=0; start<n; start++)
				max=Math.max(max,assign(-1, start));
			System.out.printf("Case #%d: %d%n",run,max);
		}
	}
	
	static int assign(int prev, int curr)
	{
		if (curr<start)
			return FAIL;
		if (prev==bff[curr])
		{
			used[curr]=true;
			int max=1;
			for (int i=0; i<n; i++)
			{
				if (!used[i])
				{
					max=Math.max(max,1+assign(curr,i));
				}
			}
			used[curr]=false;
			return max;
		}
		else
		{
			if (bff[curr]==start)
				return 1;
			if (used[bff[curr]])
				return FAIL;
			used[curr]=true;
			int k=assign(curr,bff[curr]);
			used[curr]=false;
			return k+1;
		}
	}
}