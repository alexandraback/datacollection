import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int E = in.nextInt();
            int R = in.nextInt();
            int N = in.nextInt();
            int[] vs = new int[N];
            for (int i=0; i<N; i++) vs[i] = in.nextInt();

            int[][] memo = new int[N+1][E+1];
            for (int i=0; i<=N; i++) Arrays.fill(memo[i], -1<<28);
            memo[0][E] = 0;

            int ans = 0;
            for (int i=0; i<N; i++) {
                for (int j=0; j<=E; j++) {
                    for (int k=0; k<=j; k++) {
                        int t = memo[i][j]+k*vs[i];
                        int index = min(E, j-k+R);
                        memo[i+1][index] = max(memo[i+1][index], t);
                        ans = max(ans, t);
                    }
                }
            }

            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
