package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by raggzy on 4/9/2016.
 */
public class A extends Solver {

    private static void digits(int num, Set<Integer> set) {
        while (num > 0) {
            set.add(num % 10);
            num /= 10;
        }
    }

    @Override
    public void solve() {
        int n = in.nextInt();
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= 100; i++) {
            digits(n * i, set);
            if (set.size() == 10) {
                println("Case #%d: %d", TC, n * i);
                return;
            }
        }
        println("Case #%d: INSOMNIA", TC);
    }

    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(A.class);
    }
}
