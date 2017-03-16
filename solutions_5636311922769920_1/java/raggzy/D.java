package codejam.y2016.qual;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

/**
 * Created by raggzy on 4/9/2016.
 */
public class D extends Solver {
    public void solve() {
        int K = in.nextInt();
        // the idea is: if consider the C transformations, and index i
        // if it's G -> then G is for sure at i/K^(C-1) in initial
        // if it's L -> then L is for sure at i%K in initial. And no G at i/K^(C-1) in initial
        // that with 1 index in C transformation we bound 2 indexes in initial
        // so if C > 1 the answer is (1+K)/2 otherwise it's K
        int C = in.nextInt();
        int S = in.nextInt();
        int minS;
        LongStream result;
        if (C == 1) {
            minS = K;
            result = IntStream.rangeClosed(1, K).asLongStream();
        } else {
            minS = (1 + K) / 2;
            long kPow = (long) Math.pow(K, C - 1);
            // just binding initial i and i+1
            result = IntStream.range(0, (1 + K) / 2).mapToLong(i -> kPow * (2 * i) + Math.min(K - 1, 2 * i + 1) + 1);
        }
        println("Case #%d: %s", TC, S < minS ? "IMPOSSIBLE" : result.mapToObj(String::valueOf).collect(Collectors.joining(" ")));
    }

    public static void main(String[] args) throws Exception {
        Runner.main(D.class);
    }

    public D(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }
}
