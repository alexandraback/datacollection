/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2014;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Ben
 */
public class R1BProblemB {
    
    public void solve()
    {
        
    }
    
    public void go() throws Exception
    {
        try(Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
            PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out")))
        {
            int T = sc.nextInt();
            for(int t = 1; t <= T; t++)
            {
                int A = sc.nextInt();
                int B = sc.nextInt();
                int K = sc.nextInt();
                
                int count = 0;
                for(int i = 0; i < A; i++){
                    for(int j = 0; j < B; j++){
                        int x = i&j;
                        if(x >= 0 && x < K)
                            count++;
                    }
                }
                
                pw.printf("Case #%d: %d\n", t, count);
            }
        }
    }
}
