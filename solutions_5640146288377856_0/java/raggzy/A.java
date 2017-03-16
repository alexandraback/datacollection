package codejam.y2015.round1c;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 10-May-15.
 */
public class A extends Solver {
    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    @Override
    public void solve() {
        int R = in.nextInt();
        int C = in.nextInt();
        int W = in.nextInt();
        int result = R * (C / W) + W - 1 + (C % W != 0 ? 1 : 0);
        println("Case #%d: %d", TC, result);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(A.class);
    }
}
