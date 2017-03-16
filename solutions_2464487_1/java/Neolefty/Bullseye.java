package codejam2013.round1a;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {
    public static final String NAME = "Bullseye";

    BigInteger r, t;
    public Bullseye(Scanner in) {
        r = in.nextBigInteger();
        t = in.nextBigInteger();
    }

    static final BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
    BigInteger paintUsed(BigInteger x) {
        // long result = x * x + 2 * x - r * r + 1;
//        BigInteger result = x * (2 * x + 2 * r - 1);
        BigInteger result = x.multiply(x.multiply(TWO).add(r.multiply(TWO)).subtract(BigInteger.ONE));
        return result;
    }

    boolean paintLeft(long rings) {
        return t.subtract(paintUsed(BigInteger.valueOf(rings))).compareTo(BigInteger.ZERO) >= 0;
    }

    long ringsPossible(long min, long max) {
        if (min == max) return min;
        else {
            if (max - min < 10) {
                for (long i = min; i <= max; ++i)
                    if (paintLeft(i) && !paintLeft(i+1))
                        return i;
                throw new IllegalStateException();
            }
            else {
                long chop = (max + min) / 2;
                if (paintLeft(chop))
                    return ringsPossible(chop, max);
                else
                    return ringsPossible(min, chop);
            }
        }
    }

    public String report() {
        return Long.toString(ringsPossible(1L, t.longValue()));
    }

    public static void main(String[] args) throws IOException {
        String name = new Scanner(System.in).next();
        Scanner in = new Scanner(Bullseye.class.getResourceAsStream(name));
        int n = in.nextInt();
        long start = System.currentTimeMillis();
        int fileI = 1;
        File outFile;
        do {
            outFile = new File(NAME + "_" + fileI + ".out");
            ++fileI;
        } while(outFile.exists());

        FileOutputStream fout = new FileOutputStream(outFile);
        PrintWriter print = new PrintWriter(fout);
        for (int i = 1; i <= n; ++i) {
            String report = "Case #" + i + ": " + analyze(in);
            print.println(report);
            System.out.println(report);
        }
        print.flush();
        fout.close();
        System.out.println("Elapsed: " + (System.currentTimeMillis() - start));
    }

    private static String analyze(Scanner in) {
        return new Bullseye(in).report();
    }
}
