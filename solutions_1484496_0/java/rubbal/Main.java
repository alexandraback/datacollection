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
	HashMap<Integer,Integer> h;
	void solve()
	{
		h = new HashMap<Integer,Integer>();
		boolean b = false;
		int i;
		int sum=0;
		for(i = 1 ;i<Math.pow(2,n);i++)
		{
			//debug(h);
			String s = Integer.toBinaryString(i);
			s = app(s);
			//debug(s);
			sum = 0;
			for(int j =0;j<n;j++)
				sum+=(s.charAt(j)-'0')*arr[j];
			if(h.containsKey(sum))
			{
				//debug(s,sum);
				b=true;
				break;
			}
			else
				h.put(sum,i);
		}
		if(b)
		{
			Vector<Integer> s1 = new Vector<Integer>();
			Vector<Integer> s2 = new Vector<Integer>();
			String s = Integer.toBinaryString(h.get(sum));
			s = app(s);
			int l  =s.length();
			for(int j =0 ;j<n;j++)
			{
				if(s.charAt(j)=='1')
					s1.add(arr[j]);
			}
			s = Integer.toBinaryString(i);
			l  =s.length();
			s = app(s);
			for(int j =0 ;j<n;j++)
			{
				if(s.charAt(j)=='1')
					s2.add(arr[j]);
			}
			
			System.out.print(s1.get(0));
			for(i =1;i<s1.size();i++)
				System.out.print(" "+s1.get(i));
			 System.out.println();
			System.out.print(s2.get(0));
			for(i =1;i<s2.size();i++)
				System.out.print(" "+s2.get(i));
			System.out.println();
		}
		else	
			System.out.println("Impossible");
	}


	String app(String s)
	{
		int k = n - s.length();
		StringBuilder t = new StringBuilder("");
		for(int i =0;i<k;i++)
			t.append("0");
		t.append(s);
		return new String(t);
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
	boolean input() throws IOException
	{
		n = ni();
		arr = new int[n];
		for(int i =0;i<n;i++)
			arr[i] = ni();
		return true;
	}
}