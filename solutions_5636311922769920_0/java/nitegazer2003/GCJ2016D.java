import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GCJ2016D
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
        BufferedReader br = new BufferedReader(new FileReader("D-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("D-small.out"));
        nextLine(br);
        int T = nextInt();
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            int K = nextInt();
            int C = nextInt();
            int S = nextInt();
            StringBuffer sb = new StringBuffer();
            for (int i = 1; i <= K; i++)
            {
                sb.append(i + " ");
            }
            pw.println("Case #" + t + ": " + sb.toString().trim());
        }
        pw.close();
    }
    
}