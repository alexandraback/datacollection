import java.io.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author padington
 */
public class Main1111 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskAA solver = new TaskAA();
        TaskAA.ss();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskAA {
    public static void ss() {
        int N = 1000000;
        for (int i = 1; i <= N; i++) {
            if (dp[i] == 0) {
                dp[i] = Integer.MAX_VALUE;
            }
            dp[i] = Math.min(dp[i], dp[i - 1]) + 1;
            int rev = reverse(i);
            if (rev <= N && rev > i) {
                dp[rev] = dp[i];
            }
        }
    }

    static int dp[] = new int[1000001];
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        out.println(String.format("Case #%d: %d", testNumber, dp[N]));
    }

    static int reverse(int n) {
        StringBuilder builder = new StringBuilder(String.valueOf(n));
        return Integer.parseInt(builder.reverse().toString());
    }
}

