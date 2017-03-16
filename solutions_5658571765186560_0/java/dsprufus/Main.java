import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = Integer.parseInt(in.readLine());
        // Need to do this by case analysis
        for(int i = 1; i <= t; i++){
            String[] line = in.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int r = Integer.parseInt(line[1]);
            int c = Integer.parseInt(line[2]);
            boolean ans = true;
            // If we have an onimo bigger than 7, we can make one with a whole
            // This is the key observation that let me get the rest, because we can analyze the cases
            // under the 7-onomo pretty easily
            if(x >= 7)
                ans = false;
            // If we're larger than either side we could easily block it
            else if (x > r && x > c)
                ans = false;
            // Some multiple of our piece needs to fit in without overlapping
            else if ((r * c) % x != 0 )
                ans = false;
            // If we're too short on one side we could block off a section
            else if ((x + 1) / 2 > Math.min(r, c))
                ans = false;
            // If we made it past the above and we're not 1, 2, or 3, then gabriel can win
            else if(x == 1 || x == 2 || x == 3)
               ans = true;
            // Special cases with 4, 5 and 6 block ones
            else if (x == 4)
                // Could break this with a z
               ans = Math.min(r, c) > 2;
            else if (x == 5)
                // If we are 5 by 3 then we could stop it by doing a T piece
                ans = !(Math.min(r, c) == 3 && Math.max(r, c) == 5);
            else if (x == 6)
                // If either side is less than 3 we can block it with an L
                ans = Math.min(r, c) > 3;
            out.println("Case #" + i + ": " + (ans ? "GABRIEL" : "RICHARD"));
        }
        out.close();

    }
}
