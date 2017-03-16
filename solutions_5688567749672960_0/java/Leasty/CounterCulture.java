/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import java.util.Scanner;

/**
 *
 * @author Tom
 */
public class CounterCulture {
    long target;
    
    public static CounterCulture[] readFile(Scanner input) {
        CounterCulture[] puzzles = new CounterCulture[input.nextInt()];
        for(int i = 0; i < puzzles.length; ++i) {          


            puzzles[i] = new CounterCulture(input.nextLong());
        }
        
        return puzzles;
    }
    
    public CounterCulture(long target) {
        this.target = target;
    }

    public String solve() {
        long result = 0;
        
        int[] best = new int[1000001];        
        for(int i = 2; i < best.length; ++i) {
            best[i] = Integer.MAX_VALUE;
        }
        
        best[1] = 1;
        for(int i = 1; i < best.length; ++i) {
            //System.out.println(i + " = " + best[i]);
            
            //if(best[i] < best[i - 1]) {
            //    System.out.println(i + " = " + best[i]);
            //}
            
            if(i + 1 < best.length) {
                best[i + 1] = Math.min(best[i + 1], best[i] + 1);
            }
            
            int reverse = 0;
            int temp = i;
            
            while(temp != 0) {
                reverse *= 10;
                reverse += temp%10;
                temp /= 10;
            }
            
            if(reverse < best.length) {
                best[reverse] = Math.min(best[reverse], best[i] + 1);
            }
        }
        
        result = best[(int)target];
        
        /*System.out.println(best[547]);
        System.out.println(best[1567]);
        
        if(target < 20) {
            result = target;
        } else {
            result += 10;
            long add = 9;
            long ten = 10;
            
            while(ten * 10 <= target) {
                result += 9;
                ++result;
                
                result += add;
                
                add *= 10;
                add += 9;
                
                ten *= 10;
                
                //System.out.println(result);
            }
            
            long last = 0;
            long first = target;
            long pow = 1;
                    
            while(10 < first) {
                last += pow * first%10;
                first /= 10;
                first %= 10;
            }
            
            result += first + last;
        }*/
        
        return "" + result;
    }
}
