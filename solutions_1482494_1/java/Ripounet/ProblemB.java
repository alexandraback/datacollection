package gcj.gcj2012.round1A;

import gcj.SolverBase;

import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.Arrays;

public class ProblemB extends SolverBase {

    public ProblemB() {
        super("Kingdom Rush");
    }

    public static void main(String[] args) throws Exception {
        SolverBase problem = new ProblemB();
        // problem.verbose = true;
        problem.solve(System.in, System.out);
    }

    @Override
    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        int N = readSingleLineIntArray(reader)[0];
        // int[] a = new int[N];
        // int[] b = new int[N];
        // String[] s = new String[N];
        Abi[] abi = new Abi[N];
        for (int i = 0; i < N; i++) {
            int[] AB = readSingleLineIntArray(reader);
            int A = AB[0];
            int B = AB[1];
            // a[i] = A;
            // b[i] = B;
            // s[i] = B + " " + A + " " + i;
            abi[i] = new Abi(A, B, i);
        }

        int stars = 0;
        int levels = 0;

        // Arrays.sort(b);
        Arrays.sort(abi);

        // Glutony eat all free 2-stars
        int top = 0;
        for (; top < N; top++) {
            if (abi[top].b <= stars) {
                stars += 2;
                abi[top].b = -1;
                abi[top].a = -1; // this level WON'T be made for 1-star rating
                // now
                levels++;
            } else {
                break;
            }
        }

        boolean win = true;
        while (win) {
            win = false;

            for (int small = N - 1; small >= top; small--) {
                if (abi[small].a != -1 && abi[small].a <= stars) {
                    stars += 1;
                    levels++;
                    abi[small].a = -1;
                    win = true;
                    break;
                }
            }

            for (; top < N; top++) {
                if (abi[top].b <= stars) {
                    if (abi[top].a == -1) {
                        stars += 1;
                    } else {
                        stars += 2;
                    }
                    abi[top].b = -1;
                    abi[top].a = -1; // this level WON'T be made for 1-star
                    // rating now
                    levels++;
                    win = true;
                } else {
                    break;
                }
            }

            if (top == N) {
                // finished! at last!
                break;
            }
        }

        if (top != N) {
            out.println("Too Bad");
            return;
        }

        out.println(levels);
    }

    static class Abi implements Comparable<Abi> {

        public int a, b, i;

        @Override
        public int compareTo(Abi other) {
            return this.b - other.b;
        }

        public Abi(int aa, int bb, int ii) {
            a = aa;
            b = bb;
            i = ii;
        }
    }
}
