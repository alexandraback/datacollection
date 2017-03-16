import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Task3 {
    private static final String TASK = "Task3";
    private static int n;
    private static int m;
    private static int k;
    private static int maxRhombusEdge;
    private static int maxRhombusEncloses;
    private static int total;

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        Locale.setDefault(Locale.US);

        InputStream in = System.in;
        if (args.length > 0) in = new FileInputStream(args[0]);

        try (Scanner s = new Scanner(in)) {
            int t = s.nextInt();
            for (int j = 0; j < t; j++) {
                n = s.nextInt();
                m = s.nextInt();
                k = s.nextInt();
                maxRhombusEdge = (Math.min(n, m) + 1) / 2;
                maxRhombusEncloses = rhombusEncloses(maxRhombusEdge);
                total = n*m;

                int result = solve();
                sb.append("Case #").append(j+1).append(": ").append(result).append("\n");
            }
        }

        try (FileWriter f = new FileWriter("CodeJam2014_Round1C/src/" + TASK + "_results.txt")) {
            f.write(sb.toString());
        }
    }

    private static int rhombusEncloses(int rhombusEdge) {
        if (rhombusEdge == 1) return 1;
        return (rhombusEdge-1)*4 + rhombusEncloses(rhombusEdge - 1);
    }

    private static int solve() {
        if (n < 3 || m < 3) return k;


        int max = 2*(n+m-2);
        int result = Math.min(solveA(), find(1, max));
        System.out.println("Solving for n = " + n + ", m = " + m + " and k = " + k + " got result " + result);

        return result;
    }

    private static int solveA() {
        int stones = 2*(n+m-2);
        int covered = n*m;

        if (covered - k <= 4) return stones - (covered-k);

        stones -= 4;
        covered -= 4;

        while (covered >= k) {
            stones--;
            covered-=2;
        }

        return stones+1;
    }

    private static int find(int from, int to) {
        while (to - from > 1) {
            int mid = (from + to) / 2;
            if (isEnough(mid))
                to = mid;
            else
                from = mid+1;
        }

        if (isEnough(from)) return from;
        else return to;
    }

    private static boolean isEnough(int mid) {
        return enclosed(mid, maxRhombusEdge) >= k;
    }

    private static int enclosed(int stones, int maxREdge) {
        if (stones < 4) return stones;

        int maxEdge = Math.min(stones/4+1, maxREdge);
        if (maxEdge == 1)
            return stones;

        int used = (maxEdge-1)*4;
        int enclosed = rhombusEncloses(maxEdge);
        int left = stones - used;

        int enclosedWithLeft = enclosed(left+maxEdge/2, maxEdge/2)-maxEdge/2; //think of the edge case

        return Math.min(total, enclosed + enclosedWithLeft);
    }

}
