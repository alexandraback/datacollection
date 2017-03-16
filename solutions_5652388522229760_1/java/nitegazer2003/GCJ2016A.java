import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.util.*;

public class GCJ2016A
{

private static StringTokenizer st;
    
    public static void nextLine(BufferedReader br) throws IOException
    {
        st = new StringTokenizer(br.readLine());
    }
    
    public static int nextInt()
    {
        return Integer.parseInt(st.nextToken());
    }
    
    public static String next()
    {
        return st.nextToken();
    }
    
    public static long nextLong()
    {
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble()
    {
        return Double.parseDouble(st.nextToken());
    }
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter pw = new PrintWriter(new File("A-large.out"));
        nextLine(br);
        int T = nextInt();
        boolean[] seen = new boolean[10];
        int count = 10;
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            long n = nextInt();
            if (n == 0)
            {
                pw.println("Case #" + t + ": INSOMNIA");
                continue;
            }
            Arrays.fill(seen, false);
            count = 10;
            for (int i = 1; i < 10000; i++)
            {
                count -= update(seen, i * n);
                if (count == 0)
                {
                    pw.println("Case #" + t + ": " + (i * n));
                    break;
                }
            }
        }
        pw.close();
    }
    
    static int update(boolean[] seen, long num)
    {
        int count = 0;
        while (num > 0)
        {
            int rem = (int)(num % 10);
            if (!seen[rem])
            {
                seen[rem] = true;
                count++;
            }
            num /= 10;
        }
        return count;
    }

    
}