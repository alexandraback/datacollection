/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012pa;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;


/**
 *
 * @author Fred
 */
public class CodeJam2012PA 
{

    /**
     *         type entrada.txt | java -jar Programa.jar > saida.txt
     */
    public static void main(String[] args) throws Exception 
    {        

        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        String line = buf.readLine();

        
        int j = 1;
        while((line = buf.readLine()) != null)
        {
            String[] str = line.split(" ");

            int n = Integer.valueOf(str[0]);
            int s = Integer.valueOf(str[1]);
            int p = Integer.valueOf(str[2]);

            ArrayList<Integer> triplets = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) 
            {
                triplets.add(Integer.valueOf(str[3+i]));
            }

            System.out.println("Case #"+j+": "+calcula(s, p, triplets));
            j++;
        }      
    }
    
    public static String calcula(int s, int p, ArrayList<Integer> t)
    {
        int count = 0;
        int sused = 0;
        for(Integer i : t)
        {
            if(i == 0)
            {
                if(p <= 0)
                    count++;
            }
            else if(i == 1)
            {
                if(p <= 1)
                    count++;
            }
            else if(i == 2)
            {
                if(p <= 1)
                    count++;
                else
                {
                    if(p <= 2)
                    {
                        count++;
                        sused++;
                    }
                }
            }
            else if(i == 3)
            {
                if(p <= 1)
                    count++;
                else
                {
                    if(p <= 2)
                    {
                        count++;
                        sused++;
                    }
                }
            }
            else if(i % 3 == 2) //numero 11
            {
                if( (i/3) + 1 >= p)
                    count++;
                else if((i/3) + 2 >= p)
                {
                    sused++;
                    count++;
                }
            }
            else if(i % 3 == 1) // 10
            {
                if((i/3) + 1 >= p)
                    count++;
            }
            else if(i % 3 == 0) //9
            {
                if(i/3 >= p)
                    count++;
                else if((i/3) + 1 >= p)
                {
                    count++;
                    sused++;
                }
            }
        }

        int inv = sused - s;
        if(inv <= 0)
            return String.valueOf(count);
        return String.valueOf(count-inv);
    }

}
