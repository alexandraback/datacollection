/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;
import java.util.*;
import java.lang.*;
/**
 *
 * @author Tom
 */
public class NewLotteryGame {
    private long A;
    private long B;
    private long K;
    
    public static NewLotteryGame[] readFile(Scanner input) {
        NewLotteryGame[] puzzles = new NewLotteryGame[input.nextInt()];
        
        for(int i = 0; i < puzzles.length; ++i) {
            puzzles[i] = new NewLotteryGame(input.nextLong(), input.nextLong(), input.nextLong());
        }
        
        return puzzles;
    }
    
    private NewLotteryGame(long A, long B, long K) {
        this.A = A;
        this.B = B;
        this.K = K;
    }
    
    public String solve() {
        long result = 0;
        
        for(int i = 0; i < A; ++i) {
            for(int j = 0; j < B; ++j) {
                if((i & j) < K) {
                    ++result;
                }
            }
        }
        
        return "" + result;
    }
}
