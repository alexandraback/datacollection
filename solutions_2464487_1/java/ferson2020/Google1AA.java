import java.io.*;
import java.util.*;

public class Google1AA
{   public static void main(String[] args) throws Throwable
    {   new Google1AA();
    }
    
    public Google1AA() throws Throwable
    {   Scanner in = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));
        int numTests = in.nextInt();
        
        for (int i = 0; i < numTests; i++)
        {   
            double r = in.nextDouble();
            double t = in.nextDouble();
            String numCircles = new Double((1.0 - r * 2 + Math.sqrt(r * r * 4 - r * 4 + 1.0 + t * 8))/4.0).toString();
            
            if (numCircles.indexOf('.') >= 0)
            {
                numCircles = numCircles.substring(0, numCircles.indexOf('.'));
            }
              
            out.println("Case #" + (i + 1) + ": " + numCircles);
        }
        out.close();
    }
}