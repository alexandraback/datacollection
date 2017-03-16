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
 * @author AlexFetisov
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
            int n = in.nextInt();
            int[] f = new int[n];
            int[] id = new int[n];
            for (int i = 0; i < n; ++i) {
                f[i] = in.nextInt() - 1;
                id[i] = i;
            }
            int res = 1;
            do {

                for (int i = 2; i <= n; ++i) {
                    boolean ok = true;
                    for (int j = 0; j < i; ++j) {
                        if (j == 0 && (f[id[0]] == id[i - 1] || f[id[0]] == id[1])) continue;
                        if (j == i - 1 && (f[id[i - 1]] == id[i - 2] || f[id[i - 1]] == id[0])) continue;
                        if (j > 0 && j < i - 1) {
                            if (f[id[j]] == id[j - 1] || f[id[j]] == id[j + 1]) {
                                continue;
                            }
                        }
                        ok = false;
                        break;
                    }
                    if (ok) {
                        res = Math.max(res, i);
                    }
                }
            } while (ArrayUtils.nextPermutation(id));

            out.println("Case #" + testNumber + ": " + res);
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

    static class ArrayUtils {
        public static boolean nextPermutation(int[] p) {
            for (int a = p.length - 2; a >= 0; --a) {
                if (p[a] < p[a + 1]) {
                    for (int b = p.length - 1; ; --b) {
                        if (p[b] > p[a]) {
                            int t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                            for (++a, b = p.length - 1; a < b; ++a, --b) {
                                t = p[a];
                                p[a] = p[b];
                                p[b] = t;
                            }
                            return true;
                        }
                    }
                }
            }
            return false;
        }

    }
}

