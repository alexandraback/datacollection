import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
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
            String a = in.next();
            String b = in.next();
            String[] res = slow(a, b);
            out.printf("Case #%d: %s %s\n", testNumber, res[0], res[1]);
        }

        String[] slow(String a, String b) {
            int n = 1;
            for (int i = 0; i < a.length(); ++i) {
                n *= 10;
            }
            List<Long> alist = new ArrayList<>();
            List<Long> blist = new ArrayList<>();
            for (long x = 0; x < n; ++x) {
                if (match(x, a).length() != 0) {
                    alist.add(x);
                }
                if (match(x, b).length() != 0) {
                    blist.add(x);
                }
            }
            String[] res = new String[2];
            res[0] = "not";
            res[1] = "found!";

            Long delta = Long.MAX_VALUE;
            for (int i = 0; i < alist.size(); ++i) {
                for (int j = 0; j < blist.size(); ++j) {
                    long cur = Math.abs(alist.get(i) - blist.get(j));
                    delta = Math.min(delta, cur);
                }
            }
            for (int i = 0; i < alist.size(); ++i) {
                for (int j = 0; j < blist.size(); ++j) {
                    long cur = Math.abs(alist.get(i) - blist.get(j));
                    if (cur == delta) {
                        res[0] = match(alist.get(i), a);
                        res[1] = match(blist.get(j), b);
                        return res;
                    }
                }
            }
            System.err.println("botva!");
            return res;
        }

        String match(long x, String t) {
            long p10 = 1;
            for (int i = 0; i < t.length(); ++i) {
                p10 *= 10;
            }
            String res = "";
            for (int i = 0; i < t.length(); ++i) {
                p10 /= 10;
                char c = t.charAt(i);
                char d = (char) ('0' + (x / p10 % 10));
                if (c != '?' && c != d) {
                    return "";
                }
                res += d;
            }
            return res;
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

    }
}

