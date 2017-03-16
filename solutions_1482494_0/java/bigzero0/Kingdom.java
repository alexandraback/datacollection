package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;



class Level
{
    int one, two;

    public Level(int one, int two) 
    {        
        this.one = one;
        this.two = two;
    }
}


class LevelComparator implements Comparator<Level>
{
    @Override
    public int compare(Level o1, Level o2) 
    {
        if (o1.two < o2.two)
            return -1;
        if (o1.two > o2.two)
            return 1;
        return 0;
    }
}

public class Kingdom 
{
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('B', 0);
        
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt();
        int stars;
        Level[] need;
        boolean[] completed;
        int one, two;
        int index, index2;
        int attempts;
        
        for (int i = 0; i < t; ++i) 
        {
            String result = "Case #" + (i + 1) + ": ";
            int n = input.nextInt();
            
            need = new Level[n];
            completed = new boolean[n];
            
            for (int j = 0; j < n; ++j) 
            {
                one = input.nextInt();
                two = input.nextInt();
                
                need[j] = new Level(one, two);
            }
            
            Arrays.sort(need, new LevelComparator());
                    
            stars = 0;
            index = 0;
            attempts = 0;
            
            while (stars < (2 * n))
            {
                while (stars >= need[index].two)
                {
                    if (completed[index])
                        ++stars;
                    else
                        stars += 2;
                        
                    ++index;
                    
                    ++attempts;
                    
                    if (index == n)
                        break;
                }
                
                if (index == n)
                    break;
                
                index2 = n - 1;
                
                while (((stars < need[index2].one) || (completed[index2])) && (--index2 >= index))
                    continue;
                
                if (index2 >= index)
                {
                    ++stars;
                    completed[index2] = true;
                    ++attempts;
                }
                else
                    break;
            }
            
            if (stars == (2 * n))
                result += attempts;
            else
                result += "Too Bad";
            
            System.out.println(result);
        }
    }
}
