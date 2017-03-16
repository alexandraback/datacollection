package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class StandingOvation {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new FileReader("A-large (3).in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");
        
        int T = in.nextInt();
        
        for (int t = 1; t <= T; t++) {
            in.nextInt();
            String s = in.next();
            int ans = minMembers(s);
           out.println("Case #" + t + ": " + ans);
           System.out.println(ans);
        }
        in.close();
        out.close();
    }
    
    public static int minMembers(String s) {
        int best = 0;
        int cumulative = 0;
        for (int i = 0; i < s.length(); i++) {
            cumulative += Integer.parseInt(s.substring(i, i+1));
            if (i - cumulative + 1> best)
                best = i - cumulative + 1;
        }
        return best;
    }
    
    
    
    
}
