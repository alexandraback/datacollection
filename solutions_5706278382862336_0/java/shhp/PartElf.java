package PartElf;

import java.io.File;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class PartElf {
    
    
    public static void main(String[] args){
        Scanner scanner = null;
        FileOutputStream outputFile = null; 
        
        try{
            File inputData = new File("src/PartElf/small.in");
            scanner = new Scanner(inputData);
            /* Firstly, read the case counts N */
            int caseNumber = scanner.nextInt();
            /* Solve cases one by one */            
            StringBuilder output = new StringBuilder();
            for(int i = 1; i <= caseNumber; i++){
                System.out.println("--------Case #" + i + "---------");   
                String[] split = scanner.next().split("/");
                long P = Long.valueOf(split[0]);
                long Q = Long.valueOf(split[1]);
                
                output.append("Case #").append(i).append(": "); 
                int generation = minGeneration(P, Q);
                output.append(generation <= 40 && generation > 0 ? generation+"\n" : "impossible\n");
                }
                
            
            outputFile = new FileOutputStream(new File("src/PartElf/output_small.txt"));
            outputFile.write(output.toString().getBytes(),0,output.toString().length());
            System.out.println(output.toString());
                        
        }       
        catch(Exception e){
            e.printStackTrace();
        }
        finally{
            try{
                if(scanner != null)
                    scanner.close();
                if(outputFile != null)
                    outputFile.close();
            }catch(Exception e){
                e.printStackTrace();
            }
            
        }
    }
    
    static boolean isPowerOfTwo(long value) {
        return (value & value-1) == 0;
    }
    
    static boolean isEven(long value) {
        return (value % 2) == 0;
    }
    
    static int minGeneration(long P, long Q) {
        if (!isEven(Q))  return -1;
        
        int generation = 0;
        boolean possible = true;
        do {
            Q >>= 1;
            ++generation; 
            if (P == Q)  break;
            if (!isEven(Q)) {
                possible = false;
                break;
            }
        } while (P < Q);
        if (P == Q) {
            return generation;
        } else if (!possible) {
            return -1;
        }
        else {
            int ancesterGene = minGeneration(P-Q, Q); 
            return ancesterGene <= 40 - generation && ancesterGene > 0 ? generation : -1;
        }
    }

}
