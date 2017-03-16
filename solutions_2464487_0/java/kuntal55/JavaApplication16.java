/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication16;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author sunil
 */
public class JavaApplication16 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        String readLine="";
        BufferedReader br = new BufferedReader(new FileReader("//home//sunil//Desktop//CODEJAM//round1//A-small-attempt0.in"));
        int no_test= Integer.parseInt(br.readLine());
        
         FileWriter output = null;

        output = new FileWriter("//home//sunil//Desktop//CODEJAM//round1//A-small-attempt0.out");
        BufferedWriter writer = new BufferedWriter(output);
        
        for(int i=0;i<no_test;i++)
        {
            String str = br.readLine();
            double area =0;
            int r= Integer.parseInt(str.split(" ")[0]);
            int T= Integer.parseInt(str.split(" ")[1]);
            int st=r;
            area = (r+1)*(r+1)-(r*r);                
            while(area<=T)
            {
                r=r+2;
                area += (r+1)*(r+1)-(r*r);                
            }
            writer.write("Case #"+(i+1)+": "+(r-st)/2);
            writer.write("\n");
            writer.flush();
                
            
        }
        
    }
}
