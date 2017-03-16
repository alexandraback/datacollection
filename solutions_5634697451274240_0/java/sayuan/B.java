import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void solve(int caseNum) {
        String s = in.next();
        int c = 1;
        for (int i=1; i<s.length(); i++) if (s.charAt(i)!=s.charAt(i-1)) c++;
        if (s.charAt(s.length()-1)=='+') c--;
        out.println(c);
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
