import java.util.*;
import java.io.*;
import java.text.*;

public class TypeWriterMonkey
{
    static char[] k, s;
    static int keys, sLen, tLen, max=0, tot=0;
    static String target;
    public static void main (String[] args) throws IOException
    {
        DecimalFormat df = new DecimalFormat("0.0######");
        //Scanner scan = new Scanner(System.in);
        Scanner scan = new Scanner(new File("B-small-attempt1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt1.out")));
        int t = scan.nextInt();
        
        for (int i=1; i<=t; i++)
        {
            keys = scan.nextInt();
            tLen = scan.nextInt();
            sLen = scan.nextInt();
            max=0;
            tot=0;
            s = new char[sLen];
            k = scan.next().toCharArray();
            target = scan.next();
            int cnt=search(0);
            //System.out.println(max + " " + search(0) + " " + tot);
            out.println("Case #" + i + ": " + df.format(max-(double)cnt/tot));
            System.out.println(i);
        }
        out.close();
        System.exit(0);
    }
    
    static int search(int loc)
    {
        if (loc==sLen)
        {
            tot++;
            int cnt=0;
            String string = "";
            for (int i=0; i<sLen; i++)
                string += s[i];
            for (int i=0; i<=sLen-tLen; i++)
                if (target.equals(string.substring(i, i+tLen)))
                    cnt++;
            if (cnt>max)
            {
                max = cnt;
            }
            return cnt;
        }
        
        int sum=0;
        for (int i=0; i<keys; i++)
        {
            s[loc] = k[i];
            sum += search(loc+1);
        }
        return sum;
    }
}
