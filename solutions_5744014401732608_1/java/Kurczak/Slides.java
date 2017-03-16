package pl.kurczak.gcj;

import java.io.PrintStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.time.Duration;
import java.time.Instant;
import java.util.Scanner;

/**
 * @author Andrzej Kurczewski
 */
public class Slides {
    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(Files.newBufferedReader(Paths.get("s-in.txt")));
             PrintStream out = new PrintStream("s-out.txt", "UTF-8")
//             PrintStream out = System.out
        ) {
            Instant before = Instant.now();
            solve(in, out);
            Instant after = Instant.now();
            System.out.println(Duration.between(before, after));
        }
    }

    private static void solve(Scanner in, PrintStream out) throws Exception {
        int tests = in.nextInt();
        for (int i = 1; i <= tests; i++) {
            int buildings = in.nextInt();
            long ways = in.nextLong();
            out.format("Case #%d: %s%n", i, solve(buildings, ways));
        }
    }

    private static String solve(int buildings, long ways) {
        long maxWays = 1L << (buildings - 2);
        if (ways > maxWays) {
            return "IMPOSSIBLE";
        } else if (ways == maxWays) {
            StringBuilder solution = new StringBuilder("POSSIBLE\n");
            for (int i = 0; i < buildings; i++) {
                for (int j = 0; j <= i; j++) {
                    solution.append("0");
                }
                for (int j = i+1; j < buildings; j++) {
                    solution.append("1");
                }
                solution.append("\n");
            }
            return solution.toString().trim();
        }
        StringBuilder solution = new StringBuilder("POSSIBLE\n");
        boolean[] waysToBuild = getWaysToBuild(buildings, ways);
        for (int i = 0; i < buildings - 1; i++) {
            for (int j = 0; j <= i; j++) {
                solution.append("0");
            }
            for (int j = i+1; j < buildings - 1; j++) {
                solution.append("1");
            }
            if (waysToBuild[i]) {
                solution.append("1");
            } else {
                solution.append("0");
            }
            solution.append("\n");
        }
        for (int i = 0; i < buildings; i++) {
            solution.append("0");
        }
        return solution.toString().trim();
    }

    private static boolean[] getWaysToBuild(int buildings, long ways) {
        boolean[] waysToBuild = new boolean[buildings];
        for (int i = 1; i < buildings; i++) {
            waysToBuild[i] = ways % 2 != 0;
            ways /= 2;
        }
        return waysToBuild;
    }
}
