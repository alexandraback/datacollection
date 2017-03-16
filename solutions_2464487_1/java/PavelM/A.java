package codejam.round1a;


import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {


    static class Parser {
        final Scanner scan;

        public Parser(final BufferedReader reader) {
            scan = new Scanner(reader).useLocale(Locale.US);
        }

        void toNextLine() {
            if (scan.hasNextLine())
                scan.nextLine();
        }

        int nextInt() {
            final int val = scan.nextInt();
            if (logging)
                System.out.println(val);
            return val;
        }

        int[] nextInts(int n) {
            final int[] array = new int[n];
            for (int i = 0; i < n; ++i)
                array[i] = scan.nextInt();
            if (logging)
                System.out.println(Arrays.toString(array));
            return array;
        }

        long nextLong() {
            final long val = scan.nextLong();
            if (logging)
                System.out.println(val);
            return val;
        }

        long[] nextLongs(int n) {
            final long[] array = new long[n];
            for (int i = 0; i < n; ++i)
                array[i] = scan.nextLong();
            if (logging)
                System.out.println(Arrays.toString(array));
            return array;
        }

        double nextDouble() {
            final double val = scan.nextDouble();
            if (logging)
                System.out.println(val);
            return val;
        }

        double[] nextDoubles(int n) {
            final double[] array = new double[n];
            for (int i = 0; i < n; ++i) {
                array[i] = scan.nextDouble();
            }
            if (logging)
                System.out.println(Arrays.toString(array));
            return array;
        }

        BigInteger nextBigInt() {
            final BigInteger val = scan.nextBigInteger();
            if (logging)
                System.out.println(val);
            return val;
        }

        BigInteger[] nextBigInts(int n) {
            final BigInteger[] array = new BigInteger[n];
            for (int i = 0; i < n; ++i)
                array[i] = scan.nextBigInteger();
            if (logging)
                System.out.println(Arrays.toString(array));
            return array;
        }

        BigDecimal nextBigDecimal() {
            final BigDecimal val = scan.nextBigDecimal();
            if (logging)
                System.out.println(val);
            return val;
        }

        BigDecimal[] nextBigDecimals(int n) {
            final BigDecimal[] array = new BigDecimal[n];
            for (int i = 0; i < n; ++i)
                array[i] = scan.nextBigDecimal();
            if (logging)
                System.out.println(Arrays.toString(array));
            return array;
        }

        String next() {
            final String val = scan.next();
            if (logging)
                System.out.println(val);
            return val;
        }

        public static final int TOKENS_NUM = 1;
        public static final String TOKEN_DELIM_PATTERN = " ";

        String[] nextPatternLine() {
            final StringTokenizer stringTokenizer = new StringTokenizer(scan.nextLine(), TOKEN_DELIM_PATTERN, true);
            final String[] strings = new String[TOKENS_NUM];
            int n = 0;
            while (stringTokenizer.hasMoreTokens())
                strings[n++] = stringTokenizer.nextToken();
            return strings;
        }

        void close() {
            scan.close();
        }
    }


    public static final String INPUT_FILE_NAME = "A-large (1).in";
    public static final String OUTPUT_FILE_NAME = "A.out";

    public static final boolean logging = false; //TODO
    public static final boolean isTest = false;

    public static void main(final String[] args) throws IOException {
        final Parser parser;
        final PrintWriter out;
        if (isTest) {
            parser = new Parser(new BufferedReader(new FileReader("test.txt")));
            out = new PrintWriter(System.out);
        } else {
            parser = new Parser(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
            out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME)));
        }

        new A(parser, out).process();

        parser.close();
        out.close();
    }

    final Parser in;
    final PrintWriter out;

    public A(final Parser in, final PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    void process() throws IOException {
        final int num = in.nextInt();
        for (int n = 1; n <= num; ++n) {
            loadInstance();
            out.format("Case #%d: %s%n", n, checkInstance());
        }
    }

    BigInteger r;
    BigInteger t;

    void loadInstance() {
        r = in.nextBigInt();
        t = in.nextBigInt();
        in.toNextLine();
    }

    BigInteger checkInstance() {
        BigInteger n = t;
//        BigInteger v = value(n);
//        while (v.compareTo(t)  0) {
//            n = n.add(BigInteger.ONE);
//            v = value(n);
//        }

        BigInteger m = BigInteger.ZERO;
        while (n.compareTo(m) >= 0)
        {
            BigInteger dif = n.subtract(m);
            if (dif.compareTo(TWO) >= 0) {
                BigInteger mid = dif.divide(TWO).add(m);

                BigInteger v = value(mid);
                if (v.compareTo(t) < 0)
                    m = mid.add(BigInteger.ONE);
                else if (v.compareTo(t) > 0)
                    n = mid.subtract(BigInteger.ONE);
                else
                    return mid;
            } else {
                if (value(n).compareTo(t) <= 0)
                    return n;
                n = n.subtract(BigInteger.ONE);
                if (value(n).compareTo(t) <= 0)
                    return n;
                n = n.subtract(BigInteger.ONE);
                if (value(n).compareTo(t) <= 0)
                    return n;
                throw new AssertionError();
            }
        }

        throw new AssertionError();
    }

    static BigInteger TWO = BigInteger.valueOf(2);

    BigInteger value(BigInteger n) {
        BigInteger i = r.add(n).multiply(TWO).subtract(BigInteger.ONE);
        return n.multiply(i);
    }


}
