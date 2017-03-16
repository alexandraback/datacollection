// Hello Google, I am a student looking for an internship, (424)-242-2440
// Don't let this ugly code give you any wrong impressions, thanks

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        // Classic Bipartite
        int trials = sc.nextInt(); // [1,50]
        for (int i = 0; i < trials; i++) {
            int numBlocks = sc.nextInt(); // [1,1000]
            ArrayList<Double> naomisBlocks = new ArrayList<Double>(numBlocks);
            for (int j = 0; j < numBlocks; j++) {
                naomisBlocks.add(sc.nextDouble());
            }
            ArrayList<Double> kensBlocks = new ArrayList<Double>(numBlocks);
            for (int j = 0; j < numBlocks; j++) {
                kensBlocks.add(sc.nextDouble());
            }

            Collections.sort(naomisBlocks);
            Collections.sort(kensBlocks);

            System.out.printf("Case #%d: %d %d%n", (i + 1),
                    (solveDW(numBlocks, naomisBlocks, kensBlocks) + 0),
                    solveW(naomisBlocks, kensBlocks));

        }
        sc.close();
    }

    private static int solveW (ArrayList<Double> naomisBlocks,
            ArrayList<Double> kensBlocks) {
        int count = naomisBlocks.size();
        while (naomisBlocks.size() > 0) {
            boolean noBigger = true;
            for (int j = 0; j < kensBlocks.size(); j++) {
                if (kensBlocks.get(j) >= naomisBlocks.get(0)) {
                    count--;
                    kensBlocks.remove(j);
                    naomisBlocks.remove(0);
                    j = kensBlocks.size();
                    noBigger = false;
                }
            }
            if (noBigger) {
                kensBlocks.remove(0);
                naomisBlocks.remove(0);
            }
        }
        return count;
    }

    private static int solveDW (int numBlocks, ArrayList<Double> naomisBlocks,
            ArrayList<Double> kensBlocks) {
        int result = 0;
        int loss = 0;
        int leftN = 0, leftK = 0, rightN = numBlocks - 1, rightK = numBlocks - 1;
        for (int i = 0; i < numBlocks; i++) {
            if (naomisBlocks.get(leftN) > kensBlocks.get(leftK)) {
                // Good choice, move up
                result += 1;
                leftN++;
                leftK++;
            } else if (naomisBlocks.get(rightN) > kensBlocks.get(rightK)) {
                // Good choice, move up
                result += 1;
                rightN--;
                rightK--;
            } else {
                // Bad choice, sacrifice block
                if (naomisBlocks.get(leftN) < kensBlocks.get(rightK))
                    loss++;
                leftN++;
                rightK--;
            }
        }
        return result;
    }
}
