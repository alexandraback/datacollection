package gcj.qual2015.b;

import java.io.*;
import java.net.URL;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskX {
    public static void main(String[] args) throws IOException {
        String inFile = "B-small-attempt0.in";

        URL inFileUrl = TaskX.class.getResource(inFile);
        InputStream inputStream = new BufferedInputStream(new FileInputStream(inFileUrl.getFile()));
        Scanner in = new Scanner(inputStream);

        String outFile = inFile + ".out";
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outFile)));

        System.out.printf("Input File = [%s]\n", inFile);
        System.out.printf("Output File = [%s]\n", outFile);

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            Solver solver = new Solver();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }

    static class Solver {

        public String solve(int testNumber, Scanner in, PrintWriter out) {
            int D = in.nextInt();

            int[] a = new int[D];
            int ma = 0;
            for (int i = 0; i < D; i++) {
                a[i] = in.nextInt();
                ma = Math.max(ma, a[i]);
            }

            int mi = 1_000_000;
            for (int h = 1; h <= ma; h++) {
                int cost = h;
                for (int i = 0; i < D; i++) {
                    cost += ((a[i]-1) / h);
                }

                mi = Math.min(mi, cost);
            }

            return "" + mi;
        }
    }
}


