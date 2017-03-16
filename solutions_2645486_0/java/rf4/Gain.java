/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rounda;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 *
 * @author Rizal ZAF
 */
public class Gain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("B-small-attempt0.in"));
        FileWriter writer = new FileWriter("B.txt");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            
            String[] vals = br.readLine().split(" ");
            long e = Long.parseLong(vals[0]);
            long r = Long.parseLong(vals[1]);
            
            String[] vals2 = br.readLine().split(" ");
            long[] vs = new long[vals2.length];
            for(int j=0; j<vals2.length; j++){
                vs[j] = Long.parseLong(vals2[j]);
            }
            
            long max =0;
            long sum = 0;
            for(int j=0; j<vals2.length; j++){
                sum = sum + vs[j];
                if(vs[j] > max){
                    max = vs[j];
                }
            }
            
            long maxgain = (max * e) + ((sum - max)*r);
            
            
            writer.write("Case #" + (i+1) + ": " + maxgain + "\r\n");
            
        }
        
        writer.close();
    }
    
}
