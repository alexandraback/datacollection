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
	int m,n;
	
	void execute() throws IOException
	{
		totalCases = ni();
		for(testNum = 1; testNum <= totalCases; testNum++)
		{
			input();
			System.out.println("Case #"+testNum+":");
			solve();
		}
	}

	void solve()
	{
		double[] temp = new double[n];
		for(int i =0;i<n;i++)
		{
			double x = (2*s)/n-arr[i];
			temp[i]=((x*100)/s);
		}
		//double x = (2*s)/n-arr[n-1];
		//System.out.println((x*100)/s);
		boolean[] check  = new boolean[n];
		int count = 0;
		int sumn = 0;
		for(int i =0;i<n;i++)
		{
			check[i]=true;
			if(temp[i]<=0)
				check[i]=false;
			else
			{
				count++;
				sumn+=arr[i];
			}
		}
		
		double[] temp2 = new double[n];
		for(int i =0;i<n;i++)
		{
			if(check[i])
			{	
				double x = (s+sumn)/count-arr[i];
				temp2[i]=((x*100)/s);
			}
		}
		//debug(count);
		//double ans = 0;
		for(int i =0;i<n-1;i++)
		{
			//ans+=temp2[i];
			System.out.print(temp2[i]+" ");
		}
		//double x = (2*s)/n-arr[n-1];
		System.out.println(temp2[n-1]);
		//ans+=temp2[n-1];
				
		//debug(ans);
	}
	
	void printarr(int [] a,int b)
	{
		for(int i = 0;i<=b;i++)
		{
			if(i==0)
				System.out.print(a[i]);
			else
				System.out.print(" "+a[i]);
		}
		System.out.println();
	}
	int[] arr;
	double s;
	boolean input() throws IOException
	{
		n = ni();
		s = 0;
		arr = new int[n];
		for(int i =0;i<n;i++)
		{
			arr[i]=ni();
			s+=arr[i];
		}
		return true;
	}
}