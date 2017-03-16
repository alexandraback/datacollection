import java.io.*;
import java.util.*;

public class SafetyInNumbers {

    BufferedReader br;
    StringTokenizer st = new StringTokenizer("");

    private void solve() throws IOException {
//        final String IO_FILE = null;
        final String IO_FILE = "./A/A-small-attempt0";
        final PrintWriter pw;
        if (IO_FILE == null) {
            br = new BufferedReader(new InputStreamReader(System.in));
            pw = new PrintWriter(System.out);
        } else {
            br = new BufferedReader(new FileReader(IO_FILE + ".in"));
            pw = new PrintWriter(IO_FILE + ".out");
        }
        int testCases = nextInt();
        for (int ti = 1; ti <= testCases; ti++) {
            int n = nextInt();
            List<Integer> s = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                s.add(nextInt());
            }
            List<Double> res = doSolve(s, n);
            pw.print("Case #" + ti + ":");
            for (Double re : res) {
                pw.printf(" %.6f", re * 100);
            }
            pw.println();
        }
        br.close();
        pw.close();
    }

    private List<Double> doSolve(List<Integer> s, int n) {
        List<Double> res = new ArrayList<Double>();
        double sum = 0;
        for (int v : s) {
            sum += v;
        }
        double low = 0;
        double high = 3 * sum;
        while (Math.abs(high - low) > 1e-9) {
            double V = (low + high) / 2;
            double ySum = 0;
            for (int si : s) {
                double y = (V - si) / sum;
                ySum += Math.max(y, 0);
            }
            if (ySum > 1) {
                high = V;
            } else {
                low = V;
            }
        }
        for (int si : s) {
            double y = (high - si) / sum;
            res.add(Math.max(y, 0));
        }
        return res;
    }

    private double find(int si, int sj, double sum, int n) {
//        return ((sj - si) * (n - 1) + sum) / (n * sum);
        return (sj - si + sum) / (2 * sum);
    }

    String nextString() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    public static void main(String[] args) throws IOException {
        new SafetyInNumbers().solve();
    }
}
