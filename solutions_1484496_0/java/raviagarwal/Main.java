

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
	int MAXN = 2000000;
	int n;
	int arr[];	
	int done[][] = new int[MAXN][20];
	int got[];
	
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
		//done = new int[MAXN][20];
		got = new int[MAXN];
		int upto = (int)Math.pow(2,n);
		boolean ohyes = false;
		for(int i = 1;i<upto;i++)
		{
			int temp[] = new int[n];
			
			int ind = 0;			
			int sum = 0;
			
			for(int j = 0;j<n;j++)
			{
				int a = 1<<j;
				if((a&i)>0)
				{
					sum = sum+arr[j];
					temp[ind++] = arr[j];
				}
			}
			if(got[sum] == 0)
			{
				for(int j = 0;j<ind;j++)
				{
					done[sum][j] = temp[j];
				}
				got[sum] = ind;
			}
			else
			{
				System.out.println("Case #"+testNum+":");
				//System.out.print(done[sum][0]);
				for(int j = 0;j<got[sum];j++)
				{
					System.out.print(done[sum][j]+" ");
				}
				System.out.println();
				//System.out.print(temp[0]);
				for(int j = 0;j<ind;j++)
				{
					System.out.print(temp[j]+" ");
				}
				System.out.println();
				ohyes = true;
				break;
			}
			
		}
		if(!ohyes)
		{
			System.out.print("Case #"+testNum+":\n");
			System.out.print("Impossible\n");
		}
	}

	boolean input() throws IOException
	{
		n = ni();
		arr = new int[n];
		for(int i = 0;i<n;i++)
		{
			arr[i] = ni();			
		}
		return true;
	}


}


