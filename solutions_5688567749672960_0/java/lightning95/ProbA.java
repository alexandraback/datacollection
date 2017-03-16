import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbA {
    RW rw;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new ProbA().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    String reverse(String s) {
        String res = "";
        for (char c : s.toCharArray()) {
            res = c + res;
        }
        int i = 0;
        for (char c : res.toCharArray()) {
            if (c == '0') {
                ++i;
            } else {
                break;
            }
        }
        return res.substring(i);
    }

    private void solve() {
        int t_num = rw.nextInt();

        for (int t_id = 0; t_id < t_num; ++t_id) {
            int n = rw.nextInt();
            int[] ans = new int[n + 1];
            Arrays.fill(ans, 1_000_000);
            ans[1] = 1;
            for (int i = 1; i < n; ++i){
                int next = Integer.parseInt(reverse(String.valueOf(i)));
                if (next > i && next <= n) {
                    ans[next] = Math.min(ans[next], ans[i] + 1);
                }
                ans[i + 1] = Math.min(ans[i + 1], ans[i] + 1);
            }
            rw.println("Case #" + (t_id + 1) + ": " + ans[n]);
        }
    }
}

