import java.util.*;
import java.io.*;

public class C
{
    public static void main (String[] args) throws IOException
    {
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small.dat")));
        
        out.println("Case #1:");
        int n=16, j=50;
        
        boolean[] s = new boolean[n];
        s[n-1] = s[0] = true;
        
        int cnt=0;
        while (cnt<j)
        {
            /*
            for (int d=n-1; d>=0; d--)
                System.out.print(s[d]?1:0);
            System.out.println();*/
            long[] div = new long[11];
            boolean comp = true;
            
            // go through each base
            for (int b=2; b<=10; b++)
            {
                // generate the number in the intended base
                long m=0, pow=1;
                for (int d=0; d<n; d++) // d for digit
                {
                    if (s[d])
                        m += pow;
                    pow*=b;
                }
                //System.out.println(b + " " + m + " " + div[b]);
                // check for compositeness (find a divisor)
                if (m%2==0)
                    div[b] = 2;
                else for (long d=3; d*d<=m; d+=2) // d for divisor
                {
                    if (m%d==0)
                    {
                        div[b] = d;
                        break;
                    }
                }
                //System.out.println(b + " " + m + " " + div[b]);
                if (div[b]==0)
                {
                    comp = false;
                    break;
                }
            }
            
            if (comp)
            {
                cnt++;
                for (int d=n-1; d>=0; d--)
                    out.print(s[d]?1:0);
                for (int b=2; b<=10; b++)
                    out.print(" " + div[b]);
                out.println();
            }
            
            // generate next string
            if (!s[1])
                s[1] = true;
            else
            {
                int d=1;
                while (d<n && s[d])
                {
                    s[d] = false;
                    d++;
                }
                if (d==n)
                    break;
                else
                    s[d] = true;
            }
        }
        out.close();
    }
}
