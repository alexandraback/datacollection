import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class C{
    public static void main(String[] args) throws IOException{
        File file = new File("C-small-attempt0.in");
        Scanner fileScanner = new Scanner(file);
        
        PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
        
        String line = null;
        line = fileScanner.nextLine();
        int testCaseNum = Integer.parseInt(line);
        
        for(int i = 0; i < testCaseNum; i++){
            line = fileScanner.nextLine();
            String[] boundaries = line.split(" ");
            int A = Integer.parseInt(boundaries[0]);
            int B = Integer.parseInt(boundaries[1]);
            
            int fairSquareNumCount = 0;
            
            int Asqrt = (int)Math.ceil(Math.sqrt(A));
            int Bsqrt = (int)Math.floor(Math.sqrt(B));
            
            for(int j = Asqrt; j <= Bsqrt; j++){
                if(isPalindromeNumber(j) && isPalindromeNumber(j*j))
                    fairSquareNumCount++;
            }
            
            writer.println("Case #" + (i+1) + ": " + fairSquareNumCount);
        }
        
        writer.close();
    }
    
    public static boolean isPalindromeNumber(int number) {
        int currentNum = number;
        int reverse = 0;
        
        while (currentNum != 0) {
            int remainder = currentNum % 10;
            reverse = reverse * 10 + remainder;
            currentNum = currentNum / 10;
        }
        if (number == reverse) {
            return true;
        }
        return false;
    }
}