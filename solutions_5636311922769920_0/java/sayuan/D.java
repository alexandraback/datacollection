import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class D {

    void solve(int caseNum) {
        int k = in.nextInt();
        int c = in.nextInt();
        int s = in.nextInt();

        if ((k+c-1)/c > s) {
            out.println(" IMPOSSIBLE");
            return;
        }

        StringBuilder buf = new StringBuilder();
        for (int i=0; i<k; i+=c) {
            long p = 0;
            for (int j=0; j<c; j++) {
                if (i+j>=k) break;
                p = (p*k+i+j);
            }
            buf.append(" ").append(p+1);
        }
        out.println(buf);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public D() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d:", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new D();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
