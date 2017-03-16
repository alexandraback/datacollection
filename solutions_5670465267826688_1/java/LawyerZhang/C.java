import java.util.*;

public class C {
    static final int ONE = 1, I = 2, J = 3, K = 4;
    static int[][] table = new int[][] {
        {ONE, I, J, K},
        {I, -ONE, K, -J},
        {J, -K, -ONE, I},
        {K, J, -I, -ONE}
    };

    static int multiply(int x, int y) {
        int negate = 1;
        if (x < 0) {
            negate = -negate;
            x = -x;
        }
        if (y < 0) {
            negate = -negate;
            y = -y;
        }
        return negate * table[x - 1][y - 1];
    }

    static int pow(int x, long p) {
        if (p == 0)
            return ONE;
        else if (p == 1)
            return x;
        long t = p / 2;
        int r = pow(x, t);
        r = multiply(r, r);
        if (p % 2 == 1L)
            r = multiply(r, x);
        return r;
    }

    public static final void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int cs = 1; cs <= T; ++cs) {
            int l = scan.nextInt();
            long x = scan.nextLong();
            int[] a = new int[l];
            String s = scan.next();
            for (int i = 0; i < l; ++i) {
                if (s.charAt(i) == 'i')
                    a[i] = I;
                else if (s.charAt(i) == 'j')
                    a[i] = J;
                else
                    a[i] = K;
            }

            int single = ONE;
            for (int i = 0; i < l; ++i)
                single = multiply(single, a[i]);
            int end = pow(single, x);

            int repeat = (int) Math.min(9L, x);
            int[] b = new int[repeat * l];
            for (int i = 0; i < repeat; ++i)
                for (int j = 0; j < l; ++j)
                    b[i * l + j] = a[j];
            int curr = ONE;
            boolean hasI = false, hasJ = false;
            for (int i = 0; i < b.length; ++i) {
                curr = multiply(curr, b[i]);
                if (!hasI) {
                    if (curr == I)
                        hasI = true;
                } else {
                    if (curr == multiply(I, J))
                        hasJ = true;
                }
            }
            if (hasI && hasJ && end == multiply(multiply(I, J), K)) {
                System.out.format("Case #%d: YES\n", cs);
            } else {
                System.out.format("Case #%d: NO\n", cs);
            }
        }
    }
}
