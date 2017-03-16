package codejam.y2015.round1c;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;

public class C extends Solver {
    public C(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    @Override
    public void solve() {
        long C = in.nextLong();
        int D = in.nextInt();
        long V = in.nextLong();

        long[] coins = new long[D];
        for (int i = 0; i < D; i++) {
            coins[i] = in.nextLong();
        }
        long sum = 0;
        int i = 0;
        int added = 0;
        while (sum < V) {
            if ((i < D) && (coins[i] <= sum + 1)) {
                sum += C * coins[i];
                i++;
            } else {
                added++;
                sum += C * (sum + 1);
            }
        }
        println("Case #%d: %d", TC, added);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(C.class);
    }
}
