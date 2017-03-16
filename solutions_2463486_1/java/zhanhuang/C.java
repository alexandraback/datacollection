import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class C{
    public static void main(String[] args) throws IOException{
        File file = new File("C-large-1.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        String line = null;
        line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i = 0; i < testCaseNum; i++){
            line = fileScanner.nextLine();
            String[] boundaries = line.split(" ");
            long A = Long.parseLong(boundaries[0]);
            long B = Long.parseLong(boundaries[1]);
            
            int fairSquareNumCount = 0;
            
            long Asqrt = (long)Math.ceil(Math.sqrt(A));
            long Bsqrt = (long)Math.floor(Math.sqrt(B));
            
            for(long j = Asqrt; j <= Bsqrt; j++){
                if(isPalindromeNumber(j) && isPalindromeNumber(j*j))
                    fairSquareNumCount++;
            }
            
            writer.println("Case #" + (i+1) + ": " + fairSquareNumCount);
        }
        
        writer.close();
    }
    
    public static boolean isPalindromeNumber(long number) {
        long currentNum = number;
        long reverse = 0;
        
        while (currentNum != 0) {
            long remainder = currentNum % 10;
            reverse = reverse * 10 + remainder;
            currentNum = currentNum / 10;
        }
        if (number == reverse) {
            return true;
        }
        return false;
    }
}