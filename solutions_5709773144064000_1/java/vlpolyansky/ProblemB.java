import com.sun.swing.internal.plaf.metal.resources.metal_it;

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemB {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemB();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "B-large";

    public ProblemB() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            double c = nextDouble();
            double f = nextDouble();
            double x = nextDouble();
            double timeToBuild = 0;
            double best = x / 2.0;
            for (int k = 1; k < x + 1; ++k) {
                timeToBuild = timeToBuild + c / (2 + (k - 1) * f);
                best = Math.min(best, timeToBuild + x / (2 + k * f));
            }
            out.printf("Case #%d: %.10f\n", ii, best);
        }
    }

    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            