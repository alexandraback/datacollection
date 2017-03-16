package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class First {

    public static void main(String[] args) throws FileNotFoundException {
        String path = ClassLoader.getSystemClassLoader().getResource("codejam/").getPath();
        First worker = new First();

        worker.scan(new File(path, "first-s.in"), new File(path, "first-s.out"));
//        worker.scan(new File(path, "first-x.in"), new File(path, "first-x.out"));
    }

    private void scan(File input, File output) throws FileNotFoundException {
        Scanner in = new Scanner(input);
        PrintWriter out = new PrintWriter(output);

        int n = Integer.parseInt(in.nextLine());
        for (int i = 0; i < n; i++) {
            String[] x = in.nextLine().split(" ");
            String[] y = in.nextLine().split(" ");
            int a = Integer.parseInt(x[0]);
            int b = Integer.parseInt(x[1]);
            double[] p = new double[y.length];
            for (int j = 0; j < y.length; j++) {
                p[j] = Double.parseDouble(y[j]);
            }
            out.printf("Case #%d: %s\n", i + 1, solve(a, b, p));
        }

        out.flush();
        out.close();
        in.close();
    }

    public String solve(int a, int b, double[] p) {
        double min = 2 + b;
        for (int i = 0; i < a; i++) {
            double pp = pPos(p, a - i);
            double pn = 1 - pp;
            int togo = (1 + i + b - (a - i));
            double exp = pp * togo + pn * (togo + 1 + b);
            if (exp < min) {
                min = exp;
            }
        }
        return String.format("%.6f", min);
    }

    double pPos(double[] p, int k) {
        double x = 1;
        for (int i = 0; i  < k; i++) {
            x *= p[i];
        }
        return x;
    }
}
