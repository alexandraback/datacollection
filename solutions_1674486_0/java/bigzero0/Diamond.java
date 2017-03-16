package google;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Stack;

class Graph<E> extends HashMap<E, HashSet<E>>
{
    public void add(E x, E y)
    {
        HashSet<E> set = new HashSet<E>();
        
        if (containsKey(x))
            set = this.get(x);
        else
            set.clear();
        
        set.add(y);
        put(x, set);
        
        if (!containsKey(y))
            put(y, new HashSet<E>());
    }
    
    public void remove(E x, E y)
    {
        if (containsKey(x))
        {
            HashSet<E> set = get(x);
            
            set.remove(y);
            this.put(x, set);
        }
    }
    
    void addPoint(E x)
    {
        if (!containsKey(x))
            put(x, new HashSet<E>());
    }
    
    int ways(E x, E y)
    {
        int result = 0;
        
        HashSet<E> set;
        Stack<E> stack = new Stack<E>();
        
        while (true)
        {
            if (x.equals(y))
            {
                ++result;
                if (result == 2)
                    return result;
            }
            try
            {
                set = get(x);
                
                for (E e : set)
                    stack.push(e);
            }
            catch (Exception e)
            {
                
            }
            if (stack.empty())
                break;
            else
                x = stack.pop();
        }
        
        return result;
    }
    
    
}

public class Diamond 
{
    public static void main(String[] args) throws FileNotFoundException, IOException 
    {
        IO.changeGoogleIO('A', 0);
        
        Graph<Integer> graph;
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt();
        int m, n;
        boolean flag;

        for (int i = 0; i < t; ++i) 
        {
            graph = new Graph<Integer>();
            n = input.nextInt();
            flag = false;
            
            for (int j = 1; j <= n; ++j)
            {
                graph.addPoint(j);
                
                m = input.nextInt();
            
                for (int k = 0; k < m; ++k)
                    graph.add(j, input.nextInt());
                
            }
            
            for (int j = 1; j <= n; ++j) 
            {
                if (flag)
                    break;
                
                for (int k = 1; k <= n; ++k) 
                {
                    if ((graph.ways(j, k) >= 2) && (j != k))
                    {
                        flag = true;
                        break;
                    }
                }
            }
            
            System.out.print("Case #" + (i + 1) + ": ");
            
            if (flag)
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}
