package codejam.y2015.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.*;

/**
 * Created by bistrashkin on 5/2/15.
 */
public class A extends Solver {
    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private static Integer reverse(int n) {
        LinkedList<Integer> digits = new LinkedList<Integer>();
        while (n > 0) {
            digits.addLast(n%10);
            n /= 10;
        }
        if (digits.getFirst() == 0) {
            return null;
        }
        Collections.reverse(digits);
        int pow10 = 1;
        int result = 0;
        for (int digit : digits) {
            result += pow10 * digit;
            pow10 *= 10;
        }
        return result;
    }


    @Override
    public void solve() {
        int N = in.nextInt();
        int[] F = new int[N + 1];
        F[0] = 0;
        for (int i = 1; i <= N; i++) {
            F[i] = 1 + F[i-1];
            Integer reverse = reverse(i);
            if (reverse != null && reverse < i) {
                F[i] = Math.min(F[i], 1 + F[reverse]);
            }
        }
        out.println(String.format("Case #%d: %d", TC, F[N]));
    }

    public static void main(String[] args) throws Exception {
//        System.out.println(reverse(20));
        Runner.main(A.class);
    }
}
