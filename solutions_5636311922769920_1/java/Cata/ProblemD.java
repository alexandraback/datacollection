import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemD {

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("D.in"));
        PrintStream out = new PrintStream("D.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            int k, c, s;
            k = in.nextInt();
            c = in.nextInt();
            s = in.nextInt();
            out.print("Case #" + t + ":");
            int lowerLimit = lowerLimit(k, c);
            if (s < lowerLimit) {
                out.println(" IMPOSSIBLE");
                continue;
            }
            int[] a = new int[c];
            int coveredBit = 0;
            for (int i = 0; i < lowerLimit; i++) {
                for (int j = 0; j < c; j++) {
                    a[j] = coveredBit;
                    coveredBit++;
                    if (coveredBit == k) coveredBit--;
                }
                out.print(" " + number(a, c));
            }
            out.println();
        }
    }

    private static BigInteger number(int[] a, int c) {
        BigInteger result=BigInteger.ZERO;
        for (int i = a.length - 1; i >= 0; i--) {
            result=result.multiply(BigInteger.valueOf(c)).add(BigInteger.valueOf(a[i]));
        }
        return result.add(BigInteger.ONE);
    }

    private static int lowerLimit(int k, int c) {
        return (k + c - 1) / c;
    }

}
