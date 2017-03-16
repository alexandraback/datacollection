package Round1C;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class CLessMoneyMoreProblems {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int t = 1; t <= tests; t++) {
            int maxCoinCount = sc.nextInt(); //guaranteed to be 1 in the small case
            int denominationCount = sc.nextInt();
            int maxValue = sc.nextInt();
            Set<Integer> denominations = new HashSet<Integer>();
            for (int x = 0; x < denominationCount; x++) {
                denominations.add(sc.nextInt());
            }
            boolean[] reachable = new boolean[maxValue + 1];
            reachable[0] = true;
            for (int denomination : denominations) {
                for (int x = maxValue; x >= 0; x--) {
                    if (reachable[x] && x + denomination <= maxValue) {
                        reachable[x + denomination] = true;
                    }
                }
            }
            List<Set<Integer>> canReachWith = new ArrayList<Set<Integer>>();
            for (int x = 0; x <= maxValue; x++) {
                canReachWith.add(new HashSet<Integer>());
            }
            for (int x = 1; x <= maxValue; x++) {
                if (denominations.contains(x)) continue;
                for (int y = 0; x + y <= maxValue; y++) {
                    if (reachable[y] && !reachable[x + y]) canReachWith.get(x + y).add(x);
                }
            }
            int minCoinsAdded = leastCoins(reachable, denominations, canReachWith, maxValue);
            System.out.printf("Case #%d: %d%n", t, minCoinsAdded);
        }
        sc.close();
    }
    static int leastCoins(boolean[] reachable, Set<Integer> denominations, List<Set<Integer>> canReachWith, int maxVal) {
        //this operates on the following principle: everything has to have something covering it. See what gives the best results (I hope it doesn't take too long to run.)
        for (int x = 1; x <= maxVal; x++) {
            if (!reachable[x]) { //cover the first thing that isn't covered, then continue recursively
                int minCoins = Integer.MAX_VALUE;
                for (int denomination : canReachWith.get(x)) {
                    if (denominations.contains(denomination)) continue;
                    //add possibilities
                    boolean[] added = new boolean[maxVal + 1];
                    for (int y = 1; y <= maxVal; y++) {
                        if (!reachable[y] && canReachWith.get(y).contains(x)) {
                            reachable[y] = true;
                            added[y] = true;
                        }
                    }
                    List<Set<Integer>> newCanReachWith = new ArrayList<Set<Integer>>();
                    for (int z = 0; z <= maxVal; z++) {
                        newCanReachWith.add(new HashSet<Integer>());
                    }
                    for (int z = 1; z <= maxVal; z++) {
                        if (denominations.contains(z)) continue;
                        for (int y = 0; z + y <= maxVal; y++) {
                            if (reachable[y] && !reachable[z + y]) newCanReachWith.get(z + y).add(z);
                        }
                    }
                    denominations.add(denomination);
                    for (int y = 0; denomination + y <= maxVal; y++) {
                        if (reachable[y] && !reachable[denomination + y]) newCanReachWith.get(denomination + y).add(denomination);
                    }
                    //test the best case with it
                    minCoins = Math.min(minCoins, leastCoins(reachable, denominations, newCanReachWith, maxVal));
                    //clean up
                    for (int y = 1; y <= maxVal; y++) {
                        if (added[y]) reachable[y] = false;
                    }
                    denominations.remove(denomination);
                }
                return minCoins + 1;
            }
        }
        return 0;
    }
}
