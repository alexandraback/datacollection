import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {

    public static final int MAX_DEPTH = 27;

    List<BigInteger> ps;

    void dfs(int depth, String f, String r, int sqSum) {
        if (depth==MAX_DEPTH) return;

        BigInteger b = new BigInteger(f+r);
        ps.add(b.multiply(b));

        for (int d=0; d<=2; d++) {
            if (sqSum*2+d*d>=10) break;
            b = new BigInteger(f+d+r);
            ps.add(b.multiply(b));
        }

        for (int d=0; d<=2; d++) {
            int sum = sqSum+d*d;
            if (sum>=5) break;
            dfs(depth+1, f+d, d+r, sum);
        }
    }

    public C() throws Exception {
        ps = new ArrayList<BigInteger>();

        ps.add(BigInteger.valueOf(0));
        ps.add(BigInteger.valueOf(1));
        ps.add(BigInteger.valueOf(4));
        ps.add(BigInteger.valueOf(9));

        dfs(1, "1", "1", 1);
        dfs(1, "2", "2", 4);
        Collections.sort(ps);

        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            BigInteger A = in.nextBigInteger();
            BigInteger B = in.nextBigInteger();
            int pa = Collections.binarySearch(ps, A);
            if (pa<0) pa = ~pa;
            int pb = Collections.binarySearch(ps, B);
            if (pb<0) pb = ~pb-1;
            int ans = 1+pb-pa;
            out.println(ans);
        }
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
