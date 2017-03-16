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
import java.io.PrintStream;
import java.util.Arrays;
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int i, j, k;
            String ans[][][][] = new String[3][3][3][11];
            int pp[][][][] = new int[3][3][3][11];
            int a[][] = new int[27][3], c = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    for (k = 0; k < 3; k++) {
                        a[c][0] = i;
                        a[c][1] = j;
                        a[c][2] = k;
                        c++;
                        countMax(a, c, i, j, k, ans, pp);
                    }
                }
            }
            int T = in.nextInt();
            for (int t = 1; t <= T; t++) {
                int J = in.nextInt(), P = in.nextInt(), S = in.nextInt(), K = in.nextInt();
                String x = "";
                int max = 0;

                for (i = 0; i <= K; i++) {
                    if (pp[J - 1][P - 1][S - 1][i] > max) {
                        max = pp[J - 1][P - 1][S - 1][i];
                        x = ans[J - 1][P - 1][S - 1][i];
                    }
                }
                out.printLine("Case #" + t + ": " + max);
                DebugUtils.print(max);
                int index[][] = new int[30][3];
                c = 0;
                for (i = 0; i < J; i++) {
                    for (j = 0; j < P; j++) {
                        for (k = 0; k < S; k++) {
                            index[c][0] = i + 1;
                            index[c][1] = j + 1;
                            index[c++][2] = k + 1;
                        }
                    }
                }
                for (i = 0; i < x.length(); i++) {
                    if (x.charAt(i) == '1') {
                        out.printLine(index[i][0] + " " + index[i][1] + " " + index[i][2]);
                        DebugUtils.print(index[i][0] + " " + index[i][1] + " " + index[i][2]);
                    }
                }
            }
        }

        public void countMax(int a[][], int PP, int J, int P, int S, String ans[][][][], int pp[][][][]) {
            int i, j, k;
            int c = 0;
            String s;
            int allowed[] = new int[PP], comb = 0;
            int ks[] = new int[11];
            //Arrays.fill(ks, 0);
            for (i = (1 << PP) - 1; i >= 0; i--) {
                s = Integer.toBinaryString(i);
                while (s.length() < PP) {
                    s = "0" + s;
                }
                c = 0;
                comb = 0;
                Arrays.fill(allowed, -1);
                for (j = 0; j < PP; j++) {
                    if (s.charAt(j) == '1') {
                        allowed[c++] = j;
                    }
                }
                for (j = 0; j < c; j++) {
                    for (k = j + 1; k < c; k++) {
                        if (sameComb(a[allowed[j]], a[allowed[k]])) {
                            comb++;
                            if (comb > 10) break;
                        }
                    }
                    if (comb > 10) break;
                }
                if (comb <= 10 && ks[comb] < c) {
                    ks[comb] = c;
                    ans[J][P][S][comb] = s;
                    pp[J][P][S][comb] = c;
                }


            }

            //DebugUtils.print(J, P, S, ks);
        }

        public boolean sameComb(int x[], int y[]) {
            if (x[0] == y[0]) {
                if (x[1] == y[1] || x[2] == y[2]) {
                    return true;
                }
                return false;
            } else if (x[1] == y[1] && x[2] == y[2]) {
                return true;
            }
            return false;
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

    }

    static class DebugUtils {
        public static void print(Object... a) {
            boolean oj = System.getProperty("ONLINE_JUDGE") != null;
            if (!oj)
                System.out.println(Arrays.deepToString(a));
        }

    }
}

