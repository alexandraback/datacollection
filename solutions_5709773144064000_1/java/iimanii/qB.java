/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Jam2014;

import base.base;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek    Apr 12, 2014
 */
public class qB extends base {
    static String jam = "Jam2014";
    static String round = "Qualification";
    
    static String problem = "B";
    static String inputSize = "large";
    static String attempt = "";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+attempt+".in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) { 
            String[] t = file.poll().split(" ");
            double C = Double.parseDouble(t[0]);
            double F = Double.parseDouble(t[1]);
            double X = Double.parseDouble(t[2]);
            
            output.append("Case #").append(i+1).append(": ").append(solution(C, F, X)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-"+attempt+".out", output.toString());
        System.out.println(output);
    }
    
    public static String solution(double c, double f, double x) {
        double time = 0;
        double rate = 2;
        
        while(true) {
            double t1 = x / rate;
            double t2 = (c/rate) + (x/(rate+f));
            
            if(t1 <= t2)  // || Math.abs(t1 - t2) < 0.00000001)
               return Double.toString(time+t1);
            
            time += c/rate;
            rate += f;
        }
    }
}

