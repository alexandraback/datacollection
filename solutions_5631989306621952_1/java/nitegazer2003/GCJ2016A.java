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
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            String s = next();
            boolean[] front = new boolean[s.length()];
            char highest = 'A';
            for (int i = 0; i < s.length(); i++)
            {
                char q = s.charAt(i);
                if (q >= highest)
                {
                    highest = q;
                    front[i] = true;
                }
                else
                {
                    front[i] = false;
                }
            }
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < s.length(); i++)
            {
                if (front[i])
                {
                    sb.insert(0, s.charAt(i));
                }
                else
                {
                    sb.append(s.charAt(i));
                }
            }
            pw.println("Case #" + t + ": " + sb.toString());
        }
        pw.close();
    }

    
}