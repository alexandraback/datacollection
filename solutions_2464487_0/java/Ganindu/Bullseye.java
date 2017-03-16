
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Bullseye {
    
    static BufferedWriter bw;
    
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("A-small-attempt0.in"));
        bw = new BufferedWriter(new FileWriter(new File("output.txt")));
            
        int tc = sc.nextInt();
        for(int d=1;d<=tc;d++){
            bw.write("Case #"+String.valueOf(d)+": ");
            
            double r = sc.nextLong();
            double t = sc.nextLong();            
            
            double n = -(0.5*r-0.25) + Math.sqrt(((2*r-1)/16.0)*(2*r-1) + 0.5*t);
            long ni = (long)n;

            bw.write(String.valueOf(ni));
            bw.newLine();
            bw.flush();
                
        }
        sc.close();
        bw.close();
    }
    
}
