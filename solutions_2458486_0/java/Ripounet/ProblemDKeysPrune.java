package gcj.gcj2013.qualif;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Treasure
 */
public class ProblemDKeysPrune {

    public static void main(String[] args) throws Exception {
        ProblemDKeysPrune problem = new ProblemDKeysPrune();
        problem.solve(System.in, System.out);
    }

    public ProblemDKeysPrune() {
        // ...
    }

    int K;
    int N;
    int[] start;
    int[][] chests;
    BitSet opened;
    Set<String> seen;
    int win;
    int[] hand;
    int[] solution;
    int nbRecCalls;

    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] KN = readSingleLineIntArray(reader);
        K=KN[0];
        N=KN[1];
        start = readSingleLineIntArray(reader);
        check(K==start.length);
        chests = readIntArrays(reader, N);
        opened = new BitSet(N);
        seen = new HashSet<String>(N);
        win=0;
        nbRecCalls=0;

        hand = new int[42];
        for(int i=0;i<hand.length;i++)
            hand[i] = 0;
        int h=K;
        for(int key:start)
            hand[key]++;
        solution = new int[22];
        solution = naiveForSmall(h,0);
        checkSolution();
        //System.out.println("\n\tnbRecCalls = "+nbRecCalls);
        if(null==solution)
            out.println(IMPOSSIBLE);
        else{
            for(int i=0;i<N;i++)
                out.print((solution[i]+1)+" ");
            out.println();
        }
    }

    /**
     * Full search with BackTracking.
     */
    private final int[] naiveForSmall(int h, int s) {
        nbRecCalls++;
        if( seen.contains( opened.toString() ) )
            return null;
        seen.add( opened.toString()  );
        //if(nbRecCalls%10000000==0)
        //    System.out.println("\t\tnbRecCalls = "+nbRecCalls+" ;\t h = "+h);
        //long verif = checksum(hand,h,solution,s,win,opened,N);
        for(int c=0;c<N;c++){
            int[] chest = chests[c];
            if(!opened.get(c)){

                int neededKey = chest[0];
                if( hand[neededKey] > 0 ){
                    // Setting up
                    hand[neededKey] --;
                    h--;
                    solution[s++] = c;
                    opened.set(c);
                    win ++;
                    for(int k=2;k<chest.length;k++){
                        hand[chest[k]] ++ ;
                        h++;
                    }

                    checkHandChests(h);

                    // Finished?
                    if(win==N)
                        return solution;

                    if(h>0){
                        // Go recursive
                        int[] rec = naiveForSmall(h, s);
                        if( rec != null )
                            return rec;
                    }

                    checkHandChests(h);

                    // Cleaning up
                    for(int k=2;k<chest.length;k++){
                        hand[chest[k]] --;
                        h--;
                    }
                    win--;
                    opened.clear(c);
                    solution[s-1] = -1;
                    s--;
                    hand[neededKey]++;
                    h++;

                    //checkHandChests(h);
                    //check( checksum(hand,h,solution,s,win,opened,N)==verif );
                }
            }
        }
        return null;
    }

    private void checkHandChests(int h) {
        int nbKeysInHand = 0;
        for(int i=0;i<h;i++)
            nbKeysInHand += hand[i];
        int open=0;
        int contents = 0;
        for(int c=0;c<N;c++)
            if(opened.get(c)){
                open ++;
                contents += chests[c][1];
            }
        check( K - open + contents == h );
    }

    private static long checksum(int[] hand, int h, int[] solution, int s, int win, boolean[] opened,int N) {
        long sum =0;
        for(int i=0;i<h;i++){
            sum = 3*sum + hand[i];
        }
        sum = 3*sum + h;
        for(int i=0;i<s;i++){
            sum = 3*sum + solution[i];
        }
        sum = 3*sum + s;
        sum = 3*sum + win;
        for(int i=0;i<N;i++){
            sum = 3*sum + (opened[i] ? 1 : 0);
        }
        return sum;
    }

    private boolean notNegative() {
        for(int v:hand)
            if(v<0)
                return false;
        return true;
    }

    private static int contains(int[] hand, int h, int neededKey) {
        for(int i=0;i<h;i++)
            if(hand[i]==neededKey)
                return i;
        return -1;
    }

    private void checkSolution() {
        if(solution==null)
            return;
        List<Integer> trueHand = new ArrayList<Integer>();
        Set<Integer> uniqueChests =new HashSet<Integer>();
        for(int key:start)
            trueHand.add(key);
        for(int i=0;i<N;i++){
            int c=solution[i];
            check(!uniqueChests.contains(c)); // would be a duplicate
            uniqueChests.add(c);
            int pos = trueHand.indexOf(chests[c][0]);
            check( pos != -1 ); if(pos == -1) return;
            trueHand.remove(pos);
            for(int k=2;k<chests[c].length;k++){
                trueHand.add(chests[c][k]);
            }
        }
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

    public int[][] readIntArrays(BufferedReader reader, int lines) throws Exception {
        int[][] arrays = new int[lines][];
        for (int i = 0; i < lines; i++) {
            arrays[i] = readSingleLineIntArray(reader);
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
