package de.jaki.codejam.two015.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class B {


    private static final String PATTERN = "CASE #%d: %s";
    //private static final String NAME = "b.in";
    //private static final String NAME = "B-small-attempt1.in";
    private static final String NAME = "B-large.in";
    //private static final String OUT = "b.out";
    //private static final String OUT = "B-small-attempt1.out";
    private static final String OUT = "B-large.out";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(NAME));
        PrintWriter pw = new PrintWriter(OUT);
        int testCount = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < testCount; i++) {
            long t0 = System.currentTimeMillis();
            String sol = solve(sc);
            System.out.println(String.format(PATTERN, i + 1, sol));
            pw.println(String.format(PATTERN, i + 1, sol));
            long t1 = System.currentTimeMillis();
            System.out.println(t1 - t0);
        }
        pw.flush();
        pw.close();
    }

    private static String solve(Scanner sc) {
        int d = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        int max = 0;
        int total = 0;
        for (int i = 0; i < d; i++) {
            int e = sc.nextInt();
            total += e;
            max = Math.max(max, e);
            list.add(e);
        }
        Collections.sort(list);

        int best = max;
        for (int i = 2; i <= max && i <= best; i++) {
            int estimate = ((total / i) - list.size());
            if (estimate + i > best) {
                continue;
            }
            best = Math.min(best, solve(new ArrayList<Integer>(list), i, best) + i);
        }
        return "" + best;
    }

    private static int solve(List<Integer> list, int benchmark, int limit) {
        int steps = 0;
        Collections.sort(list);
        Integer max = list.get(list.size() - 1);
        while (max > benchmark && steps < limit) {
            List<Integer> toAdd = new ArrayList<>();
            for (int i = list.size() - 1; i >= 0; i--) {
                if (list.get(i) > benchmark) {
                    toAdd.add(list.get(i) - benchmark);
                    list.set(i, benchmark);
                }
            }
            list.addAll(toAdd);
            steps += toAdd.size();

            Collections.sort(list);
            max = list.get(list.size() - 1);
        }
        return steps;
    }


}
