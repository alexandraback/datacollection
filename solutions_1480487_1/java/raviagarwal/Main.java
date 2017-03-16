

import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer=null;
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
	
	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}
	
	int ni() throws IOException
	{
		return Integer.parseInt(ns());
	}
	
	long nl() throws IOException 
	{
		return Long.parseLong(ns());
	}
	
	double nd() throws IOException 
	{
		return Double.parseDouble(ns());
	}
		
	String ns() throws IOException 
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			tokenizer = new StringTokenizer(br.readLine());
		return tokenizer.nextToken();
	}
	
	String nline() throws IOException
	{
		tokenizer=null;
		return br.readLine();
	}
		
	

	//Main Code starts Here
	int totalCases, testNum;	
	int N;
	int s[];
	int sum;
	
	void execute() throws IOException
	{
		totalCases = ni();
		for(testNum = 1; testNum <= totalCases; testNum++)
		{
			if(!input())
				break;
			solve();
		}
	}
	
	void solve() throws IOException
	{
		double x[] = new double[N];
		double want = (2.0*sum)/N;
		int s2 = 0;
		int p2 = 0;
		for(int i = 0;i<N;i++)
		{
			if(s[i]>want)
			{
				s2 = s2+s[i];
				p2++;
			}
		}
		//debug(want);
		want = ((sum + sum - s2)*1.0)/(N-p2);
		//debug(want);
		
		for(int i = 0;i<N;i++)
		{			
			x[i] = ((want-(double)s[i])*100.0)/sum;		
			if(x[i]<0)
				x[i] = 0.0;
		}
		System.out.print("Case #"+testNum+":");
		for(int i = 0;i<N;i++)
		{
			System.out.printf(" %.6f",x[i]);
		}
		System.out.println();
	}

	boolean input() throws IOException
	{
		N = ni();
		s = new int[N];
		sum = 0;
		
		for(int i = 0;i<N;i++)
		{			
			s[i] = ni();		
			sum+=s[i];
		}
		return true;
	}
}
