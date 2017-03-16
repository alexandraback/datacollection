import java.util.*;
import java.io.*;

public class D
{
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("D-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D-large.dat")));
        
        int t = scan.nextInt();
        scan.nextLine();
        for (int r=1; r<=t; r++)
        {
            int k = scan.nextInt();
            int c = scan.nextInt();
            int s = scan.nextInt();
            out.print("Case #" + r + ":");
            
            if (c*s<k)
            {
                out.println(" IMPOSSIBLE");
                continue;
            }
            
            long len = 1;
            for (int i=0; i<c; i++)
                len *= k;
                
            int i=0;
            while (i<k)
            {
                long loc=1;
                long wid = len/k;
                do
                {
                    loc += wid*(i++);
                    wid /= k;
                } while (i<k && wid>0);
                out.print(" " + loc);
            }

            out.println();
        }
        out.close();
    }
}
