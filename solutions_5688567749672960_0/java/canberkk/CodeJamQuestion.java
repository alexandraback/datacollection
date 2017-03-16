/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamquestion;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Canberk
 */
public class CodeJamQuestion {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A-small-attempt1.in"));
            PrintWriter out = new PrintWriter("A-small-attempt1.out");

            int cases = Integer.parseInt(in.nextLine());
            int[] sh = new int[14];
            sh[0] = 0;
            sh[1] = 10;
            for (int i = 1; i<14; i++){
                int a = i/2;
                int b = i-a;
                sh[i] = sh[i-1] + (int)Math.pow(10, a) + (int)Math.pow(10, b) - 1;
            } 
            
            for (int n = 1; n <= cases; n++) {
                String answer = "Case #" + n + ": ";
                String input = in.nextLine();
                int y = 0;
                if(input.endsWith("0")){
                    y++;
                    input = (Integer.parseInt(input)-1)+"";
                }                
                int digits = input.length();
                y += sh[digits-1];
                int a = digits/2;
                if(a>0) y += Integer.parseInt(reverse(input.substring(0, a)));
                y += Integer.parseInt(input.substring(a));
                if (a>0 && (int) Math.pow(10, a - 1) == Integer.parseInt(input.substring(0, a))) {
                    y--;
                }
                out.println(answer + y);
            }

            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
    public static String reverse(String input) {
        String output = "";
        for(int i = input.length()-1; i>-1;i--){
            output += input.charAt(i);
        }
        return output;
    }
    
}
