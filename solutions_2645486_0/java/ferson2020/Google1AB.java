import java.io.*;
import java.util.*;

public class Google1AB
{   public static void main(String[] args) throws Throwable
    {   new Google1AB();
    }
    
    public Google1AB() throws Throwable
    {   Scanner in = new Scanner(new File("B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("B-small-attempt0.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   
            int energyCap = in.nextInt();
            int replenish = in.nextInt();
            int numValues = in.nextInt();
            int[] values = new int[numValues];
            
            for (int j = 0; j < numValues; j++)
            {
                values[j] = in.nextInt();
            }
            
            int energy = energyCap;
            int totalValue = 0;
            for (int j = 0; j < numValues; j++)
            {
                boolean found = false;
                for (int k = 1; !found && j + k < numValues && k * replenish < energyCap; k++)
                {
                    if (values[j + k] > values[j])
                    {
                        found = true;
                        int energyToUse = energy - (energyCap - k * replenish);
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