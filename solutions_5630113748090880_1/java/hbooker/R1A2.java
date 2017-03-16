import java.util.ArrayList;
import java.util.Scanner;

public class R1A2
{
    public static void main(String[] args)
    {
        Scanner stdin = new Scanner(System.in);
        int numberOfCases = stdin.nextInt();
        
        for(int c = 0; c < numberOfCases; ++c)
        {
            int rowLength = stdin.nextInt();
            ArrayList<int[]> lines = new ArrayList();
            
            for(int i = 0; i < 2 * rowLength - 1; ++i)
            {
                int[] line = new int[rowLength];
                for(int j = 0; j < rowLength; ++j)
                {
                    line[j] = stdin.nextInt();
                }
                lines.add(line);
            }
            
            System.out.print("Case #" + (c + 1) + ":");
            
            int[] missingLine = entriesWithOddCardinality(lines, rowLength);
            
            for(int i = 0; i < rowLength; ++i)
            {
                System.out.print(" " + missingLine[i]);
            }
            System.out.println("");
        }
    }
    
    private static int largestLastEntry(ArrayList<int[]> lines, int arLength) 
    {
        int largest = lines.get(0)[arLength - 1];
        
        for(int[] line : lines)
        {
            if(line[arLength - 1] > largest)
                largest = line[arLength - 1];
        }
        
        return largest;
    }

    private static int[] entriesWithOddCardinality(ArrayList<int[]> lines, int arLength) 
    {
        int[] entryCardinality = new int[largestLastEntry(lines, arLength) + 1];
        
        for(int[] line : lines)
        {
            for(int entry : line)
            {
                ++entryCardinality[entry];
            }
        }
        
        int[] results = new int[arLength];
        int pos = 0;
        
        for(int i = 0; i < entryCardinality.length; ++i)
        {
            if(entryCardinality[i] % 2 != 0)
            {
                results[pos++] = i;
            }
        }
        
        return results;
    }
}
