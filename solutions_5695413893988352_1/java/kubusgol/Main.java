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
        long diff = Long.MAX_VALUE;
        long cans = Long.MAX_VALUE;
        long jans = Long.MAX_VALUE;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String C = in.next();
            String J = in.next();
            String ans[] = new Opt().opt(C, J);
            out.println("Case #" + testNumber + ": " + ans[0] + " " + ans[1]);
//        Random r = new Random();
//        while (true) {
//            int N = Math.max(1, r.nextInt(5));
//            String C = gen(N);
//            String J = gen(N);
//            String[] brute = new Brute().brute(C, J);
//            String[] opt = new Opt().opt(C, J);
//            if (!brute[0].equals(opt[0]) && !brute[1].equals(opt[1])) {
//                System.out.println(C);
//                System.out.println(J);
//                System.out.println(brute[0] + " " + brute[1]);
//                System.out.println(opt[0] + " " + opt[1]);
//                break;
//            }
//        }
        }

        private class Opt {
            private String[] opt(String C, String J) {
                cans = 0;
                jans = 0;
                diff = Long.MAX_VALUE;
                generate(C.toCharArray(), J.toCharArray(), 0, 0, 0);
                int N = C.length();
                return new String[]{pad(cans, N), pad(jans, N)};
            }

            private void generate(char[] c, char[] j, int cur, int cval, int jval) {
                if (cur == c.length) {
                    compare(new String(c), new String(j));
                    return;
                }

                if (c[cur] != '?' && j[cur] != '?') {
                    if (cval != jval) {
                        generate(c, j, cur + 1, cval, jval);
                    } else {
                        if (c[cur] == j[cur]) {
                            generate(c, j, cur + 1, 0, 0);
                        } else if (Integer.parseInt(c[cur] + "") > Integer.parseInt(j[cur] + "")) {
                            generate(c, j, cur + 1, 1, 0);
                        } else {
                            generate(c, j, cur + 1, 0, 1);
                        }
                    }
                } else if (c[cur] == '?' && j[cur] == '?') {
                    if (cval == jval) {
                        c[cur] = '0';
                        j[cur] = '0';
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '0';
                        j[cur] = '1';
                        generate(c, j, cur + 1, 0, 1);
                        c[cur] = '1';
                        j[cur] = '0';
                        generate(c, j, cur + 1, 1, 0);
                        c[cur] = '?';
                        j[cur] = '?';
                    } else if (cval > jval) {
                        c[cur] = '0';
                        j[cur] = '9';
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '?';
                        j[cur] = '?';
                    } else {
                        c[cur] = '9';
                        j[cur] = '0';
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '?';
                        j[cur] = '?';
                    }
                } else if (c[cur] == '?') {
                    if (cval == jval) {
                        c[cur] = j[cur];
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '?';

                        int jnum = Integer.parseInt(j[cur] + "");
                        if (jnum > 0) {
                            c[cur] = (char) ((jnum - 1) + '0');
                            generate(c, j, cur + 1, 0, 1);
                            c[cur] = '?';
                        }

                        if (jnum < 9) {
                            c[cur] = (char) ((jnum + 1) + '0');
                            generate(c, j, cur + 1, 1, 0);
                            c[cur] = '?';
                        }
                    } else if (cval > jval) {
                        c[cur] = '0';
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '?';
                    } else {
                        c[cur] = '9';
                        generate(c, j, cur + 1, cval, jval);
                        c[cur] = '?';
                    }
                } else {
                    if (cval == jval) {
                        j[cur] = c[cur];
                        generate(c, j, cur + 1, cval, jval);
                        j[cur] = '?';

                        int cnum = Integer.parseInt(c[cur] + "");
                        if (cnum > 0) {
                            j[cur] = (char) ((cnum - 1) + '0');
                            generate(c, j, cur + 1, 1, 0);
                            j[cur] = '?';
                        }

                        if (cnum < 9) {
                            j[cur] = (char) ((cnum + 1) + '0');
                            generate(c, j, cur + 1, 0, 1);
                            j[cur] = '?';
                        }

                    } else if (cval > jval) {
                        j[cur] = '9';
                        generate(c, j, cur + 1, cval, jval);
                        j[cur] = '?';
                    } else {
                        j[cur] = '0';
                        generate(c, j, cur + 1, cval, jval);
                        j[cur] = '?';
                    }
                }
            }

            private String pad(long cans, int n) {
                String ans = cans + "";
                while (ans.length() < n) {
                    ans = "0" + ans;
                }
                return ans;
            }

            private void compare(String c, String j) {
                long ci = Long.parseLong(c);
                long ji = Long.parseLong(j);

                long dd = Math.abs(ci - ji);
                if (dd < diff) {
                    diff = dd;
                    cans = ci;
                    jans = ji;
                } else if (dd == diff) {
                    if (ci < cans) {
                        cans = ci;
                        jans = ji;
                    } else if (ci == cans) {
                        if (ji < jans) {
                            cans = ci;
                            jans = ji;
                        }
                    }
                }
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

