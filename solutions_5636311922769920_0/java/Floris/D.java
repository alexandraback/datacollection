import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Pattern;

public class D {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/D-small-attempt1.in");
        System.setOut(new PrintStream("/home/floris/dev/java/Codejam2016/src/D.out"));
        Scanner sc = new Scanner(in);
        sc.useDelimiter(Pattern.compile("[\n /]"));


        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int k = sc.nextInt();
            int complexity = sc.nextInt();
            int s = sc.nextInt();

            int needed = (k+complexity-1)/complexity;
            if (s < needed) {
                System.out.printf("Case #%d: IMPOSSIBLE%n", c);
                continue;
            }
            System.out.printf("Case #%d:", c);
            for (int i = 0, v = 0; i < needed; i++) {
                BigInteger t =BigInteger.ZERO;
                BigInteger m = BigInteger.ONE;
                for (int j = 0; j < complexity; j++, v++) {
                    t = t.add(m.multiply(BigInteger.valueOf(Math.min(v, k-1))));
                    m=m.multiply(BigInteger.valueOf(k));
                }
                System.out.print(" " + (t.add(BigInteger.ONE)));
            }
            System.out.println();
        }
    }
}
