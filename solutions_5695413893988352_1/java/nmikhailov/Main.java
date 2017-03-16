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
 * @author Nikita Mikhailov
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        long maxDiff = Long.MAX_VALUE;
        long resA = 999999999999999999L;
        long resb = 999999999999999999L;
        int[] aa;
        int[] bb;

        private int[] conv(String s) {
            int[] list = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '?') {
                    list[i] = -1;
                } else {
                    list[i] = s.charAt(i) - '0';
                }
            }
            return list;
        }

        private long maximize(int[] a) {
            long res = 0;
            for (int i = 0; i < a.length; i++) {
                if (a[i] == -1) {
                    res = res * 10L + 9;
                } else {
                    res = res * 10L + a[i];
                }
            }
            return res;
        }

        private long minimize(int[] a) {
            long res = 0;
            for (int i = 0; i < a.length; i++) {
                if (a[i] == -1) {
                    res = res * 10L + 0;
                } else {
                    res = res * 10L + a[i];
                }
            }
            return res;
        }

        private void update(long a, long b) {
            long diff = Math.abs(a - b);
            if (maxDiff > diff) {
                maxDiff = diff;
                resA = a;
                resb = b;
            } else if (maxDiff == diff) {
                if (resA > a) {
                    resA = a;
                    resb = b;
                } else if (resA == a && resb > b) {
                    resb = b;
                }
            }
        }

        private void evalute(int pos) {
            if (pos == aa.length) {
                update(maximize(aa), maximize(bb));
                return;
            }

            if (aa[pos] == -1 || bb[pos] == -1) {
                if (aa[pos] == -1 && bb[pos] == -1) {

                    aa[pos] = bb[pos] = 0;
                    aa[pos] = 1;
                    update(minimize(aa), maximize(bb));

                    aa[pos] = bb[pos] = 0;
                    bb[pos] = 1;
                    update(maximize(aa), minimize(bb));

                    aa[pos] = bb[pos] = 0;
                    evalute(pos + 1);


                } else if (aa[pos] == -1) {
                    int x = bb[pos];

                    aa[pos] = x >= 1 ? x - 1 : 0;
                    update(maximize(aa), minimize(bb));

                    aa[pos] = x <= 8 ? x + 1 : 9;
                    update(minimize(aa), maximize(bb));

                    aa[pos] = x;
                    evalute(pos + 1);
                } else {
                    int x = aa[pos];

                    bb[pos] = x >= 1 ? x - 1 : 0;
                    update(minimize(aa), maximize(bb));

                    bb[pos] = x <= 8 ? x + 1 : 9;
                    update(maximize(aa), minimize(bb));

                    bb[pos] = x;
                    evalute(pos + 1);
                }
            } else {
                if (aa[pos] == bb[pos]) {
                    evalute(pos + 1);
                } else {
                    if (aa[pos] > bb[pos]) {
                        update(minimize(aa), maximize(bb));
                    } else {
                        update(maximize(aa), minimize(bb));
                    }
                }
            }
        }

        private String pad(String x, int n) {
            String res = "";
            for (int i = 0; i < n - x.length(); i++) {
                res = "0" + res;
            }
            return res + x;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String a = in.readToken();
            String b = in.readToken();

            maxDiff = Long.MAX_VALUE;

            int n = a.length();

            aa = conv(a);
            bb = conv(b);

            evalute(0);

            out.println("Case #" + testNumber + ": " + pad("" + resA, a.length()) + " " + pad("" + resb, a.length()));
        }

    }

    static class FastScanner {
        private StringTokenizer st;
        private BufferedReader in;

        public FastScanner(final InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
        }

        public String readToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (final IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public String next() {
            return readToken();
        }

    }
}

