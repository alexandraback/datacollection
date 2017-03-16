import java.util.Scanner;
import java.io.File;
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author chaitanya
 */
public class Main {
    public static void main(String[] args){
        
        File f = new File("/home/chaitanya/Documents/Code/Elf/src/Data");
        try{
            Calculate c = new Calculate();
            Scanner s = new Scanner(f);
            
            int times = Integer.parseInt(s.nextLine().trim());
            
            for(int i=0;i<times;i++){
                String inp[]=s.nextLine().trim().split("/");
                
                int numerator=Integer.parseInt(inp[0]);
                int denominator=Integer.parseInt(inp[1]);
                
                boolean b = c.checkPossibility(numerator, denominator);
                
                if(b){
                    System.out.println("Case #"+(i+1)+": "+c.generation(numerator, denominator));
                }
                else
                    System.out.println("Case #"+(i+1)+": impossible");
            }
        }catch(Exception e){
            System.out.println("Error");
        }
        
    }
}
