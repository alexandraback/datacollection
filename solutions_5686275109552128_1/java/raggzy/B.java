package codejam.y2015.qualification;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 11-Apr-15.
 */
public class B extends Solver {
    public B(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    @Override
    public void solve() {
        int D = in.nextInt();
        int[] P = new int[D];
        for (int i = 0; i < D; i++) {
            P[i] = in.nextInt();
        }
        int result = Integer.MAX_VALUE;
        for (int last = 1; last <= 1000; last++) {
            int splits = 0;
            for (int i = 0; i < D; i++) {
                if (P[i] % last == 0) {
                    splits += P[i] / last - 1;
                } else {
                    splits += P[i] / last;
                }
            }
            result = Math.min(result, splits + last);
        }
        println("Case #%d: %d", TC, result);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(B.class);
    }
}
