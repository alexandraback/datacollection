package gcj.gcj2013.qualif;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

/**
 * Fair and Square
 */
public class ProblemC {

    public static void main(String[] args) throws Exception {
        ProblemC problem = new ProblemC();
        problem.solve(System.in, System.out);
    }

    public ProblemC() {
        // Initialize my memoization
        initializeMemo();
    }

    Map<BigInteger,BigInteger> memo = new HashMap<BigInteger,BigInteger>(1000000);

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        BigInteger[] AB=readSingleLineBigIntegerArray(reader);
        BigInteger A = AB[0];
        BigInteger B = AB[1];

        //out.println(naiveForSmall(out, A, B));
        out.println(easyForLarge1(A, B));
    }

    BigInteger easyForLarge1(BigInteger A, BigInteger B) {

        BigInteger sqA = new BigInteger(""+(long)(Math.sqrt(A.doubleValue())));
        if(sqA.multiply(sqA).compareTo(A) < 0)
            sqA=sqA.add(BigInteger.ONE);

        BigInteger sqB = new BigInteger(""+(long)(Math.sqrt(B.doubleValue())));

        while(!memo.containsKey(sqA)){
            sqA = sqA.add(BigInteger.ONE);

            // limit case
            if(sqA.equals(sqB)){
                if(memo.containsKey(sqB))
                    return BigInteger.ONE;
                else
                    return BigInteger.ZERO;
            }
        }
        BigInteger uptoA = memo.get(sqA);

        while(!memo.containsKey(sqB))
            sqB = sqB.subtract(BigInteger.ONE);
        BigInteger uptoB = memo.get(sqB);

        return (uptoB.subtract(uptoA)).add(BigInteger.ONE);
    }

    BigInteger initializeMemo() {
        BigInteger count = BigInteger.ZERO;
        BigInteger j = new BigInteger("10000000");

        for(BigInteger i=BigInteger.ONE;i.compareTo(j) <= 0;i=i.add(BigInteger.ONE)){
            BigInteger ii = i.multiply(i);
            if(isPalindrome(i) && isPalindrome(ii)){
                count = count.add(BigInteger.ONE);
                // How many so far?
                memo.put(i, count);
            }
        }

        return count;
    }

    BigInteger naiveForSmall(BigInteger A, BigInteger B) {
        BigInteger count = BigInteger.ZERO;
        BigInteger sqA = new BigInteger(""+(long)(Math.sqrt(A.doubleValue())));
        if(sqA.multiply(sqA).compareTo(A) < 0)
            sqA=sqA.add(BigInteger.ONE);

        for(BigInteger i=sqA;i.multiply(i).compareTo(B) <= 0;i=i.add(BigInteger.ONE)){
            BigInteger ii = i.multiply(i);
            if(isPalindrome(i) && isPalindrome(ii)){
                count = count.add(BigInteger.ONE);
                //out.println( ii + " matches");
            }
        }

        return count;
    }

    private boolean isPalindrome(BigInteger i) {
        return isPalindrome(i.toString());
    }

    private boolean isPalindrome(String str) {
        int n = str.length()-1;
        int m = str.length()/2;
        for(int i=0;i<m;i++)
            if(str.charAt(i)!=str.charAt(n-i))
                return false;
        return true;
    }

    static class Interval implements Comparable<Interval> {

        public BigDecimal a;
        public BigDecimal b;
        public BigDecimal nbFairSquares;

        @Override
        public int compareTo(Interval other) {
            return a.compareTo(other.a);
        }

        public Interval(BigDecimal a, BigDecimal b, BigDecimal nbFairSquares) {
            super();
            this.a = a;
            this.b = b;
            this.nbFairSquares = nbFairSquares;
        }

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

    public BigInteger[] readSingleLineBigIntegerArray(BufferedReader reader) throws Exception {
        String[] bigintAsStrings = readSingleLineStringArray(reader);
        BigInteger[] bigints = new BigInteger[bigintAsStrings.length];
        for (int i = 0; i < bigintAsStrings.length; i++) {
            bigints[i] = new BigInteger(bigintAsStrings[i]);
        }
        return bigints;
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
