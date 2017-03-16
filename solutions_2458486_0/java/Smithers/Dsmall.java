// Solution to Problem D. Treasure in Java.

import java.util.Scanner;

public class Dsmall {
    
    private static final int MAXKEY = 200;
    
    private static class Solver {
        int n;
        int[] haveKeys;
        int[] chestLocks;
        int[][] chestKeys;
        
        boolean[] isBadState;
        int[] openOrder;
        int openCount;
        int state;
        
        Solver(int n) {
            this.n = n;
            haveKeys = new int[MAXKEY];
            chestLocks = new int[n];
            chestKeys = new int[n][MAXKEY];
            
            isBadState = new boolean[1<<n];
            openOrder = new int[n];
            openCount = 0;
            state = 0;
        }
        
        boolean solve() {
            for (int i=0; i<n; i++) {
                if ((state & 1<<i) != 0) continue;
                if (haveKeys[chestLocks[i]] == 0) continue;
                if (isBadState[state | 1<<i]) continue;
                
                state |= 1<<i;
                haveKeys[chestLocks[i]]--;
                for (int j=0; j<MAXKEY; j++) haveKeys[j] += chestKeys[i][j];
                openOrder[openCount++] = i;
                
                if (openCount == n) return true;
                if (solve()) return true;
                
                openCount--;
                for (int j=0; j<MAXKEY; j++) haveKeys[j] -= chestKeys[i][j];
                haveKeys[chestLocks[i]]++;
                state &= ~(1<<i);
            }
            isBadState[state] = true;
            return false;
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int i, j;
        
        int t = scanner.nextInt();
        for (int c = 1; c <= t; c++) {
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            
            Solver solver = new Solver(n);
            
            for (i=0; i<k; i++) solver.haveKeys[scanner.nextInt()]++;
            
            for (i=0; i<n; i++) {
                solver.chestLocks[i] = scanner.nextInt();
                int ki = scanner.nextInt();
                for (j=0; j<ki; j++) solver.chestKeys[i][scanner.nextInt()]++;
            }
            
            if (solver.solve()) {
                System.out.print("Case #" + c + ":");
                for (i=0; i<n; i++) System.out.print(" " + (solver.openOrder[i]+1));
                System.out.println();
            } else {
                System.out.println("Case #" + c + ": IMPOSSIBLE");
            }
        }
    }
    
}
