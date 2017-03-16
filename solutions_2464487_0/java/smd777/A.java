package gcj2013.r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class A {

    //borrowed from gangqinlaohu on http://stackoverflow.com/questions/13649703/square-root-of-bigdecimal-in-java
    public static BigDecimal sqrt(BigDecimal in, int scale) {
        BigDecimal sqrt = new BigDecimal(1);
        sqrt.setScale(scale + 3, RoundingMode.FLOOR);
        BigDecimal store = new BigDecimal(in.toString());
        boolean first = true;
        do {
            if (!first) {
                store = new BigDecimal(sqrt.toString());
            } else {
                first = false;
            }
            store.setScale(scale + 3, RoundingMode.FLOOR);
            sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
                    BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
        } while (!store.equals(sqrt));
        return sqrt.setScale(scale, RoundingMode.FLOOR);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("src/gcj2013/r1a/in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("src/gcj2013/r1a/A.out")));

        int T = Integer.parseInt(in.readLine());
        for (int i = 0; i < T; i++) {
            String[] line = in.readLine().split(" ");
            BigDecimal r = new BigDecimal(line[0]);
            BigDecimal t = new BigDecimal(line[1]);

            BigDecimal one = BigDecimal.ONE, two = BigDecimal.valueOf(2),
                    four = BigDecimal.valueOf(4), eight = BigDecimal.valueOf(8);

            BigDecimal count = one.subtract(two.multiply(r));
            BigDecimal sqrt = sqrt(four.multiply(r.pow(2)).subtract(four.multiply(r)).add(eight.multiply(t)).add(one), 40);
            count = count.add(sqrt);
            count = count.divide(four);

            out.println("Case #" + (i + 1) + ": " + count.longValue());
        }

        out.close();
    }
}
