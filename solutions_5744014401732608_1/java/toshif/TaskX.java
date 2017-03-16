package gcj1c.task2;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "B-large.in";

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
            int B = in.nextInt();
            long M = in.nextLong();

            System.err.printf("%s %s\n", B, M);

            // System.err.printf("%s %s\n", M, Long.toBinaryString(M));

            long ma = (long)Math.pow(2, B - 2);

            if (ma < M) {
                System.err.printf("ma=%s, M=%s\n", ma, M);
                return "IMPOSSIBLE";
            }

            String s = new StringBuilder(Long.toBinaryString(M)).reverse().toString();
            int[][] r = new int[B][B];
            for (int i = 0; i < B; i++) {
                for (int j = i+1; j < B-1; j++) {
                    r[i][j] = 1;
                }
                if (i>0 && i <B-1) {
                    // if ( s.length() > B-2-i && s.charAt(B-2-i) == '1' ) {
                    if (i-1 < s.length() && s.charAt(i-1) == '1') {
                        r[i][B-1] = 1;
                    }
                }
            }

            if (ma == M) {
                for (int i = 0; i < B-1; i++) {
                    r[i][B-1] = 1;
                }
            }

            StringBuilder sb = new StringBuilder();
            sb.append("POSSIBLE\n");
            for (int i = 0; i < B; i++) {
                String s2 = "";
                for (int j = 0; j < B; j++) {
                    s2 += r[i][j];
                }

                if (i != B-1) {
                    s2 += "\n";
                }
                sb.append(s2);
            }


            return sb.toString();
        }
    }
}


