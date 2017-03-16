import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.util.*;

public class GCJ2016B
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
        BufferedReader br = new BufferedReader(new FileReader("B-small.in"));
        PrintWriter pw = new PrintWriter(new File("B-small.out"));
        nextLine(br);
        int T = nextInt();
        
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            String s = next();
            int count = 0;
            for (int j = 0; j < s.length() - 1; j++)
            {
                if (s.charAt(j) != s.charAt(j+1))
                {
                    count++;
                }
            }
            if (s.charAt(s.length() - 1) == '-')
            {
                count++;
            }
            pw.println("Case #" + t + ": " + count);
        }
        pw.close();
    }
    
}