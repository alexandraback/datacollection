package problem2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Case
{
    private double cost; // C
    private double prod; // F
    private double goal; // X
                         
    public Case(String data)
    {
        String[] split = data.split(" ");
        cost = Double.parseDouble(split[0]);
        prod = Double.parseDouble(split[1]);
        goal = Double.parseDouble(split[2]);
    }
    
    public double solveByIterating()
    {
        return iterate(Integer.MAX_VALUE);
    }
    
    private double iterate(int maxIter)
    {
        // iteration 0
        double incomeRate = 2.0;
        // when will we reach the goal ?
        double goalTime = goal / incomeRate;
        // when would we be able to build the next factory ?
        double factoryTime = cost / incomeRate;
        
        // save the time needed if we built no factory
        double bestTime = goalTime;
        
        for (int i = 1; i < maxIter; ++i)
        {
            // the income rate we would have with i factories
            incomeRate = 2.0 + prod * i;
            // the time at which we would reach our objective
            goalTime = goal / incomeRate + factoryTime;
            // the time at which we will be able to build an additional factory
            factoryTime = cost / incomeRate + factoryTime;
            
            if (goalTime < bestTime)
            {
                bestTime = goalTime;
            }
            else
            {
                break;
            }
        }
        
        return bestTime;
    }
}
