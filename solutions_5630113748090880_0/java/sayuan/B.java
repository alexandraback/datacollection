import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void solve(int caseNum) {
        int n = in.nextInt();
        int[] count = new int[2501];
        for (int i=0; i<2*n-1; i++) {
            for (int j=0; j<n; j++) {
                count[in.nextInt()]++;
            }
        }

        StringBuilder buf = new StringBuilder();
        for (int i=1; i<=2500; i++) {
            if ((count[i]&1)!=0) buf.append(" ").append(i);
        }
        out.println(buf);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d:", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
