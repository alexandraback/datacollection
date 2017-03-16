import java.util.Arrays;
import java.util.Scanner;


public class Q2 {
    public static final int IMPOSSIBLE = Integer.MAX_VALUE;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            int stages = in.nextInt();
            int[][] lvlMap = new int[stages][2];
            for (int k = 0; k <stages; k++) {
                for (int j = 0; j < 2; j++) {
                    lvlMap[k][j] = in.nextInt();
                }
            }
            int plays = find(lvlMap);
            System.out.print("Case #" + (i + 1) + ": ");
            if (plays == IMPOSSIBLE) {
                System.out.println("Too Bad");
            }
            else {
                System.out.println(plays);
            }
        }
    }
    
    public static int find(int[][] lvlMap) {
        int stars = 0;
        int plays = 0;
        int[] completed = new int[lvlMap.length];
        
        while (true) {
            
            //System.out.printf("Stars: %d plays: %d\n", stars, plays);
            
            // Find level which we can get max stars
            int lvl = -1;
            int stage = -1; // 0, 1
            for (int i = 0; i < completed.length; i++) {
                // Try 2 stars first
                if (lvlMap[i][1] <= stars && completed[i] != 2) {
                    // No reason we can't get it right away
                    lvl = i;
                    stage = 1;
                    break;
                }
            }
            
            if (lvl == -1) {
                int best = -1;
                // Find best 1 star stage (with highest 2 star)
                for (int i = 0; i < completed.length; i++) {
                    if (completed[i] > 0)
                        continue; // completed
                    if (lvlMap[i][1] > best && lvlMap[i][0] <= stars) {
                        best = lvlMap[i][1];
                        lvl = i;
                        stage = 0;
                    }
                }
            }
            
            if (lvl == -1) {
                for (int i = 0; i < completed.length; i++) {
                    if (completed[i] != 2){
                        return IMPOSSIBLE;
                    }
                }
                return plays;
            }
            
            //System.out.printf("lvl: %d stage: %d completed: %d\n\n", lvl, stage + 1, completed[lvl]);
            
            int gain = stage + 1 - completed[lvl];
            
            if (gain == 0) {
                throw new RuntimeException("Error!");
            }
            stars += gain;
            
            completed[lvl] = stage + 1;
            plays++;
        }

    }
}
