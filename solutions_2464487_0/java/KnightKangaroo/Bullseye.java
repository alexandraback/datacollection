import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Bullseye {
    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws IOException {
        input = new Scanner(new File(args[0]));
        output = new BufferedWriter(new FileWriter("bullseye.out"));

        int numCase = input.nextInt();

        for (int i = 0; i < numCase; i++) {
            long r = input.nextLong();
            long t = input.nextLong();
            
            int k = (int) Math.floor((-2*r+1+Math.sqrt(4*r*r-4*r+1+8*t))/4);
            
            output.write("Case #" + (i + 1) + ": " + k +"\n");
        }
        
        output.close();
    }
    
    
}