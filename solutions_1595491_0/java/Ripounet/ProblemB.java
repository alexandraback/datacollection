package gcj.gcj2012.qualif;

import gcj.SolverBase;

import java.io.BufferedReader;
import java.io.PrintStream;

public class ProblemB extends SolverBase {

    public ProblemB() {
        super("Dancing With the Googlers");
    }

    public static void main(String[] args) throws Exception {
        SolverBase problem = new ProblemB();
        // problem.verbose = true;
        problem.solve(System.in, System.out);
    }

    @Override
    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] line = readSingleLineIntArray(reader);
        int N = line[0];
        int S = line [1];
        int p = line [2];

        int x = 0;
        for(int i=3;i<3+N;i++){
            int sum = line [i];

            if( sum < p ){
                // no way...
                continue;
            }

            if( sum >= ((p-1)+(p-1)+p) ){
                // No surprise needed
                x ++;
            }else if( S>0 && sum >= ((p-2)+(p-2)+p) ){
                x ++;
                S --;
            }
        }

        out.println( x );
    }
}
