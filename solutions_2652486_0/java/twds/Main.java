import java.util.*;
import java.math.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wd
 */
public class Main {
    
    static int R, N, M, K;
    static int[] guess;
    static int[] res;
    
    static boolean v(int index, int current, int target) {
        if (index == N) {
            return current == target;
        }
        return v(index + 1, current, target) || v(index + 1, current * res[index], target);
    }
    
    static boolean verify(int value) {
        return v(0, 1, value);
    }
    
    static boolean search(int index, int min) {
        if (index == N) {
            for (int i = 0; i < K; i++) {
                if (!verify(guess[i])) {
                    return false;
                }
            }
            return true;
        }
        
        for (int i = min; i <= M; i++) {
            res[index] = i;
            if (search(index + 1, i)) {
                return true;
            }
        }
        return false;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            R = scan.nextInt();
            N = scan.nextInt();
            M = scan.nextInt();
            K = scan.nextInt();
            System.out.println(String.format("Case #%d:", taskIndex));
            
            guess = new int[K];
            res = new int[N];
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < K; j++) {
                    guess[j] = scan.nextInt();
                }
                search(0, 2);
                for (int j = 0; j < N; j++) {
                    System.out.print(res[j]);
                }
                System.out.println();
            }
        }
    }
}
