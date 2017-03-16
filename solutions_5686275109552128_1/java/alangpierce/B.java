package qual;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Ordering;
import com.google.common.collect.TreeMultiset;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;

public class B {
    private static final String PROBLEM = "qual/B-large";
    private final Scanner in;
    public B(Scanner in) {
        this.in = in;
    }

    private String runCase() {
        int n = in.nextInt();
        List<Integer> vals = nextIntList(n);
        int max = Ordering.natural().max(vals);
        int bestNumSteps = max;
        for (int numNormalSteps = 1; numNormalSteps < max; numNormalSteps++) {
            int numSpecialSteps = 0;
            for (int val : vals) {
                numSpecialSteps += (val - 1) / numNormalSteps;
            }
            bestNumSteps = Math.min(bestNumSteps, numNormalSteps + numSpecialSteps);
        }
        return String.format("%d", bestNumSteps);
    }

    private List<Integer> nextIntList(int n) {
        ImmutableList.Builder<Integer> builder = ImmutableList.builder();
        for (int i = 0; i < n; i++) {
            builder.add(in.nextInt());
        }
        return builder.build();
    }

    private void runCases() throws FileNotFoundException {
        int numCases = in.nextInt();
        PrintWriter writer = new PrintWriter(PROBLEM + ".out");
        for (int casenum = 1; casenum <= numCases; casenum++) {
            String result = runCase();
            System.out.printf("Case #%d: %s%n", casenum, result);
            writer.printf("Case #%d: %s%n", casenum, result);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(PROBLEM + ".in"));
        new B(in).runCases();
    }
}
