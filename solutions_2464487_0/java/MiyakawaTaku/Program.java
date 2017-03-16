import java.io.*;
import java.math.*;
import java.util.*;

public class Program {

    private final BigInteger r, t;


    public Program(long r, long t) {
        this.r = BigInteger.valueOf(r);
        this.t = BigInteger.valueOf(t);
    }


    public BigInteger getStatus() {
        BigInteger r2_1 = r.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
        BigInteger r2_1_pow2 = r2_1.multiply(r2_1);
        BigInteger sqrt = getSqrtOrBitSmaller(r2_1_pow2.add(BigInteger.valueOf(8).multiply(t)));
        return r2_1.negate().add(sqrt).divide(BigInteger.valueOf(4));
    }

    private static final BigInteger TWO  = BigInteger.valueOf(2);

    static BigInteger getSqrtOrBitSmaller(BigInteger num) {
        if (num.equals(BigInteger.ONE)) {
            return BigInteger.ONE;
        }
        BigInteger x = num;
        while (true) {
            BigInteger nextx = x.subtract(x.multiply(x).subtract(num).divide(x.multiply(TWO)));
            if (nextx.multiply(nextx).equals(num)) {
                return nextx;
            } else if (nextx.equals(x)) {
                BigInteger y = x.subtract(BigInteger.ONE);
                while (true) {
                    BigInteger y2 = y.multiply(y);
                    if (y2.compareTo(num) <= 0) {
                        return y;
                    }
                    y = y.subtract(BigInteger.ONE);
                }
            } else {
                x = nextx;
            }
        }
    }


    public static List<Program> readCases(BufferedReader reader) throws IOException {
        int numCases = Integer.parseInt(reader.readLine());
        List<Program> cases = new ArrayList<>(numCases);

        for (int caseIndex = 0; caseIndex < numCases; ++ caseIndex) {
            String[] cols = reader.readLine().split(" ");
            long r = Long.parseLong(cols[0]);
            long t = Long.parseLong(cols[1]);
            cases.add(new Program(r, t));
        }
        return cases;
    }

    public static void main(String[] args) throws IOException {
        int t = 1;
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            for (Program kase : readCases(reader)) {
                System.out.printf("Case #%d: %s%n", t, kase.getStatus());
                ++ t;
            }
        }
    }
}

// vim: et sw=4 sts=4
