/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancing;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Dancing {
    
    
    public static int numDancer(double[] a, double numtoget, int s)
    {
        int iter = 0;
        for(int i = 0; i < a.length; i++)
        {
            a[i] = a[i] - numtoget;
            double c = Math.floor(a[i]/2);
            if(a[i] < 0)
            {
                
            }
            else if(c > numtoget || c == numtoget || c == numtoget - 1)
            {
                iter = iter + 1;
            }
            else if (c == numtoget - 2 && s != 0)
            {
                s = s - 1;
                iter = iter + 1;
            }
        }
        return iter;
    }

    
    
    public static void main(String[] args) throws FileNotFoundException, IOException  {
        
     FileReader theFileID = new FileReader("B-small-attempt0.in");
     BufferedReader inFile = new BufferedReader(theFileID);
     FileWriter fw = new FileWriter("output.txt");
     PrintWriter output = new PrintWriter(fw);
     String line;

     int numCases = 0;
     if((line = inFile.readLine()) != null)
         numCases = Integer.parseInt(line);

     String[] x = null;
     int n = 0, s = 0;
     double numtoget = 0;
     
     
  
     for(int i = 0; (line = inFile.readLine()) != null && i < numCases; i++) {
         
         x = line.split(" ");
         n = Integer.parseInt(x[0]);
         s = Integer.parseInt(x[1]);
         numtoget = Integer.parseInt(x[2]);
         double[] a = new double[n];
         for(int j = 3; j < x.length; j++)
         {
             a[j-3] = Integer.parseInt(x[j]);
         }
         
         int y = numDancer(a, numtoget, s);
         
         output.write("Case #"+ (i + 1) + ": " + y);
            output.println();
         
         
            }

            
            
     
     inFile.close();
     output.close();
     fw.close();
        
     double[] b = {15, 13, 11};
        System.out.println(numDancer(b, 5, 1));
        double[] c = {23, 22, 21};
        System.out.println(numDancer(c, 8, 0));
        double[] e = {8, 0};
        System.out.println(numDancer(e, 1, 1));
        double[] d = {29, 20, 8, 18, 18, 21};
        System.out.println(numDancer(d, 8, 2));
    }
}
