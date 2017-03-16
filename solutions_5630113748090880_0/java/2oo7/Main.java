import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.Map;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Arthur Gazizov  [2oo7] - Kazan FU
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("input.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.out");
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
            int n = in.nextInt();
            Counter<Integer> counter = new Counter<>();
            int lines = 2 * n - 1;
            for (int i = 0; i < lines; i++) {
                for (int j = 0; j < n; j++) {
                    counter.inc(in.nextInt());
                }
            }
            TreeSet<Integer> set = counter.keySet().stream().filter(key -> counter.get(key) % 2 == 1).collect(Collectors.toCollection(TreeSet::new));
            out.print("Case #" + testNumber + ":");
            for (int value : set) {
                out.print(" " + value);
            }
            out.println();
        }

    }

    static class Counter<T> extends HashMap<T, Integer> implements Map<T, Integer> {
        public void add(T key, Integer count) {
            if (!containsKey(key)) {
                put(key, 0);
            }
            put(key, get(key) + count);
        }

        public void inc(T key) {
            add(key, 1);
        }

        public Integer get(Object key) {
            Integer ret = super.get(key);
            return ret == null ? 0 : ret;
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(Writer writer) {
            super(writer);
        }

        public FastPrinter(OutputStream out) {
            super(out);
        }

        public void close() {
            super.close();
        }

    }

    static class FastScanner extends BufferedReader {
        boolean isEOF;

        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }

        public FastScanner(InputStreamReader inputStreamReader) {
            super(inputStreamReader);
        }

        public int read() {
            try {
                int ret = super.read();
                if (isEOF && ret < 0) {
                    throw new InputMismatchException();
                }
                isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        public String next() {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            while (!isWhiteSpace(c)) {
                sb.appendCodePoint(c);
                c = read();
            }
            return sb.toString();
        }

        public static boolean isWhiteSpace(int c) {
            return c >= -1 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (!isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

    }
}

