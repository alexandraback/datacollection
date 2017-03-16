import java.io.*;
import java.util.StringTokenizer;

public class ProblemCLarge {

    public static void main(String[] args) throws Exception {
        new ProblemCLarge();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-large";

    public ProblemCLarge() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    int[] d, n, w, e, s, delta_d, delta_p, delta_s;
    int N;
    Node head;

    private void solve() throws Exception {

        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            out.print("Case #" + ii + ": ");
            N = nextInt();
            d = new int[N];
            n = new int[N];
            w = new int[N];
            e = new int[N];
            s = new int[N];
            delta_d = new int[N];
            delta_p = new int[N];
            delta_s = new int[N];
            for (int i = 0; i < N; ++i) {
                d[i] = nextInt();
                n[i] = nextInt();
                w[i] = nextInt();
                e[i] = nextInt();
                s[i] = nextInt();
                delta_d[i] = nextInt();
                delta_p[i] = nextInt();
                delta_s[i] = nextInt();
            }
            head = new Node(-(1 << 5), (1 << 5) - 1, 0);
            int ans = 0;
            while (true) {
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] < min) {
                        min = d[i];
                    }
                }
                if (min == Integer.MAX_VALUE) {
                    break;
                }
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] == min) {
                        if (head.getMin(w[i], e[i] - 1) < s[i]) {
                            ans++;
                        }
                    }
                }
                for (int i = 0; i < N; ++i) {
                    if (n[i] > 0 && d[i] == min) {
                        head.set(w[i], e[i] - 1, s[i]);
                        d[i] += delta_d[i];
                        n[i]--;
                        w[i] += delta_p[i];
                        e[i] += delta_p[i];
                        s[i] += delta_s[i];
                    }
                }
            }
            out.println(ans);

        }
    }

    class Node {
        int vl, vr;
        int value;
        Node left = null, right = null;
        boolean toPush = true;

        Node(int vl, int vr, int value) {
            this.vl = vl;
            this.vr = vr;
            this.value = value;
        }

        void push() {
            toPush = false;
            if (left == null) {
                int m = (int)Math.floor((vl + vr) / 2d);
                left = new Node(vl, m, value);
                right = new Node(m + 1, vr, value);
            } else {
                if (left.value < value) {
                    left.value = value;
                    left.toPush = true;
                }
                if (right.value < value) {
                    right.value = value;
                    right.toPush = true;
                }
            }
        }

        int getMin(int l, int r) {
            if (r < vl || vr < l) {
                return Integer.MAX_VALUE;
            }
            if (l <= vl && vr <= r) {
                return value;
            }
            if (toPush) {
                push();
            }
            return Math.min(left.getMin(l, r), right.getMin(l, r));
        }

        void set(int l, int r, int s) {
            if (r < vl || vr < l) {
                return;
            }
            if (l <= vl && vr <= r) {
                if (value < s) {
                    value = s;
                    toPush = true;
                }
                return;
            }
            push();
            left.set(l, r, s);
            right.set(l, r, s);
        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            