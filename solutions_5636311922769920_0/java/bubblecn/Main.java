package reg;
import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "D-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("d.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            long k = in.nextLong();
            long c = in.nextLong();
            long s = in.nextLong();
            long[] pow = new long[(int) c + 1];
            pow[0] = 1;
            for (int i = 1; i <= c; i++)
                pow[i] = pow[i - 1] * k;

            if (c * s < k) {
                out.println("IMPOSSIBLE");
                return;
            }
            for (long p = 0; p < k; ) {
                long pos = 0;
                for (long lvl = 1; lvl <= c; lvl++) {
                    pos += Math.min(p, k - 1) * pow[(int) (c - lvl)];
                    p++;
                }
                out.print(pos + 1 + " ");
            }

            out.println();
        }

    }
}

