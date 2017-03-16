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
public class Codejamround12 {
    
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
                
                MyComparable5 my_cmp5 = new MyComparable5 ();
                MyComparable6 my_cmp6 = new MyComparable6 ();
                
                for (int i = 0; i < num_case; i++) {                    
                    input_s = l_rd.readLine();
                    
                    int lvlnum;
                    num_step_req = Integer.MAX_VALUE;
                    int num_star = 0;
                    int cur_steps = 0;
                    int two_count = 0;
                    
                    lvlnum = Integer.parseInt(input_s);
                    boolean [] one_star = new boolean [lvlnum];
                    boolean [] two_star = new boolean [lvlnum];
                    
                    for (int j = 0; j< lvlnum;j++)
                    {
                        one_star[j] = false;
                        two_star[j] = false;
                    }
                    
                    ArrayList<Level> lvl = new ArrayList <Level> (lvlnum);
                    
                    for (int j = 0; j< lvlnum; j++)
                    {
                        input_s = l_rd.readLine();
                        String[] values = input_s.split(" "); 
                        //one_star[j] = Integer.parseInt(values[0]);
                        //two_star[j] = Integer.parseInt(values[1]);  
                        lvl.add (new Level(Integer.parseInt(values[0]), Integer.parseInt(values[1])));
                    }
                    search:
                    do
                    {
                        Collections.sort (lvl, my_cmp5);
                        int len = lvl.size ();
                        if (len <= 0)
                            break;
                        //greed first
                       Level tmp_lvl = lvl.get(0);
                       //if (tmp_lvl.two_flag)
                       //{
                        //   break;
                       //}
                       //can we do this one?
                       if (num_star  >= tmp_lvl.twostar && !tmp_lvl.two_flag && !tmp_lvl.one_flag)
                       {
                           //then do it
                           cur_steps += 1;
                           if (tmp_lvl.one_flag)
                                       num_star += 1;
                                   else
                                       num_star += 2;
                           
                           tmp_lvl.two_flag = true;
                           two_count++;
                           if (two_count == lvlnum)
                           {
                               if (num_step_req > cur_steps)
                                   num_step_req = cur_steps;
                               break;
                           }
                           if (tmp_lvl.one_flag && tmp_lvl.two_flag)
                               lvl.remove (0);                                                    
                       }
                       else
                       {
                           Collections.sort (lvl, my_cmp6);
                           
                           for (int j = 0; j< len; j++)
                           {
                               Level tmp_lvl2 = lvl.get(j);
                               if (num_star >= tmp_lvl2.onestar && !tmp_lvl2.one_flag)
                                   {
                                       cur_steps += 1;                                       
                                       num_star += 1;
                                       
                                       tmp_lvl2.one_flag = true;
                                       
                                       if (tmp_lvl2.one_flag && tmp_lvl2.two_flag)
                                           lvl.remove (j); 
                                       continue search;
                                   } 
                               
                               else
                               {
                                   if (num_star >= tmp_lvl2.twostar && !tmp_lvl2.two_flag)
                               {
                                   cur_steps += 1;
                                   if (tmp_lvl2.one_flag)
                                       num_star += 1;
                                   else
                                       num_star += 2;
                                   tmp_lvl2.two_flag = true;
                                   two_count++;
                                   if (two_count == lvlnum)
                                   {
                                       if (num_step_req > cur_steps)
                                           num_step_req = cur_steps;
                                       break search;
                                   }
                                   if (tmp_lvl2.one_flag && tmp_lvl2.two_flag)
                                       lvl.remove (j);   
                                   
                                   continue search;
                               }
                                                                       
                               }                                                              
                           }
                           break;
                       }                                               
                    }
                    while (true);
                    
                    
                    //String[] values = input_s.split(" ");                    

                    //n_word = Integer.parseInt(values[0]);//Integer.parseInt();

                    pw.print ("Case #"+ (i+1)+": ");
                    
                    if (num_step_req < Integer.MAX_VALUE)
                        pw.print (num_step_req); 
                    else
                        pw.print ("Too Bad");

                    pw.println ();
                }                
                
                pw.close();
                
                l_rd.close();
            }            
        } catch (IOException e) {
            e.printStackTrace();
        }        
    }
    
    private static int num_step_req = 0;
}

class Level
{
    public int onestar;
    public int twostar;
    public boolean one_flag;
    public boolean two_flag;
    public Level (int o, int t)
    {
        onestar = o;
        twostar = t; 
        one_flag = false;
        two_flag = false;
    }
}

class MyComparable5 implements Comparator<Level>
{
    @Override
    public int compare(Level o1, Level o2)
    {
        int tmp1 = 1;
        int tmp2 = 1;
        
        int tmp1_1 = 1;
        int tmp2_2 = 1;
        
        if (!o1.one_flag)
            tmp1_1 = 0;
        
        if (!o2.one_flag)
            tmp2_2 = 0;
        
        if (!o1.two_flag)
            tmp1 = 0;
        
        if (!o2.two_flag)
            tmp2 = 0;
        
        return ((tmp1_1 - tmp2_2) * 2002 +(tmp1 - tmp2)) * 2002 + o1.twostar - o2.twostar;
    }
}

class MyComparable6 implements Comparator<Level>
{
    @Override
    public int compare(Level o1, Level o2)
    {
        int tmp1 = 1;
        int tmp2 = 1;
        
        int tmp1_1 = 1;
        int tmp2_2 = 1;
        
        if (!o1.one_flag)
            tmp1_1 = 0;
        
        if (!o2.one_flag)
            tmp2_2 = 0;
        
        if (!o1.two_flag)
            tmp1 = 0;
        
        if (!o2.two_flag)
            tmp2 = 0;
        
        return (((tmp1_1 - tmp2_2) * 2002 +(tmp2 - tmp1)) * 2002 + o1.onestar - o2.onestar)* 2002 + o2.twostar - o1.twostar;
    }
}