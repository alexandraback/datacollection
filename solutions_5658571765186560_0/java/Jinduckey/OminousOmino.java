package codejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class OminousOmino {

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner in = new Scanner(new FileReader("D-small-attempt0.in"));
        PrintWriter out = new PrintWriter("output.txt", "UTF-8");

        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            int X = in.nextInt();
            int R = in.nextInt();
            int C = in.nextInt();

            boolean richardWins = richardWins(X, R, C);
            String ans;
            if (richardWins)
                ans = "RICHARD";
            else
                ans = "GABRIEL";
            
            out.println("Case #" + t + ": " + ans);
            System.out.println(ans);
        }
        in.close();
        out.close();
    }
    public static boolean richardWins(int X, int R, int C) {
        int temp = R;
        R = Math.max(R, C);
        C = Math.min(temp,  C);
        
        if (R * C % X != 0)
            return true;
        if (X > Math.max(R, C))
            return true;
        if ((X + 1) / 2 > Math.min(R, C))
            return true;
        if (X >= 7)
            return true;
        if (X == 1 || X == 2 || X == 3)
            return false;
        if (X == 4) {
            if (C == 2)
                return true;
            return false;
        }
        if (X == 5) {
            
        }
        if (X == 6) {
            
        }
        return true;
    }
    
    
    

}
