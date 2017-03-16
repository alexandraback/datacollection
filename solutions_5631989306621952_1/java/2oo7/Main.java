import java.io.*;
import java.io.OutputStream;
import java.util.InputMismatchException;
import java.io.IOException;
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
        }catch (IOException e){
            throw new RuntimeException();
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.out");
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
            String s = in.next();
            StringBuilder builder = new StringBuilder();
            builder.append(s.charAt(0));
            for (int i = 1; i < s.length(); i++) {
                if (s.charAt(i) < builder.charAt(0)) {
                    builder.append(s.charAt(i));
                } else {
                    StringBuilder temp = new StringBuilder();
                    temp.append(s.charAt(i));
                    builder = temp.append(builder.toString());
                }
            }
            out.println("Case #" + testNumber + ": " + builder);
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

