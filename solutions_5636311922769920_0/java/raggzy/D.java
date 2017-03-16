package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Created by raggzy on 4/9/2016.
 */
public class D extends Solver {
    @Override
    public void solve() {
        int K = in.nextInt();
        int C = in.nextInt();
        int S = in.nextInt();
        println("Case #%d: %s", TC, IntStream.rangeClosed(1, K).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
    }

    public static void main(String[] args) throws Exception {
        Runner.main(D.class);
    }
    public D(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }
}
