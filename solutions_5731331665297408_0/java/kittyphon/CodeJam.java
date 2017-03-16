import java.util.Scanner;
import java.io.*;

public class CodeJam {
	
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int t=in.nextInt();
		for(int q=1;q<=t;q++)
		{
			out.print("Case #"+q+": ");
			int n=in.nextInt();
			int m=in.nextInt();
			int[][] M = new int[n][n];
			int[] code = new int[n];
			int[] ans = new int[n];
			for(int i=0;i<n;i++)
			{
				code[i]=in.nextInt();
				ans[i]=99999;
			}
			for(int i=0;i<m;i++)
			{
				int x=in.nextInt();
				int y=in.nextInt();
				x--;
				y--;
				M[x][y]++;
				M[y][x]++;
			}
			int[] tmp = new int[n];
			int[] check = new int[n];
			gen(M,code,ans,tmp,check,n,0);
			for(int i=0;i<n;i++)
				out.print(ans[i]);
			out.println();
		}
		in.close();
		out.close();
	}
	
	public static void walk(int[][] M,int[] tmp,int x,int[] next,int n)
	{
		if(next[0]==n)
			return;
		while(true)
		{
			if(M[x][tmp[next[0]]]==1)
			{
				int p=tmp[next[0]];
				next[0]++;
				walk(M,tmp,p,next,n);
			}
			else
				break;
			if(next[0]==n)
				break;
		}
		return;
	}
	
	public static void gen(int[][] M,int[] code,int[] ans,int[] tmp,int[] check,int n,int i)
	{
		if(i==n)
		{
			int[] next = new int[1];
			next[0]=1;
			walk(M,tmp,tmp[0],next,n);
			if(next[0]==n)
			{
				for(int j=0;j<n;j++)
					System.out.print(tmp[j]);
				System.out.println();
				int ok=0;
				for(int j=0;j<n;j++)
				{
					if(ans[j]>code[tmp[j]])
					{
						ok=1;
						break;
					}
					if(ans[j]<code[tmp[j]])
						break;
				}
				if(ok==1)
					for(int j=0;j<n;j++)
						ans[j]=code[tmp[j]];
			}
		}
		for(int j=0;j<n;j++)
		{
			if(check[j]==0)
			{
				check[j]=1;
				tmp[i]=j;
				gen(M,code,ans,tmp,check,n,i+1);
				check[j]=0;
			}
		}
	}
}
