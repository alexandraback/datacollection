import java.io.*;
import java.util.*;

public class a1 {

    public static void main(String[] args)throws Exception {
      String s,fin;
        int fir,las;
        int i,j;
        BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(b.readLine());
        for(i=0;i<t;i++)
            {
            
            s=b.readLine();
            fir=s.charAt(0)-'0';
            fin=s.charAt(0)+"";
            for(j=1;j<s.length();j++)
                {
                las=s.charAt(j)-'0';
                if(fir>las)
                    {
                    fin=fin+s.charAt(j);
                }
                else
                    {
                     fir=s.charAt(j)-'0';
                      fin=s.charAt(j)+fin;
                }
            }
            System.out.println("Case #"+(i+1)+": "+fin);
        }
    }
}
