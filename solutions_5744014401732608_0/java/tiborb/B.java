import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.*;

public class B {

            public static final String INPUT_FILE = "B-small-attempt1";
//    public static final String INPUT_FILE = "B-large";
//    public static final String INPUT_FILE = "B-test";

    Scanner sc;
    PrintWriter out;
    private int B;
    private long M;
    private int[][] m;
    private int total;


    void out(int cas, Object result) {
        String s = String.format("Case #%d: %s", cas, result);
        System.out.println(s);
        out.println(s);
    }

    void out(String s) {
        System.out.print(s);
        out.print(s);
    }

    void cesta(int[] c, int i, int d) {
        if (total == M) {
            return;
        }
        if (i == d) {
            mark(c, d);
            total++;
            return;
        }
        for (int j = c[i-1] + 1; j <= B-(d-i); j++) {
            c[i] = j;
            cesta(c, i+1, d);
        }
    }

    void calc() {
        total = 1;
        m[0][B-1] = 1;
        int[] c = new int[B];
        for (int d = 2; d < B; d++) {
            Arrays.fill(c, 0);
            c[0] = 1;
            c[d] = B;
            cesta(c, 1, d);
        }
    }

    void mark(int[] c, int d) {
        for (int k = 0; k < d; k++) {
            m[c[k]-1][c[k+1]-1] = 1;
        }
//        System.out.println(Arrays.toString(c));
//        print();
    }

    void run() throws FileNotFoundException {
        sc = new Scanner(new File(INPUT_FILE + ".in"));
        out = new PrintWriter(INPUT_FILE + ".out");
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            B = sc.nextInt();
            M = sc.nextLong();
            if (M > pow(2, B - 2)) {
                out(t + 1, "IMPOSSIBLE");
            } else {
                out(t + 1, "POSSIBLE");
                m = new int[B][B];
                calc();
                print();
            }
        }
        sc.close();
        out.close();
    }

    void print() {
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                out(String.valueOf(m[i][j]));
            }
            out("\n");
        }
    }


    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }


}
