import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    public static final int MAX_N = 2000;
    static BigDecimal[][] C = new BigDecimal[MAX_N+1][MAX_N+1];
    static {
        for (int n=0; n<=MAX_N; n++) {
            C[n][0] = C[n][n] = BigDecimal.valueOf(1);
            for (int k=1; k<n; k++) {
                C[n][k] = C[n-1][k-1].add(C[n-1][k]);
            }
        }
    }

    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int N = in.nextInt();
            int X = abs(in.nextInt());
            int Y = in.nextInt();

            double ans = 0;
            if (((X+Y)&1)==0) {
                int d = (X+Y)/2;

                int h = 1;
                for (int i=0; i<d; i++) {
                    N -= h*2-1;
                    if (N<0) break;
                    h += 2;
                }

                if (N>=2*h-1) {
                    ans = 1;
                } else if (N>0) {
                    if (X!=0) {
                        if (N-(h-1)>Y) ans = 1;
                        else if (N>Y) {
                            BigDecimal a = BigDecimal.valueOf(0);
                            BigDecimal b = BigDecimal.valueOf(2).pow(N);
                            for (int i=0; i<N-Y; i++) {
                                a = a.add(C[N][i]);
                            }
                            ans = a.divide(b).doubleValue();
                        }
                    }
                }
            }
            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
