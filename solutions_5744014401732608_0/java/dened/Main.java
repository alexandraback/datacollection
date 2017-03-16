import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.io.IOException;
import java.io.Reader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Denis Nedelyaev
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
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
        InputStream inputStream = new FileInputStream(toRun);
        OutputStream outputStream = new FileOutputStream("b.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskB {
        private final FastScanner in;
        private final PrintWriter out;

        public TaskB(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            int n = in.nextInt();
            long m = in.nextLong();
            boolean[][] adj = realSolve(n, m);
            StringBuilder ans = new StringBuilder();
            if (adj == null) {
                ans.append("IMPOSSIBLE\n");
            } else {
                ans.append("POSSIBLE\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        ans.append(adj[i][j] ? '1' : '0');
                    }
                    ans.append('\n');
                }
            }
            out.print("Case #" + testNumber + ": " + ans);
        }

        private boolean[][] realSolve(int n, long m) {
            boolean[][] adj = new boolean[n][n];
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    adj[i][j] = true;
                }
            }

            long[] val = new long[n];
            val[n - 1] = 1;
            for (int i = n - 2; i >= 1; i--) {
                for (int j = i + 1; j < n; j++) {
                    val[i] += val[j];
                }
            }

            for (int i = 1; i < n; i++) {
                if (val[i] <= m) {
                    m -= val[i];
                    adj[0][i] = true;
                }
            }

            if (m != 0) {
                return null;
            }
            return adj;
        }

    }

    static class FastScanner {
        private final BufferedReader br;
        private String line;
        private int pos;

        public FastScanner(String s) throws IOException {
            this(new StringReader(s));
        }

        public FastScanner(InputStream is) throws IOException {
            this(new InputStreamReader(is, "UTF-8"));
        }

        public FastScanner(Reader reader) throws IOException {
            this(new BufferedReader(reader));
        }

        public FastScanner(BufferedReader reader) throws IOException {
            br = reader;
            line = br.readLine();
            pos = 0;
        }

        public String next() throws IOException {
            if (!skipWhitespace()) {
                return null;
            }

            int start = pos;

            while (pos < line.length()) {
                char c = line.charAt(pos);

                if (c == ' ' || c == '\t') {
                    break;
                }

                pos++;
            }

            return line.substring(start, pos);
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        private boolean skipWhitespace() throws IOException {
            while (line != null) {
                while (pos < line.length()) {
                    char c = line.charAt(pos);

                    if (c != ' ' && c != '\t') {
                        return true;
                    }

                    pos++;
                }

                line = br.readLine();
                pos = 0;
            }

            return false;
        }

    }
}

