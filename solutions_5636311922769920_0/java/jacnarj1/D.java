import java.util.*;
import java.io.*;

public class D
{
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("D-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("D-small.dat")));
        
        int t = scan.nextInt();
        scan.nextLine();
        for (int r=1; r<=t; r++)
        {
            int k = scan.nextInt();
            int c = scan.nextInt();
            int s = scan.nextInt();
            out.print("Case #" + r + ":");
            for (int i=1; i<=k; i++)
                out.print(" " + i);
            out.println();
        }
        out.close();
    }
}
