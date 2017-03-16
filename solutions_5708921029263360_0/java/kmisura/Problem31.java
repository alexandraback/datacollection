import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Problem31 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("data/C-small-attempt1.out"));

        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {

            int j = sc.nextInt();
            int p = sc.nextInt();
            int s = sc.nextInt();

            int k = sc.nextInt();

            // int j_ = 1;
            // int p_ = 1;
            // int s_ = 1;
            int[][] js = new int[11][11];
            int[][] ps = new int[11][11];
            for (int i = 0; i < 11; i++) {
                for (int h = 0; h < 11; h++) {
                    js[i][h] = k;
                    ps[i][h] = k;
                }
            }
            List<String> ret = new ArrayList<String>();
            for (int k_ = 1; k_ <= k; k_++) {
                for (int j_ = 1; j_ <= j; j_++) {
                    for (int p_ = 1; p_ <= p; p_++) {
                        int best = 1;
                        for (int s_ = 1; s_ <= s; s_++) {
                            if (Math.min(js[j_][s_], ps[p_][s_]) > Math.min(js[j_][best], ps[p_][best])) {
                                best = s_;
                            }
                        }
                        if (Math.min(js[j_][best], ps[p_][best]) > 0) {
                            js[j_][best]--;
                            ps[p_][best]--;
                            String x = "" + j_ + " " + p_ + " " + best;
                            if (ret.size() == 0 || !ret.get(ret.size() - 1).equals(x)) {
                                ret.add(x);
                            }
                        }
                    }
                }
            }

            pw.println("Case #" + tc + ": " + ret.size());
            for (String x : ret) {
                pw.println(x);
            }
        }

        pw.close();
    }

}
