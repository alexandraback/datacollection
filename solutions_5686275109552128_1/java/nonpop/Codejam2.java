package codejam2;

import java.util.ArrayList;
import java.util.Scanner;

public class Codejam2 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int testCases = s.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            int diners = s.nextInt();
            ArrayList<Integer> pancakes = new ArrayList<>(diners);
            for (int diner = 0; diner < diners; diner++) {
                pancakes.add(s.nextInt());
            }

            int best = 1000;
            for (int goal = 1000; goal >= 1; goal--) {
                int got = goal;
                for (int i = 0; i < diners; i++) {
                    got += (pancakes.get(i) - 1) / goal;
                }
                best = Math.min(best, got);
            }
            
            System.out.println("Case #" + testCase + ": " + best);
        }
    }
    
}
