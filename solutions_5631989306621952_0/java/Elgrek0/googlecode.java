/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Paris
 */
public class googlecode {

    public static void main(String args[]) throws FileNotFoundException, IOException {

        BufferedReader in = new BufferedReader(new FileReader("A-small-attempt2.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {
            String s = in.readLine();
            char[] c=s.toCharArray();
            
            char start=c[0];
            
            String finalstring=""+c[0];
            
            for(int k=1;k<c.length;k++){
                if(c[k]>=start){
                    start=c[k];
                    finalstring=c[k]+finalstring;
                }
                else{
                    finalstring=finalstring+c[k];
                }
                
            }
           // System.out.println("Case #" + (i + 1) + ": "+finalstring);        
            
            
            
            
            out.append("Case #" + (i + 1) + ": "+finalstring);
            out.append("\n");

        }
        out.close();

    }

}
