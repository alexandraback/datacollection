import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author shu_mj @ http://shu-mj.com
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        Scanner in;
        PrintWriter out;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
            run();
        }

        void run() {
            int t = in.nextInt();
            for (int i = 1; i <= t; i++) {
                out.printf("Case #%d: ", i);
                solve();
            }
        }

        private void solve() {
            String s = in.next();
            LinkedList<Character> res = new LinkedList<>();
            for (char c : s.toCharArray()) {
                if (res.size() == 0 || res.getFirst() > c) {
                    res.addLast(c);
                } else {
                    res.addFirst(c);
                }
            }
            for (char c : res) out.print(c);
            out.println();
        }

    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            eat("");
        }

        private void eat(String s) {
            st = new StringTokenizer(s);
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public boolean hasNext() {
            while (!st.hasMoreTokens()) {
                String s = nextLine();
                if (s == null)
                    return false;
                eat(s);
            }
            return true;
        }

        public String next() {
            hasNext();
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

