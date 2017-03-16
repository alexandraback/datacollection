
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author lvamanu
 */
public class LotteryGame {
    public static void main(String[] args) throws FileNotFoundException {
        
     Scanner in = new Scanner(new File("B-small-attempt0.in")); 
        PrintWriter out = new PrintWriter(new File("Bsmall.out"));
        int T = in.nextInt(); 
        for (int i = 1; i <= T; i++) {
            int A = in.nextInt();
            int B = in.nextInt(); 
            int K = in.nextInt();
            int win = 0;
            //boolean vis[] = new boolean[K + 1]; 
            for (int a = 0; a < A; a++) {
                for (int b = 0; b < B; b++) {
                    int res = a&b; 
                    //System.out.println(a + " " + b + " " + res);
                    if (res < K ) {
                        win ++; 
                    }
                }
            }
            
            out.println("Case #" + i+ ": " + win);
            
        }
        in.close(); 
        out.close();
    }
    
}
