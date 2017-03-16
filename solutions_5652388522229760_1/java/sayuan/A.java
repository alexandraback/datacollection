import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    void solve(int caseNum) {
        int n = in.nextInt();
        if (n==0) {
            out.println("INSOMNIA");
            return;
        }
        int d = 0;
        for (int i=n;; i+=n) {
            int t = i;
            while (t>0) {
                d |= 1<<(t%10);
                t /= 10;
            }
            if (d == (1<<10)-1) {
                out.println(i);
                return;
            }
        }
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
