import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class c {
    //static String in = "src/c.in";
    static String out = "src/c.out";
    public static void main(String[] args) throws IOException {
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        write.write("Case #1:\n");
        
        int numNeeded = 50;
        int length = 16;
        int numDone = 0;
        
        String usedStrings[] = new String[numNeeded];
        
        for(int subLength = 2; subLength < length && numDone < numNeeded; subLength++) {
            if(length % subLength == 0) {
                int innerLength = subLength - 2;
                if(innerLength == 0) {
                    //TODO?
                } else {
                    for(int inner = 0; inner < Math.pow(2, subLength - 2) && numDone < numNeeded; inner++) {
                        int subI = 1 + (inner << 1) + (1 << (subLength - 1));
                        String subS = Integer.toBinaryString(subI);
                        String str = "";
                        for(int x = 0; x < (length / subLength); x++) {
                            str += subS;
                        }
                        
                        boolean good = true;
                        for(int x = 0; x < numDone; x++) {
                            if(str.equals(usedStrings[x])) {
                                System.out.println("Paranoid justified; skipping dupe.");
                                good = false;
                            }
                        }
                        
                        if(good) {
                            write.write(str);
                            for(int x = 2; x <= 10; x++) {
                                write.write(" ");
                                write.write(Long.toString(Long.parseLong(subS, x)));
                            }
                            write.write("\n");
                            usedStrings[numDone] = str;
                            numDone++;
                        }
                    }
                }
            }
        }
        
        write.close();
    }
}
