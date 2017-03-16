package codejam.y2015.qualification;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * Created by raggzy on 11-Apr-15.
 */
public class A extends Solver {

    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    @Override
    public void solve() {
        int S = in.nextInt();
        int stood = 0;
        int result = 0;
        String str = in.next();
        char[] pipsWithShy = str.toCharArray();
        for (int shy = 0; shy <= S; shy++) {
            if (shy > stood) {
                int needToStand = shy - stood;
                result += needToStand;
                stood += needToStand;
            }
            stood += Character.digit(pipsWithShy[shy], 10);
        }
        println("Case #%d: %d", TC, result);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(A.class);
    }
}
