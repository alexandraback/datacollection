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
        InputStream inputStream = new FileInputStream(toRun);
        OutputStream outputStream = new FileOutputStream("a.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskA {
        private static final int MAX_NUM = 1000000;
        private final FastScanner in;
        private final PrintWriter out;
        private final long[] ans;

        public TaskA(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;

            ans = new long[MAX_NUM + 1];
            for (int n = 1; n <= MAX_NUM; n++) {
                boolean[] seen = new boolean[10];
                int count = 0;
                for (int k = 1; count < 10; k++) {
                    for (long t = ans[n] = (long) k * n; t > 0; t /= 10) {
                        int d = (int) (t % 10);
                        if (!seen[d]) {
                            seen[d] = true;
                            count++;
                        }
                    }
                }
            }
        }

        public void solve(int testNumber) throws IOException {
            int n = in.nextInt();
            out.println("Case #" + testNumber + ": " + realSolve(n));
        }

        private String realSolve(int n) {
            if (n == 0) {
                return "INSOMNIA";
            }

            return Long.toString(ans[n]);
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

