import java.io.*;
import java.util.*;
import java.math.*;


public class Problem1 {

	public static void main(String args[])throws Exception{
		String wd="C:\\Users\\prishriv.ORADEV\\";
		Scanner sc=new Scanner(new FileReader(wd+"input.txt"));
		PrintWriter pw=new PrintWriter(new FileWriter(wd+"output.txt"));
		
		int C=sc.nextInt();
		for(int i=0;i<C;i++){
			int count=0;
			String st=sc.next();
			String arr[]=st.split("/");
			Long P=Long.parseLong(arr[0]);
			Long Q=Long.parseLong(arr[1]);
			long h=gcd(P,Q);
			System.out.println(h);
			P=P/h;
			Q=Q/h;
			if(!IsPowerOfTwo_2(Q))
				{
					pw.println("Case #"+(i+1)+": Impossible");continue;
				}
			else{
				while(P<Q){
					P*=2;
					count++;
				}
				pw.println("Case #"+(i+1)+": "+count);
				
			}
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	static long gcd(long a, long b) {
	    if(((a % b)==0)) return b;
	    return gcd(b, a%b);
	}

	static boolean IsPowerOfTwo_2(long number)
	{
	    double log = Math.log(number)/Math.log(2);
	    double pow = Math.pow(2, Math.round(log));
	    return pow == number;
	}
}