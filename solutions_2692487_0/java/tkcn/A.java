import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int A = in.nextInt();
            int N = in.nextInt();
            int[] arr = new int[N];
            for (int i=0; i<N; i++) arr[i] = in.nextInt();
            Arrays.sort(arr);

            int ans = N;
            int cur = 0;
            for (int i=0; i<N; i++) {
                if (A>arr[i]) {
                    A += arr[i];
                    continue;
                }
                ans = min(ans, cur+N-i);
                A += A-1;
                cur++;
                if (cur>ans) break;
                i--;
                continue;
            }
            ans = min(ans, cur);

            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
