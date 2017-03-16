package gcj.gcj2013.qualif;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * Lawnmower
 */
public class ProblemB {

    public static void main(String[] args) throws Exception {
        ProblemB problem = new ProblemB();
        problem.solve(System.in, System.out);
    }

    public ProblemB() {
        // ...
    }

    int N, M;
    long[][] lawn;
    boolean[][] horiz;

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] NM = readSingleLineIntArray(reader);
        N = NM[0];
        M = NM[1];
        lawn = readLongArrays(reader, N);
        horiz=new boolean[N][M];

        boolean result = attempt1();

        out.println( result ? "YES" : "NO" );
    }

    /**
     * @param out
     */
    boolean attempt1() {
        for(int i=0;i<N;i++){
            // What is the max of this horizontal line?
            long max = lawn[i][0];
            for(int j=1;j<M;j++)
                if(lawn[i][j]>max)
                    max=lawn[i][j];

            // true == "I was cut this high by the horizontal mowing"
            for(int j=0;j<M;j++)
                horiz[i][j] = (lawn[i][j]==max);
        }


        for(int j=0;j<M;j++){
            // What is the max of this vertical line?
            long max = lawn[0][j];
            for(int i=1;i<N;i++)
                if(lawn[i][j]>max)
                    max=lawn[i][j];

            for(int i=0;i<N;i++)
                if(lawn[i][j]<max && !horiz[i][j]){
                    // Lower than horizontal mowing
                    // + lower than vertical mowing
                    // = IMPOSSIBLE
                    return false;
                }
        }

        return true;
    }

    public static final String TOKEN_SEPARATOR = " ";

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public boolean verbose = false;

    public void solve(InputStream in, PrintStream out) throws Exception {
        InputStreamReader isr = new InputStreamReader(in);
        BufferedReader reader = new BufferedReader(isr);
        long T = Long.parseLong(reader.readLine());
        for (long i = 1; i <= T; i++) {
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
