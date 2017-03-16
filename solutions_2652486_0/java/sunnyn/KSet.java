import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class KSet {
	static int N;
	static long[] p; 
	static int[] m;
	public static void main(String args[]) throws IOException
	{
		long time = System.currentTimeMillis();
		BufferedReader in = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("test.out")));
		N = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());
		int R = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		out.println("Case #1:");
		for(int j=0; j<R; j++)
		{
			st = new StringTokenizer(in.readLine());
			long[] prod = new long[K];
			for(int k=0; k<K; k++)
			{
				prod[k] = Integer.parseInt(st.nextToken());
			}
			p = prod;
			m = new int[K];
			for(int l=0; l<K; l++)
				m[l] = N; 
			out.println(res());
		}
		in.close();
		out.close();
		System.out.println("Runtime: "+(System.currentTimeMillis()-time));
		System.exit(0);
	}
	public static String res()
	{
		String res = "";
		int num5 = findmaxPow(5);
		int num7 = findmaxPow(7);
		int num3 = findmaxPow(3);
		for(int i=0; i<num5; i++)
			res+="5";
		for(int i=0; i<num7; i++)
			res+="7";
		//
		for(int i=0; i<num3; i++)
			res+="3";
		//
		if(res.length()==3) return res;
		else if(res.length()==2)
		{
			for(int i=0; i<p.length; i++)
			{
				if(p[i]!=1) return res+p[i];
			}
			return res+"2";//or 4,3,5
		}
		else if(res.length()==1)
		{
			if(findmaxPow(16)==1) return res+"44";
			if(findmaxPow(8)==1) return res+"24";
			if(findmaxPow(4)==1) return res+"22"; //or 4+3,5
			if(findmaxPow(2)==1) return res+"22"; //or3,4,5
			return res+"22";
		}
		else
		{
			if(findmaxPow(64)==1) return res+"444";
			if(findmaxPow(32)==1) return res+"244";
			if(findmaxPow(16)==1) return res+"224"; //or 44x
			if(findmaxPow(8)==1) return res+"222"; //42x
			if(findmaxPow(4)==1) return res+"222"; //4xx or 22x
			if(findmaxPow(2)==1) return res+"222"; //2xx
			return res+"222";
		}
	}
	public static int findmaxPow(long x)
	{
		int max = 0;
		for(int i=0; i<p.length; i++)
		{
			for(int j=12; j>0; j--)
			{
				long r = (long)Math.pow(x, j);
				if(p[i]%r==0) 
				{
					max = Math.max(j,max);
					p[i]/=r;
					m[N]-=j;
					break;
				}
			}
		}
		return max;
	}
}
