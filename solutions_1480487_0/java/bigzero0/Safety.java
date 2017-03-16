package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Safety 
{
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('A', 0);
        
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt();
        int n, n2;
        int[] numbers;
        double[] res_numbers;
        double sum = 0, sum2;
        double one;
        String result;
        double result0;
        
        for (int i = 0; i < t; ++i) 
        {
            sum = 0;
            
            result = "Case #" + (i + 1) + ": ";
            
            n = input.nextInt();
            numbers = new int[n];
            res_numbers = new double[n];
            
            for (int j = 0; j < n; ++j)
            {
                numbers[j] = input.nextInt();
                sum += numbers[j];
            }

            one = (2 * sum) / n;
            sum2 = sum;
            n2 = n;
            
            System.out.print(result);
            
            for (int j = 0; j < n; ++j)
            {
                res_numbers[j] = (one - numbers[j]) / sum;
                
                res_numbers[j] *= 100;
                
                if (res_numbers[j] < 0)
                {
                    sum2 -= numbers[j];
                    --n2;
                }
            }
            
            one = (sum + sum2) / n2;
            
            for (int j = 0; j < n; ++j) 
            {
                if (res_numbers[j] < 0)
                    res_numbers[j] = 0;
                else
                {
                    if (sum == 0)
                        res_numbers[j] = 0;
                    else
                    {
                        res_numbers[j] = (one - numbers[j]) / sum;
                        res_numbers[j] *= 100;
                    }    
                }
            }
            
            for (int j = 0; j < n; ++j) 
            {
                System.out.printf("%f", res_numbers[j]);
                if (j < (n -1))
                    System.out.print(" ");
            }
            
            System.out.println();
        }
    }
}
