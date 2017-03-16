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

            final int E = in.nextInt();
            final int R = in.nextInt();
            final int N = in.nextInt();
            final int[] v = new int[N];
            final int[] m = new int[N];
            final int[] m2 = new int[N];
            int minV = Integer.MAX_VALUE;
            int maxV = 0;
            final int s = E / R;
            long sum = 0;
            for (int i = 0; i < N; i++) {
                final int v2 = in.nextInt();
                v[i] = v2;
                m[i] = E;
                if (v2 < minV) {
                    minV = v2;
                }
                if (v2 > maxV) {
                    maxV = v2;
                }
            }

            for (int p = maxV; p >= minV; p--) {
                for (int x = 0; x < N; x++) {
                    if (v[x] != p) {
                        continue;
                    }
                    int m3 = m[x] - m2[x];
                    if (m3 <= 0) {
                        continue;
                    }
                    sum += p * m3;
                    int r = m[x];
                    m[x] = m2[x];
                    int end = Math.max(0, x - s);
                    for (int x2 = x - 1; x2 >= end; x2--) {
                        r -= R;
                        if (r > m2[x2]) {
                            m2[x2] = r;
                        }
//                        r += R;
//                        if (r < m[x2]) {
//                            m[x2] -= m3;
//                        }
                    }
                    end = Math.min(N - 1, x + s);
                    r = m[x];
//                    m3 =  m2;
                    for (int x2 = x + 1; x2 <= end; x2++) {
                        r += R;
                        if (r < m[x2]) {
                            m[x2] = r;
                        }
                    }
                }
            }
//            int rest = 0;
//            for (int x = 0; x < N; x++) {
//                rest += Math.min(m[x], R);
//            }
//            sum += rest * minV;

            result(String.valueOf(sum));
        }
        out.close();
    }

    private void result(String res) throws IOException {
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
