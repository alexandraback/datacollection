import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class D
{
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("./input_small.txt"));
        PrintWriter writer = new PrintWriter("./output_small.txt");
        int nTests = scanner.nextInt();
        int k;
        int c;
        int s;
        long[] solution;
        
        for(int i = 0; i < nTests; i++)
        {
            scanner.nextLine(); //skip line (i.e., next line)
            k = scanner.nextInt();
            c = scanner.nextInt();
            s = scanner.nextInt();

            writer.print("Case #" + (i+1) +": ");            

            solution = solve(k, c);
            
            if(solution.length <= s)
            {
                for(int j = 0; j < solution.length; j++) writer.print(" " + solution[j]);
            }
            else
            {
                writer.print(" IMPOSSIBLE");
            }

            writer.println();

        }
            
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
        
        int[] x = {0,1,0,1};
        System.out.println(aBaseB(x, 5));
    }
    
    public static long[] solve(int k, int c)
    {
        int outLength;
        if(k%c == 0)
        {
            outLength = k/c;
        }
        else
        {
            outLength = k/c + 1;
        }
        long[] output = new long[outLength];
        int tempPosition;
        int i = 0;
        int outLoc = 0; //position in output
        int[] tempDigits = new int[c];
        
        //For each tile in original sequence
        while(i < k)
        {
            for(int j = 0; j < tempDigits.length; j++)
            {
                if(i < k) tempDigits[j] = i;
                i++;
                System.out.print(tempDigits[j]);
            }
            System.out.println();
            output[outLoc++] = aBaseB(tempDigits, k) + 1; //plus one for zero-index
            
            //reset tempDigits to zeros
            for(int j = 0; j < tempDigits.length; j++) tempDigits[j] = 0;
        }
        
        return output;
    }
    
    public static long aBaseB(int[] a, int b)
    {
        long output = 0;
        long baseValue = 1;
        int n = a.length;
        
        for(int i = 0; i < n; i++)
        {
            output += a[n - i - 1]*baseValue;
            baseValue *= b;
        }
        return output;
    }
}
