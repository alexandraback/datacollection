package y2015.r1B;

import java.io.*;
import java.util.*;

/**
 * @author aurel, 5/2/15
 */
public class A {
    //public static final String type = "test";
    public static final String type = "small-attempt1";
    //public static final String type = "large";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/r1B/A-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/r1B/A-" + type + ".out"
        ));

        Map<Long, Long> mem = new HashMap<>();

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            long n = in.nextLong();
            out.write("Case #" + ti + ": " + g(n) + "\n");
            System.out.println(ti);
        }

        in.close();
        out.close();
    }

    private static long f(long n, Map<Long, Long> mem) {
        if (mem.containsKey(n)) return mem.get(n);
        if (n == 1) return 1;
        long min = 1 + f(n - 1, mem);
        if (n % 10 != 0 && rev(n) < n) {
            min = Math.min(min, 1 + f(rev(n), mem));
        }
        mem.put(n, min);
        return min;
    }

    private static long g(long n) {
        Queue<long[]> q = new LinkedList<>();
        q.add(new long[]{n, 1});
        Set<Long> viz = new HashSet<>();
        viz.add(n);
        while (!q.isEmpty()) {
            long[] v = q.poll();
            if (v[0] == 1) return v[1];
            if (!viz.contains(v[0] - 1)) {
                viz.add(v[0] - 1);
                q.add(new long[]{v[0] - 1, v[1] + 1});
            }
            long r = rev(v[0]);
            if (v[0] % 10 != 0 && r < v[0] && !viz.contains(r)) {
                viz.add(r);
                q.add(new long[]{r, v[1] + 1});
            }
        }
        return 1;
    }


    private static long rev(long n) {
        long m = 0;
        while (n > 0) {
            m = m * 10 + n % 10;
            n /= 10;
        }
        return m;
    }
}
