import java.io.*;
import java.util.*;

public class Google1AC
{   public static void main(String[] args) throws Throwable
    {   new Google1AC();
    }
    
    public Google1AC() throws Throwable
    {   Scanner in = new Scanner(new File("C-small-1-attempt2.in"));
        PrintWriter out = new PrintWriter(new FileWriter("C-small-1-attempt2.out"));
        int numTests = in.nextInt();
        int numSets = in.nextInt();
        int numCards = in.nextInt();
        int limit = in.nextInt();
        int numProducts = in.nextInt();
        
        out.println("Case #1:");
        
        for (int i = 0; i < numSets; i++)
        {   
            Map<Integer, Integer> primePowers = new HashMap<Integer, Integer>();
            
            for (int j = 0; j < numProducts; j++)
            {
                int currProduct = in.nextInt();
                int prime = 2;
                while (prime * prime <= currProduct)
                {
                   if (currProduct % prime == 0)
                   {
                       int power = 0;
                       while (currProduct % prime == 0)
                       {
                           power++;
                           currProduct /= prime;
                       }
                       Integer wrappedPrime = new Integer(prime);
                       if (!primePowers.containsKey(prime) || power > primePowers.get(wrappedPrime).intValue())
                       {
                           primePowers.put(wrappedPrime, new Integer(power));
                       }
                   }

                   prime++;
                }
                Integer wrappedPrime = new Integer(currProduct);
                if (currProduct > 1 && !primePowers.containsKey(wrappedPrime))
                {
                    primePowers.put(wrappedPrime, new Integer(1));
                }
            }
            
            int numFives = 0;
            Integer wrappedFive = new Integer(5);
            if (primePowers.containsKey(wrappedFive))
            {
                numFives = primePowers.get(wrappedFive);
            }
            for (int j = 0; j < numFives; j++)
            {
               out.print("5");
            }
            
            int numThrees = 0;
            Integer wrappedThree = new Integer(3);
            if (primePowers.containsKey(wrappedThree))
            {
                numThrees = primePowers.get(new Integer(3));
            }
            for (int j = 0; j < numThrees; j++)
            {
               out.print("3");
            }
            
            int numTwos = 0;
            Integer wrappedTwo = new Integer(2);
            if (primePowers.containsKey(wrappedTwo))
            {
                numTwos = primePowers.get(new Integer(2));
            }
            int numLeft = numCards - numFives - numThrees;
            if (numTwos < numLeft)
            {
                numTwos = numLeft;
            }
            for (int j = 0; j < numTwos - numLeft; j++)
            {
               out.print("4");
            }
            for (int j = numTwos - numLeft; j < numLeft; j++)
            {
               out.print("2");
            }
            out.println();
        }
        out.close();
    }
}