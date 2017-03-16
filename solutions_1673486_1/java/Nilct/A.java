import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * Apr 28, 2012 
 * @author Nil_ct
 * GGJ - Qualification Round
 */
public class A {
    private final static boolean LOCAL= true;
    private static final boolean DEBUG= true;
    private static final int TEST= 0, SMALL= 1, LARGE= 2;
    private static final String[] infile= { "-test.in",  "-small.in",  "-large.in"};
    private static final String[] outfile= {"-test.out", "-small.out", "-large.out"};
    java.io.BufferedReader br;
    java.io.PrintWriter out;
    int N;
    String[] tok;

    private String[] getTok() throws IOException {return br.readLine().split(" ");}
    private int getInt() throws IOException {return Integer.valueOf(br.readLine());}
    private int[] getInt(int N) throws IOException {
        int[] data= new int[N]; tok= br.readLine().split(" ");
        for (int i=0; i<N; i++) data[i]= Integer.valueOf(tok[i]);
        return data;
    }
    private int toInt(String s) { return Integer.valueOf(s); }



    private double answer(int A, int B) {
        int i, j;
        // continue
        double contCorrect= B-A+1;
        double contCorrectPerc= 1;
        for (i=0; i<A; i++) contCorrectPerc*= p[i];
        double contIncorrect= B-A+1 +(B+1);
        double contIncorrectPerc= 1- contCorrectPerc;

        double minStroke= contCorrect*contCorrectPerc + contIncorrect*contIncorrectPerc;

        // give up
        double giveUp= 1+B+1;
        double giveUpPerc= 1.0;

        if (giveUp<minStroke) minStroke= giveUp;

        // back
        double[] backCorrect= new double[A];
        double[] backCorrectPerc= new double[A];
        double[] backIncorrect= new double[A];
        double[] backIncorrectPerc= new double[A];
        double backMean= 0;
        backCorrect[0]= contCorrect;
        backCorrectPerc[0]= contCorrectPerc;
        backIncorrect[0]= contIncorrect;
        backIncorrectPerc[0]= 1-contCorrectPerc;

        for (i=1; i<A; i++) {
            backCorrect[i]= B-A + 2*i + 1;
            backCorrectPerc[i]= 1;
            for (j=0; j<A-i; j++) backCorrectPerc[i]*= p[j];
            backIncorrect[i]= backCorrect[i] + B+1;
            backIncorrectPerc[i]= 1-backCorrectPerc[i];

            backMean= backCorrect[i] *backCorrectPerc[i] + backIncorrect[i]*backIncorrectPerc[i];
            if (backMean< minStroke) minStroke= backMean;
        }



        return minStroke;
    }


    int A, B;
    double[] p;
    public void solve() throws IOException {
        int i,j,k;
        String s;

        int MODE= LARGE;
        br = new BufferedReader (new FileReader("A"+infile[MODE]));
        out = new PrintWriter(new BufferedWriter(new FileWriter("A"+outfile[MODE])));
//
//        if (true) {
//            br = new BufferedReader(new InputStreamReader(System.in));
//            out= new PrintWriter(System.out);
//        }
        int C= Integer.valueOf(br.readLine());
        for (int c=1; c<=C; c++) {
            // read
            tok= getTok();
            A= Integer.valueOf(tok[0]);
            B= Integer.valueOf(tok[1]);
            p= new double[A];
            tok= getTok();
            for (i=0; i<A; i++) p[i]= Double.valueOf(tok[i]);
            // output
            out.printf("Case #%d: %10.7f\n", c, answer(A, B));
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A().solve();
    }
}
