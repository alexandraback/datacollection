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
 *
 * @author safadurimo
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
            int b = in.nextInt();
            long m = in.nextLong();

            boolean poss = true;

            int b2 = b - 2;
            if (m > (1 << b2)) poss = false;
            String po = poss ? "POSSIBLE" : "IMPOSSIBLE";
            out.printf("Case #%d: %s\n", testNumber, po);
            if (!poss) {

                return;
            }

            int[][] matrix = new int[b][b];

            long x = 1;
            int exp = 2;
            while (2 * x <= m) {
                x = 2 * x;
                exp++;
            }
            for (int i = 0; i < exp; i++) {
                for (int j = 0; j < exp; j++) {
                    if (j > i) {
                        matrix[i][j] = 1;
                    }
                }
            }


            while (m != 0) {
                if (1l << exp <= m) {
                    if (exp + 1 < b - 1)
                        matrix[exp + 1][b - 1] = 1;
                    m -= 1 << exp;
                }
                exp--;
            }


            // int check
            int[] dp = new int[b];
            dp[0] = 1;
            for (int i = 0; i < b; i++) {
                for (int j = i + 1; j < b; j++) {
                    if (matrix[i][j] == 1)
                        dp[j] += dp[i];
                }
            }
            //out.println("XXX" + dp[b-1]);


            // output

            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    out.print(matrix[i][j]);
                }
                out.println();
            }

        }

    }
}

