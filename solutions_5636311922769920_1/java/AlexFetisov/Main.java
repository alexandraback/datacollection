import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AlexFetisov
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
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD_GCJ solver = new TaskD_GCJ();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD_GCJ {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int k = in.nextInt();
            int c = in.nextInt();
            int s = in.nextInt();
            if (s * 2 < k) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (c == 1 && s < k) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (c == 1) {
                for (int i = 0; i < s; ++i) {
                    out.print(i + 1);
                    out.print(" ");
                }
                out.println();
                return;
            }

            if (k % 2 == 1) {
                out.print(IntegerUtils.pow((long) k, (long) c));
                out.print(" ");
                --s;
                --k;
            }

            long begin = 0;
            for (int block = 0; block < k; block += 2) {
                out.print(begin + block + 1 + 1);
                out.print(" ");
                begin += k;
            }
            out.println();
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer stt;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public String nextString() {
            while (stt == null || !stt.hasMoreTokens()) {
                stt = new StringTokenizer(nextLine());
            }
            return stt.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

        public String next() {
            return nextString();
        }

    }

    static class IntegerUtils {
        public static long pow(long x, long p) {
            long result = 1;
            for (long i = p; i > 0; i >>= 1) {
                if ((i & 1) != 0) {
                    result = (result * x);
                }
                x = (x * x);
            }
            return result;
        }

    }
}

