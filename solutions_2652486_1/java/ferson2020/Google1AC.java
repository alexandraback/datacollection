import java.io.*;
import java.util.*;

public class Google1AC
{   public static void main(String[] args) throws Throwable
    {   new Google1AC();
    }
    
    public Google1AC() throws Throwable
    {   Scanner in = new Scanner(new File("C-small-2-attempt1.in"));
        PrintWriter out = new PrintWriter(new FileWriter("C-small-2-attempt1.out"));
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
                Long currProduct = in.nextLong();
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
                Integer wrappedPrime = new Integer(new Long(currProduct).intValue());
                if (currProduct > 1 && !primePowers.containsKey(wrappedPrime))
                {
                    primePowers.put(wrappedPrime, new Integer(1));
                }
            }
            
            int numSevens = 0;
            Integer wrappedSeven = new Integer(7);
            if (primePowers.containsKey(wrappedSeven))
            {
                numSevens = primePowers.get(wrappedSeven);
            }
            for (int j = 0; j < numSevens; j++)
            {
               out.print("7");
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
            
            int numTwos = 0;
            Integer wrappedTwo = new Integer(2);
            if (primePowers.containsKey(wrappedTwo))
            {
                numTwos = primePowers.get(new Integer(2));
            }
            
            int numLeft = numCards - numSevens - numFives - numThrees;
            if (numTwos < numLeft)
            {
                numTwos = numLeft;
            }
            
            for (int j = 0; j < numThrees; j++)
            {
               if (numTwos > numLeft)
               {
                   out.print("6");
                   numTwos--;
               }
               else
               {
                   out.print("3");
               }
            }
            
            int numEights = (numTwos - numLeft) / 2;
            for (int j = 0; j < numEights; j++)
            {
               out.print("8");
            }
            numTwos -= numEights * 3;
            numLeft -= numEights;
            
            int numFours = numTwos - numLeft;
            for (int j = 0; j < numFours; j++)
            {
               out.print("4");
            }
            numTwos -= numFours * 2;
            numLeft -= numFours;
            
            for (int j = 0; j < numLeft; j++)
            {
               out.print("2");
            }
            
            out.println();
        }
        out.close();
    }
}