/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pancakes;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author daishan
 */
public class Pancakes {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        int tests,count;
        boolean in_plus,in_minus,in_first_minus;
        
        String pattern;
         try{
            BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
            tests = Integer.parseInt(br.readLine());
            for(int i=0;i<tests;i++){
                count=0;
                in_plus=in_minus=in_first_minus=false;
                pattern = br.readLine();
                for(int j=0;j<pattern.length();j++){
                    if(pattern.charAt(j)=='-'){
                        if(!in_plus && !in_minus && !in_first_minus){
                            in_first_minus=true;
                            count+=1;
                            continue;
                        }
                        if(in_first_minus){
                            continue;
                        }
                        if(in_plus){
                            count+=2;
                            in_plus=false;
                            in_minus=true;
                            continue;
                        }
                        if(in_minus){
                            continue;
                        }
                        
                    }
                    else{
                        in_first_minus=false;
                        in_minus=false;
                        in_plus=true;
                        continue;
                    }
                }
                bw.write("Case #"+(i+1)+": "+count+"\n");
                
                
            }
            br.close();
            bw.close();
         }
         catch(Exception e){
             e.printStackTrace();
         }
    }
    
}
