import static java.lang.Math.*;
import java.util.*;

/**
 * Puh.... that took forever. 42 min.
 */

public class digits {
    final static double EPSILON = 1e-10;

    // Ported from C++ version at
    // http://stanford.edu/~liszt90/acm/notebook.html#file15
    //
    // Reduced row echelon form via Gauss-Jordan elimination 
    // with partial pivoting.  This can be used for computing
    // the rank of a matrix.
    //
    // Running time: O(n^3)
    //
    // INPUT:    a[][] = an nxm matrix
    //
    // OUTPUT:   rref[][] = an nxm matrix (stored in a[][])
    //           returns { rank of a[][], index of last pivot column }
    static int [] rref(double [][]a) {
        int n = a.length;
        int m = a[0].length;
        int r = 0;
        int lastc = 0;  // last pivot column
        for (int c = 0; c < m && r < n; c++) {
            int j = r;
            for (int i = r+1; i < n; i++) 
                if (abs(a[i][c]) > abs(a[j][c])) 
                    j = i;
            if (abs(a[j][c]) < EPSILON) continue;

            lastc = c;
            double [] temp = a[r]; // swap(a[j], a[r]);
            a[r] = a[j];
            a[j] = temp;

            double s = 1.0 / a[r][c];
            for (int k = 0; k < m; k++) 
                a[r][k] *= s;
            for (int i = 0; i < n; i++) if (i != r) {
                double t = a[i][c];
                for (int k = 0; k < m; k++) 
                    a[i][k] -= t * a[r][k];
            }
            r++;
        }
        return new int [] { r, lastc };
    }

    /*
     * Linear Equation Solver for dummies (that's us).
     *
     * Solve a general system of linear equations with a single
     * rhs, given in augmented form A | b.
     *
     * rank(A) = rank(A|b) = n   : unique solution
     * rank(A) = rank(A|b) < n   : many solutions
     * rank(A) < rank(A|b)       : no solutions
     */
    enum Solution { UNIQUE, MANY, INCONSISTENT }

    static Solution solvelinearsystem(double [][]A) {
        /* Likely you will want to debug that you constructed
         * the system correctly during a contest.
        System.err.println("Solving linear system:");
        for (int i = 0; i < A.length; i++)
            System.err.println((char)('A' + i) + java.util.Arrays.toString(A[i]));
        */
        int m = A.length;           // number of equations
        int n = A[0].length - 1;    // number of variables
        int [] rc = rref(A);
        int rankAb = rc[0];
        int lastpivotcol = rc[1];
        boolean rankAEqualrankAb = lastpivotcol < n;

        /*
        System.err.println("RREF is:");
        for (int i = 0; i < A.length; i++)
            System.err.println((char)('A' + i) + java.util.Arrays.toString(A[i]));
            */

        if (!rankAEqualrankAb)
            return Solution.INCONSISTENT;

        if (rankAb == n)
            return Solution.UNIQUE;

        if (rankAb < n)
            return Solution.MANY;

        throw new Error();
    }

    static String [] D = new String[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

    static String solve(String s) {
        double [][] coeff = new double[26][11];
        int [] order = new int[26];
        for (int j = 0; j < order.length; order[j] = j, j++);
        for (char c = 'A'; c <= 'Z'; c++) {
            for (int d = 0; d < 10; d++) {
                for (char l : D[d].toCharArray())
                    if (l == c)
                        coeff[c-'A'][d] += 1;
            }
        }
        for (char c : s.toCharArray()) {
            coeff[c-'A'][10] += 1;
        }
        String answer = "";
        Solution x = solvelinearsystem(coeff);
        for (int d = 0; d < 10; d++) {
            for (int i = 0; i < Math.round(coeff[d][10]); i++)
                answer += Integer.toString(d);
        }
        return answer;
    }

    public static void main(String []av) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int c = 1; c <= T; c++) {
            String sol = solve(s.nextLine());
            System.out.printf("Case #%d: %s%n", c, sol);
        }
    }
}
