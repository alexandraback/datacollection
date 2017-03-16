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
import java.util.Collection;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] a = new int[2 * n - 1][n];
            int[] inpDeg = new int[2505];
            int[] outDeg = new int[2505];

            for (int i = 0; i < 2 * n - 1; ++i) {
                for (int j = 0; j < n; ++j) {
                    a[i][j] = in.nextInt();
                    if (j != 0) {
                        inpDeg[a[i][j]]++;
                        outDeg[a[i][j - 1]]++;
                    } else {
                        inpDeg[a[i][j]]++;
                    }
                    if (j == n - 1) {
                        outDeg[a[i][j]]++;
                    }
                }
            }

            TreeSet<Integer> list = new TreeSet<Integer>();
            for (int i = 0; i < inpDeg.length; ++i) {
                if (inpDeg[i] != 0 && ((inpDeg[i] % 2 == 1 || outDeg[i] % 2 == 1))) {
                    list.add(i);
                }
            }

            out.println("Case #" + testNumber + ": " + ArrayUtils.toString(list));
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
        public static String toString(Collection<Integer> collection) {
            StringBuilder result = new StringBuilder("");
            for (int x : collection) {
                result.append(x).append(" ");
            }
            return result.substring(0, result.length() - 1);
        }

    }
}

