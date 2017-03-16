import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A_large {

    public A_large() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int A = in.nextInt();
            int B = in.nextInt();

            double[] pro = new double[A];
            double[] total = new double[A+1];
            for (int i=0; i<A; i++) pro[i] = in.nextDouble();
            total[0] = 1;
            for (int i=1; i<=A; i++) total[i] = total[i-1]*pro[i-1];
            double ans = 2+B;
            for (int i=0; i<=A; i++) {
                ans = min(ans, A-i+B-i+1+(1-total[i])*(B+1));
            }
            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new A_large();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    } 
    // }}}
}
