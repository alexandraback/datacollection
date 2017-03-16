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

        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter pw = new PrintWriter(new File("B-large.out"));
        nextLine(br);
        int T = nextInt();
        for (int t = 1; t <= T; t++)
        {
            nextLine(br);
            int n = nextInt();
            ArrayList<ArrayList<Integer>> masterList = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < 2*n-1; i++)
            {
                nextLine(br);
                ArrayList<Integer> list = new ArrayList<Integer>();
                for (int j = 0; j < n; j++)
                {
                    list.add(nextInt());
                }
                masterList.add(list);
            }
            int[] count = new int[2501];
            for (int i = 0; i < masterList.size(); i++)
            {
                for (Integer j : masterList.get(i))
                {
                    count[j]++;
                }
            }
            ArrayList<Integer> leftover = new ArrayList<Integer>();
            for (int i = 0; i < count.length; i++)
            {
                if (count[i] % 2 != 0)
                {
                    leftover.add(i);
                }
            }
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < leftover.size(); i++)
            {
                sb.append(leftover.get(i) + " ");
            }
            pw.println("Case #" + t + ": " + sb.toString().trim());
        }
        pw.close();

    }

}