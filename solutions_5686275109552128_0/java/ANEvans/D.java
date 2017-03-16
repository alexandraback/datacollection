import java.io.*;
import java.util.*;

public class D
{
    public static void main(String[] args) throws Exception
    {
        //precalculate the optimal number of stacks for each size
        
        
        //gather the inputs
        Scanner in = new Scanner(System.in);
        int nData = in.nextInt();
        
        for (int asdf = 0; asdf < nData; asdf++)
        {
            //gather the input
            int nstacks = in.nextInt();
            int[] pancakes = new int[nstacks];
            int highest = 0;
            
            for (int i = 0; i < nstacks; i++)
            {
                pancakes[i] = in.nextInt();
                highest = (pancakes[i] > highest ? pancakes[i] : highest);
            }
            
        //    if (asdf != 1) continue;
            
            int[] stacks = new int[highest + 1];
            
            for (int i = 0; i < nstacks; i++)
            {
                stacks[pancakes[i]]++;
            }
            
            //do the algorithm
            int answer = solve(stacks);
            
            System.out.println("Case #" + (asdf + 1) + ": " + answer);
        }
    }
    
    public static int solve(int[] stacks)
    {
        int answer = 1000000000;
        int largest = stacks.length - 1;
        int goal = 1000000000;
        int prev = 1000000000;
        
        //for (int i = 1; i < 32; i++)
        for (int i = 1; i <= largest; i++)
        {
            prev = goal;
        //    goal = (int)Math.ceil(largest / (float)i);
            goal = i;
            int cost = goal;
       //     System.out.println("analyzing prev=" + prev + " goal=" + goal);
            
            for (int j = 0; j < stacks.length; j++)
            {
                if (stacks[j] != 0)
                {
                    cost += stacks[j] * cost(j, goal);
                }
            }
            
       //     System.out.println("cost=" + cost);
            
            if (cost < answer)
            {
       //         System.out.println("looking for a target height of " + goal);
                answer = cost;
            }
        }
        
        return answer;
    }
    
    public static int cost(int size, int target)
    {
        if (target >= size)
        {
            return 0;
        }
        
        int stacks = (int)Math.ceil(size / (float)target);
        int cost = stacks - 1;
        
        return cost;
    }
}




















