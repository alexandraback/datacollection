import java.io.*;
import java.util.*;
public class A
{
    boolean isPowerOfTwo (long n)
    {
      if (n == 0)
        return false;
      while (n != 1)
      {
        if (n%2 != 0)
          return false;
        n = n/2;
      }
      return true;
    }
    
    int whichPower (long n)
    {
        int ctr = 0;
        while (n!=1)
        {
            n = n/2;
            ctr++;
        }
        return ctr;
    }

    public static long gcm(long a, long b) {
        return b == 0 ? a : gcm(b, a % b);
    }
    
    public static void main (String [] args) throws IOException
    {
        FileReader fin = new FileReader ("A-large.in");
        BufferedReader in = new BufferedReader (fin);
        A ob = new A ();
        int t;
        t = Integer.parseInt(in.readLine());
        
        for (int i = 0; i < t; i++)
        {
            long p = 0;
            long q = 0;
            String s = in.readLine();
            String pa = "";
            String qa = "";
            int j = 0;
            while (s.charAt(j) != '/')
            {
                pa = pa + s.charAt(j);
                j++;
            }
            j++;
            while (j < s.length())
            {
                qa = qa + s.charAt(j);
                j++;
            }
            p = Long.parseLong(pa);
            q = Long.parseLong(qa);
            long gcm = gcm (p,q);
            p = p/gcm;
            q = q/gcm;
            
            if (ob.isPowerOfTwo (q) == false)
            {
                System.out.println ("Case #"+(i+1)+": impossible");
            }
            else
            {
                double ratio = (double)q/p;
                int start = (int)Math.ceil(ratio);
                while (!ob.isPowerOfTwo(start))
                {
                    start++;
                }
                System.out.println ("Case #"+(i+1)+": "+ob.whichPower(start));
            }
        }
    }
}
            