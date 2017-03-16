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
            final String regex = "B-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int[][] dp = new int[s.length() + 1][2];
            if (s.charAt(0) == '+') {
                dp[1][0] = 0;
                dp[1][1] = 1;
            } else {
                dp[1][0] = 1;
                dp[1][1] = 0;
            }
            for (int i = 2; i <= s.length(); i++) {
                if (s.charAt(i - 1) == '+') {
                    dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1] + 1);
                    dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
                } else {
                    dp[i][0] = Math.min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                    dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1]);
                }
            }
            out.println("Case #" + testNumber + ": " + dp[s.length()][0]);
        }

    }
}

