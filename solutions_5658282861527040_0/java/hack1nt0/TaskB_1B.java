package contest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by DaiYang on 2014/4/13.
 */
public class TaskB_1B {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileInputStream("TaskB_1B.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("TaskB_1B.out"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        for (int Case = 1; Case <= T; ++Case) {
            out.print("Case #" + Case + ": ");
            int A = in.nextInt() - 1;
            int B = in.nextInt() - 1;
            int K = in.nextInt() - 1;
            int maxB = 30;
            long[][][][] dp = new long[maxB + 1][2][2][2];
            for (int i = 0; i <= maxB; ++i)
                for (int as = 0; as < 2; ++as)
                    for (int bs = 0; bs < 2; ++bs)
                        for (int ks = 0; ks < 2; ++ks) {
                            long res = 0;
                            /*
                            if (as == 0 && bs == 0 && ks == 0)
                                res = (long)Math.pow(2, i + 1) * 2L;
                            else {
                            */

                            //0 0
                            {
                                int nas = as == 1 && (A >> i & 1) == 0 ? 1 : 0;
                                int nbs = bs == 1 && (B >> i & 1) == 0 ? 1 : 0;
                                int nks = ks == 1 && (K >> i & 1) == 0 ? 1 : 0;
                                res += i > 0 ? dp[i - 1][nas][nbs][nks] : 1;
                            }
                            //0 1
                            boolean bs1 = false;
                            if (bs == 0 || (B >> i & 1) == 1) {
                                bs1 = true;
                                int nas = as == 1 && (A >> i & 1) == 0 ? 1 : 0;
                                int nbs = bs;
                                int nks = ks == 1 && (K >> i & 1) == 0 ? 1 : 0;
                                res += i > 0 ? dp[i - 1][nas][nbs][nks] : 1;
                            }
                            //1 0
                            boolean as1 = false;
                            if (as == 0 || (A >> i & 1) == 1) {
                                as1 = true;
                                int nas = as;
                                int nbs = bs == 1 && (B >> i & 1) == 0 ? 1 : 0;
                                int nks = ks == 1 && (K >> i & 1) == 0 ? 1 : 0;
                                res += i > 0 ? dp[i - 1][nas][nbs][nks] : 1;
                            }
                            //1 1
                            if (as1 && bs1 && (ks == 0 || (K >> i & 1) == 1)) {
                                int nas = as;
                                int nbs = bs;
                                int nks = ks;
                                res += i > 0 ? dp[i - 1][nas][nbs][nks] : 1;
                            }
                            dp[i][as][bs][ks] = res;
                        }
            out.println(dp[maxB][1][1][1]);
        }
        out.close();
    }
}
