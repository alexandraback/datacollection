import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class B{
    public static void main(String[] args) throws IOException{
        File file = new File("B-small-attempt0.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        
        char[][] boardArray = new char[4][4];
        
        String line = null;
        line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i = 0; i < testCaseNum; i++){
            line = fileScanner.nextLine();
            String[] dimensions = line.split(" ");
            int rowNum = Integer.parseInt(dimensions[0]);
            int columnNum = Integer.parseInt(dimensions[1]);
            
            int[][] lawnArray = new int[rowNum][columnNum];
            int[] rowMaxHeight = new int[rowNum];
            int[] columnMaxHeight = new int[columnNum];
            for(int j = 0; j < rowNum; j++){
                line = fileScanner.nextLine();
                String[] rowHeights = line.split(" ");
                for(int k = 0; k < rowHeights.length; k++){
                    lawnArray[j][k] = Integer.parseInt(rowHeights[k]);
                    if(lawnArray[j][k] > rowMaxHeight[j]){
                        rowMaxHeight[j] = lawnArray[j][k];
                    }
                    if(lawnArray[j][k] > columnMaxHeight[k]){
                        columnMaxHeight[k] = lawnArray[j][k];
                    }
                }
            }
            
            boolean possible = true;
            for(int j = 0; j < rowNum; j++){
                for(int k = 0; k < columnNum; k++){
                    if(lawnArray[j][k] < rowMaxHeight[j] && lawnArray[j][k] < columnMaxHeight[k]){
                        possible = false;
                        break;
                    }
                }
                if(!possible)
                    break;
            }
            
            
            writer.print("Case #" + (i+1) + ": ");
            if(possible){
                writer.print("YES");
            } else{
                writer.print("NO");
            }
            writer.println();
        }
        
        writer.close();
    }
}