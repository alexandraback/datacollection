import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class BullseyeLarge {
    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws IOException {
        input = new Scanner(new File(args[0]));
        output = new BufferedWriter(new FileWriter("bullseye-large.out"));

        int numCase = input.nextInt();

        for (int i = 0; i < numCase; i++) {
            long r = input.nextLong();
            long t = input.nextLong();
            
            long k = (long) Math.floor(t/(2*r));
            long diff = t-2*k*r-(2*k-1)*k;
                        
            while (diff < 0) {
            	k--;
            	diff = t-2*k*r-(2*k-1)*k;
            }
            
            output.write("Case #" + (i + 1) + ": " + k +"\n");
        }
        
        output.close();
    }
    
    
}