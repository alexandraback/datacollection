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

public class ProblemB implements Callable<String> {

    public static void main(String[] args) throws Exception {
        String path = "/home/valou/today_shortcut/2013_1C/";
        String fileIn = null;
        fileIn = "B-sample.in";
        fileIn = "B-small-attempt0.in";
        //fileIn = "B-small-practice.in";
        //fileIn = "B-large-practice.in";
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

    int X,Y;


    public ProblemB() {
        // Read data here, for 1 case
        X = in.nextInt();
        Y = in.nextInt();
        print(naiveForSmall());
    }

    private String naiveForSmall() {
        String path = "";
        return path;
    }

    public String solveSingle() throws Exception {
        String result = "";
        int i=0;
        int j=0;
        if(X>0){
            while(i<X){
                result += "WE";
                i++;
            }
        }
        if(X<0){
            while(i>X){
                result += "EW";
                i--;
            }
        }
        if(Y>0){
            while(j<Y){
                result += "SN";
                j++;
            }
        }
        if(Y<0){
            while(j>Y){
                result += "NS";
                j--;
            }
        }
        check(i==X && j==Y);
        return result;
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
            ProblemB onecase = new ProblemB();
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
