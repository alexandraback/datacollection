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
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
 *
 * @author Andrey Rechitsky (arechitsky@gmail.com)
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
            char[] cs = in.next().toCharArray();
            char[] js = in.next().toCharArray();
            int l = cs.length;
            //1 c==j
            boolean[] pos = new boolean[3];
            long[][] ans = new long[3][2];
            int cp = -1;
            pos[0] = true;
            for (int i = 0; i < l; i++) {
                int c = 0;
                if (cs[i] != '?') c = cs[i] - '0';
                if (js[i] != '?') {
                    if (cs[i] != '?' && js[i] != cs[i]) {
                        pos[0] = false;
                        cp = i;
                        break;
                    }
                    c = js[i] - '0';
                }
                ans[0][0] = ans[0][0] * 10 + c;
            }
            ans[0][1] = ans[0][0];

            if (!pos[0]) {
                char[][] inp = {cs, js};
                for (int tmp = 0; tmp < 2; tmp++) {
                    pos[tmp + 1] = true;
                    char ccs[] = Arrays.copyOf(inp[tmp], l);
                    char jjs[] = Arrays.copyOf(inp[(tmp + 1) % 2], l);
                    int ccp = cp;
                    boolean ec = false;
                    for (; ccp >= 0; ccp--) {
                        if (ccs[ccp] == '?' && jjs[ccp] == '?') {
                            ec = true;
                            break;
                        } else if (ccs[ccp] == '?' && jjs[ccp] != '?') {
                            if (jjs[ccp] == '9') continue;
                            ccs[ccp] = (char) (jjs[ccp] + 1);
                            break;
                        } else if (ccs[ccp] != '?' && jjs[ccp] == '?') {
                            if (ccs[ccp] == '0') continue;
                            jjs[ccp] = (char) (ccs[ccp] - 1);
                            break;
                        } else {
                            if (ccs[ccp] > jjs[ccp]) break;
                        }
                    }
                    if (ccp == -1) {
                        pos[tmp + 1] = false;
                        continue;
                    }
                    if (ec) {
                        int newCp = -1;
                        for (int i = 0; i < ccp; i++) {
                            if (ccs[i] != '?' && ccs[i] > '0') newCp = i;
                        }
                        if (newCp >= 0) {
                            ccp = newCp;
                        } else {
                            ccs[ccp] = '1';
                        }
                        jjs[ccp] = (char) (ccs[ccp] - 1);
                    }
                    ans[tmp + 1][tmp] = 0;
                    ans[tmp + 1][(tmp + 1) % 2] = 0;
                    for (int i = 0; i < l; i++) {
                        if (i < ccp) {
                            int c = 0;
                            if (ccs[i] != '?') c = ccs[i] - '0';
                            if (jjs[i] != '?') c = jjs[i] - '0';
                            ans[tmp + 1][tmp] = ans[tmp + 1][tmp] * 10 + c;
                            ans[tmp + 1][(tmp + 1) % 2] = ans[tmp + 1][(tmp + 1) % 2] * 10 + c;
                        } else {
                            ans[tmp + 1][tmp] = ans[tmp + 1][tmp] * 10 + (ccs[i] == '?' ? 0 : (ccs[i] - '0'));
                            ans[tmp + 1][(tmp + 1) % 2] = ans[tmp + 1][(tmp + 1) % 2] * 10 + (jjs[i] == '?' ? 9 : (jjs[i] - '0'));
                        }
                    }


                }
            }

            int best = -1;
            long bestsc = 0;
            for (int i = 0; i < 3; i++) {
                if (!pos[i]) continue;
                long sc = Math.abs(ans[i][0] - ans[i][1]);
                if (best == -1 || sc < bestsc ||
                        (sc == bestsc && (ans[i][0] < ans[best][0] ||
                                (ans[i][0] == ans[best][0] && ans[i][1] < ans[best][1])))) {
                    best = i;
                    bestsc = sc;
                }
            }
            int[] cc = new int[l];
            long ii = ans[best][0];
            for (int j = 0; j < l; j++) {
                cc[l - 1 - j] = (int) (ii % 10);
                ii /= 10;
            }
            int[] jc = new int[l];
            long jj = ans[best][1];
            ;
            for (int k = 0; k < l; k++) {
                jc[l - 1 - k] = (int) (jj % 10);
                jj /= 10;
            }
            out.print("Case #%d: ", testNumber);
            for (int i = 0; i < l; i++) {
                out.print((char) ('0' + cc[i]));
            }
            out.print(' ');
            for (int i = 0; i < l; i++) {
                out.print((char) ('0' + jc[i]));
            }
            out.printLine();
        }

    }

    static class FastPrinter {
        private final PrintWriter writer;

        public FastPrinter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public FastPrinter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine() {
            writer.println();
        }

        public void print(char c) {
            writer.print(c);
        }

        public void print(String s) {
            writer.print(s);
        }

        public void print(String format, Object... args) {
            print(String.format(format, args));
        }

    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer st;

        public FastScanner(InputStream stream) {
            this.reader = new BufferedReader(new InputStreamReader(stream));
            this.st = new StringTokenizer("");
        }

        public String next() {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(readLine());
            }
            return st.nextToken();
        }

        private String readLine() {
            String line = tryReadLine();
            if (line == null) throw new InputMismatchException();
            return line;
        }

        private String tryReadLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

    }
}

