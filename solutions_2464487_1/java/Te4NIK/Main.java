import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	static Scanner sc;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception
	{
		sc = new Scanner(new File("z2.in"));
		pw = new PrintWriter(new File("zja.out"));

		int T;
		BigInteger r,t,L,R,M,F;
		BigInteger two,one;
		two=BigInteger.valueOf(2);
		one=BigInteger.valueOf(1);

		T=sc.nextInt();
		for(int i=0; i<T; i++)
		{
			r=sc.nextBigInteger();
			t=sc.nextBigInteger();
		
		    L=BigInteger.valueOf(0);
		    R=BigInteger.valueOf(1000000000);
			while(L.compareTo(R)==-1)
			{
				M=(L.add(R)).divide(two);
				//pw.println(M);
			    //pw.flush();
			    F=(M.add(r)).multiply(two);
			    F=F.subtract(one);
			    F=F.multiply(M);

			    if(F.compareTo(t)<1)
			    	L=M.add(one);
			    else
			    	R=M;
			}
			pw.println("Case #"+(i+1)+": "+(L.subtract(one)));
		}
		pw.flush();
	}
}
