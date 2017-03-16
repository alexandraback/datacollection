package gcj.gcj2013.round1A;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * Manage your Energy
 */
public class ProblemB {

    public static void main(String[] args) throws Exception {
        ProblemB problem = new ProblemB();
        problem.solve(System.in, System.out);
    }

    public ProblemB() {
        // ...
    }

    int E, R, N;

    int[] v;

    long[][] best;

    long maxtotal = 0;

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] ERN = readSingleLineIntArray(reader);
        E = ERN[0];
        R = ERN[1];
        R = Math.min(R, E);
        N = ERN[2];

        v = readSingleLineIntArray(reader);
        check(N == v.length);

        best = new long[N][E+1];
        maxtotal = 0;

        for (int j = R; j <= E; j++) {
            long gain = j * v[0];
            if (gain > maxtotal)
                maxtotal = gain;
            best[0][E - j + R] = gain;
        }

        for (int i = 1; i < N; i++) {
            for (int j1 = 0; j1 <= E; j1++) {
                for (int j2 = 0; j2 <= j1; j2++) {
                    long gain = j2 * v[i];
                    long total = best[i - 1][j1] + gain;
                    if (total > maxtotal)
                        maxtotal = total;
                    int top=Math.min(j1 - j2 + R, E);
                    if( total > best[i][top] )
                        best[i][top] = total;
                }
            }
        }
        //printTab();

        out.println(maxtotal);
    }

    void printTab(){
        System.out.println();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= E; j++) {
                System.out.print(best[i][j]);
                System.out.print("\t");
            }
            System.out.println();
        }
        System.out.println();
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
