package gcj.gcj2013.round1A;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.BitSet;
import java.util.Random;

/**
 * Good Luck
 */
public class ProblemC {

    public static void main(String[] args) throws Exception {
        ProblemC problem = new ProblemC();
        problem.solve(System.in, System.out);
    }

    public ProblemC() {
        // ...
    }

    int R, N, M, K;

    long[][] products;

    Random random=new Random(123456L);

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] RNMK = readSingleLineIntArray(reader);
        R = RNMK[0];
        N = RNMK[1];
        M = RNMK[2];
        K = RNMK[3];

        products = readLongArrays(reader, R);

        naiveSmall1(out);
    }

    private void naiveSmall1(PrintStream out) {
        check(N == 3);
        check(M <= 5);
        // int[][] c = new int[N][M];
        BitSet[][][] bs = new BitSet[M+1][M+1][M+1];
        for (int i = 2; i <= M; i++)
            for (int j = 2; j <= M; j++)
                for (int k = 2; k <= M; k++) {
                    BitSet reach = new BitSet();
                    reach.set(1);
                    reach.set(i);
                    reach.set(j);
                    reach.set(k);
                    reach.set(i * j);
                    reach.set(i * k);
                    reach.set(j * k);
                    reach.set(i * j * k);
                    bs[i][j][k] = reach;
                }

        out.println();
        for (int r = 0; r < R; r++) {
            boolean[][][] eliminated = new boolean[M+1][M+1][M+1];
            int left=64;
            for (long p : products[r]) {
                for (int i = 2; i <= M; i++)
                    for (int j = 2; j <= M; j++)
                        for (int k = 2; k <= M; k++)
                            if(!bs[i][j][k].get((int)p) && !eliminated[i][j][k]){
                                eliminated[i][j][k] = true;
                                left --;
                            }
            }
            check(left > 0);

            int a=-1;
            int b=-1;
            int c=-1;
            do{
                a=2+random.nextInt(M-1);
                b=2+random.nextInt(M-1);
                c=2+random.nextInt(M-1);
            }while(eliminated[a][b][c]);
            out.print(a);
            out.print(b);
            out.print(c);
            out.println();

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
