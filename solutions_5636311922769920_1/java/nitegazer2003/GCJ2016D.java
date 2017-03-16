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
        BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
        PrintWriter pw = new PrintWriter(new File("D-large.out"));
        nextLine(br);
        int T = nextInt();
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            int K = nextInt();
            int C = nextInt();
            int S = nextInt();
            StringBuffer sb = new StringBuffer();
            
            if (S * C < K)
            {
                pw.println("Case #" + t + ": IMPOSSIBLE");
                continue;
            }
            if (S == K)
            {
                for (int i = 1; i <= K; i++)
                {
                    sb.append(i + " ");
                }
                pw.println("Case #" + t + ": " + sb.toString().trim());
                continue;
            }
            long[] pows = new long[C+1];
            pows[0] = 1;
            for (int i = 1; i < C; i++)
            {
                pows[i] = pows[i-1] * K;
            }
            int ctr = 1;
            HashSet<Long> ans = new HashSet<Long>();
            for (int i = 0; i < S; i++)
            {
                long val = 0;
                for (int j = 0; j < C; j++)
                {
                    val += pows[j] * (ctr-1);
                    if (ctr < K)
                    {
                        ctr++;
                    }
                    //System.out.println(i + " " + val);
                }
                ans.add(val);
            }
            for (Long l : ans)
            {
                sb.append((l+1) + " ");
            }
            pw.println("Case #" + t + ": " + sb.toString().trim());
        }
        pw.close();
    }
    
}