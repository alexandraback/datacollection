import java.io.*;
import java.util.*;

public class Google1AB
{   public static void main(String[] args) throws Throwable
    {   new Google1AB();
    }
    
    public Google1AB() throws Throwable
    {   Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("B-large.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   
            long energyCap = in.nextLong();
            long replenish = in.nextLong();
            int numValues = in.nextInt();
            long[] values = new long[numValues];
            
            for (int j = 0; j < numValues; j++)
            {
                values[j] = in.nextLong();
            }
            
            long energy = energyCap;
            long totalValue = 0;
            for (int j = 0; j < numValues; j++)
            {
                boolean found = false;
                for (int k = 1; !found && j + k < numValues && replenish * k < energyCap; k++)
                {
                    if (values[j + k] > values[j])
                    {
                        found = true;
                        long energyToUse = energy - (energyCap - k * replenish);
                        if (energyToUse > 0)
                        {
                            energy -= energyToUse;
                            totalValue += values[j] * energyToUse;
                        }
                    }
                }
                if (!found)
                {
                    totalValue += values[j] * energy;
                    energy = 0;
                }
                energy += replenish;
                if (energy > energyCap)
                {
                    energy = energyCap;
                }
            }
              
            out.println("Case #" + (i + 1) + ": " + totalValue);
        }
        out.close();
    }
}