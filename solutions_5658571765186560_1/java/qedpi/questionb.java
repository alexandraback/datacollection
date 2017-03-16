import java.io.*;
import java.util.*;

public class questionb
{
    public static void main(String[] args) throws IOException
    {
        File f = new File("test.txt");
        Scanner in = new Scanner(f);
        PrintWriter out = new PrintWriter(new FileWriter("testout.txt"));
        int numCases = in.nextInt();
        in.nextLine();

        //problem specific
        int blocks;
        int rows, cols, product;
        String output;
        
        for(int i = 0; i < numCases; i++){
            
            blocks = in.nextInt();
            rows = in.nextInt();
            cols = in.nextInt();
            product = rows * cols;
            
            //smaller one first
            if ( rows > cols ){
                int temp = rows; rows = cols; cols = temp;
            }
            
            //in.nextLine();
            if ( blocks == 1 || (blocks == 2 && product % 2 == 0) ||
                (blocks == 3 && ( product % 3 == 0 && rows >= 2)) ||
                (blocks == 4 && ( product % 4 == 0 && rows >= 3)) ||
                (blocks == 5 && ( product % 5 == 0 && rows >= 3)) || 
                (blocks == 6 && ( product % 6 == 0 && rows >= 4))){
                    output = "GABRIEL";
                } else {
                    output = "RICHARD";
                }
            //System.out.println( blocks + " " + cols + " " + rows + " " + out);
            
            if (i == numCases - 1){ //last case
                out.print("Case #" + (i + 1) + ": " + output);
            } else {
                out.println("Case #" + (i + 1) + ": " + output);            
            }
        }
        out.close();
    }
}
