import java.util.*;
import java.io.*;
public class A {
	static int t, ans, gen;
	static boolean poss;
	static long p,q;
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		t = i(in.readLine());
		for(int x = 0; x < t; x++)
		{
			out.printf("Case #%d: ",x+1);
			poss = false; gen = 1; ans = 45;
			String[] arr = in.readLine().split("/");
			p = Long.parseLong(arr[0]);
			q = Long.parseLong(arr[1]);
			if(p==q)
			{
				poss = true;
				ans = 0;
			}
			while(gen<=40)
			{
				//System.out.println(p+" "+q);
				if(2*p>=q)
				{
					long tp = (2*p-q)<<1;
					long tq = 2*q;
					p = tp;
					q = tq;
					ans = Math.min(ans,gen);
					if(p==0)
						poss = true;
					p/=gcd(tp,tq);
					q/=gcd(tp,tq);
				}
				else
				{
					
					if(q%2==0)
						q>>=1;
					else
						p<<=1;
					if(q==1)
						poss = true;
				}
				gen++;	
			}
			if(poss)
				out.println(ans);
			else
				out.println("impossible");
		}
		out.close();
		System.exit(0);
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
