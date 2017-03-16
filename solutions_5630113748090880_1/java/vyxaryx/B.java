import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {
    static class ProblemData {
        private final BufferedReader rd;
        private final PrintWriter wr;
        private StringTokenizer tok = null;

        public ProblemData(BufferedReader rd, PrintWriter wr) {
            this.rd = rd;
            this.wr = wr;
        }

        public static ProblemData files(String ifn, String ofn) throws IOException {
            BufferedReader rd = new BufferedReader(new FileReader(new File(ifn)));
            PrintWriter wr = new PrintWriter(new FileWriter(ofn));
            return new ProblemData(rd, wr);
        }

        public static ProblemData console() {
            BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter wr = new PrintWriter(System.out);
            return new ProblemData(rd, wr);
        }

        public void close() {
            try {
                rd.close();
            } catch (Exception ignored) {
            }
            try {
                wr.close();
            } catch (Exception ignored) {
            }
        }

        public String readToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public void writeLine(String line) {
            wr.println(line);
        }
    }

    public static void enforce(boolean condition) {
        if (!condition) {
            throw new AssertionError();
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        new Thread(new B()).start();
    }

    private void solve() throws IOException {
        ProblemData data = ProblemData.files("b.in", "b.out");
        int tn = Integer.parseInt(data.readToken());
        for (int ti = 0; ti < tn; ++ti) {
            int[] result = solveTest(data);
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < result.length; ++i) {
                sb.append(" ");
                sb.append(result[i]);
            }
            data.writeLine(String.format("Case #%d:%s", ti + 1, sb.toString()));
        }
        data.close();
    }

    private int[] solveTest(ProblemData data) throws IOException {
        int n = Integer.parseInt(data.readToken());
        int l = 2 * n - 1;
        int[][] a = new int[l][n];
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < n; ++j) {
                a[i][j] = Integer.parseInt(data.readToken());
            }
        }
        int[][] x = new int[n][2];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < 2; ++j) {
                x[i][j] = -1;
            }
        }
        int[] d = new int[l];
        Arrays.fill(d, -1);
        for(int i = 0; i < n; ++i) {
            int mv = Integer.MAX_VALUE;
            for(int j = 0; j < l; ++j) {
                if(d[j] != -1) {
                    continue;
                }
                mv = Math.min(mv, a[j][i]);
            }
            for(int j = 0; j < l; ++j) {
                if(d[j] != -1) {
                    continue;
                }
                if(a[j][i] == mv) {
                    d[j] = i;
                    if(x[i][0] == -1) {
                        x[i][0] = j;
                    } else {
                        enforce(x[i][1] == -1);
                        x[i][1] = j;
                    }
                }
            }
        }
        int[] r = new int[n];
        int k = -1;
        int[] b = null;
        Arrays.fill(r, -1);
        for(int i = 0; i < n; ++i) {
            if(x[i][1] == -1) {
                k = i;
                b = a[x[i][0]];
                r[i] = b[i];
                break;
            }
        }
        enforce(k != -1);
        enforce(b != null);
        for(int i = 0; i < n; ++i) {
            if(i == k) {
                continue;
            }
            int v0 = a[x[i][0]][k];
            int v1 = a[x[i][1]][k];
            if(v0 == b[i]) {
                r[i] = v1;
            } else {
                r[i] = v0;
            }
        }
        return r;
    }
}
