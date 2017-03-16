import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while (b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            long r = in.nextLong();
            long t = in.nextLong();

            BigInteger a0 = BigInteger.valueOf(2*r+1);

            BigInteger a = BigInteger.valueOf(2);
            BigInteger b = a0.subtract(BigInteger.valueOf(2));
            BigInteger c = BigInteger.valueOf(-t);

            BigInteger b24ac = b.multiply(b).subtract(a.multiply(c).multiply(BigInteger.valueOf(4)));
            BigInteger srb24ac = sqrt(b24ac);

            BigInteger ans = b.negate().add(srb24ac).divide(a.multiply(BigInteger.valueOf(2)));
            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
