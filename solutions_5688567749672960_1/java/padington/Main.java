import java.io.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author padington
 */
public class Main {
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
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long N = in.nextLong();
        if (N < 21) {
            out.println(String.format("Case #%d: %d", testNumber, N));
            return;
        }

        long cur = 10;
        long ans = cur;
        long p9 = 9;
        long pp9 = 0;
        int i = 0;
        while (cur * 10 <= N) {
            i++;
            if (i % 2 == 1) {
                pp9 = p9;
            } else {
                p9 = p9 * 10 + 9;
            }
            ans += p9 + 1 + pp9;
            cur *= 10;
        }

        int len = String.valueOf(N).length();
        int l2 = (len + 1) / 2;

        if (N > cur && Long.parseLong(String.valueOf(N).substring(l2, len)) == 0) {
            N--;
            ans++;
        }
        if (cur < N) {
            long res = reverse(String.valueOf(N).substring(0, l2)) + Long.parseLong(String.valueOf(N).substring(l2, len));
            ans += Math.min(res, N - cur);
        }
        out.println(String.format("Case #%d: %d", testNumber, ans));
    }

    static long reverse(String n) {
        StringBuilder builder = new StringBuilder(String.valueOf(n));
        return Long.parseLong(builder.reverse().toString());
    }

}

