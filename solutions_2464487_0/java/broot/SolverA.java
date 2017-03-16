import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class SolverA {

    private static final String fileName = "A-small-0";
    private Writer out;
    private Scanner in;
    private String chars;
    private int charsPos;
    private int T;
    private int case_;

    private long r2;
    private long t;

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

            long r2 = in.nextLong() * 2;
            long t = in.nextLong();
            long c = 0;
            while (t >= 0) {
                long c2 = c + 1;
                t -= r2 - c * c + c2 * c2;
                c += 2;
            }
            result(String.valueOf((c - 2) / 2));
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
