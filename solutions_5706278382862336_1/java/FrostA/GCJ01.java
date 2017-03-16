import java.io.*;
import java.util.*;


public class GCJ01 {
	public static PrintStream out;
	public static long GCD(long a, long b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s = new Scanner(new File("GCJ01.txt"));
		out = new PrintStream(new File("GCJ01.out.txt"));
		long t = s.nextLong();
		for(long i=0;i<t;i++){
			out.print("Case #");
			out.print(i+1);
			out.print(": ");
			String st=s.next();
			Scanner ss = new Scanner(st.substring(0, st.indexOf('/')));
			long p = ss.nextLong();
			ss = new Scanner(st.substring(st.indexOf('/')+1));
			long q=ss.nextLong();
			long x=GCD(p,q);
			p/=x;
			q/=x;
			if(!power(q)){
				out.println("impossible");
				continue;
			}
			out.println(get(q)-get(p));
		}
	}
	public static long get(long x){
		long i=1;
		long r=0;
		while(i<x){
			r++;
			i*=2;
		}
		if(i>x)r--;
		return r;
	}
	public static boolean power(long x){
		if((x==0)||(x==2))return true;
		if((x%2)==1)return false;
		return power(x/2);
	}
}
