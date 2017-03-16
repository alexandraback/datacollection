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

public class ProblemC implements Callable<String> {

    public static void main(String[] args) throws Exception {
        String path = "/home/valou/today_shortcut/2013_1C/";
        String fileIn = null;
        fileIn = "C-sample.in";
        fileIn = "C-small-attempt0.in";
        //fileIn = "C-large-attempt0.in";
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

    int N;
    Tribe[] tribes;
    int attacksLeft;

    public ProblemC() {
        // Read data here, for 1 case
        N=in.nextInt();
        tribes = new Tribe[N];
        for(int i=0;i<N;i++){
            int d=in.nextInt();
            int n=in.nextInt();
            int w=in.nextInt();
            int e=in.nextInt();
            int s=in.nextInt();
            int delta_d=in.nextInt();
            int delta_p=in.nextInt();
            int delta_s=in.nextInt();
            tribes[i] = new Tribe(d,n,w,e,s,delta_d,delta_p,delta_s);
            attacksLeft += n;
        }
    }

    int OFFSET = 1000000;
    int MAX_EAST = 1000000;
    long[] wall = new long[OFFSET + MAX_EAST];

    public String solveSingle() throws Exception {
        long succeded = 0;

        while(attacksLeft > 0){
            int day = Integer.MAX_VALUE;
            for(Tribe tribe:tribes)
                if( tribe.n>0 && tribe.d < day )
                    day = tribe.d;


            check(day!=Integer.MAX_VALUE);

            int newHeight = -1;
            for(Tribe tribe:tribes)
                if(tribe.d==day){

                    boolean success=false;
                    for(int x=tribe.w;x<=tribe.e;x++)
                        if(wall[OFFSET+x] < tribe.s){
                            success=true;
                            break;
                        }

                    if( success ){
                        succeded++;
                        if( tribe.s > newHeight )
                            newHeight = tribe.s;
                    }

                    // Update Tribe...
                    tribe.n --;
                    tribe.d += tribe.delta_d;
                    tribe.s += tribe.delta_s;

                    attacksLeft--;
                }

            // Update Wall...
            if(newHeight>=0)
                for(Tribe tribe:tribes)
                    if(tribe.d==day)
                        for(int x=tribe.w;x<=tribe.e;x++)
                            wall[OFFSET+x] = newHeight;

        }


        return ""+(succeded-1);
    }

    static class Tribe implements Comparable<Tribe> {

        int d;
        int n,w,e,s,delta_d,delta_p,delta_s;
        // Declare other fields here

        @Override
        public int compareTo(Tribe other) {
            return this.d - other.d;
        }
        public Tribe(int d, int n, int w, int e, int s, int delta_d, int delta_p, int delta_s) {
            this.d = d;
            this.n = n;
            this.w = w;
            this.e = e;
            this.s = s;
            this.delta_d = delta_d;
            this.delta_p = delta_p;
            this.delta_s = delta_s;
        }
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
            ProblemC onecase = new ProblemC();
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
