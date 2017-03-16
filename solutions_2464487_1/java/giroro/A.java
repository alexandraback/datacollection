import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;

public class A {
    public final static String FILE_IN = "A-large.in";
    public final static String FILE_OUT = "A-large.out";

    private static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) {
                b = mid.subtract(BigInteger.ONE);
            }
            else {
                a = mid.add(BigInteger.ONE);
            }
      }
      return a.subtract(BigInteger.ONE);
    }

    public static void solveCase(BigInteger rr, BigInteger tt, BufferedWriter w, int index) throws IOException {
        BigInteger rr2 = rr.multiply(new BigInteger("2"));
        BigInteger b = rr2.add(new BigInteger("3"));
        BigInteger c = rr2.subtract(tt).add(BigInteger.ONE);

        BigInteger d1 = b.multiply(b).subtract(c.multiply(new BigInteger("8"))).multiply(new BigInteger("100000000"));
        BigDecimal d2 = new BigDecimal(sqrt(d1)).divide(new BigDecimal("10000"));
        BigDecimal d3 = d2.subtract(new BigDecimal(b));
        BigDecimal d4 = d3.divide(new BigDecimal("4")).add(new BigDecimal("1"));

        String aa = d4.toString();
        int idx = aa.indexOf(".");
        if (idx >= 0) {
            aa = aa.substring(0, idx);
        }

        w.write("Case #" + (index+1) + ": " + aa);
        w.newLine();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader r = new BufferedReader(new FileReader(FILE_IN));
        BufferedWriter w = new BufferedWriter(new FileWriter(FILE_OUT));
        int num = Integer.parseInt(r.readLine());
        for (int i=0; i<num; i++) {
            String[] cc = r.readLine().split(" ");
            BigInteger rr = new BigInteger(cc[0]);
            BigInteger tt = new BigInteger(cc[1]);

            solveCase(rr, tt, w, i);
        }

        w.close();
        r.close();
    }
}