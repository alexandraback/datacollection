import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File(
				"input.txt")));
		int T=Integer.parseInt(in.readLine());
		BinaryIndexedTree Tr=new BinaryIndexedTree(10000002);
		for(int i=1;i<=10000001;i++)
			{
			long sq=(long)i*i;
			if(isPalindrome(Long.toString(sq))&&isPalindrome(Integer.toString(i)))
				{
				System.out.println("sq of "+i);
				Tr.update(i,1);
				}
			}
		for(int t=0;t<T;t++)
			{
			String S[]=in.readLine().split(" ");
			long A=Long.parseLong(S[0]);
			long B=Long.parseLong(S[1]);
			long As=(long)Math.sqrt(A);
			long Bs=(long)Math.sqrt(B);
			int ans=0;
			if(As*As==A)
				{
				if(As==1)
					ans=Tr.query((int)Bs);
				else
					ans=Tr.query((int)Bs)-Tr.query((int)(As-1));
				}
			else
				ans=Tr.query((int)Bs)-Tr.query((int)(As));
			out.println("Case #"+(t+1)+": "+ans);
			}
		out.close();
		}

	private static boolean isPalindrome(String s)
		{
		String ss="";
		for(int i=s.length()-1;i>=0;i--)
			ss=ss+s.charAt(i);
		return ss.equals(s);
		}
	}

/*
 * Create a BinaryIndexedTree where query(i) returns the sum
 * of entries 1-->i.
 * IMPORTANT: Array indices supported are 1-->N for both query
 * and update operations.
 */
class BinaryIndexedTree
	{
	int bit[];
	int n;

	public BinaryIndexedTree(int n)
		{
		this.bit=new int[n+1];
		this.n=n;
		}

	public int query(int i) //get the sum A[1]-->A[i];
		{
		int ans=0;
		while (i>0)
			{
			ans+=bit[i];
			i-=i&(-i);
			}
		return ans;
		}

	public void update(int i,int val) //A[i]-->A[i]+val
		{
		while (i<=n)
			{
			bit[i]+=val;
			i+=i&(-i);
			}
		}
	}
//must declare new classes here