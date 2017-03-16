import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Csmall {
    FastScanner in;
    PrintWriter out;

    public void solve(int testNo) throws IOException {
        System.out.println("Solving case " + testNo);
        
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        ArrayList<Integer> a1 = new ArrayList<Integer>();
        ArrayList<Integer> a2 = new ArrayList<Integer>();
        
        boolean found = false;
        search:
        for (int x = 0; x < (1 << n); x++) {
            for (int y = x; y > 0; y = (y - 1) & x) {
                int t1 = 0;
                int t2 = 0;
                for (int i = 0; i < n; i++) {
                    if (((1 << i) & x) != 0 && ((1 << i) & y) == 0) {
                        t1 += a[i];
                    }
                    if (((1 << i) & y) != 0) {
                        t2 += a[i];
                    }
                }
                
                if (t1 == t2) {
                    found = true;
                    for (int i = 0; i < n; i++) {
                        if (((1 << i) & x) != 0 && ((1 << i) & y) == 0) {
                            a1.add(a[i]);
                        }
                        if (((1 << i) & y) != 0) {
                            a2.add(a[i]);
                        }
                    }
                    break search;
                }
            }

        }

        out.println("Case #" + testNo + ":");
        System.out.println("Case #" + testNo + ":");
        if (found) {
            for (int i = 0; i < a1.size(); i++) {
                out.print(a1.get(i));
                System.out.print(a1.get(i));
                if (i < a1.size() - 1) {
                    out.print(" ");
                    System.out.print(" ");
                }
            }
            out.println();
            System.out.println();
            for (int i = 0; i < a2.size(); i++) {
                out.print(a2.get(i));
                System.out.print(a2.get(i));
                if (i < a2.size() - 1) {
                    out.print(" ");
                    System.out.print(" ");
                }
            }
            out.println();
            System.out.println();
        } else {
            out.println("Impossible");
            System.out.println("Impossible");
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-attempt0.in"));
            out = new PrintWriter(new File("C-small-attempt0.out"));

            int testNo = in.nextInt();
            for (int test = 0; test < testNo; test++) {
                solve(test + 1);
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new Csmall().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}