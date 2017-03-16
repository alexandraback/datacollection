
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author saopayne
 */
public class HousePancakes {
    
    
    public static int factorial(int n) {
        int fact = 1; // this  will be the result
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    
     public static void main(String [] args){
       try {
           
            File file = new File("B-large.in");
            Scanner input = new Scanner(file);
//            Reader reader = new FileReader("pancake.in");
//            BufferedReader bufReader = new BufferedReader(reader);
//            String x = bufReader.readLine();
            int numOfTestCases = Integer.parseInt(input.nextLine());
     
            File files = new File("pancakesmall.out");
            FileWriter writer = new FileWriter(files);
            for(int i = 1 ; i <= numOfTestCases; i++){
                int pa = input.nextInt();
                int [] P = new int[pa];
                for(int j = 0; j < pa; j++){
                    P[j] = input.nextInt();
                }
                int max = P[0];
                for (int counter = 1; counter < P.length; counter++)
                {
                     if (P[counter] > max)
                     {
                      max = P[counter];
                     }
                }
                int ans = max;
                int  Z = 2;
                
                 while (Z < ans){
                    int SUM = 0;
                    for(int t = 0; t < P.length; t++){
                        SUM +=Math.floor((P[t]-1)/Z);
                        
                    }
                    ans = Math.min(ans, (SUM)+Z);
                    Z += 1;
                 }
                 writer.write("Case #" + i + ": " + ans + "\n");
                
            }
            writer.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(StandingOvation.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(StandingOvation.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
