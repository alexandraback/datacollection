import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Arrays;
import java.util.Scanner;

public class SolverB {

    private static final String fileName = "B-small-0";
    private Writer out;
    private Scanner in;
    private String chars;
    private int charsPos;
    private int T;
    private int case_;

    public static void main(String[] args) throws IOException {
        new SolverB().solve();
    }

    public void solve() throws IOException {
        in = new Scanner(new File(fileName + ".in"));
        out = new FileWriter(fileName + ".out");
        T = in.nextInt();

        int lastProgress = 0;
        for (case_ = 0; case_ < T; case_++) {
            int progress = case_ * 100 / T;
            if (progress > lastProgress) {
                System.out.println(progress + "%, " + case_ + "/" + T);
                lastProgress = progress;
            }

            int N = in.nextInt();
            int X = in.nextInt();
            int Y = in.nextInt();

            int r = (Math.abs(X) + Y) / 2;
            if (r == 0) {
                result (N > 0 ? 1 : 0);
                continue;
            }
            int min = (2 * (r - 1) + 1) * r;
            if (N <= min) {
                result(0);
                continue;
            }
            int n = N - min;
            int kmin = Y + 1;
            if (n >= 2 * r + kmin) {
                result(1);
                continue;
            }
            if (X == 0 || n < kmin) {
                result(0);
                continue;
            }

            double s = 1;
            for (int k = kmin; k < n; k++) {
                s += binom(n, k);
            }
            s /= Math.pow(2, n);

            result(s);
        }
        out.close();
    }

    private double binom(int n, int k) {
        double coeff = 1;
        for (int i = n - k + 1; i <= n; i++) {
            coeff *= i;
        }
        for (int i = 1; i <= k; i++) {
            coeff /= i;
        }
        return coeff;
    }

    private void result(double res) throws IOException {
        out.write("Case #" + (case_ + 1) + ": " + res + "\n");
    }

    private char nextChar() {
        if (chars == null) {
            chars = in.next();
            charsPos = 0;
        } else {
            charsPos++;
        }
        return chars.charAt(charsPos);

    }

    private void endChars() {
        if (chars.length() > charsPos + 1) {
            throw new RuntimeException("String wasn't read fully: " + chars + ", pos: " + charsPos);
        }
        chars = null;
    }
}
