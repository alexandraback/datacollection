/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package CodeJam2013;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
/**
 *
 * @author gadam
 */
public class Solution {

    /**
     * @param args the command line arguments
     * 
     * 
     * 
     * 
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Scanner scan = new Scanner(System.in);
        
        int T = scan.nextInt();
        
        int case_num =1;
        while(case_num <= T)
        {
            long r = scan.nextLong();
            
            long t = scan.nextLong();
            int max_brings = 0;
            
            int j=1, k=0;
            
            long cur_guess = 1;
            long prev_guess = 1;
            while(true)
            {
                long value = 2 * (cur_guess)*cur_guess +
                        2 * r * cur_guess - cur_guess;
                
                if(value > t)
                {
                    cur_guess = (cur_guess + prev_guess) /2;
                    if(cur_guess == prev_guess)
                        break;
                }
                else if(value == t)
                    break;
                else
                {
                    prev_guess = cur_guess;
                    cur_guess *= 2; 
                }
            }
            
            System.out.println("Case #"+ case_num + ": " + cur_guess);
            
            case_num++;
        }
        
    }
}

