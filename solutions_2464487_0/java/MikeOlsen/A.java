import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;

public class A {
    static String in = "src/in";
    static String out = "src/out";
    
    static long r;
    static long t;
    static long answer;
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numLines = scan.nextInt();        
        for(int x = 1; x <= numLines; x++){
            r = scan.nextLong();
            t = scan.nextLong();
            
            long root = 1;
            while(root*(2*root+2*r - 1) < t){
                root *= 2;
            }
            long thing = root/10;
            while(thing > 9){
                while(root *(2*root+2*r - 1) > t){
                    root = root - thing;
                }
                thing = thing/10;
                
                
                while(root *(2*root+2*r - 1) < t){
                    root = root + thing;
                }
            }
            thing = 1;
            while(root *(2*root+2*r - 1) > t){
                root = root - thing;
            }
            
            write.write("Case #" + x + ": " + root);
            write.newLine();
        }
        scan.close();
        write.close();
    }
    
    static String generate(){
        String answer = "";
        return answer;
    }
    
}