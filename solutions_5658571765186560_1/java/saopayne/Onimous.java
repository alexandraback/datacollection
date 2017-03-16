
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
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
public class Onimous {
    
    
    
    public static void main (String [] args){
        
        try {

            Reader reader = new FileReader("D-large.in");
            BufferedReader bufReader = new BufferedReader(reader);
            String x = bufReader.readLine();
            int numOfTestCases = Integer.parseInt(x);

            File file = new File("ominous_large.out");
            FileWriter writer = new FileWriter(file);
            for (int i = 1; i <= numOfTestCases; i++) {
                String[] in = bufReader.readLine().split(" ");
                int X = Integer.parseInt(in[0]);
                int R = Integer.parseInt(in[1]);
                int C = Integer.parseInt(in[2]);
                boolean ans = true;

                if (X >= 7){
                    ans = false;
                 }
                else if( X > R && X > C){
                    ans = false;
                }
                else if (R * C % X != 0){
                    ans = false;  
                  }
                else if (Math.floor((X + 1)/2) > Math.min(R, C)){
                    ans = false;
                }
                else if (X==1 || X== 2 || X==3){
                    ans = true;
                }
                else if (X == 4){
                    ans = Math.min(R, C) > 2;
                }
                else if (X == 5){
                    ans = (!(Math.min(R, C) == 3 && Math.max(R, C) == 5));
                }
                else if (X == 6){
                    ans = Math.min(R, C) > 3;
                }
                
                if(ans){
                    writer.write("Case #" + i + ": " + "GABRIEL" + "\n");
                }else{
                    writer.write("Case #" + i + ": " + "RICHARD" + "\n");
                }
    

            }
            writer.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(StandingOvation.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(StandingOvation.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
       
}
