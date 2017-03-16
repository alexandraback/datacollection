import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Arrays;
import java.util.Scanner;

public class SolverA {

    private static final String fileName = "A-large-0";
    private Writer out;
    private Scanner in;
    private String chars;
    private int charsPos;
    private int T;
    private int case_;

    public static void main(String[] args) throws IOException {
        new SolverA().solve();
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

            int A = in.nextInt();
            int N = in.nextInt();
            int[] motes = new int[N];
            for (int i = 0; i < N; i++) {
                motes[i] = in.nextInt();
            }
            Arrays.sort(motes);

            if (A == 1) {
                result(String.valueOf(N));
                continue;
            }

            int min = Integer.MAX_VALUE;
            int ops = 0;
            for (int i = 0; i < N; i++) {
                int m = motes[i];
                if (A > m) {
                    A += m;
                    continue;
                }

                min = Math.min(min, ops + N - i);
                while (A <= m && ops < min) {
                    ops++;
                    A += A - 1;
                }
                A += m;
            }
            min = Math.min(min, ops);
            result(String.valueOf(min));
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
