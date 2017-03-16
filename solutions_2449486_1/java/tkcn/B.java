import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);

            int n = in.nextInt();
            int m = in.nextInt();
            int[][] map = new int[n][m];
            for (int r=0; r<n; r++) {
                for (int c=0; c<m; c++) {
                    map[r][c] = in.nextInt();
                }
            }

            String ans = "YES";
            for (int r=0; r<n; r++) {
                for (int c=0; c<m; c++) {
                    boolean colValid = true;
                    for (int cr=0; cr<n; cr++) {
                        if (map[cr][c]<=map[r][c]) continue;
                        colValid = false;
                        break;
                    }
                    boolean rowValid = true;
                    for (int cc=0; cc<m; cc++) {
                        if (map[r][cc]<=map[r][c]) continue;
                        rowValid = false;
                        break;
                    }
                    if (!rowValid&&!colValid) ans = "NO";
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
