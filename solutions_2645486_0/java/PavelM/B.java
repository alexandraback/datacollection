package codejam.round1a;


import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;

public class B {

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


    public static final String INPUT_FILE_NAME = "B-small-attempt3.in";
    public static final String OUTPUT_FILE_NAME = "B.out";

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

        new B(parser, out).process();

        parser.close();
        out.close();
    }

    final Parser in;
    final PrintWriter out;

    public B(final Parser in, final PrintWriter out) {
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

    long E;
    long R;
    int N;
    long[] vals;

    void loadInstance() {
        E = in.nextLong();
        R = in.nextLong();
        N = in.nextInt();
        in.toNextLine();
        vals = in.nextLongs(N);
        System.out.println("E=" + E + "R=" + R+ "N=" + N);
        in.toNextLine();
    }

    long checkInstance() {
        boolean[] used = new boolean[N];
        long[] energy = new long[N];
        long[] need = new long[N];
        boolean[] dEnergy = new boolean[N];
        long[] spent = new long[N];

        Arrays.fill(energy, E);

        while(true) {
            System.out.println("v" + Arrays.toString(vals));
            System.out.println("e" + Arrays.toString(energy));
            System.out.println("s" + Arrays.toString(spent));
            System.out.println("u" + Arrays.toString(used));
            System.out.println();
            int maxI = -1;
            long max = Long.MIN_VALUE;
            for (int i = 0; i < N; i++) {
                if (!used[i] && max < vals[i]) {
                    maxI = i;
                    max = vals[i];
                }
            }
            if (maxI == -1)
                break;

            long v = 0;
            if (dEnergy[maxI]) {
                for (int j = maxI + 1; j < N && !used[j]; j++) {
                    energy[j] = 0;
                    used[j] = true;
                }
            } else {
                for (int j = maxI + 1; j < N && !used[j]; j++) {
                    v += R;
                    energy[j] = Math.min(Math.min(v, E), energy[j]);
                    if (v >= E)
                        break;
                }
            }
            v = 0;
            long v1 = energy[maxI];
            for (int j = maxI - 1; j >= 0 && !used[j]; j--) {
                v += R;
                v1 -= R;
                long u = Math.min(v, E);
                energy[j] = Math.min(u, energy[j] - v1);
                dEnergy[j] = true;
                if (v >= E)
                    break;
            }

            spent[maxI] = energy[maxI];
            used[maxI] = true;
            energy[maxI] = 0;
        }

        long total = 0;
        for (int i = 0; i < N; i++) {
            total += vals[i] * spent[i];
        }


        return total;
    }

    long checkInstance1() {
        boolean[] used = new boolean[N];
        long[] energy = new long[N];
        long[] need = new long[N];
        boolean[] dEnergy = new boolean[N];
        long[] spent = new long[N];

        Arrays.fill(energy, E);

        long d = E / R;

        int pos = 0;
        long e = E;
        long total = 0;

        while (pos < N) {
            int maxI = -1;
            long max = Long.MIN_VALUE;
            long maxE = 0;
            for (int i = pos; i < pos + d; ++i) {
                if (max < vals[i]) {
                    maxI = i;
                    max = vals[i];
                    maxE = e;
                }
                e = Math.min(E, e += R);
            }
            total += maxE * max;
            pos = maxI + 1;
        }
        return total;
    }


}
