import java.util.*;
public class FairAndSqaure{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		Vector<Long> FandS=new Vector<Long>();
		for(long i=1;i<=10000000;i++)
		if(isPalindrome(i)&&isPalindrome(i*i))
		FandS.add(i*i);
		for(int c=1;c<=T;c++)
		{
			String s1=in.next(),s2=in.next();
			long A=Long.parseLong(s1),B=Long.parseLong(s2);
			long count=0;
			for(int i=0;i<FandS.size();i++)
			if(FandS.elementAt(i)>=A&&FandS.elementAt(i)<=B)
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
}
			

	
