import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class GCJ2016C2
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
    static ArrayList<Integer>[] revedges;
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("C-large.in"));
        PrintWriter pw = new PrintWriter(new File("C-large.out"));
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
            revedges = new ArrayList[n];
            for (int i = 0; i < n; i++)
            {
                revedges[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < n; i++)
            {
                revedges[bff[i]].add(i);
            }
            boolean[] used = new boolean[n];
            int cyccount = 0;
            int bestsa = 0;
            for (int i = 0; i < n; i++)
            {
                if (used[i]) continue;
                ArrayList<Integer> nodes = new ArrayList<Integer>();
                int ptr = i;
                boolean[] chain = new boolean[n];
                while (!chain[ptr])
                {
                    chain[ptr] = true;
                    nodes.add(ptr);
                    ptr = bff[ptr];
                }
                int cyclen = 0;
                for (int j = 0; j < nodes.size(); j++)
                {
                    if (ptr == nodes.get(j))
                    {
                        cyclen = nodes.size() - j;
                        break;
                    }
                }
                //System.out.println("Starting at " + i + " found cycle " + nodes + " len " + cyclen);
                boolean[] avoid = new boolean[n];
                for (int j = nodes.size() - 1; j >= nodes.size() - cyclen; j--)
                {
                    avoid[nodes.get(j)] = true;
                }
                if (cyclen > 2)
                {
                    for (int j = nodes.size() - 1; j >= nodes.size() - cyclen; j--)
                    {
                        revdfs(used, nodes.get(j), 0, avoid);
                    }
                    bestsa = Math.max(bestsa, cyclen);
                }
                else
                {
                    int d1 = revdfs(used, nodes.get(nodes.size() - 1), 0, avoid);
                    d1 += revdfs(used, nodes.get(nodes.size() - 2), 0, avoid);
                    cyccount += d1 + 2;
                }
            }
            int ans = Math.max(bestsa, cyccount);
            pw.println("Case #" + t + ": " + ans);
        }
        pw.close();
    }
    
    static int revdfs(boolean[] used, int pos, int depth, boolean[] avoid)
    {
        int ans = depth;
        used[pos] = true;
        //System.out.println("Eliminating " + pos);
        for (Integer next : revedges[pos])
        {
            if (avoid[next]) continue;
            ans = Math.max(ans, revdfs(used, next, depth + 1, avoid));
        }
        return ans;
    }
}