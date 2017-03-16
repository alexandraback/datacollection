
import java.util.*;
import java.io.*;
import java.math.*;

public class probA 
{
    static BigInteger TWO = new BigInteger("2");

    public static void main(String ... orange) throws Exception
    {
        Scanner input = new Scanner(System.in);

        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
            long r = input.nextLong();
            long t = input.nextLong();

            BigInteger A = TWO;
            BigInteger B = TWO.multiply(new BigInteger(r + "")).subtract(BigInteger.ONE);
            BigInteger C = new BigInteger(t + "").negate();
            BigInteger N = B.negate().add(isqrt(B.multiply(B).subtract(new BigInteger("4").multiply(A).multiply(C)))).divide(TWO.multiply(A));

            System.out.println("Case #" + (n + 1) + ": " + N);
        }
    }

    static BigInteger isqrt(BigInteger n)
    {
        BigInteger xn = BigInteger.ONE;
        BigInteger xn1 = xn.add(n.divide(xn)).divide(TWO);
        while (xn1.subtract(xn).abs().compareTo(BigInteger.ONE) > 0)
        {
            xn = xn1;
            xn1 = xn.add(n.divide(xn)).divide(TWO);
        }
        while (xn1.multiply(xn1).compareTo(n) > 0)
            xn1 = xn1.subtract(BigInteger.ONE);
        return xn1;
    }
}

