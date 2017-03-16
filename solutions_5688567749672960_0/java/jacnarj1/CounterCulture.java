import java.io.*;
import java.util.*;

public class CounterCulture
{
    public static void main (String[] args) throws IOException
    {
        //Scanner scan = new Scanner(System.in);
        Scanner scan = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
        
        int[] dist = new int[1000001];
        dist[1] = 1;
        
        for (int i=1; i<1000000; i++)
        {
            if (dist[i+1]==0 || dist[i+1]>dist[i]+1)
                dist[i+1] = dist[i]+1;
            int s = reverse(i);
            if (s>i && (dist[s]==0 || dist[s]>dist[i]+1))
                dist[s] = dist[i]+1;
        }

        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
            out.println("Case #" + i + ": " + dist[scan.nextInt()]);
        
        out.close();
        System.exit(0);
    }
    
    static int reverse(int n)
    {
        String s1 = Integer.toString(n);
        String s2 = "";
        for (int i=0; i<s1.length(); i++)
        s2 = s1.charAt(i) + s2;
        return Integer.parseInt(s2);
        
    }
}
                