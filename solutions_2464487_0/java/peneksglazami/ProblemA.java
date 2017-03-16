import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

/**
 * Problem A.
 */
public class ProblemA {

    public static void main(String[] args) throws Exception {
        new ProblemA().run();
    }

    private void run() throws Exception {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
        PrintWriter writer = new PrintWriter("A_output.txt");
        int testCount = scanner.nextInt();
        for (int test = 1; test <= testCount; test++) {
            long r = scanner.nextLong();
            long t = scanner.nextLong();

            long a = 2;
            long b = (2 * r - 1);
            long c = -t;
            BigDecimal d = BigDecimal.valueOf(b).multiply(BigDecimal.valueOf(b)).subtract(BigDecimal.valueOf(4).multiply(BigDecimal.valueOf(a).multiply(BigDecimal.valueOf(c))));
            BigDecimal res = BigDecimal.valueOf(-b).add(sqrt(d, 50)).divide(BigDecimal.valueOf(4));

            writer.print("Case #" + test + ": " + res.toBigInteger().toString());
            if (test < testCount) {
                writer.println();
            }
        }

        scanner.close();
        writer.close();
    }

    // http://stackoverflow.com/questions/13649703/square-root-of-bigdecimal-in-java
    public static BigDecimal sqrt(BigDecimal in, int scale) {

        BigDecimal sqrt = new BigDecimal(1);
        sqrt.setScale(scale + 3, RoundingMode.FLOOR);
        BigDecimal store = new BigDecimal(in.toString());
        boolean first = true;
        do {
            if (!first) {
                store = new BigDecimal(sqrt.toString());
            } else first = false;
            store.setScale(scale + 3, RoundingMode.FLOOR);
            sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
                    BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
        } while (!store.equals(sqrt));
        return sqrt.setScale(scale, RoundingMode.FLOOR);
    }
}