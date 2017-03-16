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
        int[] c = new int[128];
        for (char ch: s.toCharArray()) c[ch]++;

        int[] ans = new int[10];
        ans[0] = c['Z'];
        ans[2] = c['W'];
        ans[4] = c['U'];
        ans[6] = c['X'];
        ans[8] = c['G'];

        ans[3] = c['H'] - ans[8];
        ans[5] = c['F'] - ans[4];
        ans[7] = c['S'] - ans[6];

        ans[9] = c['I'] - ans[5] - ans[6] - ans[8];
        ans[1] = c['N'] - ans[7] - ans[9]*2;

        StringBuilder buf = new StringBuilder();
        for (int i=0; i<10; i++)
            for (int j=0; j<ans[i]; j++) 
                buf.append(i);

        out.println(buf);
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
