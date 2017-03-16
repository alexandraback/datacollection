import java.util.Scanner;
import java.io.PrintWriter;
import java.io.File;
import java.util.LinkedList;

/**
 * Google CodeJam
 * n.weatherburn@gmail.com
 * 
 * @author Nicholas Weatherburn
 */

public class Round1ProblemA {
    
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter pw = new PrintWriter("Resuts-Practice-A.txt");
        int repeats = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < repeats; i++) {
            LinkedList<Integer> list = new LinkedList<Integer>();
            String word = scan.next();
            int length = scan.nextInt();
            int startOfPrevious = 0;
            int count = 0;
            for (int j = 0; j <= word.length() - length; j++) {
                boolean found = true;
                for (int k = 0; k < length; k++) {
                    if (word.charAt(k+j) == 'a' || word.charAt(k+j) == 'e' || word.charAt(k+j) == 'i' || word.charAt(k+j) == 'o' || word.charAt(k+j) == 'u') {
                        found = false;
                        j += k;
                        break;
                    }
                }
                if (found) {
                    count += (j - startOfPrevious + 1)*(word.length() - (j+length-1));
                    startOfPrevious = j+1;
                }
            }
            pw.println("Case #" + (i + 1) + ": " + count);

        }
        scan.close();
        pw.close();
        System.out.println("Finished");
    }

}