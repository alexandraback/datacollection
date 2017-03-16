/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012pa;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

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
        String e = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz";
        String t = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq";
        HashMap<String, String> etot = new HashMap<String, String>();
        for (int i = 0; i < e.length(); i++) 
        {
            etot.put(String.valueOf(e.charAt(i)), String.valueOf(t.charAt(i)));            
        }
        

        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        String line = buf.readLine();
        
        int j = 1;

        while((line = buf.readLine()) != null)
        {
            String string = "";
            for (int i = 0; i < line.length(); i++) 
            {
                string = string + translate(String.valueOf(line.charAt(i)), etot);
            }
            System.out.println("Case #"+j+": "+string);
            j++;
        }      
    }
    
    
    public static String translate(String l, HashMap<String, String> etot)
    {
        return etot.get(l);
    }
}
