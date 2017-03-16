
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 * @author Addy
 */
public final class CodeJamIO
{

    private static final String input = ".in";
    private static final String output = ".out";
    //input
    private final Scanner sc;
    private final PrintStream ps;
    private int index;
    private final int size;
    //data
    private int min;
    private int max;

    public CodeJamIO(String file)
    {
        Scanner tussensc = null;
        PrintStream tussenps = null;
        try
        {
            tussensc = new Scanner(new File(file + input));
            tussenps = new PrintStream(new File(file + output));
        }
        catch(FileNotFoundException ex)
        {
            ex.printStackTrace(System.err);
            System.exit(1);
        }
        sc = tussensc;
        ps = tussenps;
        index = 0;
        size = sc.nextInt();
        //init
        init();
        next();
    }

    public void print(String solution)
    {
        ps.println("Case #" + index + ": " + solution);
    }

    public boolean hasMore()
    {
        return index < size;
    }

    public void close()
    {
        sc.close();
        ps.close();
    }

    public void init()
    {
    }

    public void next()
    {
        min = sc.nextInt();
        max = sc.nextInt();
        index++;
    }

    public void solve()
    {
        //calc
        int opl = 0;

        int tien2 = 10;
        while(tien2 <= min)
            tien2 *= 10;
                    HashSet<Integer> set = new HashSet<>();
        for(int n = min; n < max; n++)
        {
            set.clear();
            int tien = 10;
            while(tien < n)
            {
                final int deel = n / tien;
                final int rest = n % tien;
                int m = (rest * tien2 / tien) + deel;
                if(n < m && m <= max)
                {
                    if(!set.contains(m))
                    {
                        set.add(m);
                        opl++;
                    }
                }
                tien *= 10;
            }
        }
        //print
        print(Integer.toString(opl));
    }

    public static void main(String[] args)
    {
        CodeJamIO cd = new CodeJamIO("C-large");
        cd.solve();
        while(cd.hasMore())
        {
            cd.next();
            cd.solve();
        }
        cd.close();
    }

}
