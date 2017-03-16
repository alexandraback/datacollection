import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Kartik Singal (ka4tik)
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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        long poww(long n, long p) {
            long ret = 1;
            while (p > 0) {
                if (p % 2 == 1) {
                    ret = ret * n;
                }
                p = p / 2;
                n *= n;
            }
            return ret;
        }

        long f(long n) {
            if (n == 0 || n == 1)
                return 1;
            if (n == 2)
                return 1;
            return poww(2, n - 2);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {

            out.print("Case #" + testNumber + ": ");
            long n = in.nextLong();
            long m = in.nextLong();
            long ways = f(n);
            int g[][] = new int[(int) n][(int) n];
            for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g[i][j] = 0;
            if (m > ways) {
                out.println("IMPOSSIBLE");
            } else {
                out.println("POSSIBLE");

                for (int i = 1; i < n; i++) {
                    for (int j = i + 1; j < n; j++)
                        g[i][j] = 1;
                }
                for (long i = 0; i < n; i++) {
                    long x = n - i - 1;

                    if (m >= f(x)) {
                        g[0][(int) i + 1] = 1;
                        m -= f(x);
                        if (m == 0) break;
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        out.print(g[i][j]);
                    }
                    out.println();
                }
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}

