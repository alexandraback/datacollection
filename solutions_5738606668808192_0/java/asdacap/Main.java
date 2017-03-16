import java.util.*;
import java.math.*;
import java.security.*;

public class Main{
	static Scanner in = new Scanner(System.in);
	int N,J;

	private final static BigInteger ZERO = new BigInteger("0");
	private final static BigInteger ONE  = new BigInteger("1");
	private final static BigInteger TWO  = new BigInteger("2");
	private final static SecureRandom random = new SecureRandom();

	BigInteger rho(BigInteger N) {
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

	boolean primeOK(BigInteger num){
		int checkFactor = 256;
		if(num.isProbablePrime(checkFactor)){
			return false;
		}
		for(int i=3;i<=10;i++){
			if(new BigInteger(num.toString(2), i).isProbablePrime(checkFactor)){
				return false;
			}
		}
		return true;
	}

	void printResult(BigInteger num){
		System.out.print(num.toString(2));
		for(int i=2;i<=10;i++){
			System.out.print(" ");
			BigInteger inRep = new BigInteger(num.toString(2), i);
			System.out.print(rho(inRep).toString());
		}
		System.out.println();
	}

	void run(){
		N = in.nextInt();
		J = in.nextInt();

		BigInteger cur = BigInteger.ONE;
		int co = 0;
		cur = cur.shiftLeft(N-1);
		cur = cur.add(BigInteger.ONE);
		BigInteger TWO = BigInteger.valueOf(2);

		BigInteger ulimit = BigInteger.ONE;
		ulimit = ulimit.shiftLeft(N);

		while(cur.compareTo(ulimit) < 0 && co < J){
			if(primeOK(cur)){
				printResult(cur);
				co++;
			}
			cur = cur.add(BigInteger.valueOf(2));
		}

	}

	public static void main(String[] args){
		int t = in.nextInt();
		for(int i=0;i<t;i++){
			System.out.println("Case #"+(i+1)+":");
			new Main().run();
		}
	}

}
