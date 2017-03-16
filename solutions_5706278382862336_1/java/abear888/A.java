import java.io.*;
import java.util.*;

public class A {

	static long gcd(long a, long b)
	{
	  if(a == 0 || b == 0) return a+b; // base case
	  return gcd(b,a%b);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader x = new BufferedReader(new FileReader("C:/Documents and Settings/alvin/My Documents/alvin/Computer Science/Code Jam/alarge.in"));
		PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("C:/Documents and Settings/alvin/My Documents/alvin/test.out.txt")));
		int numcases=Integer.parseInt(x.readLine());
		for (int a=1; a<=numcases; a++){
			String input=x.readLine();
			int cutoff=0;
			for (int b=0; b<input.length(); b++){
				if (input.charAt(b)=='/'){
					cutoff=b;
					break;
				}
			}
			long numerator=Long.parseLong(input.substring(0,cutoff));
			long denominator=Long.parseLong(input.substring(cutoff+1, input.length()));
			long divisor=gcd(numerator,denominator);
			numerator=numerator/divisor;
			denominator=denominator/divisor;
			System.out.println(numerator);
			System.out.println(denominator);
			System.out.println(a+"a");
			if ((denominator & (denominator - 1)) != 0 ){//power of 2
				out.println("Case #"+a+": impossible");
				continue;
			}
			else{
				
				numerator=numerator*(long)Math.pow(2, 40-(Math.log(denominator)/Math.log(2)));
			}
			for (int i=39; i>=0; i--){
				if (numerator>=Math.pow(2, i)){
					int value=40-i;
					out.println("Case #"+a+": "+value);
					break;
				}
			}
		}
		out.close();
		System.exit(0);
	}

}
