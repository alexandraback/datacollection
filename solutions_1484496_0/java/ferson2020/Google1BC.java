import java.io.*;
import java.util.*;

public class Google1BC
{   public static void main(String[] args) throws Throwable
    {   new Google1BC();
    }
    
    public Google1BC() throws Throwable
    {   Scanner in = new Scanner(new File("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new FileWriter("C-small-attempt0.out"));
        int numTests = in.nextInt();
        for (int i = 0; i < numTests; i++)
        {   int size = in.nextInt();
            int[] nums = new int[size];
            int total = 0;
            for (int j = 0; j < size; j++)
            {   nums[j] = in.nextInt();
                total += nums[j];
            }
            boolean[] found = new boolean[total];
            out.println("Case #" + (i + 1) + ":");
            int common = commonSubset(0, nums, 0, found);
            //System.out.println(common);
            if (common == -1)
            {   out.println(" impossible");
            }
            else
            {   getSubsets(0, nums, 0, common, new int[1], new int[size], 0, out);
            }
        }
        out.close();
    }

    private int commonSubset(int curr, int[] nums, int total, boolean[] found)
    {   if (curr == nums.length)
        {   if (total == 0)
            {   return -1;
            }
            if (found[total - 1])
            {   return total;
            }
            found[total - 1] = true;
            return -1;
        }
        int currRet = commonSubset(curr + 1, nums, total, found);
        if (currRet != -1)
        {   return currRet;
        }
        return commonSubset(curr + 1, nums, total + nums[curr], found);
    }
    
    private void getSubsets(int curr, int[] nums, int total, int common, int[] numFound, int[] elements, int size, PrintWriter out)
    {   if (numFound[0] >= 2)
        {   return;
        }
        if (total == common)
        {   println(elements, size, out);
            numFound[0]++;
            return;
        }
        if (curr == nums.length)
        {   return;
        }
        getSubsets(curr + 1, nums, total, common, numFound, elements, size, out);
        if (total + nums[curr] <= common)
        {   elements[size] = nums[curr];
            getSubsets(curr + 1, nums, total + nums[curr], common, numFound, elements, size + 1, out);
        }
    }
    
    private void println(int[] array, int size, PrintWriter out)
    {   for (int i = 0; i < size; i++)
        {   out.print(" " + array[i]);
        }
        out.println();
    }
}