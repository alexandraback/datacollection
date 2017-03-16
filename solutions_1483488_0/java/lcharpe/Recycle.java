/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package recycle;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Recycle {

    public static int recyclepos(String a, String b)
    {
        int iter = 0;
        int c = Integer.parseInt(a);
//        System.out.println(c);
        int d = Integer.parseInt(b);
//        System.out.println(d);
        int e = a.length();
//        System.out.println(e);
        int x = c;
        int[] s = new int[d-c];
        int[] s1 = new int[a.length()];
        for(int i = 0; i < d-c; i++)
        {
            s[i]  = x;
            x++;
        }
        for(int i = 0; i < d - c + 1; i++)
        {
            int h = Integer.parseInt(a);
            if (i != 0 && s[i-1] != 0)
            {
            for(int j = e - 1; j > 0; j--)
            {
                String f = a.substring(e-j) + a.substring(0, e-j);
                //System.out.println(f);
                int g = Integer.parseInt(f);
                //System.out.println(g);
                s1[j] = g;
                for(int y = 0; y < s1.length; y++)
                {
                    if(y == j);
                    else if(s1[y] == g)
                    {
                        g = 0;
                        break;
                    }
                }
                if(g > c && g > h && g <= d)
                    iter = iter + 1;
                //System.out.println("interations: "+ iter);
                }
            }
            if(i < d-c){
            a = String.valueOf(s[i]);
            }
        }
            
            
        return iter;
           
    }
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        
     FileReader theFileID = new FileReader("C-small-attempt0.in");
     BufferedReader inFile = new BufferedReader(theFileID);
     FileWriter fw = new FileWriter("output.txt");
     PrintWriter output = new PrintWriter(fw);
     String line;

     int numCases = 0;
     if((line = inFile.readLine()) != null)
         numCases = Integer.parseInt(line);

     String[] x = null;
     
  
     for(int i = 0; (line = inFile.readLine()) != null && i < numCases; i++) {
         
         x = line.split(" ");
         String a = x[0];
         String b = x[1];
         int y = recyclepos(a, b);
         
         
         output.write("Case #"+ (i + 1) + ": " + y);
            output.println();
         
            }

            
            
     
     inFile.close();
     output.close();
     fw.close();
        
        System.out.println(recyclepos("1", "9"));
        System.out.println(recyclepos("10", "40"));
        System.out.println(recyclepos("100", "500"));
        System.out.println(recyclepos("1111", "2222"));
        
        
    }
}
