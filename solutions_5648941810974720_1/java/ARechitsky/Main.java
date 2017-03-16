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
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStreamReader;
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
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int zc = 0;
            int oc = 0;
            int wc = 0;
            int rc = 0;
            int uc = 0;
            int vc = 0;
            int xc = 0;
            int sc = 0;
            int gc = 0;
            int nc = 0;
            char[] s = in.next().toCharArray();
            int[] counts = new int[26];
            for (char c : s) {
                counts[c - 'A']++;
            }
            int[] ans = new int[10];
            ans[0] = counts['z' - 'a'];
            ans[2] = counts['w' - 'a'];
            ans[4] = counts['u' - 'a'];
            ans[1] = counts['o' - 'a'] - ans[0] - ans[2] - ans[4];
            ans[3] = counts['r' - 'a'] - ans[0] - ans[4];
            ans[6] = counts['x' - 'a'];
            ans[7] = counts['s' - 'a'] - ans[6];
            ans[5] = counts['v' - 'a'] - ans[7];
            ans[8] = counts['g' - 'a'];
            ans[9] = counts['i' - 'a'] - ans[5] - ans[6] - ans[8];
            out.print("Case #%d: ", testNumber);
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < ans[i]; j++) {
                    out.print(i);
                }
            }
            out.printLine();
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

        public void printLine() {
            writer.println();
        }

        public void print(long i) {
            writer.print(i);
        }

        public void print(String s) {
            writer.print(s);
        }

        public void print(String format, Object... args) {
            print(String.format(format, args));
        }

    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            this.reader = new BufferedReader(new InputStreamReader(stream));
            this.st = new StringTokenizer("");
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

