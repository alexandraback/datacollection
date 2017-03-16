import java.util.*;

public class C
{
    static int n;
    static boolean[][] a;
    static String best;
    static String cur;
    static boolean[] v;
    static String[] c;
    static int d;

    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int T = scan.nextInt();
        for(int ca=1;ca <= T;ca++)
        {
            n = scan.nextInt();
            int m = scan.nextInt();
            a = new boolean[n][n];
            c = new String[n];
            for(int i=0;i < n;i++)
                c[i] = scan.next();

            for(int i=0;i < m;i++)
            {
                int u = scan.nextInt() - 1;
                int v = scan.nextInt() - 1;
                a[u][v] = a[v][u] = true;
            }

            best = null;

            int[] p = new int[n];
            for(int i=0;i < n;i++)
                p[i] = i;

            while(true)
            {
                String cur = "";
                // Is permutation possible?
                Stack<Integer> h = new Stack<Integer>();
                h.push(p[0]);

                boolean yes = true;
                for(int i=1;i < n;i++)
                {
                    boolean good = false;
                    while(!h.empty())
                    {
                        if(a[h.peek()][p[i]])
                        {
                            good = true;
                            h.push(p[i]);
                            break;
                        }
                        h.pop();
                    }
                    yes &= good;
                    if(!yes) break;
                }

                if(yes)
                {
                    for(int i=0;i < n;i++)
                        cur += c[p[i]];
                    if(best == null || cur.compareTo(best) < 0)
                    {
                        best = cur;
                    }
                }

                if(has(p)) next(p);
                else break;
            }
            

            System.out.println("Case #" + ca + ": " + best);
        }
    }

    public static boolean has(int[] a)
    {
        for(int i=0;i < a.length-1;i++)
            if(a[i] < a[i+1]) return true;
        return false;
    }

    public static void next(int[] a)
    {

        int i = a.length - 2;
        while(a[i] > a[i+1])
            i--;

        int j = a.length - 1;
        while(a[j] < a[i])
            j--;

        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j = a.length-1;

        while(i < j)
        {

            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
}