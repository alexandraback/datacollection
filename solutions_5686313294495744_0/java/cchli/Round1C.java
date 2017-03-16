package Round1;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * @auther chao
 * @date 16/4/30
 */
public class Round1C {
    static String[][] a;
    static int ans;
    static boolean[] real;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/C-small-attempt2.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        FileWriter out = new FileWriter("/Users/chao/Desktop/C-small-attempt2.txt");
        //PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        String s = in.readLine();
        String[] ss;
        int m = Integer.parseInt(s);
        for (int cases = 1; cases <= m; cases++) {
            s = in.readLine();
            int n = Integer.parseInt(s);
            a = new String[n][2];
            real = new boolean[n];
            for (int i = 0; i < n; i++) {
                s = in.readLine();
                ss = s.split(" ");
                a[i] = ss;
            }
            ans = 0;
            dfs(0, n);
            out.write("Case #"+cases+": "+ans+"\n");
        }
        out.flush();
        out.close();
        in.close();
    }
    private static void dfs(int k, int n) {
        if (k == n) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                boolean f1 = false, f2 = false;
                if (!real[i]) {
                    for (int j = 0; j < n; j++) {
                        if (j!=i &&real[j] && a[i][0].equals(a[j][0])) {
                            f1 = true;
                        }
                    }
                    for (int j = 0; j < n; j++) {
                        if (j!=i && real[j] && a[i][1].equals(a[j][1])) {
                            f2 = true;
                        }
                    }
                    if (!f1 || !f2) return;
                    cnt++;
                }
            }
            if (cnt > ans) ans = cnt;
            return;
        }
        real[k] = false;
        dfs(k+1, n);
        real[k] = true;
        dfs(k+1, n);
    }
}
