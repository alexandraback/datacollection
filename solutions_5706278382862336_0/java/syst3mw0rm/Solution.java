import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * User: aamir
 * Date: 5/11/14
 * Time: 2:27 PM
 */
public class Solution {
    private static long gcd(long a, long b) {
        if (a < b) return gcd(b, a);
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("/tmp/output"));
        int T = in.nextInt();
        //in.next();
        long P, Q;
        long GENAGO = 1L << 40;

        for (int curTest = 1; curTest <= T; curTest++) {
            int ans = -1;
            P = in.nextLong();
            Q = in.nextLong();


            if (P <= Q) {
                long g = gcd(P, Q);
                P = P / g;
                Q = Q / g;
                if ((GENAGO * P) % Q == 0) {
                    long X = GENAGO * P / Q;
                    ans = 0;
                    while (X > 0) {
                        X /= 2;
                        ans++;
                    }
                    ans = ans - 1;
                    ans = 40 - ans;
                }

            }


            out.print("Case #" + curTest + ": ");
            if (ans == -1) {
                out.println("impossible");
            } else {
                out.println(ans);
            }
        }

        out.close();
    }
}
