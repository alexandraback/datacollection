package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Password 
{
    static int a, b;
    static double[] prob;
    
    static double keep()
    {
        double result = 0;
        double right = 1;
        
        for (double d : prob)
            right *= d;
        
        result += (b - a + 1) * right;
        result += (2 * b - a + 2) * (1 - right);
        
        return result;
    }
    
    static double back()
    {
        double result0, result = -1;
        double right = 1;
        int deleted = 0;
        
        for (double d : prob)
            right *= d;
        
        for (int i = prob.length - 1; i >= 0; --i) 
        {
            ++deleted;
            right /= prob[i];
            result0 = 0;
            result0 += (b - a + 1 + 2 * deleted) * right;
            result0 += (2 * b - a + 2 + 2 * deleted) * (1 - right);
            
            if ((result0 < result) || (result == -1))
                result = result0;
        }
        
        return result;
    }
    
    static double right()
    {
        return (b + 2);
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('A', 1);
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt();
        
        for (int i = 0; i < t; ++i) 
        {
            String result0 = "Case #" + (i + 1) + ": ";
            
            a = input.nextInt();
            b = input.nextInt();
            prob = new double[a];
            
            for (int j = 0; j < a; ++j) 
                prob[j] = input.nextDouble();
            
            System.out.print(result0);
            double min = Math.min(keep(), Math.min(back(), right()));
            System.out.printf("%f\n", min);
        }
        
    }
}
