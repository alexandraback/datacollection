package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class Equal 
{
    
    
    static int N;
    static long[] numbers;
    static long left, right;
    static HashSet<Long> leftSet, rightSet;
    static Scanner input;
    static boolean flag;
    
    static void clear()
    {
        left = right = 0;
        leftSet = new HashSet<Long>();
        rightSet = new HashSet<Long>();
        flag = false;
    }
    
    static void back(int x)
    {
        String s;

        if ((flag) || (x == N))
            return;
        
        if ((left == right) && (!flag) && (left != 0))
        {
            s = "";
            
            for (long l : leftSet)
            {
                s += l;
                s += " ";
            }
            
            s = s.substring(0, s.length() - 1);
            
            System.out.println(s);
            
            s = "";
            
            for (long r : rightSet)
            {
                s += r;
                s += " ";
            }
            
            s = s.substring(0, s.length() - 1);
            
            System.out.println(s);
            
            flag = true;
        }
        
        left += numbers[x];
        leftSet.add(numbers[x]);
        back(x + 1);
        leftSet.remove(numbers[x]);
        left -= numbers[x];
        
        right += numbers[x];
        rightSet.add(numbers[x]);
        back(x + 1);
        rightSet.remove(numbers[x]);
        right -= numbers[x];
        
        back(x + 1);
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('C', 0);
        input = new Scanner(System.in);
        
        long T = input.nextInt();
        String result0;
        
        for (int i = 0; i < T; ++i) 
        {
            result0 = "Case #" + (i + 1) + ":";
            
            N = input.nextInt();
            numbers = new long[N];
            
            for (int j = 0; j < N; ++j) 
                numbers[j] = input.nextInt();
            
            clear();
            
            System.out.println(result0);
            
            back(0);
        }
        
        
    }
}
