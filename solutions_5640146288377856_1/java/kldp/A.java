package Codejam_1C;

import java.util.Scanner;

public class A 
{
	static Scanner s;
	public static void main(String args[])
	{
		s=new Scanner(System.in);
		int T=s.nextInt();
		for(int t=1;t<=T;t++)
		System.out.println("Case #"+t+": "+solve(s.nextInt(),s.nextInt(),s.nextInt()));
	}
	public static int solve(int r,int c,int w)
	{
		int ans=0;
		if(r>1)
		{
			ans=(r-1)*(c/w);
	//		System.out.println(ans);
		}
		if(c>=2*w)
		{
			ans+=c/w-1;
			c=c-(c/w-1)*w;
	//		System.out.println(ans+" "+c);
		}
		ans+=solve2(c,w);
		return ans;
	}
	public static int solve2(int a, int n)
	{
		if(a==n)
			return n;
		else return n+1;
	}
}


