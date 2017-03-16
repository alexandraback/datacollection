/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Googlerese {

    public static String convert(String x)
    {
        char[] a = new char[x.length()];
        String d = "";
        for(int i = 0; i < x.length(); i++)
        {
            a[i] = x.charAt(i);
            if(a[i] == 'a')
                a[i] = 'y';
            else if(a[i] == 'b')
                a[i] = 'h';
            else if(a[i] == 'c')
                a[i] = 'e';
            else if(a[i] == 'd')
                a[i] = 's';
            else if(a[i] == 'e')
                a[i] = 'o';
            else if(a[i] == 'f')
                a[i] = 'c';
            else if(a[i] == 'g')
                a[i] = 'v';
            else if(a[i] == 'h')
                a[i] = 'x';
            else if(a[i] == 'i')
                a[i] = 'd';
            else if(a[i] == 'j')
                a[i] = 'u';
            else if(a[i] == 'k')
                a[i] = 'i';
            else if(a[i] == 'l')
                a[i] = 'g';
            else if(a[i] == 'm')
                a[i] = 'l';
            else if(a[i] == 'n')
                a[i] = 'b';
            else if(a[i] == 'o')
                a[i] = 'k';
            else if(a[i] == 'p')
                a[i] = 'r';
            else if(a[i] == 'q')
                a[i] = 'z';
            else if(a[i] == 'r')
                a[i] = 't';
            else if(a[i] == 's')
                a[i] = 'n';
            else if(a[i] == 't')
                a[i] = 'w';
            else if(a[i] == 'u')
                a[i] = 'j';
            else if(a[i] == 'v')
                a[i] = 'p';
            else if(a[i] == 'w')
                a[i] = 'f';
            else if(a[i] == 'x')
                a[i] = 'm';
            else if(a[i] == 'y')
                a[i] = 'a';
            else if(a[i] == 'z')
                a[i] = 'q';
            d = d + a[i];
            
        }
        return d;
    }
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
       
     FileReader theFileID = new FileReader("A-small-attempt0.in");
     BufferedReader inFile = new BufferedReader(theFileID);
     FileWriter fw = new FileWriter("output.txt");
     PrintWriter output = new PrintWriter(fw);
     String line;

     int numCases = 0;
     if((line = inFile.readLine()) != null)
         numCases = Integer.parseInt(line);

     String x = null;
     
  
     for(int i = 0; (line = inFile.readLine()) != null && i < numCases; i++) {
         
         String y = convert(line);
         
         output.write("Case #"+ (i + 1) + ": " + y);
            output.println();
         
            }

            
            
     
     inFile.close();
     output.close();
     fw.close();
     System.out.println(convert("ejp mysljylc kd kxveddknmc re jsicpdrysi"));
     System.out.println(convert("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"));
     System.out.println(convert("de kr kd eoya kw aej tysr re ujdr lkgc jv"));
    }
}
        
    

