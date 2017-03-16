/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

/**
 *
 * @author Felke
 */
public class JavaApplication1 {

    static int[] primes = new int[10000];

    static void preparePrimes() {

        int counter = 0;
        int checkedNumber = 2;
        while (counter < 10000) {

            boolean prime = true;

            for (int k = 0; k < counter; k++) {
                if (checkedNumber % primes[k] == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) {
                primes[counter] = checkedNumber;
                counter++;
            }

            checkedNumber++;
        }
    }

    static class Number32 {

        boolean[] digit;
        int n;

        public Number32(int n) {
            
            digit = new boolean[n];
            this.n = n;

            digit[0] = true;
            digit[n - 1] = true;
            for (int l = 1; l < n - 1; l++) {
                digit[l] = false;
            }
        }

        void getNext() {
            for (int l = n - 2; l > 0; l--) {

                if (!digit[l]) {
                    digit[l] = true;

                    for (int m = l + 1; m < n - 1; m++) {
                        digit[m] = false;
                    }
                    break;
                }
            }
        }
        
        void print(){
            for (int k = 0; k < digit.length; k++){
                if (digit[k])
                    System.out.print(1);
                else 
                    System.out.print(0);
            }
            System.out.print(" ");
        }

    }
    
    static class SuperBigDecimal{
    
            BigDecimal bigDecimal;
        
        public SuperBigDecimal(Number32 number, int base, int n) {
            
            bigDecimal = new BigDecimal(0);

                        
            BigDecimal currentMultiplier = new BigDecimal(1);

            for (int k = n - 1 ; k>=0; k--){
                
                if (number.digit[k]){
                    bigDecimal = bigDecimal.add(currentMultiplier);
                }
                currentMultiplier = currentMultiplier.multiply(new BigDecimal(base));
            }
                
        }

        private int findDivider() {
            
            for(int k = 0; k <10000; k++){
             
                if (bigDecimal.compareTo(new BigDecimal(primes[k])) ==0){
                    return 0;
                }
                
                if (bigDecimal.remainder(new BigDecimal(primes[k])).compareTo(new BigDecimal("0")) == 0 ){
                    return primes[k];
                }
            }
            return 0;
        }
    
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        preparePrimes();

        Scanner reader = new Scanner(System.in);

        int t = reader.nextInt();

        for (int k = 1; k <= t; k++) {

            int n = reader.nextInt();
            int j = reader.nextInt();

            System.out.println("Case #" + k + ":");

            int found = 0;

            Number32 number = new Number32(n);

            while (found < j) {

                int[] foundPrimes = new int [9];
                boolean foundAll = true;

		for (int base = 2; base < 11; base++) {
                    SuperBigDecimal bigDecimal = new SuperBigDecimal(number, base, n);
                    
                    int divider = bigDecimal.findDivider();
                    
                    if (divider != 0){
                        foundPrimes[base-2] = divider;
                    }
                    else {
                        foundAll = false;
                        break;
                    }
                }
                
                if (foundAll){
                    
                    found++;
                    number.print();
                    
                    for (int l = 0; l < 9; l++){
                        System.out.print(foundPrimes[l] + " ");
                    }
                    System.out.println();
                    
                }

                number.getNext();
            }

        }

    }
}
