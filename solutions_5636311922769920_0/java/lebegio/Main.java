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
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lebegio
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "D-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("d.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            boolean isPos = true;
            if (C == 1 || K == 1) {
                if (S < K) {
                    out.println("Case #" + testNumber + ": IMPOSSIBLE");
                } else {
                    out.print("Case #" + testNumber + ": ");
                    for (int i = 0; i < K; i++) {
                        out.print((i + 1) + " ");
                    }
                    out.println();
                }
            } else {
                BigInteger MAX = BigInteger.valueOf(K).pow(C);
                BigInteger v = BigInteger.valueOf(K).pow(C - 1);
                BigInteger poz = BigInteger.valueOf(2);
                ArrayList<BigInteger> pozs = new ArrayList<>();
                int checked = 0;
                while (MAX.compareTo(poz) >= 0) {
                    checked += 2;
                    pozs.add(poz);
                    poz = poz.add(v).add(v).add(BigInteger.ONE).add(BigInteger.ONE);
                    if (MAX.compareTo(poz) < 0 && checked < K) {
                        pozs.add(MAX);
                        checked++;
                        break;
                    }
                }
                if (checked < K) {
                    int p = 4 / 0;
                }

                if (pozs.size() > S) {
                    out.println("Case #" + testNumber + ": IMPOSSIBLE");
                } else {
                    out.print("Case #" + testNumber + ": ");
                    for (BigInteger t : pozs) {
                        out.print(t + " ");
                    }
                    out.println();
                }
            }
        }

    }

    static class MyReader {
        private BufferedReader buffReader;
        private StringTokenizer strTokenizer;
        private static final int SIZE = 32768;

        public MyReader(InputStream inputStream) {
            buffReader = new BufferedReader(new InputStreamReader(inputStream), SIZE);
        }

        public String next() {
            if (strTokenizer == null || !strTokenizer.hasMoreTokens()) {
                try {
                    strTokenizer = new StringTokenizer(buffReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return strTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

