import java.io.*;
import java.util.*;

public class GoogleQual2012B
{   public static void main(String[] args) throws Throwable
    {   new GoogleQual2012B();
    }
    
    public GoogleQual2012B() throws Throwable
    {   Scanner in = new Scanner(new File("B-small-attempt2.in"));
        PrintWriter out = new PrintWriter(new FileWriter("B-small-attempt2.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   int numGoogs = in.nextInt();
            int numSuprsLeft = in.nextInt();
            int threshhold = in.nextInt();
            int total = 0;
            for (int j = 0; j < numGoogs; j++)
            {   int currTriple = in.nextInt();
                if (maxScore(currTriple) >= threshhold)
                {   total++;
                }
                else if (numSuprsLeft > 0 && maxScoreWithSurp(currTriple) >= threshhold)
                {   total++;
                    numSuprsLeft--;
                }
            }
            out.println("Case #" + (i + 1) + ": " + total);
        }
        out.close();
    }
    
    int maxScore(int total)
    {   if (total % 3 == 0)
        {   return total / 3;
        }
        return (total / 3) + 1;
    }
    
    int maxScoreWithSurp(int total)
    {   if (total == 0)
        {   return 0;
        }
        if (total % 3 == 2)
        {   return (total / 3) + 2;
        }
        return (total / 3) + 1;
    }
}