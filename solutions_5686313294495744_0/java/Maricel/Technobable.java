import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Technobable {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("technobable_in.txt"));
        PrintStream out = new PrintStream(new File("technobable_out.txt"));

        Technobable program = new Technobable();

        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            int n = in.nextInt();
            Pair[] pairs = new Pair[n];
            for (int i = 0; i < n; i++) {
                pairs[i] = new Pair(in.next(), in.next());
            }

            int maxFake = program.solve(pairs, n);

            String rowSolution = "Case #" + test + ": " + maxFake;

            System.out.println(rowSolution);
            out.println(rowSolution);
        }

        in.close();
        out.close();
    }

    private int solve(Pair[] pairs, int n) {
        int bestSol = 0;
        maskLoop:
        for (int mask = 0; mask < (1 << n); mask++) {
            Set<String> trueFirstWords = new HashSet<>();
            Set<String> trueSecondWords = new HashSet<>();

            for (int i = 0; i < n; i++) {
                if ((mask & (1<<i)) != 0) {
                    trueFirstWords.add(pairs[i].a);
                    trueSecondWords.add(pairs[i].b);
                }
            }

            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1<<i)) == 0) {
                    if (!trueFirstWords.contains(pairs[i].a)) {
                        continue maskLoop;
                    }
                    if (!trueSecondWords.contains(pairs[i].b)) {
                        continue maskLoop;
                    }
                    count++;
                }
            }

            bestSol = Math.max(bestSol, count);
        }

        return bestSol;
    }

    static class Pair {
        String a;
        String b;

        public Pair(String a, String b) {
            this.a = a;
            this.b = b;
        }
    }
}