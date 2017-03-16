package Qualification.B;

import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Created by mtian on 4/12/14.
 */
public class CookieClickerAlpha {
    public void solve(ContestReader cr, PrintWriter pw) throws Exception {
        double C = cr.nextDouble();
        double F = cr.nextDouble();
        double X = cr.nextDouble();
        double R = 2.0;

        double t = X / R;
        double minSec = t;
        int n = 0;
        while (true) {
            n++;
            t = t + C / (2 + (n - 1) * F) - X / (2 + (n - 1) * F) + X / (2 + n * F);
            if (t > minSec) {
                pw.println(minSec);
                return;
            } else {
                minSec = t;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ContestReader cr = new ContestReader(new FileInputStream("B-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("B-large.out"));
        CookieClickerAlpha solver = new CookieClickerAlpha();
        int T = cr.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(cr, pw);
        }
        pw.flush();
        pw.close();
    }
}

class ContestReader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    public ContestReader(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input));
        tokenizer = new StringTokenizer("");
    }

    public String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
