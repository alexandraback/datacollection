/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2013;

import base.*;
import java.util.ArrayList;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek
 */
public class C extends base {
        
    static String jam = "Jam2013";
    static String round = "Qualification";
    
    static String problem = "C";
    static String inputSize = "small";

    static ArrayList<pair> counts;
    static boolean initSmall = false;
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-attempt0.in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            String[] t = file.poll().split(" ");
            long A = Long.parseLong(t[0]);
            long B = Long.parseLong(t[1]);
            output.append("Case #").append(i+1).append(": ").append(solutionSmall(A, B)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-practice.out", output.toString());
        System.out.println(output);
    }
    
    static class pair {
        long a, c;
        pair(long i, long d) {
            a = i;
            c = d;
        }
    }
    
    public static String solutionSmall(long A, long B) {
        if(!initSmall)
            initSmall();
        
        /* no need for b-search .. very small array */
        pair a = counts.get(0), b = counts.get(0);
        for(int i=1; i < counts.size(); i++) {
            pair t = counts.get(i);
            if(t.a < A)
               a = t;
            if(t.a <= B)
               b = t;
            else
               break;
        }
        
        return Long.toString(b.c-a.c);
    }
    
    public static void initSmall() {
        int max = 10000000;
        counts = new ArrayList<pair>();
        counts.add(new pair(0, 0));
        
        long count = 0;
        for(long i=1; i < max; i++) {
            if(isPalindrome(i) && isPalindrome(i*i)) {
               counts.add(new pair(i*i, ++count));
            }
        }
        
        initSmall = true;
    }
    
    public static boolean isPalindrome(long a) {
        long b = 0;
        long c = a;
        while(c > 0) {
            b *= 10;
            b += c % 10;
            c /= 10;
        }
            
        
        return a == b;
    }
}
