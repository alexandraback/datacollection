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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String C = in.next(), J = in.next();
            int i, j, n = C.length();
            int low = 0;
            int high = (int) Math.pow(10, n);
            // DebugUtils.print(low, high);
            int cAns = -1, jAns = -1, minDiff = Integer.MAX_VALUE;
            String cAnsString = "", jAnsString = "";
            for (i = low; i < high; i++) {
                if (match(i, C, n)) {
                    for (j = low; j < high; j++) {
                        if (match(j, J, n)) {
                            if (Math.abs(i - j) < minDiff) {
                                minDiff = Math.abs(i - j);
                                cAns = i;
                                jAns = j;
                            } else if (Math.abs(i - j) == minDiff) {
                                if (i < cAns) {
                                    cAns = i;
                                    jAns = j;
                                } else if (i == cAns) {
                                    if (j < jAns) {
                                        jAns = j;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            out.printLine("Case #" + testNumber + ": " + convertToString(cAns, n) + " " + convertToString(jAns, n));
        }

        public boolean match(int num, String s, int n) {
            // DebugUtils.print(num, s);
            String x = convertToString(num, n);
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) != '?' && s.charAt(i) != x.charAt(i)) {
                    return false;
                }
            }
            return true;
        }

        public String convertToString(int x, int n) {
            String p = Integer.toString(x);
            while (p.length() < n) {
                p = "0" + p;
            }
            return p;
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tokenizer = null;

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(in.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

