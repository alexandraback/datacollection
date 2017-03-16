package gcj.gcj2013.qualif;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 * Tic-Tac-Toe-Tomek
 */
public class ProblemA {

    public static void main(String[] args) throws Exception {
        ProblemA problem = new ProblemA();
        problem.solve(System.in, System.out);
    }

    public ProblemA() {
        // ...
    }

    char[][] map;

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        map = readCharArrays(reader, 4);
        reader.readLine(); // 1 empty line
        String result="Game has not completed";
        if(full())
            result="Draw";
        if(wins('X')){
            result="X won";
            check(!wins('O'));
        }
        if(wins('O')){
            result="O won";
            check(!wins('X'));
        }
        out.println(result);
    }

    private boolean wins(char player) {

        // Lines
        for(int i=0;i<4;i++){
            int me = 0;
            for(int j=0;j<4;j++)
                if(map[i][j]==player || map[i][j]=='T')
                    me++;
            if(me==4)
                return true;
        }

        // Columns
        for(int j=0;j<4;j++){
            int me = 0;
            for(int i=0;i<4;i++)
                if(map[i][j]==player || map[i][j]=='T')
                    me++;
            if(me==4)
                return true;
        }

        // Diag 1
        int me = 0;
        for(int k=0;k<4;k++)
            if(map[k][k]==player || map[k][k]=='T')
                me++;
        if(me==4)
            return true;

        // Diag 2
        me = 0;
        for(int k=0;k<4;k++)
            if(map[k][3-k]==player || map[k][3-k]=='T')
                me++;
        if(me==4)
            return true;

        return false;
    }

    private boolean full() {
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(map[i][j]=='.')
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
