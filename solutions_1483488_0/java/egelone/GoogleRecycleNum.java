/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerecyclenum;

import java.util.*;
import java.io.*;

/**
 *
 * @author Aaron
 */
public class GoogleRecycleNum {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
         try
        {
        
            File file = new File ("input.txt");
            
            PrintWriter pw = new PrintWriter (new FileWriter ("output.txt"));               
                                
            if (file.exists ())
            {
                FileReader f_rd = new FileReader (file);
                LineNumberReader l_rd = new LineNumberReader(f_rd);
                String input_s;                
                
                
                
                input_s = l_rd.readLine();
                int num_case;
                
                 if (input_s!= null)
                 {
                    num_case = Integer.parseInt (input_s);
                } else 
                 {
                    throw new IllegalArgumentException("Invalid Input File");
                }

                 
                for (int i = 0; i< num_case;i++)
                {
                    int num_a;
                    int  num_b;
                    input_s = l_rd.readLine();
                    String[] values = input_s.split(" ");
                    int result = 0;
                    
                    num_a = Integer.parseInt(values[0]);
                    num_b = Integer.parseInt(values[1]);
                    for ( int j = num_a; j<= num_b; j++)
                    {
                        result += valid_recycle(j, num_a, num_b);                        
                    }
                    
                    pw.println ("Case #"+ (i+1)+": " + result);   
                }
                
                pw.close();
                
                l_rd.close ();
            }             
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        
    }
    static int getNumTen (int input_num)
    {
        int n = 1;
        
        while (input_num/n > 0)
            n *= 10;
        
        return n/10;
    }
    static int valid_recycle (int input_num, int num_a, int num_b)
    {
        int count = 0;
        //try to recycle the number to check if it is valid
        if (input_num < 10)
            return 0;
        //input_num = 1212;
        
        int temp = getNumTen (input_num);
        ArrayList <Integer> result = new ArrayList<Integer> ();
        breakall:       
        for (int n = 10; n <= input_num; n *= 10)
        {
            int upper = input_num/n;
            int lower = input_num%n;
            if (lower == 0 || lower < n/10)
            {
                temp = temp/10;
                continue;
            }
            int n_num = lower*temp + upper;
            
            if (n_num >= num_a && n_num <= num_b && n_num > input_num)
            {
                //System.out.println ("Getnerate " + input_num +  " ==> " + n_num);
                int len = result.size();
                for (int i = 0; i < len; i++)
                {
                    if (n_num == result.get(i))
                    {
                        temp = temp/10;
                        continue breakall;
                    }
                }
                result.add (n_num);
                count++;
            }
            temp = temp/10;
        }
        
        
        return count;        
    }
}
