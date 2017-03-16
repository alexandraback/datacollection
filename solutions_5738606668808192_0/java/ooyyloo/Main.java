import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	boolean isProbablePrime(String num) {  //传进来的是二进制
		for (int i=2;i<=10;i++)
			if (convertBase(new BigInteger(num), i, 10).isProbablePrime(50)) return true;
		return false;
	}
	BigInteger convertBase(BigInteger num, int base, int newBase) {  //只有10进制的能参加运算
		return new BigInteger(convertBase(num.toString(), base, newBase));
	}
	String convertBase(String s, int base, int newBase) {
		BigInteger tmp = BigInteger.ZERO;
		BigInteger BASE = BigInteger.valueOf(base);
		BigInteger NEWBASE = BigInteger.valueOf(newBase);
		for (int i=0; i<s.length(); i++)
			tmp = tmp.multiply(BASE).add( BigInteger.valueOf(s.charAt(i) - '0') );
		if (tmp.equals(BigInteger.ZERO)) return "0";
		String ret = "";
		while (!tmp.equals(BigInteger.ZERO)) {
			ret = tmp.mod(NEWBASE).intValue() + ret;
			tmp = tmp.divide(NEWBASE);
		}
		return ret;
	}
	
	
	Main() {
		Scanner in = new Scanner(System.in);
		in.nextInt();
		int N = in.nextInt();
		int J = in.nextInt();
		String startS = "1";
		for (int i=1; i<N-1; i++) startS += "0";
		startS += "1";
		BigInteger num = new BigInteger(convertBase(startS,2,10));
		
		System.out.println("Case #1:");
		ArrayList<BigInteger> ans = new ArrayList<BigInteger>();
		while (J > 0) {
			BigInteger tmp = convertBase(num,10,2);
			if (isProbablePrime(tmp.toString()) == false) {
				System.out.print(tmp + " ");
				for (int i=2; i<=10; i++) {
					System.out.print(PollardRho.rho(convertBase(tmp,i,10)));
					//System.out.println(convertBase(tmp,i,10).mod(PollardRho.rho(convertBase(tmp,i,10))));
					System.out.print(i==10 ? "\n" : " ");
				}
				J--;
			}
			//System.out.println(num);
			num = num.add(BigInteger.valueOf(2));
		}
	}
	public static void main(String args[]) {
		new Main();
	}
}

class PollardRho {
    private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();

	static int plist[] = new int[]{2,3,5,7,11,13,17,19,23,29,31,37,41};
    public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;
    	/*for (int i=0; i<plist.length; i++)
    		if (N.mod(BigInteger.valueOf(plist[i])).equals(BigInteger.ZERO))
    			return BigInteger.valueOf(plist[i]);*/

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }

    public static void factor(BigInteger N) {
        if (N.compareTo(ONE) == 0) return;
        if (N.isProbablePrime(20)) { System.out.println(N); return; }
        BigInteger divisor = rho(N);
        factor(divisor);
        factor(N.divide(divisor));
    }

 
    /*public static void main(String[] args) {
        BigInteger N = new BigInteger(args[0]);
        factor(N);
    }*/
}