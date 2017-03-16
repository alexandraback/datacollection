import java.io.*;
import java.util.*;

public class Program {

    private final long e, r;

    private final long vs[];

    private final long ws[];

    public Program(long e, long r, long[] vs) {
        this.e = e;
        this.r = r;
        this.vs = vs;
        this.ws = new long[vs.length];
        Arrays.fill(this.ws, -1L);
    }


    public void dumpCase() {
        System.err.println("$$$ " + e + " " + r + " " + Arrays.toString(this.vs) + " " + Arrays.toString(this.ws));
    }


    private int getRestCount() {
        int count = 0;
        for (long w : this.ws) {
            if (w < 0) {
                ++ count;
            }
        }
        return count;
    }

    private int getLargestAndFirstIndex(int start, int end) {
        long max = -1L;
        int maxIndex = -1;
        for (int i = start; i < end; ++i) {
            if (max < this.vs[i]) {
                maxIndex = i;
                max = this.vs[maxIndex];
            }
        }
        return maxIndex;
    }

    private void solve(int start, int end, long initial, long target) {
        if (start >= end) {
            return;
        }
        // Find largest and first v
        int pi = getLargestAndFirstIndex(start, end);
        long piInit = Math.min(this.e, initial + (pi - start) * this.r);
        // Determine w with target
        long after = Math.max(0, target - r * (end - pi));
        System.err.printf("start=%d end=%d initial=%d target=%d pi=%d after=%d%n", start, end, initial, target, pi, after);
        long consumed = piInit - after;
        this.ws[pi] = consumed;
        // Solve former
        solve(start, pi, initial, initial);
        // Solve latter
        solve(pi + 1, end, after + this.r, target);
    }

    public long getStatus() {
        solve(0, this.vs.length, this.e, this.r);
        long gain = 0L;
        for (int i = 0; i < this.vs.length; ++ i) {
            gain += this.vs[i] * this.ws[i];
        }
        return gain;
    }

    public static List<Program> readCases(BufferedReader reader) throws IOException {
        int numCases = Integer.parseInt(reader.readLine());
        List<Program> cases = new ArrayList<>(numCases);
        for (int caseIndex = 0; caseIndex < numCases; ++ caseIndex) {
            String[] firstline = reader.readLine().split(" ");
            long e = Long.parseLong(firstline[0]);
            long r = Long.parseLong(firstline[1]);
            int n = Integer.parseInt(firstline[2]);
            long[] vs = new long[n];
            int vsi = 0;
            for (String col : reader.readLine().split(" ")) {
                vs[vsi++] = Long.parseLong(col);
            }
            cases.add(new Program(e, r, vs));
        }
        return cases;
    }

    public static void main(String[] args) throws IOException {
        int target = -1;
        if (args.length == 1) {
            target = Integer.parseInt(args[0]);
        }
        int t = 1;
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            for (Program kase : readCases(reader)) {
                if (target < 0 || target == t) {
                    System.out.printf("Case #%d: %s%n", t, kase.getStatus());
                    if (target >= 0) {
                        kase.dumpCase();
                    }
                }
                ++ t;
            }
        }
    }
}

// vim: et sw=4 sts=4
