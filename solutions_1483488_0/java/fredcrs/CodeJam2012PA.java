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
            String[] l = line.split(" ");

            System.out.println("Case #"+j+": "+count(l[0], l[1]));
            j++;
        }      
    }
    
    public static int count(String aa, String bb)
    {
        Integer a = Integer.valueOf(aa);
        Integer b = Integer.valueOf(bb);
        int count = 0;
        for (int i = a; i <= b; i++) 
        {
            count = count +  checkRec(i, a, b);
        }
        return count;
    }
    
    //Checa se é recicle pairs entre n e m
    public static int checkRec(int n, int a, int b)
    {
        ArrayList<String> rep = new ArrayList<String>();
        int count = 0;
        String v = String.valueOf(n);
        for (int i = 0; i < v.length()-1; i++) 
        {
            char aux = v.charAt(v.length()-1);
            v = v.substring(0, v.length()-1);
            v = aux+v;
            int m = Integer.valueOf(v);
            if(a <= n && n < m && m <= b && !rep.contains(v))
            {
                rep.add(v);
                count++;
            }
        }
        return count;
    }
}
