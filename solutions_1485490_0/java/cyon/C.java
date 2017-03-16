import java.util.Arrays;
import java.util.Scanner;

public class C {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			System.out.println("Case #" + c + ": " + solve(sc));
		}
	}
	
	private static String solve(Scanner sc)
	{
		int N=sc.nextInt();
		int M=sc.nextInt();
		
		long[]ai=new long[N];
		long[]bi=new long[M];
		int[]at=new int[N];
		int[]bt=new int[M];
		
		for(int i=0;i<N;i++)
		{
			ai[i]=sc.nextLong();
			at[i]=sc.nextInt();
		}
		
		for(int i=0;i<M;i++)
		{
			bi[i]=sc.nextLong();
			bt[i]=sc.nextInt();
		}
		
		long maxi=-1;
		
		maxi = rec(0,0,ai,at,bi,bt);
		
		return Long.toString(maxi);
	}

	private static long rec(int i, int j, long[] ai, int[] at, long[] bi,
			int[] bt)
	{
		long cnt=0;
		
		//debug(i,j,ai,bi);
		
		if(i==ai.length || j==bi.length)
			return 0;
		
		if(at[i]==bt[j])
		{
			cnt=Math.min(ai[i], bi[j]);
			ai[i]-=cnt;
			bi[j]-=cnt;
			
			int ni=i;
			int nj=j;
			
			if(ai[i]==0)
			{
				ni++;
			}
			if(bi[j]==0)
			{
				nj++;
			}
			
			long res = cnt+rec(ni,nj,ai,at,bi,bt); 
			
			ai[i]+=cnt;
			bi[j]+=cnt;
			
			return res;
		}
		else
		{
			return Math.max(rec(i+1,j,ai,at,bi,bt), rec(i,j+1,ai,at,bi,bt));
		}
	}

	static void debug(Object... objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}

}