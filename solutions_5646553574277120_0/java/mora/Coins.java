/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author mora
 */
public class Coins {
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        int testNum = sin.nextInt();
        for(int i = 1; i <= testNum; i++){
            int C = sin.nextInt();
            int D = sin.nextInt();
            int V = sin.nextInt();
            
            ArrayList<Integer> coins = new ArrayList();
            for(int j = 0; j < D; j++){
                coins.add(sin.nextInt());
            }
            
            int size = getCoins(coins, V);
            
            System.out.println("Case #"+i+": "+(size - D));
            
            
        }
    }
    
    public static int getCoins(ArrayList<Integer> coins, int V){
        for(int i = 1; i <= V; i++){
            int sum = 0;
            for(int j = coins.size()-1; j>=0; j--){
                int coinVal = coins.get(j);
                if(sum == i){
                    break;
                }else{
                    if(coinVal <= i)
                        if(i >= sum+coinVal)
                            sum = sum + coinVal;
                }
                /*if(i > coinVal && i >= (sum+coinVal) ){
                    if(sum == i) break;
                    sum = sum + coinVal;
                }*/
            }
            if(sum != i){
                //System.out.println("add coin : "+ i);
                coins.add(i);
            }
            Collections.sort(coins);
        }
        return coins.size();
    }
}
