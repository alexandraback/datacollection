import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        final String regex = "C-(small|large).*[.]in";
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
        OutputStream outputStream = new FileOutputStream("c.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskC {
        private final FastScanner in;
        private final PrintWriter out;
        private int[] bff;
        private int n;
        private int[] cycle;
        private int[] cycleSize;
        private int[] distToCycle;
        private int[] entryToCycle;
        private int[] dist;

        public TaskC(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            n = in.nextInt();
            bff = in.nextInts(n);
            for (int i = 0; i < bff.length; i++) {
                bff[i]--;
            }
            out.println("Case #" + testNumber + ": " + realSolve());
        }

        private int realSolve() {
            cycle = new int[n];
            cycleSize = new int[n];
            distToCycle = new int[n];
            entryToCycle = new int[n];
            Arrays.fill(cycle, -1);
            Arrays.fill(distToCycle, -1);
            Arrays.fill(entryToCycle, -1);

            for (int i = 0; i < n; i++) {
                dist = new int[n];
                Arrays.fill(dist, -1);
                dfs(i, 0);
            }

            int ans1 = 0;
            int ans2 = 0;
            for (int i = 0; i < n; i++) {
                if (cycleSize[i] == 2) {
                    int maxTail1 = 0;
                    int maxTail2 = 0;
                    for (int j = 0; j < n; j++) {
                        if (cycle[j] == i) {
                            if (entryToCycle[j] == i) {
                                maxTail1 = Math.max(maxTail1, distToCycle[j]);
                            } else {
                                maxTail2 = Math.max(maxTail2, distToCycle[j]);
                            }
                        }
                    }

                    ans1 += cycleSize[i] + maxTail1 + maxTail2;
                }

                ans2 = Math.max(ans2, cycleSize[i]);
            }

            return Math.max(ans1, ans2);
        }

        private void dfs(int v, int d) {
            if (cycle[v] != -1) {
                return;
            }

            if (dist[v] != -1) {
                cycle[v] = v;
                cycleSize[v] = d - dist[v];
                int u = v;
                do {
                    distToCycle[u] = 0;
                    entryToCycle[u] = u;
                    u = bff[u];
                } while (u != v);

                return;
            }

            dist[v] = d;

            int u = bff[v];
            dfs(u, d + 1);
            cycle[v] = cycle[u];

            if (distToCycle[v] == -1) {
                distToCycle[v] = distToCycle[u] + 1;
            }
            if (entryToCycle[v] == -1) {
                entryToCycle[v] = entryToCycle[u];
            }
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

        public int[] nextInts(int n) throws IOException {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
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

