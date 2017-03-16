import java.util.*;
import java.io.*;

public class TrainCars {
    FastScanner in;
    PrintWriter out;

    public int check(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i != 0 && s.charAt(i) != s.charAt(i - 1)) {
                cnt++;
            }
        }
        return cnt;
    }

    String[] sets;
    int n, m;
    int ans;

    public void search(int v, int cnt, String s, boolean[] was) {
        was[v] = true;
        cnt++;

        if (cnt == n) {
            if (check(s) == m - 1) {
                ans++;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!was[i]) {
                boolean[] temp = was.clone();
                search(i, cnt, s + sets[i], temp);
            }
        }
    }

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int test = 1; test <= t; test++) {
            n = in.nextInt();
            sets = new String[n];
            boolean[] chars = new boolean[26];
            for (int i = 0; i < n; i++) {
                String s = in.next();
                sets[i] = s;
                for (int j = 0; j < s.length(); j++) {
                    chars[s.charAt(j) - 'a'] = true;
                }
            }

            m = 0;
            for (int i = 0; i < 26; i++) {
                if (chars[i]) {
                    m++;
                }
            }

            out.print("Case #" + test + ": ");

            ans = 0;

            for (int i = 0; i < n; i++) {
                search(i, 0, sets[i], new boolean[n]);
            }

            out.println(ans);
            System.out.println(test);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("traincars.in"));
            out = new PrintWriter(new File("traincars.out"));

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
        new TrainCars().run();
    }
}