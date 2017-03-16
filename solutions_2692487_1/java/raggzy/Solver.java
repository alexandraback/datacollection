package template;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 02.05.13
 * Time: 18:08
 * To change this template use File | Settings | File Templates.
 */
public abstract class Solver {
    protected final Scanner in;
    protected final PrintStream out;
    protected final int TC;


    protected Solver(Scanner in, PrintStream out, int TC) {
        this.in = in;
        this.out = out;
        this.TC = TC;
    }

    public abstract void solve();
}
