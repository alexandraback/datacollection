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
    private String fileName = "C-small-1-attempt1";
    private FastScanner in;
    private PrintWriter out;

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int m = in.nextInt();
            if (m == 1) {
                int start = in.nextInt();
                int kol = in.nextInt();
                int speed = in.nextInt();
                out.println(String.format("Case #%d: %d", i + 1, 0));
            } else {
                int start1 = in.nextInt();
                int kol = in.nextInt();
                int speed1 = in.nextInt();
                int start2 = in.nextInt();
                kol = in.nextInt();
                int speed2 = in.nextInt();
                double t1 = ((360 - start1) * speed1) / 360.0;
                double t2 = ((360 - start2) * speed2) / 360.0;
                if (start1 < start2)
                    if (t1 > t2 + speed2)
                        out.println(String.format("Case #%d: %d", i + 1, 1));
                    else
                        out.println(String.format("Case #%d: %d", i + 1, 0));
                else if (start1 > start2)
                    if (t2 > t1 + speed1)
                        out.println(String.format("Case #%d: %d", i + 1, 1));
                    else
                        out.println(String.format("Case #%d: %d", i + 1, 0));
                else
                    if (t1 < t2 + speed2  && t2 < t1 + speed1)
                        out.println(String.format("Case #%d: %d", i + 1, 0));
                    else
                        out.println(String.format("Case #%d: %d", i + 1, 1));
            }
        }
    }

    /*
    *
    * */

    /*
    *nt a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            if (a < b) {
                int temp = a;
                a = b;
                b = temp;
            }
            int ans = -1;
            int dec = a - b;
            for (int j = Math.min(99, b); j > 0; j--) {
                if (j * k == Math.min(99, j + dec)) {
                    ans = b - j;
                    break;
                }
            }
            if (Math.min(a, 99) == Math.min(b, 99) && k == 1) {
                ans = 0;
            }
            System.out.println(ans);
    * */

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
