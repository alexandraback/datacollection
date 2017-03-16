package gcj_1b.a;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "A-large.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.err.printf("Class = [%s]\n", TaskX.class);
        System.err.printf("Input File = [%s]\n", inFileUrl);
        System.err.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.err.println("------------------");
            System.err.println("test " + (i+1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.err.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            long N = in.nextLong();
            System.err.printf("N=%s\n", N);

            String s = "" + N;
            int M = s.length();

            if (M == 1) {
                return "" + N;
            }
            if (N == 10) {
                return "" + 10;
            }

            String s2 = "";
            for (int i = M - 1; i >= M/2; i--) {
                s2 = s.charAt(i) + s2;
            }

            long tot = 0;

            if ( Long.parseLong(s2) == 0 ) {
                tot += 1;
                N -= 1;
                s = "" + N;
                M = s.length();
            }

            tot += rise(M);
            System.err.printf("rise=%s\n", tot);

            String s1 = "";
            s2 = "";
            for (int i = M - 1; i >= M/2; i--) {
                s2 = s.charAt(i) + s2;
            }
            for (int i = M/2 - 1; i >= 0; i--) {
                s1 = s.charAt(i) + s1;
            }
            s1 = new StringBuilder(s1).reverse().toString();
            System.err.printf("s1=%s, s2=%s\n", s1, s2);

            tot += Long.parseLong(s1) + Long.parseLong(s2);
            if (Long.parseLong(s1) == 1) tot--;

            return "" + tot;
        }

        long rise(int m) {
            if (m == 1) return 0;
            if (m == 2) return 10;

            return riseIn(m) + rise(m-1);
        }

        long riseIn(int m) {
            int k = m / 2;

            if (m % 2 == 0) {
                // even
                return nine(k) + 1 + nine(k-1);
            }

            // odd
            return nine(k) + 1 + nine(k);
        }

        long nine(int k) {
            long v = Long.parseLong(Integer.toBinaryString(1 << k)) -1L;
            return v;
        }
    }
}


