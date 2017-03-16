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
        
        File f = new File("/home/chaitanya/Documents/Code/Stones/src/Data");
        try{
            Calculate c = new Calculate();
            Scanner s = new Scanner(f);
            
            int times = Integer.parseInt(s.nextLine().trim());
            
            for(int i=0;i<times;i++){
                String[] parts = s.nextLine().trim().split(" ");
                long m = Long.parseLong(parts[0]);
                long n = Long.parseLong(parts[1]);
                long k = Long.parseLong(parts[2]);
                
                long ans = c.Ans(m, n, k);
                
                if(ans==-1)
                    System.out.println("Wrong");
                else
                    System.out.println("Case #"+(i+1)+": "+ans);
            }
        }catch(Exception e){
            System.out.println("Error");
        }
    }
}
