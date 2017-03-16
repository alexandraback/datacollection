package y2013.round1b;

import template.Runner;
import template.Solver;

import java.io.PrintStream;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 04.05.13
 * Time: 19:27
 * To change this template use File | Settings | File Templates.
 */
public class A extends Solver {
    public A(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    private int movesToGainAll(int current, List<Integer> motes) {
        int moves = 0;
        for (int mote : motes) {
            while (current <= mote) {
                current = 2 * current - 1;
                moves++;
            }
            current += mote;
        }
        return moves;
    }

    @Override
    public void solve() {
        int A = in.nextInt();
        int N = in.nextInt();
        List<Integer> motes = new ArrayList<Integer>(N);
        for (int i = 0; i < N; i++) {
            motes.add(in.nextInt());
        }
        Collections.sort(motes);
        //
        int minMoves = N;
        if (A > 1) {
            for (int i = 1; i <= N; i++) {
                int moves = movesToGainAll(A, motes.subList(0, i)) + N - i;
                if (moves < minMoves) {
                    minMoves = moves;
                }
            }
        }
        out.println(String.format("Case #%d: %d", TC, minMoves));
    }

    public static void main(String[] args) throws Exception {
        Runner.main(A.class);
    }
}
