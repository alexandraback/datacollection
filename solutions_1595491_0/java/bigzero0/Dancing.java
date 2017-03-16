package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Dancing 
{
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('B', 0);
        
        Scanner input = new Scanner(System.in);
        
        int T = input.nextInt();
        int N, S, p, min, now;
        int result0;
        String result;
        
        for (int i = 0; i < T; ++i) 
        {
            result = "Case #" + (i + 1) + ": ";
            
            result0 = 0;
            
            N = input.nextInt();
            S = input.nextInt();
            p = input.nextInt();
            min = 3 * (p - 1);
            
            for (int j = 0; j < N; ++j)
            {
                now = input.nextInt();
                
                if (now > min)
                    ++result0;
                else if ((now > (min - 2)) && (now > 0) && (S > 0))
                {
                    ++result0;
                    --S;
                }
            }
            
            result += result0;
            
            System.out.println(result);
        }
    }
}
