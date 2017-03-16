import java.util.*;
import java.io.*;

public class R2A
{
    public static void main (String[] args) throws IOException
    {
        Scanner scan = new Scanner(new File("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
        
        int t = scan.nextInt();
        for (int i=1; i<=t; i++)
        {
            String s = scan.next().toUpperCase();
            int[] cnt = new int[200];
            for (int j=0; j<s.length(); j++)
            {
                cnt[s.charAt(j)]++;
            }
            int[] ans = new int[11];
            ans[8]=cnt['G'];
            ans[6]=cnt['X'];
            ans[0]=cnt['Z'];
            ans[2]=cnt['W'];
            ans[4]=cnt['U'];
            ans[5]=cnt['F']-ans[4];
            ans[7]=cnt['V']-ans[5];
            ans[3]=cnt['H']-ans[8];
            ans[9]=cnt['I']-(ans[5]+ans[6]+ans[8]);
            ans[1]=cnt['O']-(ans[0]+ans[2]+ans[4]);
            out.print("Case #" + i + ": ");
            for (int j=0; j<10; j++)
                for (int k=0; k<ans[j]; k++)
                    out.print(j);
            out.println();
        }
        out.close();
    }
}
