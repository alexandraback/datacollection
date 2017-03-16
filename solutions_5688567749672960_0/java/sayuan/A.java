import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    int reverse(int v) {
        int t = 0;
        while (v>0) {
            t = t*10+v%10;
            v /= 10;
        }
        return t;
    }

    void solve(int caseNum) {
        int n = in.nextInt();
        int[] d = new int[1000002];
        Arrays.fill(d, 1<<30);
        d[0] = 0;
        for (int i=0; i<=1000000; i++) {
            d[i+1] = min(d[i+1], d[i]+1);
            int r = reverse(i);
            if (r>1000000) continue;
            d[r] = min(d[r], d[i]+1);
        }
        out.println(d[n]);

    }

    // {{{
    Scanner in = new Scanner(System.in);
    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
