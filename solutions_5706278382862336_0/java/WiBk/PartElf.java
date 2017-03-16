import java.text.Normalizer;
import java.util.*;
import java.io.*;

public class PartElf {
    FastScanner in;
    PrintWriter out;

    public long GCD(long a, long b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    public class Fraction implements Comparable<Fraction> {
        public Long p, q;

        public Fraction(long p, long q) {
            this.p = p;
            this.q = q;
            normalize();
        }

        public Fraction(Fraction a, Fraction b) {
            this.q = a.q * b.q * 2;
            this.p = a.p * b.q + b.p * a.q;
            normalize();
        }

        private void normalize() {
            long k = GCD(p, q);
            p /= k;
            q /= k;
        }

        public int compareTo(Fraction other) {
            if (p * other.q - other.p * q > 0) {
                return 1;
            }

            if (p * other.q - other.p * q < 0) {
                return -1;
            }

            return 0;
        }
    }

    long[] power2 = new long[41];

    public int check(long p) {
        for (int i = 0; i <= 40; i++) {
            if (power2[i] == p) {
                return i;
            }
        }
        return -1;
    }

    public void solve() throws IOException {
        int t = in.nextInt();

        power2[0] = 1;
        for (int i = 1; i <= 40; i++) {
            power2[i] = power2[i - 1] * 2;
        }

        for (int test = 1; test <= t; test++) {
            String s = in.next();
            String[] str = s.split("/");
            long p = Long.parseLong(str[0]);
            long q = Long.parseLong(str[1]);
            out.print("Case #" + test + ": ");
            Fraction f = new Fraction(p, q);
            int k = check(f.q);
            if (k != -1) {
                p = f.p;
                q = f.q;
                int ans = 0;
                while (p < q) {
                    ans++;
                    q /= 2;
                }
                out.println(ans);
            } else {
                out.println("impossible");
            }
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("partelf.in"));
            out = new PrintWriter(new File("partelf.out"));

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
        new PartElf().run();
    }
}