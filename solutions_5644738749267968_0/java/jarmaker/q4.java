
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Akash
 */
public class q4 {
    public static void main(String args[])throws Exception
    {
        FileInputStream fis=new FileInputStream("input.in");
        DataInputStream dis=new DataInputStream(fis);
        FileOutputStream fos=new FileOutputStream("output.out");
        PrintWriter pw=new PrintWriter(fos);
        int n=Integer.parseInt((dis.readLine()));
        for (int i = 1; i <= n; i++) 
        {
            int len=Integer.parseInt(dis.readLine());
            List<Double> a=new ArrayList<>();
            List<Double> b=new ArrayList<>();
            StringTokenizer st=new StringTokenizer(dis.readLine());
            while(st.hasMoreTokens())
            {
                a.add(Double.parseDouble(st.nextToken()));
            }
            st=new StringTokenizer(dis.readLine());
            while(st.hasMoreTokens())
            {
                b.add(Double.parseDouble(st.nextToken()));
            }
            Collections.sort(a);
            Collections.sort(b);
            int dw=0;
            int w=0;
            int k=0;
            for (int j = 0; j < len; j++) 
            {
                //System.out.println(a.get(j)+"\t"+b.get(j));
                if(b.get(j)>a.get(k))
                {
                    w++;
                    k++;
                }
            }
            //System.out.println();
            k=0;
            for (int j = 0; j < len; j++) 
            {
                if(a.get(j)>b.get(k))
                {
                    dw++;
                    k++;
                }
                //System.out.println(a.get(j)+"\t"+b.get(len-j-1));
            }
            pw.println("Case #"+i+": "+dw+" "+(len-w));
        }
    pw.close();
    fos.close();
    }
    
}
