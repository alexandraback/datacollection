import java.math.BigInteger;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; ++i) {
            long r = sc.nextLong();
            long t = sc.nextLong();
            BigInteger d = BigInteger.valueOf(r);
            d = d.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
            d = d.multiply(d);
            d = d.add(BigInteger.valueOf(t).multiply(BigInteger.valueOf(8)));

            d = sqrt(d);
            d = d.subtract(BigInteger.valueOf(r)).subtract(BigInteger.valueOf(r)).add(BigInteger.ONE);
            d = d.divide(BigInteger.valueOf(4));

            System.out.println("Case #" + i + ": " + d);
        }
    }
    
    public static BigInteger sqrt(BigInteger x) {
        BigInteger l = BigInteger.ONE;
        BigInteger r = x.divide(BigInteger.valueOf(2)).add(BigInteger.ONE);
        while (r.subtract(l).compareTo(BigInteger.ONE) > 0) {
            BigInteger c = l.add(r).divide(BigInteger.valueOf(2));
            BigInteger d = c.multiply(c);
            int cmp = d.compareTo(x);
            if (cmp == 0) {
                return c;
            }
            if (cmp == -1) {
                l = c;
            } else {
                r = c;
            }
        }
        return l;
    }
}
