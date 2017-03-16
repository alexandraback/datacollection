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
            int B = in.nextInt(), i, j, k;
            long M = in.nextLong();
            long limit = (long) Math.pow(2, B - 2);
            if (M > limit) {
                out.printLine("Case #" + testNumber + ": IMPOSSIBLE");
                return;
            }
            out.printLine("Case #" + testNumber + ": POSSIBLE");
            int a[][] = new int[B][B];
            for (i = 0; i < B - 1; i++) {
                a[i][i + 1] = 1;
            }
            if (B > 2) {
                long mul[] = new long[B];
                mul[B - 1] = 1;
                mul[B - 2] = 1;
                for (i = B - 3; i >= 0; i--) {
                    mul[i] = mul[i + 1] * 2;
                }
                int index = -1;
                long x = 1;
                for (i = B - 3; i >= 0; i--) {
                    if (M >= mul[i]) {
                        for (j = i + 1; j < B; j++) {
                            a[i][j] = 1;
                        }
                        x = mul[i];
                    } else {
                        index = i;
                        break;
                    }
                }
                M -= x;
                for (i = index + 1; i < B; i++) {
                    if (M >= mul[i]) {
                        a[index][i] = 1;
                        M -= mul[i];
                    }
                }
            }
            for (i = 0; i < B; i++) {
                for (j = 0; j < B - 1; j++) {
                    out.print(a[i][j]);
                }
                out.printLine(a[i][j]);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}

