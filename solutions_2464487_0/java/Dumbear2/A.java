import java.util.*;
import java.math.*;

public class A {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int i = 0; i < t; ++i) {
            BigInteger r = cin.nextBigInteger();
            BigInteger n = cin.nextBigInteger();
            BigInteger k = BigInteger.valueOf(2);
            BigInteger lb = BigInteger.ZERO, ub = BigInteger.valueOf(1000000000000000000L);
            while (!lb.equals(ub)) {
                BigInteger mid = lb.add(ub).add(BigInteger.ONE).divide(k);
                BigInteger tmp = mid.multiply(k.add(k.multiply(k.multiply(r.add(mid.subtract(BigInteger.ONE)))))).divide(k);
                if (tmp.compareTo(n) > 0)
                    ub = mid.subtract(BigInteger.ONE);
                else
                    lb = mid;
            }
            System.out.println("Case #" + (i + 1) + ": " + lb);
        }
    }
}
