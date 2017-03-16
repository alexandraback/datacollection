package gcj.gcj2013.round1C;

import java.io.File;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ProblemA implements Callable<String> {

    public static void main(String[] args) throws Exception {
        String path = "/home/valou/today_shortcut/2013_1C/";
        String fileIn = null;
        //fileIn = "A-sample.in";
        fileIn = "A-small-attempt0.in";
        //fileIn = "A-large-attempt0.in";
        if(fileIn==null){
            in = new Scanner(System.in);
        }else{
            in = new Scanner(new File(path+fileIn));
            String fileOut = fileIn.replaceAll(".in$", "") + ".out";
            problemOutput = new PrintStream(new File(path+fileOut));
        }
        solve();
    }

    public static void precompute() throws Exception {
        // If any
    }

    String name;
    int n;

    public ProblemA() {
        // Read data here, for 1 case
        name = in.next();
        n=in.nextInt();

    }

    private int naiveForSmall() {
        // O(n^3)
        int s = name.length();
        int nvalue = 0;
        for(int i=0;i<=s-1;i++){
            for(int j=i+1;j<=s;j++){

                int row=0;
                for(int k=i;k<j;k++){
                    if( "aeiou".indexOf(name.charAt(k)) == -1 )
                        row++;
                    else
                        row=0;
                    if(row==n){
                        nvalue++;
                        break;
                    }
                }
            }
        }
        return nvalue++;
    }

    public String solveSingle() throws Exception {
        int result = naiveForSmall();
        return ""+result;
    }

    @Override
    public String call() throws Exception {
        return solveSingle();
    }

    static Scanner in;
    static PrintStream problemOutput;

    public static final String TOKEN_SEPARATOR = " ";

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static boolean verbose = false;

    public static void solve() throws Exception {
        long before = System.currentTimeMillis();
        int T = in.nextInt();
        precompute();
        List<Future<String>> futures = new ArrayList<Future<String>>(T);
        ExecutorService executor = Executors.newFixedThreadPool(4);
        // Read all T test cases from input, and run them parallel
        for (int i = 0; i < T; i++) {
            ProblemA onecase = new ProblemA();
            futures.add(executor.submit(onecase));
        }
        executor.shutdown();
        // Print results as they arrive
        for (int i = 0; i < T; i++) {
            print("Case #" + (i+1) + ": ");
            println( futures.get(i).get() );
        }
        long after = System.currentTimeMillis();
        System.err.println( "\nTook " + ((after-before)/1000) + "s");
    }

    /**
     * Prints to out AND to standard output
     */
    static void print(Object obj){
        if(problemOutput!=null)
            problemOutput.print(obj);
        System.out.print(obj);
    }

    /**
     * Prints to out AND to standard output
     */
    static void println(Object obj){
        print(obj);
        if(problemOutput!=null)
            problemOutput.println();
        System.out.println();
    }

    public int[] readSingleLineIntArray(int n) throws Exception {
        int[] ints = new int[n];
        for (int i = 0; i < n; i++)
            ints[i] = in.nextInt();
        return ints;
    }

    public long[] readSingleLineLongArray(int n) throws Exception {
        long[] longs = new long[n];
        for (int i = 0; i < n; i++)
            longs[i] = in.nextLong();
        return longs;
    }

    public BigInteger[] readSingleLineBigIntegerArray(int n) throws Exception {
        BigInteger[] bigints = new BigInteger[n];
        for (int i = 0; i < n; i++)
            bigints[i] = in.nextBigInteger();
        return bigints;
    }

    public double[] readSingleLineDoubleArray(int n) throws Exception {
        double[] doubles = new double[n];
        for (int i = 0; i < n; i++)
            doubles[i] = in.nextDouble();
        return doubles;
    }

    public BigDecimal[] readSingleLineBigDecimalArray(int n) throws Exception {
        BigDecimal[] bigdecs = new BigDecimal[n];
        for (int i = 0; i < n; i++)
            bigdecs[i] = in.nextBigDecimal();
        return bigdecs;
    }

    public String[] readSingleLineStringArray(int n) throws Exception {
        String[] strings = new String[n];
        for (int i = 0; i < n; i++)
            strings[i] = in.next();
        return strings;
    }

    public String[][] readStringArrays(int lines, int perline) throws Exception {
        String[][] arrays = new String[lines][];
        for (int i = 0; i < lines; i++) {
            arrays[i] = readSingleLineStringArray(perline);
        }
        return arrays;
    }

    public char[][] readCharArrays(int lines) throws Exception {
        char[][] arrays = new char[lines][];
        for (int i = 0; i < lines; i++) {
            String line = in.nextLine();
            arrays[i] = line.toCharArray();
        }
        return arrays;
    }

    public long[][] readLongArrays(int lines, int perline) throws Exception {
        long[][] arrays = new long[lines][];
        for (int i = 0; i < lines; i++) {
            arrays[i] = readSingleLineLongArray(perline);
        }
        return arrays;
    }

    protected static void check(boolean b) {
        if (!b) {
            throw new IllegalStateException("Check failed");
        }
    }

    protected static boolean approx(double a, double b) {
        return Math.abs(a - b) < 0.00000005;
    }

    protected static boolean approxLesserThan(double a, double b) {
        boolean lesser = a < b + 0.000005;
        if (!lesser && verbose) {
            System.out.println(a + " > " + b + " ...");
        }
        return lesser;
    }

}
