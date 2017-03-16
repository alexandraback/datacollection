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
	int totalCases, testnum;
	

	void execute() throws IOException
	{
		totalCases = ni();
		for(testnum = 1; testnum <= totalCases; testnum++)
		{
			if(!input())
				break;
			solve();
		}
	}

	int A,B;
	void solve() throws IOException
	{
		int ans=0;
		for(int i=A;i<=B;i++)
		{
			String s=String.valueOf(i);
			int n=s.length();
			HashSet<Integer> set=new HashSet<Integer>();
			for(int j=1;j<n;j++)
			{
				String t = s.substring(n-j,n) + s.substring(0,n-j);
				int k=Integer.parseInt(t);
				if(i<k && k<=B)
					set.add(k);
			}
			ans += set.size();
		}
		System.out.printf("Case #%d: %d\n",testnum,ans);
	}

	boolean input() throws IOException
	{
		A=ni();
		B=ni();
		return true;
	}
}