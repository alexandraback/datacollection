/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.security.SecureRandom;
/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	static BigInteger pot[][];
	static char str[];
	static int j;
	static int J=500;
	static int N=32;
	static BigInteger ans[][];
	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE  = new BigInteger("1");
        private final static BigInteger TWO  = new BigInteger("2");
	private final static SecureRandom random = new SecureRandom();
	public static BigInteger rho(BigInteger N) {
	    BigInteger divisor=N;
	    while(divisor.compareTo(N)==0){
		BigInteger c  = new BigInteger(N.bitLength(), random);
		BigInteger x  = new BigInteger(N.bitLength(), random);
		BigInteger xx = x;
		if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;
		do {
		    x  =  x.multiply(x).mod(N).add(c).mod(N);
		    xx = xx.multiply(xx).mod(N).add(c).mod(N);
		    xx = xx.multiply(xx).mod(N).add(c).mod(N);
	            divisor = x.subtract(xx).gcd(N);
		} while((divisor.compareTo(ONE)) == 0);
	    }
	    return divisor;
	}
	static void rec(int pos){
		if(j>=J) return;
		if(pos==N-1){
			boolean ok=true;
			BigInteger arr[]=new BigInteger[11];
			arr[0]=arr[1]=BigInteger.ZERO;
			for(int i=2;i<=10;++i){
				BigInteger tmp=BigInteger.ZERO;
				for(int j=0;j<N;++j)
					if(str[N-1-j]==1)
						tmp=tmp.add(pot[i][j]);
				if(tmp.isProbablePrime(100)) {ok=false;break;}
				arr[i]=tmp;
			}
			if(ok){
				long tmp=0;
				for(int i=0;i<N;++i){
					long aux=1;
					tmp+=str[i]*(aux<<i);
				}
				for(int i=0;i<=10;++i)
					ans[j][i]=arr[i];
				++j;
			}
			return;
		}
		str[pos]=0;
		rec(pos+1);
		str[pos]=1;
		rec(pos+1);
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		str=new char[N];
		str[0]=1;
		str[N-1]=1;
		j=0;
		pot=new BigInteger[11][N+1];
		for(int i=2;i<=10;++i)
			for(int j=0;j<N;++j)
				pot[i][j]=BigInteger.valueOf(i).pow(j);
		ans=new BigInteger[J][11];
		rec(1);
		for(int i=0;i<J;++i){
		    System.out.print(ans[i][10]);
		    for(int j=2;j<=10;++j)
		        System.out.print(" "+rho(ans[i][j]));
		    System.out.println();
		}
	}
}