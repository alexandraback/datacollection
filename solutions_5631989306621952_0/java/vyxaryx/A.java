import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A implements Runnable {
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
        new Thread(new A()).start();
    }

    private void solve() throws IOException {
        ProblemData data = ProblemData.files("a.in", "a.out");
        int tn = Integer.parseInt(data.readToken());
        for (int ti = 0; ti < tn; ++ti) {
            String result = solveTest(data);
            data.writeLine(String.format("Case #%d: %s", ti + 1, result));
        }
        data.close();
    }

    private String solveTest(ProblemData data) throws IOException {
        String s = data.readToken();
        String best = s.substring(0, 1);
        for(int i = 1; i < s.length(); ++i) {
            String s1 = best + s.substring(i, i + 1);
            String s2 = s.substring(i, i + 1) + best;
            if(s1.compareTo(s2) >= 0) {
                best = s1;
            } else {
                best = s2;
            }
        }
        return best;
    }
}
