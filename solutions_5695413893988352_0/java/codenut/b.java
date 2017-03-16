import java.util.*;
import java.io.*;

public class b {
    int toInt(char[] c) {
        int r = 0;
        for(int i = 0; i < c.length; ++i) {
            r = (r * 10) + (c[i] - '0'); 
        }
        return r;
    }
    List<String> doit(char[] c, int k) {
        if(k >= c.length) {
            return Arrays.asList(new String(c));
        }
        List<String> r = new ArrayList<>();
        if(c[k] == '?') {
            char[] d = c.clone();
            for(int i = 0; i < 10; ++i) {
                d[k] = (char) (i + '0'); 
                r.addAll(doit(d, k + 1));
            } 
        } else {
            r.addAll(doit(c, k + 1));
        }
        return r;
    }
    private void solve() throws IOException {
        int T = nextInt();

        for(int t = 1; t <= T; ++t) {
            String coders = next();
            String jammers = next();

            List<String> a = doit(coders.toCharArray(), 0);
            List<String> b = doit(jammers.toCharArray(), 0);

            Collections.sort(a);
            Collections.sort(b);

            int r = 10000;
            String ra = "";
            String rb = "";

            for(String s : a) {
                for(String p : b) {
                    int i = toInt(s.toCharArray());
                    int j = toInt(p.toCharArray());
                    if(Math.abs(i - j) < r) {
                        r = Math.abs(i - j);    
                        ra = s;
                        rb = p;
                    } 
                } 
            }

            System.out.println(String.format("Case #%d: %s %s", t, ra, rb));
        }
    }

    static void debug(Object...o) {
        System.err.println(Arrays.deepToString(o));
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String s = br.readLine();
            if(s != null) {
                st = new StringTokenizer(s);
            }
        }
        if(st.hasMoreTokens()) {
            return st.nextToken();
        } else {
            return null;
        }
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

    String nextLine(){
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    private void run(String filename) throws IOException {
        br = new BufferedReader(new FileReader(filename));
        //br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        //out = new PrintWriter(filename + ".out");
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        String filename = args[0].endsWith(".in") ? args[0] : "b.in";

        new b().run(filename);
    }
}
