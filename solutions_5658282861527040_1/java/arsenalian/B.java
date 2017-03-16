import java.io.*;
import java.util.*;
public class B
{
    boolean isPowerOfTwo (int n)
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

    public static void main (String [] args) throws IOException
    {
        FileReader fin = new FileReader ("B.in");
        BufferedReader in = new BufferedReader (fin);
        
        int t;
        t = Integer.parseInt(in.readLine());
        
        for (int i = 0; i < t; i++)
        {
            String s = in.readLine();
            StringTokenizer st = new StringTokenizer(s);
            long a = Integer.parseInt(st.nextToken());
            long b = Integer.parseInt(st.nextToken());
            long c = Integer.parseInt(st.nextToken());
            long score = 0;
            /*for (int j = 0; j < a; j++)
            {
                for (int k = 0; k < b; k++)
                {
                    int res = k&j;
                    if (res < c)
                    {
                        score++;
                    }
                }
            }*/
            score = a*b;
            if (c < a && c < b)
            {
                for (long j = c; j < a; j++)
                {
                    for (long k = c; k < b; k++)
                    {
                        long res = j&k;
                        if (res >= c)
                        {
                            score--;
                        }
                    }
                }
            }
            System.out.println ("Case #"+(i+1)+": "+score);
        }
    }
}