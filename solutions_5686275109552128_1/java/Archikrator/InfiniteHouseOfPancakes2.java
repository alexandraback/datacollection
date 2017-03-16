package google.codejam_2015;

import java.util.Arrays;
import java.util.Scanner;

public class InfiniteHouseOfPancakes2 {

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

    private static int solve(int[] pancakes) {
        Arrays.sort(pancakes);
        int max = pancakes[pancakes.length - 1];
        int bestCase = max;
        for (int targetMax = max; targetMax >=3; targetMax--) {
            int specialMinutesNeeded = 0;
            int actualMax = 0;
            for (int i = 0; i < pancakes.length; i++) {
                int j = pancakes[i];
                int mm = j;
                if (j > targetMax) {
                    double divide = Math.ceil((double)j / targetMax);
                    mm = (int)Math.ceil(j/divide);
                    specialMinutesNeeded += divide  - 1;
                    
                }
                actualMax = Math.max(actualMax, mm);
            }
            bestCase = Math.min(bestCase, actualMax +specialMinutesNeeded);
        }
        return bestCase;
    }

}
