
import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class C implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new C(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter(new FileWriter("src/output.txt"));
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String nextString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }
    
    HashSet<Integer> exist;
    boolean exitFlag;
    int rememberSum;
    void solve() throws IOException {
        int ct = nextInt();
        for (int t = 1; t <= ct; t++)
        {
            exitFlag = false;
            exist = new HashSet<Integer>();
            out.println("Case #" + t + ":");
            int n = nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            boolean[] used = new boolean[n];
            generate(0, used,a, 0);
            exitFlag = false;
            Arrays.fill(used, false);
            generateAgain(0, used,a, 0);
        }
    }
    
    void printResult(boolean[] used, int[] a)
    {
        for (int i =0 ; i < used.length; i++)
            if (used[i])
                out.print(a[i] + " " );
        out.println();
    }
    
    void generate(int x, boolean[] used,int[] a, int sum)
    {
        if (exitFlag)
            return;
        
        if (x == used.length)
        {
            if (exist.contains(sum))
            {
              //  out.println(sum);
                printResult(used, a);
                exitFlag = true;
                rememberSum = sum;
            }
            exist.add(sum);
            return;
        }
        
        generate(x + 1, used, a, sum);
        used[x] = true;
        generate(x + 1, used, a, sum + a[x]);
        used[x] = false;
    }
    
     void generateAgain(int x, boolean[] used,int[] a, int sum)
    {
        if (exitFlag)
            return;
        
        if (x == used.length)
        {
           // out.println("get sum " + sum);
            if (sum == rememberSum)
            {
                printResult(used, a);
                exitFlag = true;
            }
            return;
        }
        
        generateAgain(x + 1, used, a, sum);
        used[x] = true;
        generateAgain(x + 1, used, a, sum + a[x]);
        used[x] = false;
    }
}
