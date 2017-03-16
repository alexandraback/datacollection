import java.util.*;
public class Fair{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int c=1;c<=T;c++)
		{
			String s1=in.next(),s2=in.next();
			long A=Integer.parseInt(s1),B=Integer.parseInt(s2);
			long count=0;
			long min,max;
			if(isSquare(A))
			min=lsqrt(A);
			else
			min=lsqrt(A)+1;
			max=lsqrt(B);
			for(long i=min;i<=max;i++)
			if(isPalindrome(i)&&isPalindrome(i*i))
			count++;
			System.out.println("Case #"+c+": "+count);
		}
	}
	public static boolean isPalindrome(long n)
	{
		String s1=Long.toString(n);
		String s2="";
		for(int i=s1.length()-1;i>=0;i--)
		s2+=s1.charAt(i);
		if(s1.equals(s2))
		return true;
		else
		return false;
	}
	public static long lsqrt(long k){
		long x=k;
		long y=(x+k/x)/2;
		while(y<x)
		{
			x=y;
			y=(x+k/x)/2;
		}
		return x;
	}
	public static boolean isSquare(long k){
		long x=k;
		long y=(x+k/x)/2;
		while(y<x)
		{
			x=y;
			y=(x+k/x)/2;
		}
		if(x*x==k)
		return true;
		else
		return false;
	}
}
			

	
