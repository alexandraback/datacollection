import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    void solve(int caseNum) {
        String s = in.next();
        int l = s.length();
        StringBuilder first = new StringBuilder();
        StringBuilder second = new StringBuilder();
        char cur = s.charAt(0);
        first.append(cur);
        for (int i=1; i<l; i++) {
            char ch = s.charAt(i);
            if (ch>=cur) {
                first.append(ch);
                cur = ch;
            } else {
                second.append(ch);
            }
        }

        out.println(first.reverse().append(second));
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
