import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.PrintWriter;

public class B{
    public static void main(String[] args) throws IOException{
        File file = new File("B-small-attempt1.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        String line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i =0; i < testCaseNum; i++){
            line = fileScanner.nextLine();
            String[] nextCase = line.split(" ");
            
            int x = Integer.parseInt(nextCase[0]);
            int y = Integer.parseInt(nextCase[1]);
            
            String output = "";
            
            if(x < 0){
                for(int j = 0; j > x; j--){
                    output += "EW";
                }
            }else if(x > 0){
                for(int j = 0; j < x; j++){
                    output += "WE";
                }
            }
            if(y < 0){
                for(int j = 0; j > y; j--){
                    output += "NS";
                }
            }else if(y > 0){
                for(int j = 0; j < y; j++){
                    output += "SN";
                }
            }
            
            
            writer.print("Case #" + (i+1) + ": ");
            writer.print(output);
            writer.println();
            
        }
        
        writer.close();
    }
}