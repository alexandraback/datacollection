import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;

/**
 * Created with IntelliJ IDEA.
 * User: kris13
 * Date: 27.04.14
 * Time: 20:35
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    private boolean fileFlag = true;
    private String fileName = "C-small-attempt0";
    private FastScanner in;
    private PrintWriter out;

    private int[][] multiply = new int[][]{
            {1, 2, 3, 4},
            {2, -1, 4, -3},
            {3, -4, -1, 2},
            {4, 3, -2, -1},
    };

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int l = in.nextInt();
            int x = in.nextInt();
            String s = in.nextLine();
            StringBuilder stringBuilder = new StringBuilder(s);
            for (int j = 0; j < x - 1; j++) {
                stringBuilder.append(s);
            }
            s = stringBuilder.toString();
            int[][] d = new int[s.length()][s.length()];
            for (int j = 0; j < s.length(); j++) {
                d[j][j] = getSymb(s.charAt(j));
            }
            for (int j = 0; j < s.length(); j++) {
                for (int k = j + 1; k < s.length(); k++) {
                    d[j][k] = getMultiply(d[j][k - 1], getSymb(s.charAt(k)));
                }
            }
            String ans = "NO";
            for (int j = 1; j < s.length() - 1; j++) {
                for (int k = j + 1; k < s.length(); k++) {
                    if (d[0][j - 1] == 2 && d[j][k - 1] == 3 && d[k][s.length() - 1] == 4)
                        ans = "YES";
                }
            }
            //System.out.println(String.format("Case #%d: %s", i + 1, ans));
            out.println(String.format("Case #%d: %s", i + 1, ans));
        }
    }

    private int getSymb(char c) {
        return c == 'i' ? 2 : c == 'j' ? 3 : c == 'k' ? 4 : 1;
    }

    private int getMultiply(int q, int w) {
        boolean sign = false;
        if (q < 0){
            sign = true;
            q = -q;
        }
        if (w < 0) {
            sign = !sign;
            w = -w;
        }
        int e = multiply[q - 1][w - 1];
        if (sign) {
            e = -e;
        }
        return e;
    }

    private class Pair<Q,W> {
        Q first;
        W second;

        public Pair(Q i, W i1) {
            second = i1;
            first = i;
        }

        public Q getFirst(){
            return first;
        }

        public W getSecond(){
            return second;
        }
    }

    private class Triple<Q, W, E> {
        Q first;
        W second;
        E third;

        public Triple(Q f, W s, E t){
            first = f;
            second = s;
            third = t;
        }
    }

    public void run() {
        try {
            if (fileFlag) {
                in = new FastScanner(new File(fileName  + ".in"));
                out = new PrintWriter(new File(fileName  + ".out"));
            } else {
                in = new FastScanner(System.in);//(new File(fileName  + ".in"));
                out = new PrintWriter(System.out);//(new File(fileName  + ".out"));
            }
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;



        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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

        String nextLine() {
            if (st == null || !st.hasMoreTokens()){
                try {
                    return br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong(){
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}
