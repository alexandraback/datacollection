
package zad2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.in"));
        Formatter out = new Formatter(new File("output.txt"));
        
        int tests = in.nextInt();
        for(int test = 0 ; test < tests ; test++){
            int x = in.nextInt();
            int y = in.nextInt();
            out.format("Case #%d: ",test+1);
            for(int i = 0 ; i < Math.abs(x); i++){
                if(x>0){
                    out.format("WE");
                }else{
                    out.format("EW");
                }
            }
            for(int i = 0 ; i < Math.abs(y); i++){
                if(y > 0){
                    out.format("SN");
                }else{
                    out.format("NS");
                }
            }
            out.format("\n");
        }
        out.close();
    }
}
