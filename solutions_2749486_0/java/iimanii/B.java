/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Jam2013;

import base.*;
import java.util.Queue;

/**
 *
 * @author Ahmed Tarek
 */
public class B extends base {
        
    static String jam = "Jam2013";
    static String round = "Round1C";
    
    static String problem = "B";
    static String inputSize = "small";
    
    public static void main(String[] args) throws Exception {  
        checkDir("input/"+jam+"/"+round); 
        checkDir("output/"+jam+"/"+round);
        Queue<String> file = file("input/"+jam+"/"+round+"/"+problem+"-"+inputSize+"-attempt1.in");
        StringBuilder output = new StringBuilder(200);
        
        int T = Integer.parseInt(file.poll());
        for(int i=0; i < T && !file.isEmpty(); i++) {
            String[] l = file.poll().split(" ");
            int x = Integer.parseInt(l[0]);
            int y = Integer.parseInt(l[1]);
            
            output.append("Case #").append(i+1).append(": ").append(solutionSmall(x, y)).append("\r\n");
        }
        
        writeFile("output/"+jam+"/"+round+"/"+problem+"-"+inputSize+".out", output.toString());
        System.out.println(output);
    }
    
    public static String solutionSmall(int x, int y) {
        StringBuilder s = new StringBuilder();
        String right = "WE", left = "EW", up = "SN", down = "NS";
        
        int cx = 0;
        int cy = 0;
        int jmp = 1;
        
        /* simplest approach */
        while(cx != x && jmp <= Math.abs(x-cx)) {
           if(cx < x) {
              cx += jmp;
              s.append('E');
           } else {
              cx -= jmp;
              s.append('W');
           }
           jmp++;
        }
        
        while(cy != y && jmp <= Math.abs(y-cy)) {
           if(cy < y) {
              cy += jmp;
              s.append('N');
           } else {
              cy -= jmp;
              s.append('S');
           }
           jmp++;
        }
        
        while(cx != x) {
           if(cx < x) {
              cx++;
              s.append(right);
           } else {
              cx--;
              s.append(left);
           }
        }
        
        while(cy != y) {
           if(cy < y) {
              cy++;
              s.append(up);
           } else {
              cy--;
              s.append(down);
           }
        }
        
        System.out.println(s.length());
        if(s.length() > 500)
           System.out.println("alert");
        return s.toString();
    }
}
