import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
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
 * @author Hieu Le
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
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        private int N;
        private int J;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            N = 16;
            J = 50;
            int[] s = new int[N];
            s[0] = s[N - 1] = 1;

            out.println("Case #" + testNumber + ": ");
            for (int i = 1; i < N - 1; i++) {
                if (i == N - 1 - i) continue;
                for (int j = 1; j < N - 1; j++)
                    s[j] = 0;
                s[i] = s[N - 1 - i] = 1;
                jam(s, i, 1, out);
                if (J == 0) break;
            }
        }

        private void jam(int[] s, int distance, int index, PrintWriter out) {
            if (J == 0) return;

            if (index >= N - 1 - distance) {
                for (int i = 0; i < N; i++)
                    out.print(s[i]);
                for (int i = 2; i <= 10; i++)
                    out.print(" " + (power(i, distance) + 1));
                out.println();
                J--;
                return;
            }

            jam(s, distance, index + 1, out);

            if (s[index] == 0 && s[index + distance] == 0) {
                s[index] = s[index + distance] = 1;
                jam(s, distance, index + 1, out);
                s[index] = s[index + distance] = 0;
            }
        }

        private static long power(int base, int exponent) {
            if (exponent == 0)
                return 1;

            long result = power(base, exponent >> 1);
            result *= result;
            if (exponent % 2 == 1)
                result *= base;
            return result;
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;
        private static final int BUFFER_SIZE = 32768;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), BUFFER_SIZE);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}

