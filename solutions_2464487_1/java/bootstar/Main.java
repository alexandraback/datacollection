import java.util.*;
import java.math.*;

class Main{
	Scanner cin;
	BigInteger a, b;
	
	public Main(){
		cin = new Scanner(System.in);
	}
	public boolean check(BigInteger a, BigInteger r, BigInteger T){
		T = T.subtract(a.multiply(a).multiply(new BigInteger("2")));
		T = T.subtract(a.multiply(new BigInteger("2")));
		BigInteger ans;
		ans = r.multiply(a).multiply(new BigInteger("2"));
		ans = ans.subtract(a.multiply(new BigInteger("3")));
		if(ans.compareTo(T)<=0)
			return true;
		return false;
	}
	public void run(){
		int T = cin.nextInt(), cas = 1;
		while(cas <= T){
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			BigInteger l, r;
			l = BigInteger.ZERO;
			r = new BigInteger("2000000000000000005");
			
			while(l.compareTo(r)<=0){
				BigInteger mid = l.add(r).divide(new BigInteger("2"));
				if(check(mid, a, b))
					l = mid.add(BigInteger.ONE);
				else
					r = mid.subtract(BigInteger.ONE);
			}
			System.out.println("Case #"+cas+": "+r);
			cas = cas +1;
		}
	}
	public static void  main(String[] args){
		Main a = new Main();
		a.run();
	}
}