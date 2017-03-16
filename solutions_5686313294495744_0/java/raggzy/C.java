package codejam.y2016.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.*;

/**
 * Created by raggzy on 4/30/2016.
 */
public class C extends Solver {
    public C(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    @Override
    public void solve() {
        int N = in.nextInt();
        String[] L = new String[N];
        String[] R = new String[N];
        for (int i = 0; i < N; i++) {
            L[i] = in.next();
            R[i] = in.next();
        }
        int maxState = (1 << N) - 1;
        int result = Integer.MIN_VALUE;
        for (int state = 0; state < maxState; state++) {
            Set<String> possibleL = new HashSet<>();
            Set<String> possibleR = new HashSet<>();
            List<Integer> fakeIdxs = new LinkedList<>();
            for (int idx = 0; idx < N; idx++) {
                if ((state & (1 << idx)) > 0) {
                    fakeIdxs.add(idx);
                } else {
                    possibleL.add(L[idx]);
                    possibleR.add(R[idx]);
                }
            }
            //
            int fakeCount = 0;
            for (int fakeIdx : fakeIdxs) {
                if (possibleL.contains(L[fakeIdx]) && possibleR.contains(R[fakeIdx])) {
                    fakeCount++;
                }
            }
            result = Math.max(result, fakeCount);
        }
        println("Case #%d: %d", TC, result);
    }

    public static void main(String[] args) throws Exception {
        Runner.main(C.class);
    }
}
