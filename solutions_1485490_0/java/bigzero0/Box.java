package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Box 
{
    static long result;
    static long max;
    static int t;
    static int n, m;
    static long[][] A;
    static long[][] B;
   
    static void back(int index1, int index2)
    {
        long min;
        
        if ((index1 == n) || (index2 == m))
        {
            if (result > max)
                max = result;
                
            return;
        }
            
        if (A[index1][1] == B[index2][1])
        {
            min = Math.min(A[index1][0], B[index2][0]);
            
            result += min;
            A[index1][0] -= min;                
            B[index2][0] -= min;
            back(index1 + 1, index2);
            back(index1, index2 + 1);
            A[index1][0] += min;                
            B[index2][0] += min;
            result -= min;
        }
        else
        {
            back(index1 + 1, index2);
        
            back(index1, index2 + 1);
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('C', 0);
        
        Scanner input = new Scanner(System.in);
        
        t = input.nextInt();
        
        for (int i = 0; i < t; ++i) 
        {
            max = 0;
            
            System.out.print("Case #" + (i + 1) + ": ");
            
            n = input.nextInt();
            m = input.nextInt();
            A = new long[n][2];
            B = new long[m][2];
            
            for (int j = 0; j < n; ++j) 
            {
                for (int k = 0; k < 2; ++k) 
                {
                    A[j][k] = input.nextLong();
                }
            }
            
            for (int j = 0; j < m; ++j) 
            {
                for (int k = 0; k < 2; ++k) 
                {
                    B[j][k] = input.nextLong();
                }
            }
            
            result = 0;

            back(0, 0);
            
            System.out.println(max);
        }
    }
}
