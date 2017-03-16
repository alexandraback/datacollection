package qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemC {
    
    public static boolean isFare(String a) {
        String aStr = a;
        boolean result = true;
        int length = aStr.length();
        int upBound = length / 2;
        for (int i = 0; i < upBound; i++) {
            if (aStr.charAt(i) != aStr.charAt(length - i - 1)) {
                result = false;
                break;
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input.txt"));
            FileWriter writer = new FileWriter(new File("output.txt"));
            
            int T = scanner.nextInt();
            scanner.nextLine();
            
            // prepare polyndroms set (square roots)
            Set<Long> fares = new HashSet<Long>();
            
            for (long i = 1; i < 10000005; i++) {
                if (isFare(Long.toString(i))) {
                    if (isFare(Long.toString(i * i))) {
                        fares.add(i);
                    }
                }
            }
  
            for (int t = 1; t <= T; t++) {
                
                long a = scanner.nextLong();
                long b = scanner.nextLong();
                if (t != T) {
                    scanner.nextLine();
                }
                long a2 = (long) Math.ceil(Math.sqrt(a));
                long b2 = (long) Math.floor(Math.sqrt(b));
                
                int counter = 0;
                for (long i = a2; i <= b2; i++) {
                    if (fares.contains(i)) {
                        counter++;
                    }
                }
                
                String result = "Case #" + t + ": " + counter;
                

                System.out.println(result);
                writer.write(result + "\n");

            }
            
            scanner.close();
            writer.close();
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        
    }
}