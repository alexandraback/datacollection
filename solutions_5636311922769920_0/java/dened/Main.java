import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Reader;
import java.util.stream.Collectors;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.StringReader;
import java.io.BufferedReader;
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
        InputStream inputStream = new FileInputStream(toRun);
        OutputStream outputStream = new FileOutputStream("d.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskD {
        private final FastScanner in;
        private final PrintWriter out;

        public TaskD(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            int k = in.nextInt();
            int c = in.nextInt();
            int s = in.nextInt();

            List<Long> ans = realSolve(k, c);

            out.print("Case #" + testNumber + ": ");
            if (ans.size() > s) {
                out.println("IMPOSSIBLE");
            } else {
                out.println(
                        ans.stream()
                                .map(v -> v + 1)
                                .map(Object::toString)
                                .collect(Collectors.joining(" "))
                );
            }
        }

        private List<Long> realSolve(int k, int c) {
            List<Long> ans = new ArrayList<>();

            long p = 0;
            int j = 0;
            for (int i = 0; i < k; i++) {
                p = p * k + i;
                j = (j + 1) % c;
                if (j == 0) {
                    ans.add(p);
                    p = 0;
                }
            }

            if (j != 0) {
                while (j != 0) {
                    p *= k;
                    j = (j + 1) % c;
                }

                ans.add(p);
            }

            return ans;
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

