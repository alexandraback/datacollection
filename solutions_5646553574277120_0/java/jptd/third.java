//package codeC;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author mora
 */
public class third {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testNum = in.nextInt();
        for(int i = 1; i <= testNum; i++){
            int C = in.nextInt();
            int D = in.nextInt();
            int V = in.nextInt();
            
            ArrayList<Integer> coins = new ArrayList();
            for(int j = 0; j < D; j++){
                coins.add(in.nextInt());
            }
            
            int size = get(coins, V);
            
            System.out.println("Case #"+i+": "+(size - D));
            
            
        }
    }
    
    public static int get(ArrayList<Integer> coins, int V){
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
               
            }
            if(sum != i){
               
                coins.add(i);
            }
            Collections.sort(coins);
        }
        return coins.size();
    }
}
