package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 4/9/2016.
 */
public class B extends Solver {
    @Override
    public void solve() {
        // reverse the string and map to ints
        String line = new StringBuilder(in.nextLine()).reverse().toString();
        int[] sides = new int[line.length()];
        for (int i = 0; i < sides.length; i++) {
            sides[i] = line.charAt(i) == '+' ? 0 : 1;
        }
        // just accumulate flips
        int flips = 0;
        for (int side : sides) {
            if (side != (flips % 2)) {
                flips++;
            }
        }
        println("Case #%d: %d", TC, flips);
    }

    public B(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(B.class);
    }
}
