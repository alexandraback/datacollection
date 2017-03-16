import java.util.*;
import java.io.*;

public class A {
    public static void main (String args[]) throws Exception
    {
        File file = new File("C:\\Users\\charafi\\IdeaProjects\\Round_1_A_2016\\src\\A.in");
        PrintWriter out = new PrintWriter("C:\\Users\\charafi\\IdeaProjects\\Round_1_A_2016\\src\\A.out","UTF-8");
        Scanner in =new Scanner(file);
        int T=in.nextInt();
        for(int i=0;i<T;i++)
        {
            String S=in.next();
            String F="";
            F+=S.charAt(0);
            String t=F;
            for (int j=1;j<S.length();j++)
            {
                if(S.charAt(j)<F.charAt(0))
                {
                    F=F+S.charAt(j);
                }
                else
                {
                    t=""+S.charAt(j);
                    F=t.concat(F);
                }
            }

            out.printf("Case #%d: %s\n",i+1,F);
        }
        out.close();
    }
}
