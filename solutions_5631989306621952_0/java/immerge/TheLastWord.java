/**
 * Created by Hojae Jung on 4/15/2016.
 */
import java.util.*;
import java.io.*;

public class TheLastWord {
    public static void main(String... args) throws Exception {
        Scanner scan = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter pout = new PrintWriter(new FileWriter(new File("output.txt")));
        int cases = Integer.parseInt(scan.nextLine());
        String word, end;
        char[] letters;
        for(int bb=0; bb<cases; bb++){
            word = scan.nextLine();
            letters = word.toCharArray();
            end = "" + letters[0];
            for(int i=1; i<letters.length; i++){
                if(end.charAt(0) > letters[i])
                    end = end + letters[i];
                else
                    end = "" + letters[i] + end;
            }
            pout.println("Case #" + (bb+1) + ": " + end.toUpperCase());
        }


        pout.close();
    }
}
