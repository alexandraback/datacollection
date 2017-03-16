import java.util.*;
import java.io.*;

public class A
{
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.dat")));
        
        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
        {
            int n = scan.nextInt();
            int m, cur = n;
            out.print("Case #"+i+": ");
            boolean[] seen = new boolean[10];
            int cnt=0;
            
            if (n==0)
            {
                out.println("INSOMNIA");
            }
            else
            {
                cur = n;
                while (true)
                {
                    m = cur;
                    do
                    {
                        if (!seen[m%10])
                        {
                            seen[m%10] = true;
                            cnt++;
                        }
                        m /= 10;
                    } while (m>0);
                    if (cnt==10)
                        break;
                    cur += n;
                }
                out.println(cur);
            }
        }
        out.close();
    }
}
