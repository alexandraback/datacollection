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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            int N = in.nextInt();
            TaskC.Word[] words = new TaskC.Word[N];
            for (int i = 0; i < N; i++) {
                String a = in.next();
                String b = in.next();
                words[i] = new TaskC.Word(a, b);
            }
            int[] dp = new int[1 << N];
            // Arrays.fill(dp, -1);
            for (int i = 0; i < dp.length; i++) {
                for (int next = 0; next < N; next++) {
                    if (((1 << next) & i) == 0) {
                        int plus = 0;
                        int flag = 0;
                        for (int j = 0; j < N; j++) {
                            if (((1 << j) & i) > 0) {
                                if (words[next].a.equals(words[j].a)) flag |= 1;
                                if (words[next].b.equals(words[j].b)) flag |= 2;
                            }
                        }
                        if (flag == 3) {
                            plus = 1;
                        }
                        dp[(1 << next) | i] = Math.max(dp[(1 << next) | i], dp[i] + plus);
                    }
                }
            }
            out.println(dp[(1 << N) - 1]);
        }

        static class Word {
            String a;
            String b;

            public Word(String a, String b) {
                this.a = a;
                this.b = b;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

