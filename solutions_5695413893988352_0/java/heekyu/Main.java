import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        private String getDigit(int v, int d) {
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < d; i++) {
                sb.append(v % 10);
                v /= 10;
            }
            return sb.reverse().toString();
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            String c = in.next();
            String j = in.next();
            HashSet<Integer> canC = new HashSet<>();
            HashSet<Integer> canJ = new HashSet<>();
            canC.add(0);
            canJ.add(0);
            int L = c.length();
            for (int i = 0; i < L; i++) {
                HashSet<Integer> nextC = new HashSet<>();
                HashSet<Integer> nextJ = new HashSet<>();
                for (int cc : canC) {
                    char c1 = c.charAt(i);
                    if (c1 == '?') {
                        for (int x = 0; x < 10; x++) {
                            nextC.add(cc * 10 + x);
                        }
                    } else {
                        nextC.add(cc * 10 + (c1 - '0'));
                    }
                }
                for (int cj : canJ) {
                    char j1 = j.charAt(i);
                    if (j1 == '?') {
                        for (int x = 0; x < 10; x++) {
                            nextJ.add(cj * 10 + x);
                        }
                    } else {
                        nextJ.add(cj * 10 + (j1 - '0'));
                    }
                }
                canC = nextC;
                canJ = nextJ;
            }
            int diff = 10000;
            int ansC = -1;
            int ansJ = -1;
            for (int cc : canC) {
                for (int cj : canJ) {
                    int d = Math.abs(cc - cj);
                    if (d < diff || (d == diff && (cc < ansC || (cc == ansC && (cj < ansJ))))) {
                        diff = d;
                        ansC = cc;
                        ansJ = cj;
                    }
                }
            }
            out.println(getDigit(ansC, L) + " " + getDigit(ansJ, L));
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

    }
}

