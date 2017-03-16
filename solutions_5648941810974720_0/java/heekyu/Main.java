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
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        private void minus(char c, int[] cnt, int minus) {
            cnt[c - 'A'] -= minus;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            String s = in.next();
            int[] cnt = new int[26];
            for (int i = 0; i < s.length(); i++) {
                cnt[s.charAt(i) - 'A']++;
            }
            int[] res = new int[10];
            res[0] = cnt[25];
            minus('E', cnt, res[0]);
            minus('R', cnt, res[0]);
            minus('O', cnt, res[0]);
            res[2] = cnt['W' - 'A'];
            minus('T', cnt, res[2]);
            minus('O', cnt, res[2]);
            res[4] = cnt['U' - 'A'];
            minus('F', cnt, res[4]);
            minus('O', cnt, res[4]);
            minus('R', cnt, res[4]);
            res[6] = cnt['X' - 'A'];
            minus('S', cnt, res[6]);
            minus('I', cnt, res[6]);
            res[1] = cnt['O' - 'A'];
            minus('N', cnt, res[1]);
            minus('E', cnt, res[1]);
            res[5] = cnt['F' - 'A'];
            minus('I', cnt, res[5]);
            minus('V', cnt, res[5]);
            minus('E', cnt, res[5]);
            res[3] = cnt['R' - 'A'];
            minus('T', cnt, res[3]);
            minus('H', cnt, res[3]);
            minus('E', cnt, res[3] * 2);
            res[7] = cnt['V' - 'A'];
            minus('S', cnt, res[7]);
            minus('E', cnt, res[7] * 2);
            minus('N', cnt, res[7]);
            res[8] = cnt['T' - 'A'];
            minus('E', cnt, res[8]);
            res[9] = cnt['E' - 'A'];

            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < res[i]; j++) {
                    sb.append(i);
                }
            }
            out.println(sb.toString());
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

