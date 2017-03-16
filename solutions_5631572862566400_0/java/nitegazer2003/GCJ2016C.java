import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GCJ2016C
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
    
    static int best, n;
    static int[] bff;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new File("C-small.out"));
        nextLine(br);
        int T = nextInt();
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            n = nextInt();
            nextLine(br);
            bff = new int[n];
            System.out.println("Case " + t);
            for (int i = 0; i < n; i++)
            {
                bff[i] = nextInt() - 1;
            }
            
            best = 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dfs(new ArrayList<Integer>(), j, i))
                    {
                        best = Math.max(best, i);
                    }
                }
            }
            pw.println("Case #" + t + ": " + best);
        }
        pw.close();
    }
    
    private static boolean dfs(List<Integer> list, int pos, int depth)
    {
        if (depth == 1)
        {
            list.add(pos);
            boolean good = true;
            for (int i = 0; i < list.size(); i++)
            {
                int a = list.get(i);
                int next = i == list.size() - 1 ? list.get(0) : list.get(i+1);
                int prev = i == 0 ? list.get(list.size() - 1) : list.get(i-1);
                if (bff[a] != next && bff[a] != prev)
                {
                    good = false;
                    break;
                }
            }            
            list.remove(list.size() - 1);
            return good;
        }
        list.add(pos);
        for (int i = 0; i < n; i++)
        {
            if (list.contains(i))
            {
                continue;
            }
            
            if (bff[pos] != i && bff[i] != pos)
            {
                continue;
            }
            
            if (dfs(list, i, depth - 1))
            {
                return true;
            }
        }
        list.remove(list.size() - 1);
        return false;
    }
}