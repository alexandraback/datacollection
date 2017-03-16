import java.io.*;
import java.util.*;

public class Google1AA
{   public static void main(String[] args) throws Throwable
    {   new Google1AA();
    }
    
    public Google1AA() throws Throwable
    {   Scanner in = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt0.out"));
        int numTests = in.nextInt();
        
        for (int i = 0; i < numTests; i++)
        {   
            int r = in.nextInt();
            int t = in.nextInt();
            int numCircles = (int)((1.0 - 2 * r + Math.sqrt(4 * r * r - 4 * r + 1 + 8 * t))/4);
            out.println("Case #" + (i + 1) + ": " + numCircles);
        }
        out.close();
    }
}