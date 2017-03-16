
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "A-small-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int A = in.nextInt();
            int B = in.nextInt();
            double p[] = new double[A];
            for (int i = 0; i < p.length; i++) {
                p[i] = in.nextDouble();
            }
            double minE = B + 2;
            double product = 1;
            for (int i = 0; i < p.length; i++) {
                product *= p[i];
                double e = product * ((A - i - 1) * 2 + (B - A) + 1) + (1 - product) * ((A - i - 1) * 2 + (B - A) + 1 + B + 1);
                minE = Math.min(minE, e);
            }
            out.println("Case #" + t + ": " + minE);
        }

        out.close();
    }
}
