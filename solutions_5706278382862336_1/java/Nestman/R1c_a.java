package r1c_a;

import java.io.*;
import java.util.*;

public class R1c_a {
	
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/r1c_a/A-large.in"))));
		//Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/r1c_a/testal.out"));
		int res,rep,i,j;
		long p,q,tp,tq,cp,cq;
		boolean vis;
		String s;
		String[] s2=new String[3];
		String out="";
		
		res=sc.nextInt();
		s=sc.nextLine();
		for(rep=1;rep<=res;rep++){
			s=sc.nextLine();
			s2=s.split("/");
			p=0; q=0;
			for(i=0;i<s2[0].length();i++){
				p*=10;
				p+=(int)s2[0].charAt(i)-(int)'0';
			}
			for(i=0;i<s2[1].length();i++){
				q*=10;
				q+=(int)s2[1].charAt(i)-(int)'0';
			}
			//p=Integer.parseInt(s2[0]); q=Integer.parseInt(s2[1]);
			//p=sc.nextInt(); q=sc.nextInt();
			tp=p/gcd(p,q); tq=q/gcd(p,q);
			System.out.println(tp);
			cp=0; cq=0;
			vis=true;
			while(tp!=1){
				tp=tp>>1;
				cp++;
			}
			while(tq!=1){
				if (tq%2==1) {vis=false; break;}
				tq/=2;
				cq++;
			}
			ou.print("Case #"+rep+": ");
			if (!vis) ou.print("impossible");
			else ou.print(cq-cp);
			if (res!=rep) ou.println();
			System.out.println(cq-cp);
		}
		ou.close();
	}
	public static long gcd(long n, long m){
		if (n==0) return m;
		else return gcd(m%n,n);
	}
}