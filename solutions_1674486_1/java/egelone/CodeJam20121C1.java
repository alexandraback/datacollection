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
public class CodeJam20121C1 {
    
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
                    //String[] values = input_s.split(" ");                    

                    int N = Integer.parseInt(input_s);
                    Map m1 = new HashMap();
                    ArrayList <ItemInherite> result = new ArrayList <ItemInherite> ();
                    for (int j = 0; j< N;j++)
                    {
                        input_s = l_rd.readLine();
                        String[] values = input_s.split(" ");
                        int num = Integer.parseInt(values[0]);
                        ItemInherite tmp = new ItemInherite(j);
                        for (int m = 0 ; m< num;m++)
                        {
                            int d = Integer.parseInt(values[m+1]) -1;
                            tmp.inherit.add (d);
                            m1.put ("" + j +"to"+ d,1);  
                            System.out.println ("" + j +"to"+ d);
                        }
                             
                        tmp.cur = tmp.inherit;
                        result.add (tmp);
                    }
                    
                    boolean flag = false;
                    boolean diamand = false;
                    check:
                    do 
                    {
                        flag = false;
                        for (int j=0; j< N;j++)
                        {
                            ItemInherite tmp = result.get (j);
                            ArrayList<Integer> new_list = new ArrayList <Integer> ();
                            int size = tmp.cur.size ();
                            
                            for (int m = 0; m< size; m++)
                            {
                                int d = tmp.cur.get (m);
                                ItemInherite tmp2 = result.get (d);
                                if (tmp2.inherit.size () > 0)
                                {
                                    flag = true;
                                    int len = tmp2.inherit.size ();
                                    
                                    for (int n = 0; n < len; n++)
                                    {
                                        int f = tmp2.inherit.get(n);
                                        new_list.add (f);
                                        if (m1.containsKey("" + j +"to"+ f))
                                        {
                                            diamand = true;
                                            break check;
                                        }
                                        else
                                        {
                                            
                                            m1.put ("" + j +"to"+ f,1);
                                            System.out.println ("" + j +"to"+ f);
                                        }
                                    }
                                    
                                }
                                
                            }
                            tmp.cur = new_list;
                            
                        }
                        
                        
                        
                    }while (flag);
                    
                    
                        
                    //n_word = Integer.parseInt(values[0]);//Integer.parseInt();


                    pw.print ("Case #"+ (i+1)+": "); 
                    if (diamand)
                        pw.print ("Yes");
                    else
                                pw.print ("No");
                    pw.println ();
                }                
                
                pw.close();
                
                l_rd.close();
            }            
        } catch (IOException e) {
            e.printStackTrace();
        }        
    }
}

class ItemInherite 
{
    public int index;
    public ArrayList<Integer> inherit;
    public ArrayList<Integer> cur;
    public ItemInherite (int i)
    {
        index = i;
        inherit = new ArrayList<Integer> ();
    }
}