import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    long reverse(long v) {
        long t = 0;
        while (v>0) {
            t = t*10 + v%10;
            v /= 10;
        }
        return t;
    }

    void solve(int caseNum) {
        long n = in.nextLong();

        if (n<=20) {
            out.println(n);
            return;
        }

        int l = Long.toString(n-1).length();

        long[] t = new long[20];
        t[0] = 1;
        for (int i=1; i<19; i++) {
            t[i] = t[i-1]*10;
        }

        // debug(t);

        long cur = 10;
        long times = 10;
        for (int i=2; i<l; i++) {
            cur *= 10;
            times += t[i/2] + t[i-i/2] - 1;
            // debug(i,cur, times);
        }

        long u = n-1;
        for (int i=0; i<l/2; i++) {
            u /= 10;
        }

        long times2 = times + n-cur;
        u = reverse(u);
        cur += u;
        times += u;
        cur = reverse(cur);
        times++;
        times += n-cur;

        out.println(min(times, times2));


        // debug(times, cur);



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
