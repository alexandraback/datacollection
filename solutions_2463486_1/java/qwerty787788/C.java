import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);
    int MAX_N = (int) 1e7;
    ArrayList<Integer> all = new ArrayList<>();
    
    boolean isPalimdrome(long x) {
        String ss = Long.toString(x);
        for (int i = 0; i < ss.length() / 2; i++)
            if (ss.charAt(i) != ss.charAt(ss.length() - i - 1))
                return false;
        return true;
    }

    void init() {
        for (int x = 1; x <= MAX_N; x++) {
            if (!isPalimdrome(x))
                continue;
            long ss = x * 1L * x;
            if (isPalimdrome(ss)) {
                all.add(x);
            }
        }
        System.out.println("Precalc done.");
    }
    
    void solve() throws IOException {
        long A = in.nextLong();
        long B = in.nextLong();
        int res = 0;
        for (long x : all)
            if (x * x >= A && x * x <= B) {
                res++;
            }
        out.println(res);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            init();
            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}