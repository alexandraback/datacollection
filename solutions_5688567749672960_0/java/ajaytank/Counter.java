import java.io.*;
import java.util.*;

class Counter
{
	static BufferedReader br;
	static PrintWriter pw;
	static StringTokenizer st;
	static int n;
	static long[] ans;
	static public void main(String[] args)throws IOException
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Try No.");
		int tn=sc.nextInt();
		
		String file="Counter";
		if(tn==-1)
		{	
			br=new BufferedReader(new FileReader("test.in"));
			pw=new PrintWriter(System.out);
		}
		else
		{
			System.out.println("Small or Large");
			String chr=sc.next();
			if(chr.equals("s"))
			{
				br=new BufferedReader(new FileReader("A-small-attempt0.in"));
				pw=new PrintWriter(new FileWriter("ans"+file));
			}
			else
			{
				br=new BufferedReader(new FileReader(file+""+tn+".in"));
				pw=new PrintWriter(new FileWriter("ans"+file));
			}
				
		}
		
		int T=Integer.parseInt(br.readLine());
		ans=new long[1000001];
		ans[1]=1;
		for(int i=1;i<1000001;i++)
		{
			s(i);
		}
		for(int cn=1;cn<=T;cn++)
		{
			n=Integer.parseInt(br.readLine());
			pw.print("Case #"+cn+": ");pw.flush();
			solve();
		}
		
		pw.flush();
		pw.close();
		br.close();
	}
	
	static void solve()
	{
		pw.println(ans[n]);pw.flush();
	}
	
	
	static long s(int a)
	{
		if(a==1)return 1l;
		if(ans[a]!=0)return ans[a];
		
		if(lastZero(a))
		{
			ans[a]=s(a-1)+1;
			return ans[a];
		}
		int p=rev(a);
		if(p<a)
		{
			ans[a]=Math.min(s(a-1),s(p))+1;
			return ans[a];
		}
		
		ans[a]=s(a-1)+1;
		return ans[a];
		
	}
	static boolean lastZero(int a)
	{
		return a%10==0;
	}
	static int rev(int a)
	{
		String s=Integer.toString(a);
		String re=new StringBuffer(s).reverse().toString();
		return Integer.parseInt(re);
	}
}