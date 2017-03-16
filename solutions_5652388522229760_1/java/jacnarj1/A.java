import java.util.*;
import java.io.*;

public class A
{
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("A-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.dat")));
        
        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
        {
            int n = scan.nextInt();
            int m, cur = n;
            System.out.print("Case #"+i+": ");
            out.print("Case #"+i+": ");
            boolean[] seen = new boolean[10];
            int cnt=0;
            
            if (n==0)
            {
                System.out.println("INSOMNIA");
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
                System.out.println(cur);
                out.println(cur);
            }
        }
        out.close();
    }
}
