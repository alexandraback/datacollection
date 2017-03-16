package round1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemC
{
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(new File("inputs/round1c/problemC.in"));

        int numCases = sc.nextInt();

        for (int currCase = 1; currCase <= numCases; currCase++)
        {
            int n = sc.nextInt();
            int m = sc.nextInt();
            
            Temp[] a = new Temp[n];
            Temp[] b = new Temp[m];
            
            for (int i = 0; i < n; i++)
            {
                a[i] = new Temp(new BigInteger(sc.next()), sc.nextInt());
            }

            for (int i = 0; i < m; i++)
            {
                b[i] = new Temp(new BigInteger(sc.next()), sc.nextInt());
            }

            BigInteger max = maximize(0, 0, a, b, new BigInteger("0"));

            System.out.printf("Case #%s: %s\n", currCase, max);
        }
    }
    
    private static BigInteger maximize(int locA, int locB, Temp[] a, Temp[] b, BigInteger total)
    {
        if (locA >= a.length || locB >= b.length)
        {
            return total;
        }
        
        Temp currA = a[locA];
        Temp currB = b[locB];

        BigInteger maxTotal = total;

        if (currA.type == currB.type)
        {
            if (currA.num.compareTo(currB.num) < 0)
            {
                Temp[] bCopy = deepCopy(b);
                bCopy[locB].num = currB.num.subtract(currA.num);
                maxTotal = maxTotal.max(maximize(locA + 1, locB, deepCopy(a), bCopy, total.add(currA.num)));
            }
            else if (currA.num.compareTo(currB.num) > 0)
            {
                Temp[] aCopy = deepCopy(a);
                aCopy[locA].num = currA.num.subtract(currB.num);
                maxTotal = maxTotal.max(maximize(locA, locB+1, aCopy, deepCopy(b), total.add(currB.num)));
            }
            else
            {
                maxTotal = maxTotal.max(maximize(locA+1, locB+1, deepCopy(a), deepCopy(b), total.add(currB.num)));
            }
        }
        else
        {
            maxTotal = maxTotal.max(maximize(locA+1, locB, deepCopy(a), deepCopy(b), total));
            maxTotal = maxTotal.max(maximize(locA, locB+1, deepCopy(a), deepCopy(b), total));
        }


        return maxTotal;
    }
    
    private static Temp[] deepCopy(Temp[] t)
    {
        Temp[] copy = new Temp[t.length];
        
        for (int i = 0; i < t.length; i++)
        {
            copy[i] = new Temp(t[i].num, t[i].type);
        }

        return copy;
    }
}

class Temp
{
    BigInteger num;
    int type;

    public Temp(BigInteger num, int type)
    {
        this.num = num;
        this.type = type;
    }
}