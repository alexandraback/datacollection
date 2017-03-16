import java.io.*;
import java.math.*;
import java.util.*;

class C {
	static int n = 16;
	static int j = 50;

	final static BigInteger ZERO = new BigInteger("0");
    final static BigInteger ONE  = new BigInteger("1");
    final static BigInteger TWO  = new BigInteger("2");
    final static Random random = new Random();

    static ArrayList<BigInteger> factors;

    public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }

    public static boolean check(BigInteger curr){
    	String s = curr.toString(2);
    	if(s.charAt(n-1) == '0') return false;
    	boolean can = true;
    	factors = new ArrayList<>();
    	for(int i = 2; i <= 10; i++){
    		BigInteger test = new BigInteger(s, i);
    		//System.out.println(test);
    		if(test.isProbablePrime(20)){
    			return false;
    		} else {
    			factors.add(rho(test));
    		}
    	}
    	return true;
    }

	public static void main(String[] args) {
		System.out.println("Case #1:");
		BigInteger start = ONE;
		for(int i = 0; i < n-1; i++){
			start = start.multiply(TWO);
		}
		BigInteger end = ONE;
		for(int i = 0; i < n; i++){
			end = end.multiply(TWO);
		}
		end.subtract(ONE);
		int cnt = 0;
		for(BigInteger curr = start; curr.compareTo(end) < 0; curr = curr.add(ONE)){
			if(check(curr)){
				System.out.printf(curr.toString(2));
				for(BigInteger i : factors){
					System.out.printf(" " + i);
				}
				System.out.println();
				cnt++;
			}
			if(cnt == j) break;
		}
	}
}