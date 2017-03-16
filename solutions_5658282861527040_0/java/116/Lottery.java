package r1b2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class Lottery
{
    public static void main(String[] args)
    throws Exception
    {
        File file = new File("src/r1b2/in.txt");
        // System.out.println(file.getAbsolutePath());
        FileReader fr = new FileReader(file);
        BufferedReader bufferedReader = new BufferedReader(fr);
        int count = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < count; ++i)
        {
            String[] strs = bufferedReader.readLine().split(" ");
            int A = Integer.parseInt(strs[0]);
            int B = Integer.parseInt(strs[1]);
            int K = Integer.parseInt(strs[2]);
            
            // System.out.println("" + A + " " + B + " " + K);
            System.out.println("Case #" + (i + 1) + ": " + solve(A, B, K));
        }
    }
    
    private static long solve(int A, int B, int K)
    {
        long total = 0;
        for (int a = 0; a < A; a++)
        {
            for (int b = 0; b < B; b++)
            {
                for (int k = 0; k < K; k++)
                {
                    if ((a & b) == k)
                    {
                        // System.out.println("" + a + "^" + b + "==" + k);
                        total++;
                    }
                }
            }
        }
        
        return total;
    }
}
