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
        FastPrinter out = new FastPrinter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            char[] cs = in.next().toCharArray();
            char[] js = in.next().toCharArray();
            int l = cs.length;
            int best = 1000 * 1000 * 1000;
            ic:
            for (int i = 0; i < 1000; i++) {
                int[] cc = new int[l];
                int ii = i;
                for (int j = 0; j < l; j++) {
                    cc[l - 1 - j] = ii % 10;
                    ii /= 10;
                }
                if (ii != 0) continue;
                for (int j = 0; j < l; j++) {
                    if (cs[j] == '?') continue;
                    if (cs[j] - '0' == cc[j]) continue;
                    continue ic;
                }
                jc:
                for (int j = 0; j < 1000; j++) {
                    int[] jc = new int[l];
                    int jj = j;
                    for (int k = 0; k < l; k++) {
                        jc[l - 1 - k] = jj % 10;
                        jj /= 10;
                    }
                    if (jj != 0) continue;
                    for (int k = 0; k < l; k++) {
                        if (js[k] == '?') continue;
                        if (js[k] - '0' == jc[k]) continue;
                        continue jc;
                    }
                    int score = Math.abs(i - j) * 1000 * 1000 + i * 1000 + j;
                    best = Math.min(best, score);
                }
            }
            int[] cc = new int[l];
            int ii = best / 1000 % 1000;
            for (int j = 0; j < l; j++) {
                cc[l - 1 - j] = ii % 10;
                ii /= 10;
            }
            int[] jc = new int[l];
            int jj = best % 1000;
            for (int k = 0; k < l; k++) {
                jc[l - 1 - k] = jj % 10;
                jj /= 10;
            }
            out.print("Case #%d: ", testNumber);
            for (int i = 0; i < l; i++) {
                out.print((char) ('0' + cc[i]));
            }
            out.print(' ');
            for (int i = 0; i < l; i++) {
                out.print((char) ('0' + jc[i]));
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

        public void print(char c) {
            writer.print(c);
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

