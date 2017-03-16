package gcj.gcj2012.round1A;

import gcj.SolverBase;

import java.io.BufferedReader;
import java.io.PrintStream;

public class ProblemA extends SolverBase {

    public ProblemA() {
        super("");
    }

    public static void main(String[] args) throws Exception {
        SolverBase problem = new ProblemA();
        // problem.verbose = true;
        problem.solve(System.in, System.out);
    }

    @Override
    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] AB = readSingleLineIntArray(reader);
        int A = AB[0];
        int B = AB[1];
        double[] p = readSingleLineDoubleArray(reader);

        double y = 0.0;

        // "give up"
        y = 1 + B + 1;

        // backspace 0..A times
        int rest = B - A;
        double pOK = 1.0;
        for (int kept = 1; kept <= A; kept++) {
            int back = A - kept;
            pOK *= p[kept - 1];
            double q = pOK * (back + back + rest + 1) + (1 - pOK) * (back + back + rest + 1 + B + 1);
            if (q < y) {
                y = q;
            }
        }

        out.println(y);
    }
}
