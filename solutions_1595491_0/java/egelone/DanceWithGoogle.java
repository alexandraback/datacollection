/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancewithgoogle;

import java.util.*;
import java.io.*;


/**
 *
 * @author Aaron
 */
public class DanceWithGoogle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        //only 3x+2, 3x can be suprise
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
                    //for each test case
                    input_s = l_rd.readLine();
                    String[] values = input_s.split(" ");
                    int num_goolge;
                    int num_s;
                    int num_p;
                    int result = 0;
                    
                    num_goolge = Integer.parseInt(values[0]);
                    num_s = Integer.parseInt(values[1]);
                    num_p = Integer.parseInt(values[2]);
                    
                    for ( int j = 0; j < num_goolge; j++)
                    {
                        int total = Integer.parseInt(values[3+j]);
                        
                        int tmp = total%3;
                        if (tmp == 0 )
                        {
                            //3x, max without using suprise is X
                            if ( total/3 >= num_p)
                                result++;
                            else
                            {
                                if (num_s>0)
                                {
                                     //special case for 0    

                                    if (total/3 > 0)
                                    {
                                        if (total/3 + 1 >= num_p)
                                        {
                                            num_s--;
                                            result++;
                                        }
                                    }                                    
                                }
                            }
                        }
                        else
                        {
                            if ( tmp == 1)
                            {
                                if ( total/3 + 1 >= num_p)
                                result++;                                
                            }
                            if (tmp == 2)
                            {
                                 //3x, max without using suprise is X
                                if ( total/3 + 1 >= num_p)
                                    result++;
                                else
                                {
                                    if (num_s>0)
                                    {
                                        if (total/3 + 2 >= num_p)
                                        {
                                            num_s--;
                                            result++;
                                        }
                                    }
                                }                                
                            }
                        }                            
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
}
