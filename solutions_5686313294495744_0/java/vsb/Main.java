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
import java.util.InputMismatchException;
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
            int n = in.nextInt();
            String[][] topics = new String[n][2];
            for (int i = 0; i < n; ++i) {
                String a = in.next();
                String b = in.next();
                topics[i][0] = a;
                topics[i][1] = b;
            }
            int res = 0;
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (basis(mask, topics)) {
                    res = Math.max(res, n - Integer.bitCount(mask));
                }
            }
            out.printf("Case #%d: %d\n", testNumber, res);
        }

        boolean basis(int mask, String[][] topics) {
            int n = topics.length;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    boolean found0 = false;
                    for (int j = 0; j < n; ++j) {
                        if ((mask & (1 << j)) != 0) {
                            if (topics[i][0].equals(topics[j][0])) {
                                found0 = true;
                                break;
                            }
                        }
                    }
                    boolean found1 = false;
                    for (int j = 0; j < n; ++j) {
                        if ((mask & (1 << j)) != 0) {
                            if (topics[i][1].equals(topics[j][1])) {
                                found1 = true;
                                break;
                            }
                        }
                    }
                    if (!found0 || !found1) {
                        return false;
                    }
                }
            }
            return true;
        }

    }

    static class InputReader {
        BufferedReader bufReader;
        StringTokenizer stringTokenizer;
        boolean isEof = false;

        public InputReader(InputStream stream) {
            bufReader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (stringTokenizer == null || !stringTokenizer.hasMoreTokens()) {
                try {
                    String line = bufReader.readLine();
                    if (line == null) {
                        isEof = true;
                        return null;
                    }
                    stringTokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
            }
            return stringTokenizer.nextToken();
        }

        public int nextInt() {
            String s = next();
            if (s == null) {
                return 0;
            }
            return Integer.parseInt(s);
        }

    }
}

