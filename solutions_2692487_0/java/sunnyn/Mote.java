import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Mote {
	static int N;
	public static void main(String args[]) throws IOException
	{
		long time = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("test.out")));
		N = Integer.parseInt(in.readLine());
		for(int i=0; i<N; i++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			int A = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(in.readLine());
			int[] motes = new int[M];
			for(int j=0;j<M; j++)
				motes[j] = Integer.parseInt(st.nextToken()); 
			out.println("Case #"+(i+1)+": "+parse(A, motes));
			System.out.println("Case #"+(i+1)+": "+parse(A, motes)+ "  :"+A+":" +Arrays.toString(motes));
		}
		in.close();
		out.close();
		System.out.println("Runtime: "+(System.currentTimeMillis()-time));
		System.exit(0);
	}
	public static int min(int A, int D)
	{
		if(A>D) return 0;
		int c = 0;
		while(A<D)
		{
			A += A-1;
			c++;
		}
		return c;
	}
	public static int parse(int A, int[] motes)
	{
		int min = Integer.MAX_VALUE;
		if(A==1) return motes.length;
		Arrays.sort(motes);
		int c =0;
		for(int i=0; i<motes.length; i++)
		{
			if(A>motes[i]) A+=motes[i];
			else 
			{
				if(A+A-1>motes[i])
				{
					A = A + A - 1 + motes[i];
				    c++;
				}
				else
				{
					min = Math.min(min, c + motes.length-i);
					
					int cc = 0;
					while(A<=motes[i])
					{
						A += A-1;
						cc++;
					}
					c += cc;
					A += motes[i];/*
					int n=(motes[i]-A)/(A-1)+1;
					A  = A + n*(A-1) + motes[i];
					c+=n;*/
				}
			}
		}
		return Math.min(min,c);
	}
}
