/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fractal;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author daishan
 */
public class Fractal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int tests,k,c,s;
        String line,line_parts[];
        boolean possible;
        
        try{
            BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
            tests =Integer.parseInt(br.readLine());
            for(int i=0;i<tests;i++){
                line=br.readLine();
                line_parts=line.split("\\s+");
                k= Integer.parseInt(line_parts[0]);
                c= Integer.parseInt(line_parts[1]);
                s= Integer.parseInt(line_parts[2]);
                possible=true;
                
                bw.write("Case #"+(i+1)+":");
                if(c==1 ){
                    if(k!=s){
                        possible=false;                        
                    }
                    else{
                        for(int j=0;j<k;j++){
                            bw.write(" "+(j+1));
                        }
                    }
                }
                else {
                    if(s<k-1){
                        possible=false;  
                    }
                    else{
                        for(int j=1;j<k;j++){
                            bw.write(" "+(j+1));
                        }
                    }
                }
                if(!possible){
                    bw.write(" IMPOSSIBLE");
                }
                bw.write("\n");
            }
            
            br.close();
            bw.close();
            
        }
        catch(Exception e){
            e.printStackTrace();            
        }
    }
}
