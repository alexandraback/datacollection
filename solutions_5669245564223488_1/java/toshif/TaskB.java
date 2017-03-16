package fuku.round1C;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author fuku
 */
public class TaskB {
    public static void main(String[] args) throws FileNotFoundException {
        InputStream inputStream = TaskB.class.getResourceAsStream("B-large.in");
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(new FileOutputStream("./out.txt"));

        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.println("------------------");
            System.out.println("test " + (i+1));
            SolB solver = new SolB();
            String ans = solver.solve(i, in, out);
            out.println("Case #" + (i+1) + ": " + ans);
            System.out.println("Case #" + (i+1) + ": " + ans);
        }
        out.close();
    }
}

class SolB {

    final long MOD = 1_000_000_007;

    int[][] g;

    int M;

    public String solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt(); in.nextLine();
        String line = in.nextLine();
        String[] ss = line.split(" ");
        System.out.println("ss = " + Arrays.toString(ss));

        long base = 1;

        boolean[] same = new boolean[N];
        char[] sameChar = new char[N];
        // check all same
        for (int i = 0; i < N; i++) {
            String s = ss[i];
            for (int j = 0; j < s.length(); j++) {
                char c1 = s.charAt(j);
                boolean adj = true;
                for (int k = j + 1; k < s.length(); k++) {
                    char c2 = s.charAt(k);
                    if (c1 == c2) {
                        if (!adj) return "0";
                    } else {
                        adj = false;
                    }
                }

                if (adj && j == 0) {
                    same[i] = true;
                    sameChar[i] = c1;
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < s.length(); j++) {
                if (j == 0 || s.charAt(j) != s.charAt(j -1)) sb.append(s.charAt(j));
            }
            ss[i] = sb.toString();
        }

        System.out.println("same = " + Arrays.toString(same));
        System.out.println("sameChar = " + Arrays.toString(sameChar));
        System.out.println("ss = " + Arrays.toString(ss));

        boolean[] merged = new boolean[N];
        List<String> m = new ArrayList<>();
        for (int i = 'a'; i <= 'z'; i++) {
            char c = (char)i;

            int cnt = -1;
            for (int j = 0; j < N; j++) {
                if(sameChar[j] == c) {
                    cnt++;
                    merged[j] = true;
                }
            }

            long f = 1;
            for (int j = cnt+1; j > 1; j--) {
                f *= j;
                f %= MOD;
            }

            base *= f;
            base %= MOD;

            if (cnt >= 0) {
                // check can merge with last
                boolean canMerge = false;
                for (int j = 0; j < N; j++) {
                    if (merged[j]) continue;

                    if (ss[j].contains("" + c)){
                        canMerge = true;
                    }
                }

                if (!canMerge)
                    m.add("" + c);
            }


        }

        System.out.println("base = " + base);
        System.out.println("m1 = " + m);

        int sameSize = m.size();
        for (int i = 0; i < N; i++) {
            if (!merged[i]) m.add(ss[i]);
        }
        M = m.size();
        boolean[] same2 = new boolean[M];
        for (int i = 0; i < sameSize; i++) {
            same2[i] = true;
        }

        System.out.println("m = " + m);

        g = new int[M][M];
        for (int i = 0; i < M; i++) {
            String s1 = m.get(i);
            char lastChar = s1.charAt(s1.length() - 1);
            for (int j = 0; j < M; j++) {
                if (i == j) continue;

                String s2 = m.get(j);
                for (int k = 0; k < s2.length(); k++) {
                    char ck = s2.charAt(k);
                    if (ck == lastChar && k != 0) return "0";

                    if (ck == lastChar) {
                        g[i][j] = 1;
                    }
                }
            }

            for (int j = 0; j < s1.length(); j++) {
                char c1 = s1.charAt(j);
                for (int k = 0; k < M; k++) {
                    if (i == k) continue;

                    String s2 = m.get(k);
                    for (int l = 0; l < s2.length(); l++) {
                        char c2 = s2.charAt(l);

                        if (c1 == c2) {
                            if (!((j == s1.length()-1 && l == 0) || (j == 0 && l == s2.length()-1))) {
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < M; i++) {
            int dup = 0;
            for (int j = 0; j < M; j++) {
                if (g[i][j] == 1) dup++;
            }
            if (dup > 1) return "0";
        }

        int cnt = 0;
        used = new boolean[M];
        for (int i = 0; i < M; i++) {
            if (used[i]) continue;

            boolean root = true;
            for (int j = 0; j < M; j++) {
                if ( g[j][i] == 1 ) root = false;
            }

            if (!root) continue;
            dfs(i);

            System.out.println("i is root = " + i);

            cnt++;
        }

        for (int i = 0; i < M; i++) {
            if (!used[i]) return "0";
        }

        long ret = base;
        for (int i = cnt; i > 1; i--) {
            ret *= i;
            ret %= MOD;
        }

        String ans = "" + ret;
        return ans;
    }

    boolean[] used;

    int dfs(int i) {
        if (used[i]) return -1;

        used[i] = true;

        for (int j = 0; j < M; j++) {
            if (g[i][j] == 1)  {
                dfs(j);
            }
        }

        return 0;
    }

    // returns x^y modulo MOD. loops only log2(y) times.
    long modPow(int x, int y) {
        long res = 1, a = x;
        while (y > 0) {
            if ((y & 1) > 0) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            y >>= 1;
        }
        return res % MOD;
    }
}
