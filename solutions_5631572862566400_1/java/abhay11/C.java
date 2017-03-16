import java.io.*;
import java.util.*;

public class C
{
	static final int FAIL=-100000;
	static int[] bff;
	static int[] loc,len;
	static int n;
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int numRuns=in.nextInt();
		for (int run=1; run<=numRuns; run++)
		{
			n=in.nextInt();
			bff=new int[n];
			len=new int[n];
			loc=new int[n];
			for (int i=0; i<n; i++)
			{
				bff[i]=in.nextInt()-1;
				len[i]=FAIL;
				loc[i]=FAIL;
			}
			
			for (int i=0; i<n; i++)
				assign(0,i);
			int maxcycle=0;
			int sumcycle=0;
			for (int i=0; i<n; i++)
			{
if (args.length>0) System.out.println((i+1)+" "+(loc[i]+1)+" "+len[i]);
				if (loc[i]==-2 && len[i]>maxcycle)
					maxcycle=len[i];
				if (bff[bff[i]]==i)
					sumcycle+=1+len[i];
			}
			System.out.printf("Case #%d: %d%n", run, Math.max(maxcycle,sumcycle));
		}
	}
	
	static int assign(int sofar, int curr)
	{
		if (bff[bff[curr]]==curr)
		{
			loc[curr]=curr;
			len[curr]=Math.max(len[curr],sofar);
			return 1;
		}
		if (loc[curr]>=0)
		{
			len[loc[curr]]=Math.max(len[loc[curr]],sofar+len[curr]);
			return len[curr]+1;
		}
		if (loc[curr]==-2)
			return 0;
		if (loc[curr]==-1)
		{
			loc[curr]=-2;
			len[curr]=sofar-len[curr];
			return len[curr];
		}
		loc[curr]=-1;
		len[curr]=sofar;
		len[curr]=assign(sofar+1,bff[curr]);
		if (loc[curr]==-2)
			return 0;
		loc[curr]=loc[bff[curr]];
		if (loc[curr]==-2)
			return len[curr];
		return len[curr]+1;
	}
}