import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;

public class B {
    static String in = "src/in";
    static String out = "src/out";
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File(in));
        BufferedWriter writer = new BufferedWriter(new FileWriter(out));
        int numLines = sc.nextInt();        
        for(int x = 1; x <= numLines; x++){
            int X = sc.nextInt();
            int Y = sc.nextInt();
            
            boolean xReverse = false;
            if(X < 0){
                xReverse = true;
                X = -X;
            }
            
            boolean yReverse = false;
            if(Y < 0){
                yReverse = true;
                Y = -Y;
            }
            
            int xSteps = 0;
            while(xSteps*(xSteps+1)/2 < X){
                xSteps ++;
            }
            
            int missing = xSteps*(xSteps+1)/2 - X;
            
            String answer = "";
            if(!xReverse){
                for(int y = 1; y <= xSteps; y++){
                    if(y != missing){
                        answer += "E";
                    } else {
                        if(!yReverse){
                            answer += "N";
                        } else {
                            answer += "S";
                        }
                    }
                }
            } else {
                for(int y = 1; y <= xSteps; y++){
                    if(y != missing){
                        answer += "W";
                    } else {
                        if(!yReverse){
                            answer += "N";
                        } else {
                            answer += "S";
                        }
                    }
                }
            }
            
            System.out.println(Y);
            
            if(!yReverse){
                while(Y < missing){
                    Y++;
                    answer+="NS";
                }
                while(Y > missing){
                    Y--;
                    answer+="SN";
                }
            } else {
                while(Y < missing){
                    Y++;
                    answer+="SN";
                }
                while(Y > missing){
                    Y--;
                    answer+="NS";
                }
            }
            
            writer.write("Case #" + x + ": " + answer);
            writer.newLine();
        }
        sc.close();
        writer.close();
    }
    
    static String generate(){
        String answer = "";
        return answer;
    }
}