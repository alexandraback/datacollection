import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File(
				"input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int t=0;t<T;t++)
			{
			String S[]=in.readLine().split(" ");
			int N=Integer.parseInt(S[0]);
			int M=Integer.parseInt(S[1]);
			int A[][]=new int[N][M];
			boolean Cut[][]=new boolean[N][M];
			for(int i=0;i<N;i++)
				A[i]=parseArray(in.readLine(),M);
			//rows
			for(int i=0;i<N;i++)
				{
				int max=0;
				for(int j=0;j<M;j++)
					max=Math.max(max,A[i][j]);
				for(int j=0;j<M;j++)
					{
					if(A[i][j]==max)
						Cut[i][j]=true;
					}
				}
			//cols
			for(int j=0;j<M;j++)
				{
				int max=0;
				for(int i=0;i<N;i++)
					max=Math.max(max,A[i][j]);
				for(int i=0;i<N;i++)
					{
					if(A[i][j]==max)
						Cut[i][j]=true;
					}
				}
			boolean valid=true;
			for(int i=0;i<N;i++)
				{
				for(int j=0;j<M;j++)
					{
					if(!Cut[i][j])
						valid=false;
					}
				}
			if(valid)
				out.println("Case #"+(t+1)+": YES");
			else
				out.println("Case #"+(t+1)+": NO");
			}
		out.close();
		}
	// Parse an integer array of size N from a string s
	public static int[] parseArray(String s,int N)
		{
		int A[]=new int[N];
		StringTokenizer st=new StringTokenizer(s);
		for(int i=0;i<N;i++)
			A[i]=Integer.parseInt(st.nextToken());
		return A;
		}
	}

//must declare new classes here