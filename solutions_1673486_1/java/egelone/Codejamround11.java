/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.*;
import java.io.*;
import java.math.*;

/**
 *
 * @author Aaron
 */
public class Codejamround11 {
    
    public static void main(String[] args) {
        // TODO code application logic here

        try {
            
            File file = new File("input.txt");
            
            PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));            
            
            if (file.exists()) {
                FileReader f_rd = new FileReader(file);
                LineNumberReader l_rd = new LineNumberReader(f_rd);
                String input_s;                
                
                input_s = l_rd.readLine();
                int num_case;
                
                if (input_s != null) {
                    num_case = Integer.parseInt(input_s);
                } else {
                    throw new IllegalArgumentException("Invalid Input File");
                }
                
                
                for (int i = 0; i < num_case; i++) {                    
                    input_s = l_rd.readLine();
                    int num_typed;
                    int total_num;
                    
                    less_num_stroke = Double.MAX_VALUE;
                    
                    String[] values = input_s.split(" ");                    

                    num_typed = Integer.parseInt(values[0]);//Integer.parseInt();
                    
                    total_num = Integer.parseInt(values[1]);
                    
                    input_s = l_rd.readLine();
                    
                    //now get the percantage
                    double [] p_array = new double [num_typed];
                    double [] n_p = new double [num_typed + 1];
                    
                    String[] values2 = input_s.split(" "); 
                    
                    for (int j = 0; j< num_typed; j++)
                        p_array[j] = Double.parseDouble(values2[j]);
                    
                    double [] result_stroke = new double [num_typed+2];
                    
                    double total = 1;
                    for (int j = 0; j< num_typed;j++)
                    {
                        total *= p_array[j];
                    }
                    
                    //n_p[0] = 1 -p_array[0];
                    double tmp = 1;
                    for (int j = 0; j< num_typed; j++)
                    {
                        n_p[j] = (1-p_array[j])* tmp;
                        tmp *= p_array[j];
                    }
                    
                    n_p[num_typed] = tmp;
                    
                    double rest_char = total_num - num_typed;
                    
                    double expect_stroke = 0;
                    //j is number of backspace
                    for (int j = 0; j <= num_typed; j++)
                    {
                        
                        double tmp_p = 0;
                        
                        for (int m = 0; m< num_typed - j; m++)
                            tmp_p +=  n_p[m];
                        
                        expect_stroke  = (j + j + rest_char + 1) * (1 - tmp_p) + (tmp_p)*(j + j + rest_char + total_num + 2);
                        
                        if (expect_stroke < less_num_stroke)
                            less_num_stroke = expect_stroke;
                    }
                    
                    //return right away
                    double r_away = 2 + total_num;
                    
                    if (r_away < less_num_stroke)
                            less_num_stroke = r_away;
                    
                    
                    System.out.println (" less " + less_num_stroke);
                    pw.print ("Case #"+ (i+1)+": ");
                    pw.format ("%.6f", less_num_stroke);

                    pw.println ();
                }                
                
                pw.close();
                
                l_rd.close();
            }            
        } catch (IOException e) {
            e.printStackTrace();
        }        
    }
    
    private static double less_num_stroke = 0;
}
