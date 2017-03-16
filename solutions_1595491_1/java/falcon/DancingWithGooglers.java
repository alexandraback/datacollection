package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class DancingWithGooglers 
{
	boolean[][] isPossibleNormal;
	boolean[][] isPossibleSurprising;
	
	int P;
	int[] totalPoints;
	int N;
	int[][] memo;
	
	public DancingWithGooglers()
	{
		this.isPossibleNormal=new boolean[31][11];
		this.isPossibleSurprising=new boolean[31][11];
		for(int i=0;i<31;++i)
		{
			Arrays.fill(isPossibleNormal[i],false);
			Arrays.fill(isPossibleSurprising[i],false);
		}
		for(int a=0;a<=10;++a)
		{
			for(int b=0;b<=10;++b)
			{
				for(int c=0;c<=10;++c)
				{
					int total=a+b+c;
					int best=Math.max(a, b);
					best=Math.max(best, c);
					int maxDiff=Math.max(0,Math.abs(a-b));
					maxDiff=Math.max(maxDiff,Math.abs(b-c));
					maxDiff=Math.max(maxDiff,Math.abs(a-c));					
					if(maxDiff>2)
						continue;
					else if(maxDiff==2)
					{
						isPossibleSurprising[total][best]=true;
					}
					else
					{
						isPossibleNormal[total][best]=true;
					}					
				}
			}
		}
	}
	
	private int solve(int idx,int surpriseLeft)
	{
		if(idx>=N)
		{
			if(surpriseLeft==0)
				return 0;
			else
				return -2;			
		}
		else if(memo[idx][surpriseLeft]!=-1)
			return memo[idx][surpriseLeft];
		else
		{
			int ret=Integer.MIN_VALUE,t1=ret,t2=ret, t3=ret,t4=ret;
			boolean goNormal=false, goSurprising=false;
			for(int possi=P;possi<=10;++possi)
			{
				if(isPossibleNormal[totalPoints[idx]][possi])
					goNormal=true;
				if(isPossibleSurprising[totalPoints[idx]][possi])
					goSurprising=true;
			}
			if(goNormal)
			{
				int t=solve(idx+1,surpriseLeft);
				if(t!=-2)
					t1=1+t;
			}
			if(goSurprising && surpriseLeft>0)
			{
				int t=solve(idx+1,surpriseLeft-1);
				if(t!=-2)
					t2=1+t;
			}			
			{
				//ignore current idx and then not alter surpriseLeft
				int t=solve(idx+1,surpriseLeft);
				if(t!=-2)
					t3=t;
			}
			if(surpriseLeft>0)
			{
				int t=solve(idx+1,surpriseLeft-1);
				if(t!=-2)
				{
					t4=t;
				}
			}
			ret=Math.max(ret,t1);
			ret=Math.max(ret,t2);
			ret=Math.max(ret,t3);
			ret=Math.max(ret,t4);
			if(ret==Integer.MIN_VALUE)
				ret=-2;
			memo[idx][surpriseLeft]=ret;
			return ret;
		}
	}
	private int getMaximumGooglers(int N,int S,int P, int[] totalPoints)
	{
		this.N=N;
		this.P=P;
		this.totalPoints=totalPoints;
		this.memo=new int[N+1][N+1];
		for(int i=0;i<=N;++i)
			Arrays.fill(memo[i],-1);
		int ret=solve(0,S);
		return ret;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception 
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		DancingWithGooglers obj=new DancingWithGooglers();
		for(int t=1;t<=T;++t)
		{
			String[] tok=br.readLine().trim().split(" ");
			int N=Integer.valueOf(tok[0]);
			int S=Integer.valueOf(tok[1]);
			int P=Integer.valueOf(tok[2]);
			int[] totalPoints=new int[N];
			for(int j=0;j<N;++j)
				totalPoints[j]=Integer.valueOf(tok[3+j]);
			int ret=obj.getMaximumGooglers(N, S, P, totalPoints);
			System.out.println("Case #"+t+": "+ret);
		}
		br.close();

	}

}