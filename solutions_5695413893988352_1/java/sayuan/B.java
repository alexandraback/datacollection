import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void dfs(long x, long y, int s) {
        if (s==l) {
            long t = abs(x-y);
            if (diff > t) {
                diff = t;
                coders = x;
                jammers = y;
            } else if (diff == t) {
                if (coders > x) {
                    coders = x;
                    jammers = y;
                } else if (coders == x) {
                    jammers = min(jammers, y);
                }
            }
            return;
        }
        char c = a.charAt(s);
        char d = b.charAt(s);
        if (x>y) {
            if (c=='?') c = '0';
            if (d=='?') d = '9';
            dfs(x*10+(c-'0'), y*10+(d-'0'), s+1);
        } else if (x<y) {
            if (c=='?') c = '9';
            if (d=='?') d = '0';
            dfs(x*10+(c-'0'), y*10+(d-'0'), s+1);
        } else {
            if (c=='?' && d=='?') {
                dfs(x*10, y*10, s+1);
                dfs(x*10+1, y*10, s+1);
                dfs(x*10, y*10+1, s+1);
            } else if (c=='?') {
                int t = d-'0';
                dfs(x*10+t, y*10+t, s+1);
                if (t>0) dfs(x*10+t-1, y*10+t, s+1);
                if (t<9) dfs(x*10+t+1, y*10+t, s+1);
            } else if (d=='?') {
                int t = c-'0';
                dfs(x*10+t, y*10+t, s+1);
                if (t>0) dfs(x*10+t, y*10+t-1, s+1);
                if (t<9) dfs(x*10+t, y*10+t+1, s+1);
            } else {
                dfs(x*10+(c-'0'), y*10+(d-'0'), s+1);
            }
        }
    }

    String a;
    String b;
    int l;
    long diff;
    long coders;
    long jammers;
    void solve(int caseNum) {
        a = in.next();
        b = in.next();
        l = a.length();
        diff = Long.MAX_VALUE;
        dfs(0, 0, 0);
        out.printf("%0"+l+"d %0"+l+"d\n", coders, jammers);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
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
