/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package coinjam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author daishan
 */
public class CoinJam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int primes[];
        int divisors[];        
        int n=16;
        int t=50;
        int bit;        
        String line,line_parts[];        
        String test="1";
        for(int i=0;i<n-2;i++){
            test+="0";            
        }
        test+="1";
        StringBuilder number = new StringBuilder(test);
        int count=0;
        boolean prime;
        long value;
        try{
            BufferedReader br = new BufferedReader(new FileReader("primes.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
            bw.write("Case #1:\n");
            primes = new int[1000];
            for(int i=0;i<100;i++){
                line=br.readLine();
                line_parts= line.split("\\s+");                
                for(int j=0;j<10;j++){                      
                    primes[10*i+j]=Integer.parseInt(line_parts[j]);
                }                
            }
            while(count<t){                
                divisors= new int[9]; 
                prime=false;
                for(int i=2;i<=10 && !prime;i++){                    
                    value=0;
                    for(int j=0;j<n;j++){
                        bit = (number.charAt(j)=='1')? 1:0;                        
                        value = value*i+bit;
                    }
                    prime=true;
                    for(int j=0;j<1000 &&prime ;j++){
                        if ((value%primes[j])==0){
                            prime=false;
                            divisors[i-2]=primes[j];
                            break;
                        }
                    }
                }
                if(!prime){
                    count++;
                    bw.write(number.toString());
                    for(int i=0;i<9;i++){
                        bw.write(" "+divisors[i]);
                    }
                    bw.write("\n");
                }
                for(int i=14;i>=1;i--){
                    if (number.charAt(i)=='0'){
                        number.setCharAt(i, '1');
                        break;
                    }
                    else{
                        number.setCharAt(i, '0');
                    }
                    
                }
            }
            br.close();
            bw.close();
        }
                
                
            
            
            
               
            
            
            
            
            
            
            
            
            
        
        catch(Exception e){
            e.printStackTrace();
        }
    }
    
}
