import java.util.*;
import java.io.*;
public class B{
	static int t, n, vis[],ans,mod=1000000007;
	static boolean[] b;
	static String[] arr;
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		t = i(in.readLine());
		for(int x = 0; x < t; x++)
		{
			ans  = 0;
			out.printf("Case #%d: ",x+1);
			n = i(in.readLine());
			b = new boolean[n];
			vis = new int[n];
			Arrays.fill(vis, -1);
			arr = in.readLine().split(" ");
			boolean done = false;
			for(int i = 0; i < arr.length; i++)
				if(!test(new StringBuilder(arr[i])))
				{
					out.println(0);
					done = true;
				}
			if(done) continue;
			permute(0);
			out.println(ans);
		}
		out.close();
		System.exit(0);
	}
	static void permute(int i)
	{
		if(i==n)
		{
			StringBuilder sb = new StringBuilder();
			for(int j= 0; j < vis.length; j++)
			{
				sb.append(arr[vis[j]]);
			}
			if(test(sb))
				ans=(ans+1)%mod;
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(!b[j])
				{
					b[j]=true;
					vis[i]=j;
					permute(i+1);
					b[j]=false;
					vis[i]=-1;
				}
			}
		}
	}
	static boolean test(StringBuilder s)
	{
		boolean let[] = new boolean[26];
		Arrays.fill(let,true);
		char prev = '0';
		for(int i = 0; i < s.length(); i++)
		{
			if(s.charAt(i)!=prev)
			{
				if(!let[s.charAt(i)-'a']) return false;
				let[s.charAt(i)-'a']=false;
				prev = s.charAt(i);
			}
		}
		return true;
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
	static long gcd(long a, long b)
	{
		return (b==0)? a: gcd(b,a%b);
	}
}
