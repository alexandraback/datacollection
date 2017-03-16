import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Скромная Няша Стесняша Блять; Зверь нахуй
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskC {
        int a;
        int b;
        int c;
        int k;
        ArrayList<int[]> arr;
        ArrayList<Integer> ans;
        ArrayList<Integer> stack;
        int[][] ab;
        int[][] ac;
        int[][] bc;

        private void f(int pos) {
            if (pos == arr.size()) {
                if (ans.size() < stack.size()) {
                    ans = new ArrayList<>(stack);
                }
            } else {
                int aa = arr.get(pos)[0];
                int bb = arr.get(pos)[1];
                int cc = arr.get(pos)[2];
                if (ab[aa][bb] + 1 <= k && ac[aa][cc] + 1 <= k && bc[bb][cc] + 1 <= k) {
                    ++ab[aa][bb];
                    ++ac[aa][cc];
                    ++bc[bb][cc];
                    stack.add(pos);

                    f(pos + 1);

                    --ab[aa][bb];
                    --ac[aa][cc];
                    --bc[bb][cc];
                    stack.remove(stack.size() - 1);
                }
                f(pos + 1);
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            System.err.println("testNumber: " + testNumber);
            a = in.readInt();
            b = in.readInt();
            c = in.readInt();
            k = in.readInt();

            arr = new ArrayList<>();
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    for (int l = 0; l < c; l++) {
                        arr.add(new int[]{i, j, l});
                    }
                }
            }

            ans = new ArrayList<>();
            stack = new ArrayList<>();
            ab = new int[a][b];
            ac = new int[a][c];
            bc = new int[b][c];
            f(0);

            out.print("Case #" + testNumber + ": " + ans.size());
            out.printLine();
            for (Integer pos : ans) {
                out.printLine(arr.get(pos)[0] + 1, arr.get(pos)[1] + 1, arr.get(pos)[2] + 1);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
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
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine() {
            writer.println();
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

