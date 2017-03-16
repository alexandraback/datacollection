package google.codejam_2015;

import java.util.Scanner;

public class InfiniteHouseOfPancakes1 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            int dinNum = s.nextInt();
            int[] pancakes = new int[dinNum];
            for (int j = 0; j < pancakes.length; j++) {
                pancakes[j] = s.nextInt();
            }
            System.out.printf("Case #%d: %d%n", i + 1, solve(pancakes));
        }
    }
    static int[] cache = new int[1001];

    private static int split(int i) {
        if (cache[i] != 0) {
            return cache[i];
        }
        double doubleI = (double) i;
        int bestCase = i;
        int partitionable = 1;
        int max = (int) Math.ceil(i / 3d);
        for (int j = 2; j <= max; j++) {
            int thisCase = (int) Math.ceil(doubleI / j) + j - 1;
            if (thisCase < bestCase) {
                bestCase = thisCase;
                partitionable = j;
            } else {
                break;
            }
        }
        cache[i] = partitionable;
        return partitionable;
    }

     private static int solve(int[] pancakes) {
       return solve(pancakes, 0, 0,0);
    }
    
    
    private static int solve(int[] pancakes, int currentIdx, int maxMinutes, int specialMinutes) {
        if (currentIdx>= pancakes.length) return maxMinutes + specialMinutes;
        int bestResult = solve(pancakes, currentIdx + 1, Math.max(maxMinutes, pancakes[currentIdx]), specialMinutes);
        // not divide
        int splits = 1;
        for (int i = 2; i <= split(pancakes[currentIdx]); i++) {
            int cost = (int) Math.ceil((double)pancakes[currentIdx] / i) ;
            cost = Math.max(maxMinutes, cost);
            int thisResult = solve(pancakes, currentIdx + 1, cost, specialMinutes + i - 1);
            if (bestResult > thisResult) {
                bestResult = thisResult;
                splits = i;
            }
        }
        return bestResult;
    }
}
