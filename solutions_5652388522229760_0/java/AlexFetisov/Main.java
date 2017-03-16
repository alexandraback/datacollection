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
        TaskA_GCJ solver = new TaskA_GCJ();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA_GCJ {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            long n = in.nextInt();
            if (n == 0) {
                out.println("INSOMNIA");
            } else {
                int mask = 0;
                mask = getMask(n);
                long N = n;
                while (mask != (1 << 10) - 1) {
                    N += n;
                    mask |= getMask(N);
                }
                out.println(N);
            }

        }

        private int getMask(long n) {
            String c = String.valueOf(n);
            int mask = 0;
            for (char cc : c.toCharArray()) {
                mask |= (1 << (cc - '0'));
            }
            return mask;
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
}

