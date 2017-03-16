import com.sun.org.apache.xalan.internal.xsltc.compiler.sym;

import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        Locale.setDefault(Locale.US);

        int t = in.nextInt();
        for (int testcase = 1; testcase <= t; testcase++) {
            int k = in.nextInt();
            int l = in.nextInt();
            int s = in.nextInt();
            String key = in.next();
            String word = in.next();
            out.printf("Case #%d: %f\n", testcase, solve(k, l, s, key, word));
        }
    }

    private double solve(int k, int l, int s, String keyboard, String word) {
        word += "#";

        int[] suff = new int[l + 1];
        int curr = 0;
        for (int i = 1; i < word.length(); i++) {
            while (curr > 0 && word.charAt(i) != word.charAt(curr)) {
                curr = suff[curr - 1];
            }
            if (word.charAt(i) == word.charAt(curr)) {
                curr++;
            }
            suff[i] = curr;
        }

        Map<Character, Integer> keys = new HashMap<>();
        for (Character ch : keyboard.toCharArray()) {
            Integer cnt = keys.get(ch);
            keys.put(ch, cnt == null ? 1 : cnt + 1);
        }

        char[] symb = toCharArray(keys);
        int[][] trans = new int[l + 1][symb.length];

        for (int i = 0; i <= l; i++) {
            for (int j = 0; j < symb.length; j++) {
                int ch = symb[j];
                if (i > 0 && ch != word.charAt(i)) {
                    trans[i][j] = trans[suff[i - 1]][j];
                } else {
                    trans[i][j] = i;
                    if (ch == word.charAt(i)) {
                        trans[i][j]++;
                    }
                }
            }
        }


        int[][] max = new int[s + 1][l + 1];
        for (int[] x : max) {
            Arrays.fill(x, -1000);
        }

        max[0][0] = 0;

        double[][] prob = new double[s + 1][l + 1];
        prob[0][0] = 1;

        double exp = 0;
        double total = 0;

        for (int i = 0; i < s; i++) {
            for (int st = 0; st <= l; st++) {
                for (int j = 0; j < symb.length; j++) {
                    char ch = symb[j];
                    int nx = trans[st][j];
                    int prem = (nx == l) ? 1 : 0;
                    max[i + 1][nx] = Math.max(max[i + 1][nx], max[i][st] + prem);
                    double p = prob[i][st] * keys.get(ch) / k;
                    prob[i + 1][nx] += p;

                    if (nx == l) {
                        total = Math.max(total, max[i + 1][nx]);
                        exp += p;
                    }
                }
            }
        }

        return total - exp;
    }

    private char[] toCharArray(Map<Character, Integer> keys) {
        char[] symb = new char[keys.size()];
        int idx = 0;
        for (Character ch : keys.keySet()) {
            symb[idx++] = ch;
        }
        return symb;
    }


    public void run() {
        try {
            in = new FastScanner(new FileInputStream("b-small-attempt0.in"));
            out = new PrintWriter(new File("b-small.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }


        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }
}