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
        sc = new Scanner(new File("C:\\Projects\\B-large.in"));
        File file = new File("C:\\Projects\\out.txt");
        wr = new PrintWriter(file);
//        wr = new PrintWriter(System.out);
    }
    
    private void solve() {
        int T = sc.nextInt();

        for (int i = 0; i < T; ++i) {
            set = new HashSet<String>();

            wr.print(String.format("Case #%d: ", (i + 1)));

            int n = sc.nextInt();
            int s = sc.nextInt();
            int p = sc.nextInt();

            int r[] = new int[n];
            for (int j = 0; j < r.length; ++j)
                r[j] = sc.nextInt();
            
            int res = 0;
            
            for (int j = 0; j < n; ++j) {
                int e = r[j] / 3;
                int k = r[j] - e * 3;
                
                if (e >= p) {
                    ++res;
                } else if (k >= 1 && e + 1 >= p) {
                    ++res;
                } else if (k == 0 && e + 1 >= p && s > 0 && e > 0) {
                    ++res;
                    --s;
                }
                else if (k == 2 && e + 2 >= p && s > 0) {
                    ++res;
                    --s;
                }

            }
            wr.println(res);
        }

        wr.flush();
    }

    public static void main(String args[]) throws Exception {
        Main main = new Main();
        
        main.prepare();
        
        main.solve();
    }
}
