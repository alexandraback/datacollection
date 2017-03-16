package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Recycled 
{
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('C', 1);
        
        Scanner input = new Scanner(System.in);
        
        int n = input.nextInt();
        int a, b;
        int x, digit;
        int len;
        int result0;
        String s;
        String result;
        
        for (int i = 0; i < n; ++i) 
        {
            result = "Case #" + (i + 1) + ": "; 
            
            a = input.nextInt();
            b = input.nextInt();
            
            result0 = 0;
            
            for (int j = a; j <= b; ++j) 
            {
                s = j + "";
                len = s.length();
                
                do
                {
                    s = s.charAt(len - 1) + s.substring(0, len - 1); 
                    
                    x = Integer.parseInt(s);
                            
                    if ((x > j) && (x >= a) && (x <= b))
                        ++result0;
                }
                while (x != j);
            }
            
            result += result0;
            
            System.out.println(result);
        }
    }
}
