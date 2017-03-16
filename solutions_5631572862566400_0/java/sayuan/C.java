import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {

    int dfs(List<Integer>[] t, int u, int skip) {
        int r = 1;
        for (int v: t[u]) {
            if (v==skip) continue;
            r = max(r, 1+dfs(t, v, skip));
        }
        return r;
    }

    void solve(int caseNum) {
        int n = in.nextInt();
        int[] bff = new int[n];
        List<Integer>[] rbff = new List[n];
        for (int i=0; i<n; i++) rbff[i] = new ArrayList();
        for (int i=0; i<n; i++) {
            int t = in.nextInt()-1;
            bff[i] = t;
            rbff[t].add(i);
        }

        int ans = -1;
        for (int i=0; i<n; i++) {
            int t = i;
            for (int j=1; j<=n; j++) {
                t = bff[t];
                if (t==i) {
                    ans = max(ans, j);
                    break;
                }
            }
        }

        int ans2 = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (bff[i]==j&&bff[j]==i) {
                   ans2 += dfs(rbff, i, j)+dfs(rbff, j, i);
                }
            }
        }
        out.println(max(ans,ans2));
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public C() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
