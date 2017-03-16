import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A
{
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        Scanner scanner = new Scanner(new File("./input_large.txt"));
        PrintWriter writer = new PrintWriter("./output_large.txt");
        int nTests = scanner.nextInt();
                
        for (int i=1; i<=nTests; i++) {
            scanner.nextLine();
            int n = scanner.nextInt();
            writer.println("Case #" + i + ": " + solveA(n));  
        }
        scanner.close();
        writer.close();
        long finish = System.currentTimeMillis();
        System.out.println("Time=" + (finish - start) + "ms");
    }
    
    public static String solveA(int n)
    {
        boolean[] indexSeen = new boolean[10];
        //set all to false
        for(int i = 0; i < indexSeen.length; i++) indexSeen[i] = false;
        if(n == 0)
        {
            return "INSOMNIA";
        }
        else
        {
            int output = 0;
            int i = 1;
            while(true)
            {
                output = i*n;
                int tempOutput = output;
                //System.out.print(tempOutput + ":  ");
                //for(int k = 0; k < indexSeen.length; k++) System.out.print(k + " " + indexSeen[k] + " ");
                //System.out.println();
                while(tempOutput >= 1)
                {
                    //System.out.print(" " + tempOutput%10);
                    indexSeen[tempOutput%10] = true;
                    tempOutput = tempOutput / 10;
                }
                //System.out.println();
                if(allBeenSeen(indexSeen)) return Integer.toString(output);
                i++;
            }
        }
        
    }
    
    public static boolean allBeenSeen(boolean[] indexSeen)
    {
        for(int i = 0; i < indexSeen.length; i++)
        {
            if(indexSeen[i] == false) return false;
        }
        return true;
    }
}
