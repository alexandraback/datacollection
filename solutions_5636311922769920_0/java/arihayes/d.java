import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class d {
    static String in = "src/D-small-attempt0.in";
    static String out = "src/d.out";
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        for(int line = 1; line <= numlines; line++) {
            int numTiles = scan.nextInt();
            int complexity = scan.nextInt();
            int maxChecked = scan.nextInt();
            
            if(numTiles != maxChecked) {
                System.err.println("SANITY CHECK ERROR; does not satisfy constraints for small input.");
            }
            
            write.write("Case #" + line + ":");
            for(int x = 0; x < numTiles; x++) {
                write.write(" " + (x + 1));
            }
            write.write("\n");
        }
        scan.close();
        write.close();
    }
}
