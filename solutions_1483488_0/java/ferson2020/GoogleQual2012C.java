import java.io.*;
import java.util.*;

public class GoogleQual2012C
{   public static void main(String[] args) throws Throwable
    {   new GoogleQual2012C();
    }
    
    public GoogleQual2012C() throws Throwable
    {   Scanner in = new Scanner(new File("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("C-small-attempt0.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   int a = in.nextInt();
            int b = in.nextInt();
            int total = 0;
            for (int curr = a; curr < b; curr++)
            {   int numDigits = this.numDigits(curr);
                int[] alreadySeen = new int[numDigits - 1];
                for (int numToTake = 1; numToTake < numDigits; numToTake++)
                {   int recycled = this.moveDigits(curr, numToTake);
                    if (recycled > curr && recycled <= b && !this.contains(alreadySeen, recycled))
                    {   total++;
                        alreadySeen[numToTake - 1] = recycled;
                    }
                }
            }
            out.println("Case #" + (i + 1) + ": " + total);
        }
        out.close();
    }
    
    private int numDigits(int n)
    {   int toRet = 1;
        while (n >= 10)
        {   n /= 10;
            toRet++;
        }
        return toRet;
    }
    
    private int moveDigits(int num, int numToTake)
    {   int exp = this.numDigits(num) - numToTake;
        int base = 1;
        for (int i = 0; i < numToTake; i++)
        {   base *= 10;
        }
        int otherBase = 1;
        for (int i = 0; i < exp; i++)
        {   otherBase *= 10;
        }
        return (num / base) + (num % base) * otherBase;
    }
    
    private boolean contains(int[] array, int value)
    {   for (int i = 0; i < array.length; i++)
        {   if (array[i] == value)
            {   return true;
            }
        }
        return false;
    }
}