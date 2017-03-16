/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rq1;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Yilian Zhang
 */
public class RQ1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        
        Scanner inFile = new Scanner(new File("A-Large.in"));
        //Scanner inFile = new Scanner(new File("file.in"));
        PrintWriter outFile = new PrintWriter(new File("outlarge.file"));
        int caseN = (int) inFile.nextInt();
        System.out.println(caseN);
        long r; 
        long t; 
        double rd;
        double td;
        
        // TODO code application logic here
        for (int i = 1; i < caseN + 1; i++) {
            r= inFile.nextLong();
            t = inFile.nextLong();
            rd = (double)r;
            td = (double)t; 
            if (2*r+1>t) {
               // System.out.println("Case #" + i + ": 0");
                outFile.println("Case #" + i + ": "+ "0");
            }
            else{
               
                double su = Math.sqrt((2*rd-1)*(2*rd-1)+8*td)+2*rd-1;
                double sr = 2*td/su;
               // System.out.println("rd is "+rd);
                //System.out.println("td is "+td);
               // System.out.println("sqrt is " +su);
                int k = (int) Math.floor(sr);
               // System.out.println("Case #" + i + ": "+k);
                outFile.println("Case #" + i + ": "+ k);
            }
             
        }
        
        
        
        //close the file
         inFile.close();
         outFile.close();
        
        
    }
}
