import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class Bullseye {
	
	private void processInput() throws IOException {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
	        long r = in.nextLong();
	        long t = in.nextLong();
	        
			String res = go(r, t);

			System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);			
		}
		
		in.close();
	}
	
	private String go(long r, long t) {
	    BigInteger bi1 = BigInteger.valueOf(1);
	    BigInteger bi2 = BigInteger.valueOf(2);
	    BigInteger bi4 = BigInteger.valueOf(4);
	    BigInteger bi8 = BigInteger.valueOf(8);
	    BigInteger rr4 = BigInteger.valueOf(r).pow(2).multiply(bi4);
	    BigInteger r4 = BigInteger.valueOf(r).multiply(bi4);
	    BigInteger t8 = BigInteger.valueOf(t).multiply(bi8);
	    BigInteger rad = rr4.subtract(r4).add(t8).add(bi1);

	    BigInteger sq = root(rad);
	    
	    BigInteger rr = BigInteger.valueOf(r).multiply(bi2).subtract(bi1);
	    BigInteger tot = sq.subtract(rr).divide(bi4);
	    
		return tot.toString();
	}

	BigInteger root(BigInteger val) {
	    BigDecimal vval = new BigDecimal(val);
        BigDecimal xmin = BigDecimal.valueOf(0);
        BigDecimal xmax = new BigDecimal(val);
        BigDecimal eps = BigDecimal.valueOf(1e-9);
        while (xmax.subtract(xmin).compareTo(eps) > 0) {
            BigDecimal p = xmin.add(xmax).divide(BigDecimal.valueOf(2));
            BigDecimal r = p.multiply(p);
            if (r.compareTo(vval) < 0) {
                xmin = p;
            } else {
                xmax = p;
            }
        }
        
        BigInteger res = xmin.toBigInteger().add(BigInteger.valueOf(2));
        if (res.multiply(res).compareTo(val) > 0) {
            res = res.subtract(BigInteger.valueOf(1));
        }
        if (res.multiply(res).compareTo(val) > 0) {
            res = res.subtract(BigInteger.valueOf(1));
        }
        
        return res;
	}

	
	public static void main(String[] args) throws Exception {
		Bullseye main = new Bullseye();
		main.processInput();
	}
}
