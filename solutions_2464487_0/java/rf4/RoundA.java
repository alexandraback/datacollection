/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rounda;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Rizal ZAF
 */
public class RoundA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("A-small-attempt0.in"));
        FileWriter writer = new FileWriter("A.txt");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            
            String[] vals = br.readLine().split(" ");
            long r = Long.parseLong(vals[0]);
            long t = Long.parseLong(vals[1]);
            
            r = r+1;
            
            double aa = 4 * Math.pow(r, 2) - (12 * r) + 8*t +9;
            double bb = Math.sqrt(aa) - (2*r) -1;
            double cc = bb/4;
            long ans = (long) cc +1;
            writer.write("Case #" + (i+1) + ": " + ans  + "\r\n");
            
        }
        
        writer.close();
    }
    
    
}
