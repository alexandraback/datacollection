/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;


import java.util.Scanner;

/**
 *
 * @author mora
 */
public class roundC {
     public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        int testNum = sin.nextInt();
        for(int i = 1; i <= testNum; i++){
            int R = sin.nextInt();
            int C = sin.nextInt();
            int W = sin.nextInt();
            
            int x = getGaruntee(R, W, C);
            System.out.println("Case #"+i+": "+x);
            
            
        }
    }
     
     public static int getGaruntee(int R, int W, int C){
         int x = R * (C/W);
         if(C % W > 0){
             x = x + W;
         }else{
             x = x + W - 1;
         }
         return x;
     }
     
}
