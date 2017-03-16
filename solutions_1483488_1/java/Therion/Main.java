import java.io.File;
import java.io.PrintWriter;

import java.util.HashSet;
import java.util.Scanner;

/**
 * User: Sasha
 * Date: 09.04.12
 * Time: 19:13
 */
public class Main {
    private Scanner sc;
    private PrintWriter wr;
    private HashSet<String> set;

    private void prepare() throws Exception {
        sc = new Scanner(new File("C:\\Projects\\C-large.in"));
        File file = new File("C:\\Projects\\out.txt");
        wr = new PrintWriter(file);
//        wr = new PrintWriter(System.out);
    }
    
    private void solve() {
        int n = sc.nextInt();

        for (int i = 0; i < n; ++i) {
            set = new HashSet<String>();

            wr.print(String.format("Case #%d: ", (i + 1)));

            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();

            int res = 0;
            for (int j = a; j < b; ++j) {
                res += cnt(j, a, b);
            }
            wr.println(res);
        }

        wr.flush();
    }

    private int cnt(int c, int left, int right) {
        int res = 0;
        String s = "" + c;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s.charAt(i + 1) == '0')
                continue;

            String t = s.substring(i + 1) + s.substring(0, i + 1);

            int d = Integer.parseInt(t);
            if (left <= d && d <= right && c < d && s.length() == ("" + d).length()) {
                if (set.contains(s + t)) continue;
                set.add(s + t);
                ++res;
            }
        }
        return res;
    }

    public static void main(String args[]) throws Exception {
        Main main = new Main();
        
        main.prepare();
        
        main.solve();
    }
}
