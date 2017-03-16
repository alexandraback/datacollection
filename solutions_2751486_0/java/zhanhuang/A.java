import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.PrintWriter;

public class A{
    public static void main(String[] args) throws IOException{
        File file = new File("A-small-attempt1.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        
        String line = null;
        line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i =0; i < testCaseNum; i++){
            line = fileScanner.nextLine();
            String[] nextCase = line.split(" ");
            
            String name = nextCase[0];
            int n = Integer.parseInt(nextCase[1]);
            char[] nameCharArray = name.toCharArray();
            
            int nameLength = nameCharArray.length;
            
            int totalSubstrings = 0;
            ArrayList<Integer> substringsFound = new ArrayList<Integer>();
            int lastSubstringStart = -1;
            
            for(int j = 0; j <= (nameLength - n); j++){
                boolean consonantSubFound = true;
                for(int k = 0; k < n; k++){
                    if (nameCharArray[j+k] == 'a' || nameCharArray[j+k] == 'e' || nameCharArray[j+k] == 'i' || nameCharArray[j+k] == 'o' || nameCharArray[j+k] == 'u'){
                        consonantSubFound = false;
                    }
                }
                if(consonantSubFound){
                    totalSubstrings += (j + 1) * (nameLength - n - j + 1);
                    if(lastSubstringStart >= 0){
                        totalSubstrings -= (lastSubstringStart + 1) * (nameLength - n - j + 1);
                    }
                    lastSubstringStart = j;
                }
            }
            
            
            writer.print("Case #" + (i+1) + ": ");
            writer.print(totalSubstrings);
            writer.println();
            
        }
        
        writer.close();
    }
}