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
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            out.printFormat("Case #%d: ", testNumber);

            String sa = in.readString();
            String sb = in.readString();
            out.printLine(smart(sa, sb).ans);
//        out.printLine(stupid(sa, sb));
            System.err.println("test " + testNumber + " ok");
        }

        private Result smart(String sa, String sb) {
            char[] a = sa.toCharArray();
            char[] b = sb.toCharArray();
            int n = a.length;
            if (b.length != n) throw new RuntimeException();

            int firstNotEq = n;
            for (int i = 0; i < n; i++) {
                if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
                    firstNotEq = i;
                    break;
                }
            }

            String ans1 = null;
            long a1 = -1;
            long b1 = -1;
            if (firstNotEq < n) {
                for (int i = 0; i < firstNotEq; i++) {
                    if (a[i] != '?') {
                        b[i] = a[i];
                    }
                    if (b[i] != '?') {
                        a[i] = b[i];
                    } else if (a[i] == '?' && b[i] == '?') {
                        a[i] = b[i] = '0';
                    } else {
                        throw new RuntimeException();
                    }
                }
                if (a[firstNotEq] < b[firstNotEq]) {
                    for (int i = firstNotEq + 1; i < n; i++) {
                        if (a[i] == '?') a[i] = '9';
                        if (b[i] == '?') b[i] = '0';
                    }
                } else if (b[firstNotEq] < a[firstNotEq]) {
                    for (int i = firstNotEq + 1; i < n; i++) {
                        if (a[i] == '?') a[i] = '0';
                        if (b[i] == '?') b[i] = '9';
                    }
                } else {
                    throw new RuntimeException();
                }
                ans1 = new String(a) + " " + new String(b);
                a1 = Long.parseLong(new String(a));
                b1 = Long.parseLong(new String(b));
            } else {
                for (int i = 0; i < firstNotEq; i++) {
                    if (a[i] != '?') {
                        b[i] = a[i];
                    }
                    if (b[i] != '?') {
                        a[i] = b[i];
                    } else if (a[i] == '?' && b[i] == '?') {
                        a[i] = b[i] = '0';
                    } else {
                        throw new RuntimeException();
                    }
                }
                ans1 = new String(a) + " " + new String(b);
                a1 = Long.parseLong(new String(a), 10);
                b1 = Long.parseLong(new String(b), 10);
            }

            Result result = new Result(ans1, a1, b1);

            for (int POS = 0; POS < firstNotEq; POS++) {
                a = sa.toCharArray();
                b = sb.toCharArray();
                String ans2 = null;
                long a2 = -1;
                long b2 = -1;
                if (firstNotEq > 0 && firstNotEq < n) {
                    if (a[firstNotEq] < b[firstNotEq]) {
                        int pos = -1;
                        for (int i = POS; i >= 0; i--) {
                            if (a[i] != '?' && b[i] != '?') continue;
                            if (a[i] == '?' && b[i] == '9') continue;
                            if (a[i] == '0' && b[i] == '?') continue;
                            pos = i;
                            break;
                        }
                        for (int i = pos + 1; i < n; i++) {
                            if (a[i] == '?') a[i] = '0';
                            if (b[i] == '?') b[i] = '9';
                        }
                        for (int i = 0; i < pos; i++) {
                            if (a[i] != '?') {
                                b[i] = a[i];
                            }
                            if (b[i] != '?') {
                                a[i] = b[i];
                            } else if (a[i] == '?' && b[i] == '?') {
                                a[i] = b[i] = '0';
                            } else {
                                throw new RuntimeException();
                            }
                        }
                        if (pos != -1) {
                            if (a[pos] == '?' && b[pos] == '?') {
                                b[pos] = '0';
                                a[pos] = '1';
                            } else if (b[pos] != '?') {
                                if (b[pos] == '9') throw new RuntimeException();
                                a[pos] = (char) (b[pos] + 1);
                            } else if (a[pos] != '?') {
                                if (a[pos] == '0') throw new RuntimeException();
                                b[pos] = (char) (a[pos] - 1);
                            }
                        }
                    } else if (b[firstNotEq] < a[firstNotEq]) {
                        int pos = -1;
                        for (int i = POS; i >= 0; i--) {
                            if (a[i] != '?' && b[i] != '?') continue;
                            if (a[i] == '?' && b[i] == '0') continue;
                            if (a[i] == '9' && b[i] == '?') continue;
                            pos = i;
                            break;
                        }
                        for (int i = pos + 1; i < n; i++) {
                            if (a[i] == '?') a[i] = '9';
                            if (b[i] == '?') b[i] = '0';
                        }
                        for (int i = 0; i < pos; i++) {
                            if (a[i] != '?') {
                                b[i] = a[i];
                            }
                            if (b[i] != '?') {
                                a[i] = b[i];
                            } else if (a[i] == '?' && b[i] == '?') {
                                a[i] = b[i] = '0';
                            } else {
                                throw new RuntimeException();
                            }
                        }
                        if (pos != -1) {
                            if (a[pos] == '?' && b[pos] == '?') {
                                b[pos] = '1';
                                a[pos] = '0';
                            } else if (a[pos] != '?') {
                                if (a[pos] == '9') throw new RuntimeException();
                                b[pos] = (char) (a[pos] + 1);
                            } else if (b[pos] != '?') {
                                if (b[pos] == '0') throw new RuntimeException();
                                a[pos] = (char) (b[pos] - 1);
                            }
                        }
                    } else {
                        throw new RuntimeException();
                    }
                    ans2 = new String(a) + " " + new String(b);
                    a2 = Long.parseLong(new String(a), 10);
                    b2 = Long.parseLong(new String(b), 10);
                    Result test = new Result(ans2, a2, b2);
                    if (test.compareTo(result) < 0) {
                        result = test;
                    }
                }
            }

            return result;
        }

        static class Result implements Comparable<Result> {
            String ans;
            long a;
            long b;

            public Result(String ans, long a, long b) {
                this.ans = ans;
                this.a = a;
                this.b = b;
            }


            public int compareTo(Result o) {
                if (Math.abs(a - b) < Math.abs(o.a - o.b)) return -1;
                if (Math.abs(a - b) > Math.abs(o.a - o.b)) return 1;
                if (Math.abs(a - b) == Math.abs(o.a - o.b) && a < o.a) return -1;
                if (Math.abs(a - b) == Math.abs(o.a - o.b) && a > o.a) return 1;
                if (Math.abs(a - b) == Math.abs(o.a - o.b) && a == o.a && b < o.b) return -1;
                if (Math.abs(a - b) == Math.abs(o.a - o.b) && a == o.a && b > o.b) return 1;
                return 0;
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

        public void printFormat(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

