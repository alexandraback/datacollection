package gcj.gcj2012.qualif;

import gcj.SolverBase;

import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;

public class ProblemC extends SolverBase {

    public ProblemC() {
        super("Recycled Numbers");
    }

    public static void main(String[] args) throws Exception {
        SolverBase problem = new ProblemC();
        // problem.verbose = true;
        problem.solve(System.in, System.out);
    }

    @Override
    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int[] AB = readSingleLineIntArray(reader);
        int A = AB[0];
        int B = AB[1];

        // How many digits?
        int d = (""+A).length();
        check(d == (""+B).length());

        int x = 0;
        Set<String> done = new HashSet<String>();

        // Naive implementation 1 : full loop
        for(int i=A;i<B;i++){
            for(int k=1;k<d;k++){
                int j = rotate(i,d,k);
                if( i<j && j<=B ){
                    String pair = i+","+j;
                    if( !done.contains(pair) ){
                        x ++;
                        done.add(pair);
                    }
                }
            }
        }

        out.println(x);
    }

    static int[] pows = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

    private int rotate(int i, int d, int k) {
        int pow1 = pows[k];
        int pow2 = pows[d-k];
        int bar = i/pow1;
        int foo = pow2 * (i%pow1);
        int j = foo + bar;
        //System.out.println("rotate("+i+","+k+")"+" = "+j);
        return j;
    }
}
