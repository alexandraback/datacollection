package codejam.y2015.qualification;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 11-Apr-15.
 */
public class C extends Solver {
    public C(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private static enum Q {
        one, i, j, k
    }

    private static final Q[][] MULT = new Q[Q.values().length][Q.values().length];
    private static final int[][] SIGN = new int[Q.values().length][Q.values().length];

    static {
        MULT[Q.one.ordinal()][Q.one.ordinal()] = Q.one;
        SIGN[Q.one.ordinal()][Q.one.ordinal()] = 1;

        MULT[Q.one.ordinal()][Q.i.ordinal()] = Q.i;
        SIGN[Q.one.ordinal()][Q.i.ordinal()] = 1;
        //
        MULT[Q.one.ordinal()][Q.j.ordinal()] = Q.j;
        SIGN[Q.one.ordinal()][Q.j.ordinal()] = 1;
        //
        MULT[Q.one.ordinal()][Q.k.ordinal()] = Q.k;
        SIGN[Q.one.ordinal()][Q.k.ordinal()] = 1;
        /////////
        ////////
        MULT[Q.i.ordinal()][Q.one.ordinal()] = Q.i;
        SIGN[Q.i.ordinal()][Q.one.ordinal()] = 1;

        MULT[Q.i.ordinal()][Q.i.ordinal()] = Q.one;
        SIGN[Q.i.ordinal()][Q.i.ordinal()] = -1;
        //
        MULT[Q.i.ordinal()][Q.j.ordinal()] = Q.k;
        SIGN[Q.i.ordinal()][Q.j.ordinal()] = 1;
        //
        MULT[Q.i.ordinal()][Q.k.ordinal()] = Q.j;
        SIGN[Q.i.ordinal()][Q.k.ordinal()] = -1;
        /////////
        ////////
        MULT[Q.j.ordinal()][Q.one.ordinal()] = Q.j;
        SIGN[Q.j.ordinal()][Q.one.ordinal()] = 1;

        MULT[Q.j.ordinal()][Q.i.ordinal()] = Q.k;
        SIGN[Q.j.ordinal()][Q.i.ordinal()] = -1;
        //
        MULT[Q.j.ordinal()][Q.j.ordinal()] = Q.one;
        SIGN[Q.j.ordinal()][Q.j.ordinal()] = -1;
        //
        MULT[Q.j.ordinal()][Q.k.ordinal()] = Q.i;
        SIGN[Q.j.ordinal()][Q.k.ordinal()] = 1;
        /////////
        ////////
        MULT[Q.k.ordinal()][Q.one.ordinal()] = Q.k;
        SIGN[Q.k.ordinal()][Q.one.ordinal()] = 1;

        MULT[Q.k.ordinal()][Q.i.ordinal()] = Q.j;
        SIGN[Q.k.ordinal()][Q.i.ordinal()] = 1;
        //
        MULT[Q.k.ordinal()][Q.j.ordinal()] = Q.i;
        SIGN[Q.k.ordinal()][Q.j.ordinal()] = -1;
        //
        MULT[Q.k.ordinal()][Q.k.ordinal()] = Q.one;
        SIGN[Q.k.ordinal()][Q.k.ordinal()] = -1;
    }

    @Override
    public void solve() {
        int L = in.nextInt();
        int X = in.nextInt();
        char[] str = in.next().toCharArray();
        Q res = Q.one;
        int sign = 1;
        boolean foundI = false;
        boolean foundJ = false;
        for (int i = 0; i < X * L; i++) {
            int index = i % L;
            Q q = Q.valueOf("" + str[index]);
            sign *= SIGN[res.ordinal()][q.ordinal()];
            res = MULT[res.ordinal()][q.ordinal()];
            if (!foundI) {
                foundI = (sign == 1 && res == Q.i);
            } else if (!foundJ) {
                foundJ = (sign == 1 && res == Q.k);
            }
        }
        boolean found = foundI && foundJ && (sign == -1 && res == Q.one);
        println("Case #%d: %s", TC, found ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        Runner.main(C.class);
    }
}
