/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author Rizal ZAF
 */
public class FairSquare {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("C-small-attempt0.in"));
        FileWriter writer = new FileWriter("fairsquare.out");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            String[] minmax = br.readLine().split(" ");
            long min = Long.parseLong(minmax[0]);
            long max = Long.parseLong(minmax[1]);
            
            long sqrtmax = (long) Math.ceil(Math.sqrt(max));
            
            Set<Long> allpal = generateAllPalindrome(sqrtmax);
            
            int count = 0;
            for(long p : allpal){
                long pp = p*p;
                if (pp >= min && pp <=max){
                    if (isPalindrome(pp)){
                        count ++;
                    }
                }
            }
            
            writer.write("Case #" + (i+1) + ": " + count + "\r\n");
            
        }
        
        writer.close();
    }
    
   public static Set<Long> generateAllPalindrome(long upperb) {
        Set<Long> result = new HashSet<Long>();
        for (int i = 0; i <= 9 && i <= upperb; i++) {
               result.add((long)i);
           }

        boolean cont = true;
        for (int i = 1; cont; i++) {
            StringBuffer rev = new StringBuffer("" + i).reverse();
            cont = false;
            for (String d : "0123456789".split("")) {
                long n = Integer.parseInt("" + i + d + rev);
                if (n <= upperb) {
                    cont = true;
                    result.add(n);
                }
            }
        }
        
        return result;
    }
   
   public static boolean isPalindrome(long number) {
        long palindrome = number; 
        long reverse = 0;

        while (palindrome != 0) {
            long remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        if (number == reverse) {
            return true;
        }
        return false;
    }
    
}
