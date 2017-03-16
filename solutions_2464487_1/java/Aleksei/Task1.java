import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class Task1 {

    public static BigDecimal twoD = BigDecimal.valueOf(2);

    public static BigInteger sqrt(BigInteger a) {
        BigDecimal S = new BigDecimal(a);
        BigDecimal x = S.divide(twoD);
        for (int i = 0; i < 1000; i++) {
            x = (x.add(S.divide(x, RoundingMode.HALF_UP))).divide(twoD);
        }
        BigInteger z = x.toBigInteger();
        BigInteger prev = z;
        while (z.multiply(z).compareTo(a) <= 0) {
            prev = z;
            z = z.add(BigInteger.ONE);
        }
        z = prev;
        while (z.multiply(z).compareTo(a) >= 0) {
            prev = z;
            z = z.subtract(BigInteger.ONE);
        }
        z = prev;
        return z;
    }

    public static void main(String[] args) throws IOException {
        BigInteger two = BigInteger.valueOf(2);
        BigInteger four = BigInteger.valueOf(4);
        BigInteger eight = BigInteger.valueOf(8);
        Scanner cin = new Scanner(new File("input.txt"));
        PrintWriter cout = new PrintWriter(new File("output.txt"));
        int ntests = cin.nextInt();
        for (int testnum = 0; testnum < ntests; testnum++) {
            BigInteger r = BigInteger.valueOf(cin.nextLong());
            BigInteger t = BigInteger.valueOf(cin.nextLong());
            BigInteger tmp = two.multiply(r).subtract(BigInteger.ONE);
            BigInteger D = tmp;
            D = D.multiply(D);
            D = D.add(eight.multiply(t));
            assert (D.compareTo(BigInteger.ZERO) >= 0);
            D = sqrt(D);
            D = D.subtract(tmp);
            D = D.divide(four);
            BigInteger y;
            y = two.multiply(D).multiply(D).add(D.multiply(tmp)).subtract(t);
            while (y.compareTo(BigInteger.ZERO) > 0) {
                D = D.subtract(BigInteger.ONE);
                y = two.multiply(D).multiply(D).add(D.multiply(tmp)).subtract(t);
            }
            BigInteger tD = D.add(BigInteger.ONE);
            y = two.multiply(tD).multiply(tD).add(tD.multiply(tmp)).subtract(t);
            while (y.compareTo(BigInteger.ZERO) <= 0) {
                D = tD;
                tD = tD.add(BigInteger.ONE);
                y = two.multiply(tD).multiply(tD).add(tD.multiply(tmp)).subtract(t);
            }
            cout.println("Case #" + String.valueOf(testnum + 1) + ": " + D.toString());
            cout.flush();
        }
        cout.close();
        cin.close();
        System.exit(0);
    }

}
