package gcj.gcj2013.round1A;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * Bullseye
 */
public class ProblemA {

    public static void main(String[] args) throws Exception {
        ProblemA problem = new ProblemA();
        problem.solve(System.in, System.out);
    }

    public ProblemA() {
        // ...
    }

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        long[] rt = readSingleLineLongArray(reader);
        long r=rt[0];
        long t=rt[1];
        //BigInteger r = reader.read

        // excluded
        long top = t+1;
        // included
        long bottom = 1;
        long best = bottom;
        while(top>bottom+1){
            long x = (bottom) + ((top-bottom)/2);
            if( candoit(x,r,t) ){
                if(x>best)
                    best=x;
                bottom = x;
            }else{
                top = x;
            }
        }
        if(candoit(top, r, t))
            out.println(top);
        else
            out.println(best);
    }

    private boolean candoit(long x, long r, long t) {
        //return (2*x*r + ((x)/2) * (4*x-2) ) <= t;

        //        BigInteger xx = new BigInteger(""+x);
        //        BigInteger rr = new BigInteger(""+r);
        //        BigInteger tt = new BigInteger(""+t);
        //
        //        BigInteger aa = new BigInteger("2").multiply(xx).multiply(rr);
        //        BigInteger bb = xx.divide(new BigInteger("2"));
        //        BigInteger cc = (new BigInteger("4").multiply(xx)).subtract(new BigInteger("2"));
        //        BigInteger dd = bb.multiply(cc);
        //        BigInteger ee = aa.add(dd);

        //        return ee.compareTo(tt) <= 0;

        return (2.0*x*r + ((x)/2.0) * (4.0*x-2.0) ) <= t;
    }

    public static final String TOKEN_SEPARATOR = " ";

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public boolean verbose = false;

    public void solve(InputStream in, PrintStream out) throws Exception {
        InputStreamReader isr = new InputStreamReader(in);
        BufferedReader reader = new BufferedReader(isr);
        long N = Long.parseLong(reader.readLine());
        for (long i = 1; i <= N; i++) {
            out.print("Case #" + i + ": ");
            solveSingle(reader, out);
        }
    }

    public long[] readSingleLineLongArray(BufferedReader reader) throws Exception {
        String[] longsAsStrings = readSingleLineStringArray(reader);
        long[] longs = new long[longsAsStrings.length];
        for (int i = 0; i < longsAsStrings.length; i++) {
            longs[i] = Long.parseLong(longsAsStrings[i]);
        }
        return longs;
    }

    public double[] readSingleLineDoubleArray(BufferedReader reader) throws Exception {
        String[] doublesAsStrings = readSingleLineStringArray(reader);
        double[] doubles = new double[doublesAsStrings.length];
        for (int i = 0; i < doublesAsStrings.length; i++) {
            doubles[i] = Double.parseDouble(doublesAsStrings[i]);
        }
        return doubles;
    }

    public int[] readSingleLineIntArray(BufferedReader reader) throws Exception {
        String[] intsAsStrings = readSingleLineStringArray(reader);
        int[] ints = new int[intsAsStrings.length];
        for (int i = 0; i < intsAsStrings.length; i++) {
            ints[i] = Integer.parseInt(intsAsStrings[i]);
        }
        return ints;
    }

    public String[] readSingleLineStringArray(BufferedReader reader) throws Exception {
        String line = reader.readLine();
        if (verbose) {
            System.out.println("Reading line " + line);
        }
        return line.split(TOKEN_SEPARATOR);
    }

    public String[][] readStringArrays(BufferedReader reader, int lines) throws Exception {
        String[][] arrays = new String[lines][];
        for (int i = 0; i < lines; i++) {
            arrays[i] = readSingleLineStringArray(reader);
        }
        return arrays;
    }

    public char[][] readCharArrays(BufferedReader reader, int lines) throws Exception {
        char[][] arrays = new char[lines][];
        for (int i = 0; i < lines; i++) {
            String line = reader.readLine();
            arrays[i] = line.toCharArray();
        }
        return arrays;
    }

    public long[][] readLongArrays(BufferedReader reader, int lines) throws Exception {
        long[][] arrays = new long[lines][];
        for (int i = 0; i < lines; i++) {
            arrays[i] = readSingleLineLongArray(reader);
        }
        return arrays;
    }

    protected void check(boolean b) {
        if (!b) {
            throw new IllegalStateException("Check failed");
        }
    }

    protected boolean approx(double a, double b) {
        return Math.abs(a - b) < 0.00000005;
    }

    protected boolean approxLesserThan(double a, double b) {
        boolean lesser = a < b + 0.000005;
        if (!lesser && verbose) {
            System.out.println(a + " > " + b + " ...");
        }
        return lesser;
    }
}
