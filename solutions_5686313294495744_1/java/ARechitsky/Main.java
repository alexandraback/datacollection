import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Andrey Rechitsky (arechitsky@gmail.com)
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
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
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            HashMap<String, Integer> l = new HashMap<>();
            HashMap<String, Integer> r = new HashMap<>();
            int li = 0, ri = 0;
            ArrayList<HashSet<Integer>> g = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String s1 = in.next();
                String s2 = in.next();
                if (!l.containsKey(s1)) {
                    l.put(s1, li++);
                    g.add(new HashSet<>());
                }
                if (!r.containsKey(s2)) r.put(s2, ri++);
                g.get(l.get(s1)).add(r.get(s2));
            }
            int[] mt = new int[ri];
            Arrays.fill(mt, -1);
            boolean[] used = new boolean[li];
            for (int i = 0; i < li; i++) {
                Arrays.fill(used, false);
                tryKuhn(i, li, g, mt, used);
            }
            int tmp = 0;
            for (int i = 0; i < ri; i++) {
                if (mt[i] != -1) tmp++;
            }
            out.printLine("Case #%d: %d", testNumber, n + tmp - li - ri);
        }

        boolean tryKuhn(int v, int n, ArrayList<HashSet<Integer>> g, int[] mt, boolean[] used) {
            if (used[v]) return false;
            used[v] = true;
            for (int to : g.get(v)) {
                if (mt[to] == -1 || tryKuhn(mt[to], n, g, mt, used)) {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        }

    }

    static class FastPrinter {
        private final PrintWriter writer;

        public FastPrinter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public FastPrinter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(String s) {
            writer.println(s);
        }

        public void printLine(String format, Object... args) {
            printLine(String.format(format, args));
        }

    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            this.reader = new BufferedReader(new InputStreamReader(stream));
            this.st = new StringTokenizer("");
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(readLine());
            }
            return st.nextToken();
        }

        private String readLine() {
            String line = tryReadLine();
            if (line == null) throw new InputMismatchException();
            return line;
        }

        private String tryReadLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

    }
}

