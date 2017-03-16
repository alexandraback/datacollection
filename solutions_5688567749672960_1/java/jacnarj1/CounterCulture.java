import java.io.*;
import java.util.*;

public class CounterCulture
{
    static int[] dist;
    public static void main (String[] args) throws IOException
    {
        //Scanner scan = new Scanner(System.in);
        Scanner scan = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
        
        dist = new int[1000001];
        dist[1] = 1;
        
        for (int i=1; i<1000000; i++)
        {
            if (dist[i+1]==0 || dist[i+1]>dist[i]+1)
                dist[i+1] = dist[i]+1;
            int s = intReverse(i);
            if (s>i && (dist[s]==0 || dist[s]>dist[i]+1))
                dist[s] = dist[i]+1;
        }
        
        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
            out.println("Case #" + i + ": " + dist(scan.nextLong()));
        
        out.close();
        System.exit(0);
    }
    
    static long dist(long n)
    {
        if (n<10000)
            return dist[(int)n];
        if (reverse(n)==n)
            return 1+dist(n-1);
        if (n%10==0)
            return 1+dist(n-1);
        int digits = Long.toString(n).length();
        int modExp = (digits+1)/2;
        int modNum = 1;
        for (int i=0; i<modExp; i++)
            modNum *= 10;
        long diff = (n%modNum)-1;
        return diff + dist(reverse(n-diff));
    }
    
    static long reverse(long n)
    {
        String s1 = Long.toString(n);
        String s2 = "";
        for (int i=0; i<s1.length(); i++)
        s2 = s1.charAt(i) + s2;
        return Long.parseLong(s2);
    }
    
    static int intReverse(int n)
    {
        String s1 = Integer.toString(n);
        String s2 = "";
        for (int i=0; i<s1.length(); i++)
        s2 = s1.charAt(i) + s2;
        return Integer.parseInt(s2);
    }
}
                
                