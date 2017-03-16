import java.io.*;
import java.math.*;
import java.util.*;

public class CodeJam {

    void runCase(int caseNum) throws IOException {
        int n = nextInt();
        int s = nextInt();
        int p = nextInt();
        int ret = 0;
        Map<Integer, Boolean> nonSurprise = new HashMap<Integer, Boolean>();
        Map<Integer, Boolean> surprise = new HashMap<Integer, Boolean>();

        for (int i = 0; i <= 10; ++i) {
            for (int j = i; j <= Math.min(10, i + 2); ++j) {
                for (int k = Math.max(j, p); k <= Math.min(10, i + 2); ++k) {
                    int sum = i + j + k;
                    if (k - i == 2)
                        surprise.put(sum, true);
                    else
                        nonSurprise.put(sum, true);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int t = nextInt();
            if (nonSurprise.containsKey(t)) {
                ++ret;
            } else if (s > 0 && surprise.containsKey(t)){
                ++ret;
                --s;
            }
        }

        System.out.print(new StringBuilder().append("Case #").append(caseNum).append(": ").append(ret).toString());

        System.out.println();
    }


    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream(new File(
                "input.txt")));
        PrintStream ps = new PrintStream(new File(
                "output.txt"));
        System.setOut(ps);
        new CodeJam().runit();
        ps.flush();
        ps.close();
        return;
    }

    BufferedReader in;
    private StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }



    void runit() throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new OutputStreamWriter(System.out));
        st = new StringTokenizer("");

        int N = nextInt();
        for (int i = 0; i < N; i++) {
            runCase(i + 1);
        }

        out.flush();
    }

}
