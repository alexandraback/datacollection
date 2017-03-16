/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Jam2014;

import base.base;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek    Apr 12, 2014
 */
public class qD extends base {
    static String jam = "Jam2014";
    static String round = "Qualification";
    
    static String problem = "D";
    static String inputSize = "small";
    static String attempt = "attempt1";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            int N = Integer.parseInt(file.poll());
            Float x[][] = new Float[2][N];
            for(int j=0; j < 2; j++) {
                String[] t = file.poll().split(" ");
                for(int k=0; k < N; k++)
                    x[j][k] = Float.parseFloat(t[k]);
            }
            output.append("Case #").append(i+1).append(": ").append(solution(x[0], x[1])).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".out", output.toString());
        System.out.println(output);
    }
    
    @SuppressWarnings("empty-statement")
    public static String solution(Float[] Naomi, Float[] Ken) {
        int N = Naomi.length;
        Arrays.sort(Naomi, Collections.reverseOrder());
        Arrays.sort(Ken, Collections.reverseOrder());
        
        int w = 0;
        for(int j=0; w < N && j < N; w++, j++) {
            while(j < N && Ken[w] < Naomi[j]) 
                  j++;
            
            if(j == N)
               break;
        }
        
        int NaomiWarScore = N - w;
        
        w = 0;
        ArrayList<Float> NaomiDWar = new ArrayList<Float>(Arrays.asList(Naomi));
        
        for(int i=0; i < N; i++) {
            int j = getWinIndex(NaomiDWar, Ken[i]);
            if(j != -1) {
               NaomiDWar.remove(j);
               w++;
            }
        }
        
        int NaomiDWarScore = w;
        
        return NaomiDWarScore+" "+NaomiWarScore;
    }

    /* array is passed in sorted decendingly */
    private static int getWinIndex(ArrayList<Float> array, Float a) {
        if(array.get(0) < a)
           return -1;
        
        /* binary search */
        int left = 0;
        int right = array.size()-1;
        
        while(right-left > 0) {
            int mid = (right+left+1) / 2;
            if(array.get(mid) < a)
               right = mid-1;
            else
               left = mid;
        }

        return right;
        
    }
}

