import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Apr 14, 2012 
 * @author parisel
 * GGJ - Qualification Round
 */
public class B {
    private static final int TEST= 0, SMALL= 1, LARGE= 2;
    private static final String[] infile= { "-test.in",  "-small.in",  "-large.in"};
    private static final String[] outfile= {"-test.out", "-small.out", "-large.out"};
    java.io.BufferedReader br;
    java.io.PrintWriter out;
    String[] tok;

    private String[] getTok() throws IOException {return br.readLine().split(" ");}
    private int getInt() throws IOException {return Integer.valueOf(br.readLine());}
    private int[] getInt(int N) throws IOException {
        int[] data= new int[N]; tok= br.readLine().split(" ");
        for (int i=0; i<N; i++) data[i]= Integer.valueOf(tok[i]);
        return data;
    }
    private int toInt(String s) { return Integer.valueOf(s); }


    int[] normalBestScore, surprisingBestScore;
    private void generateBestScores() {
        normalBestScore= new int[31];
        surprisingBestScore= new int[31];
        
        int i,j,k, sum, max;
        for (i=0; i<=10; i++) {
            for (j=0; j<=10; j++) {
                for (k=0; k<=10; k++) {
                    sum= i+j+k;
                    if (isValid(i, j, k)) {
                        max= max(i,j,k);
                        if (isSurpring(i, j, k)) {
                            if (max>surprisingBestScore[sum])
                                 surprisingBestScore[sum]= max;
                        } else {
                            if (max>normalBestScore[sum])
                                 normalBestScore[sum]= max;
                        }
                    }
                }
            }
        }        
    }

    private boolean isValid(int i, int j, int k) {
        return (Math.abs(i-j)<=2) && (Math.abs(i-k)<=2) && (Math.abs(j-k)<=2);
    }

    private boolean isSurpring(int i, int j, int k) {
        return (Math.abs(i-j)==2) || (Math.abs(i-k)==2) || (Math.abs(j-k)==2);
    }

    private int max(int i, int j, int k) {
        return Math.max(i, Math.max(j, k));
    }

    int N, S, p;
    int[] t;

    private int answer() {
        int i, countNormal= 0, countSurprising= 0;
        for (i=0; i<N; i++) {
            if (normalBestScore[t[i]]>= p) ++countNormal;
            if (normalBestScore[t[i]]< p && surprisingBestScore[t[i]]>=p) ++countSurprising;
        }
        return countNormal + Math.min(S, countSurprising);
    }

    public void solve() throws IOException {
        int i,j,k;
        String s;

        int MODE= LARGE;
        br = new BufferedReader (new FileReader("B"+infile[MODE]));
        out = new PrintWriter(new BufferedWriter(new FileWriter("B"+outfile[MODE])));

        generateBestScores();

        int C= Integer.valueOf(br.readLine());
        for (int c=1; c<=C; c++) {
            // read
            tok= getTok();
            N= toInt(tok[0]);
            S= toInt(tok[1]);
            p= toInt(tok[2]);
            t= new int[N];
            for (i=0; i<N; i++) t[i]= toInt(tok[3+i]);
            // output
            out.printf("Case #%d: %d\n", c, answer());
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().solve();
    }
}
