//package Round_1B;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;

/**
 *
 * @author .
 */
public class A {
   
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());

        for (int kase = 1; kase <= T; kase++) {
            int n = in.nextInt();
            
            int[] s = new int[n];
            
            int total = 0;
            
            for(int i = 0; i < n; i++) {
                s[i] = in.nextInt();
                
                total += s[i];
            }
            
            pr("Case #" + kase + ":");
            
            double[] result = new double[n];
            boolean done = false;
            boolean[] use = new boolean[n];
            int count = n;
            for(int i = 0; i < n; i++) {
                use[i] = true;
            }
            
            while(!done) {
                done = true;
                
                total = 0;
                count = 0;
                
                for(int i = 0; i < n; i++) {
                    total += s[i];
                    if(use[i]) {
                        count += 1;
                    }
                }
                
                for(int i = 0; i < n; i++) {
                    if(!use[i]) {
                        result[i] = 0;
                        continue;
                    }
                    
                    int sum = 0;
                    for(int j = 0; j < n; j++) {
                        if(j != i && use[j]) {
                            sum += s[j];
                        }
                    }
                    
                    if(total == 0) {
                        result[i] = 100*(double)(1)/(double)count;
                    } else {
                        result[i] = 100*(double)(1 - (double)s[i]*(count - 1)/(double)total + (double)sum/(double)total)/(double)count;                        
                    }
                    
                    if(result[i] < 0) {
                        done = false;
                    }
                }
                
                for(int i = 0; i < n; i++) {
                    if(result[i] < 0) {
                        use[i] = false;
                    }
                }
            }
                
            
            for(int i = 0; i < n; i++) {
                pf(" %.6f", result[i]);
            }
            
            
            pl("");
        }
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
    
}
