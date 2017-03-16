import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;


    public void solveTest() throws IOException {
        char[] s = in.next().toCharArray();
        Deque<Character> d = new ArrayDeque<>();
        for (int i = 0; i < s.length; i++) {
            if (i == 0) {
                d.addLast(s[i]);
            } else {
                if (d.peekFirst() <= s[i]) {
                    d.addFirst(s[i]);
                } else {
                    d.addLast(s[i]);
                }
            }
        }
        d.stream().forEach(i -> out.print(i));
        out.println();
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            System.out.println("test " + test);
            long start = System.currentTimeMillis();
            solveTest();
            System.out.println("passed in " + (System.currentTimeMillis() - start) + " ms");
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-small-attempt0.in"));
            out = new PrintWriter(new File("A-small-attempt0.out"));
            Locale.setDefault(Locale.US);

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
        new A().run();
    }
}