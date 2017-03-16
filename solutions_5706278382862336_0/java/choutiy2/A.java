import java.util.*;
import java.math.*;

public class A {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		String s=sc.nextLine();
		for (int r=1;r<=t;r++){
			String[] o=sc.nextLine().split("/");
			int p=Integer.parseInt(o[0]);
			int q=Integer.parseInt(o[1]);
			
			int g=gcd(p,q);
			p=p/g;
			q=q/g;
			
			
			
			
			System.out.println("Case #"+r+": "+ans(p,q));
			
		}
	}

	private static String ans(int p, int q) {
		// TODO Auto-generated method stub
		String a=Integer.toBinaryString(q);
		boolean check=true;
		for (int i=1;i<a.length();i++)
			check=check && (a.charAt(i)=='0');
		if (!check) return "impossible";
		if (p>=q/2) return "1";
		if (p==1) return (""+(a.length()-1));
		return ans(p/2,q/2);
	}

	private static int gcd(int p, int q) {
		// TODO Auto-generated method stub
		if (p<q){
		int temp=p;
		p=q;
		q=temp;
		}
		if (q==0) return p;
		
		return gcd(q,p % q);
	}
}
