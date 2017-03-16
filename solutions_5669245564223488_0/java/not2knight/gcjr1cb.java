import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class gcjr1cb {
    public static void main(String[] args) {
        try {
            new gcjr1cb().solve();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.US);

//        String fn = "E:\\isinev\\develop\\contests\\training\\spoj\\work\\b.in";
        String fn = "E:\\isinev\\download\\B-small-attempt0.in";

        File fin = new File(fn + ".res");
        PrintWriter pw = new PrintWriter(fin);
        Scanner sc = new Scanner(new File(fn));

        int tc = sc.nextInt();

        for (int tci = 1; tci <= tc; tci++) {
            int n = sc.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = sc.next();
            }
            boolean[] u = new boolean[n];
            StringBuilder sb = new StringBuilder();
            int res = go(n, n, s, u, sb);

            pw.format("Case #%d: %d%n", tci, res);
            pw.flush();
        }
        pw.close();
    }

    int go(int n, int r, String[] s, boolean[] u, StringBuilder sb) {
        if (r == 0) {
//            System.out.println(sb);
            return check(sb.toString().toCharArray());
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!u[i]) {
                u[i] = true;
                sb.append(s[i]);
                res += go(n, r - 1, s, u, sb);
                sb.setLength(sb.length() - s[i].length());
                u[i] = false;
            }
        }
        return res;
    }

    private int check(char[] s) {
        boolean[] uc = new boolean[26];
        for (int i = 0; i < s.length; i++) {
            if (i > 0 && s[i - 1] == s[i]) {
                continue;
            }
            if (uc[s[i] - 'a']) {
                return 0;
            }
            uc[s[i] - 'a'] = true;
        }
        return 1;
    }
}