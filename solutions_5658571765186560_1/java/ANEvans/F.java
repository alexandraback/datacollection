import java.io.*;
import java.util.*;

public class F
{
    public static final int RICH = 0;
    public static final int GABE = 1;
    
    public static void main(String[] args) throws Exception
    {
        Scanner in = new Scanner(System.in);
        int nData = in.nextInt();
        
        for (int asdf = 0; asdf < nData; asdf++)
        {
            int x = in.nextInt();
            int r = in.nextInt();
            int c = in.nextInt();
            int winner;
            
            if (((r * c) % x != 0) || ((r < x) && (c < x)))
                winner = RICH;
            else if (x == 1)
                winner = GABE;
            else if (x == 2)
                winner = GABE;
            else if (x >= 7)
                winner = RICH;
            else  //solve the problem without answer lookup
            {
                if ((r >= x - 1) && (c % x == 0))
                    winner = GABE;
                else if ((c >= x - 1) && (r % x == 0))
                    winner = GABE;
                else
                    winner = RICH;
            }
            
            System.out.println("Case #" + (asdf+1) + ": " + (winner == GABE ? "GABRIEL" : "RICHARD"));
        }
    }
}
