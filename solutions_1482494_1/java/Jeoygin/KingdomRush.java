package gcj12;

import java.util.Arrays;
import java.util.Scanner;

public class KingdomRush {
    class Level implements Comparable<Level> {
        int r1;
        int r2;
        byte pass;

        @Override
        public int compareTo(Level o) {
            if (r2 != o.r2) {
                return r2 - o.r2;
            }
            return r1 - o.r1;
        }
    }

    int solve(Scanner scan) {
        int res = 0;
        int n = scan.nextInt();
        Level[] levels = new Level[n];
        Level starEarner = null;

        for (int i = 0; i < n; i++) {
            levels[i] = new Level();
            levels[i].r1 = scan.nextInt();
            levels[i].r2 = scan.nextInt();
            levels[i].pass = 0;
            if (levels[i].r1 == 0) {
                starEarner = levels[i];
            }
        }
        if (starEarner == null) {
            return -1;
        }

        Arrays.sort(levels);

        for (Level l : levels) {
            // System.out.println(l.r1 + " " + l.r2);
        }

        int stars = 0;
        for (Level l : levels) {
            while (stars < l.r2) {
                boolean find = false;
                for (int i = n - 1; i >= 0; i--) {
                    Level le = levels[i];
                    if (le.pass == 0 && le.r1 <= stars) {
                        stars ++;
                        res++;
                        le.pass = 1;
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    return -1;
                }
            }
            if (l.pass == 0) {
                stars += 2;
            } else {
                stars += 1;
            }
            l.pass = 2;

            res++;
        }

        return res;
    }

    public static void main(String[] args) {
        KingdomRush pp = new KingdomRush();
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            int res = pp.solve(scan);
            System.out.println(res != -1 ? res : "Too Bad");
        }
    }
}
