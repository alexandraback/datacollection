import java.util.*;
import java.math.*;

public class A {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		long t=sc.nextLong();
		String s=sc.nextLine();
		for (long r=1;r<=t;r++){
			String[] o=sc.nextLine().split("/");
			long p=Long.parseLong(o[0]);
			long q=Long.parseLong(o[1]);
			
			long g=gcd(p,q);
			p=p/g;
			q=q/g;
			
			
			
			
			System.out.println("Case #"+r+": "+ans(p,q));
			
		}
	}

	private static String ans(long p, long q) {
		// TODO Auto-generated method stub
		String a=Long.toBinaryString(q);
		boolean check=true;
		for (int i=1;i<a.length();i++)
			check=check && (a.charAt(i)=='0');
		if (!check) return "impossible";
		if (p>=q/2) return "1";
		if (p==1) return (""+(a.length()-1));
		return ans(p/2,q/2);
	}

	private static long gcd(long p, long q) {
		// TODO Auto-generated method stub
		if (p<q){
		long temp=p;
		p=q;
		q=temp;
		}
		if (q==0) return p;
		
		return gcd(q,p % q);
	}
}
