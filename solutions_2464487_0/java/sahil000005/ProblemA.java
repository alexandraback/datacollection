package CodeJam2013.Round1A;

import CodeJam2013.Qualification.*;
import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemA {

public static void main(String args[]) throws Exception
{
    BufferedWriter out=null;
    try
    {
    String path="C:\\Users\\SAHIL\\Documents\\NetBeansProjects\\GoogleCodeJam\\src\\CodeJam2013\\Qualification\\";

        Scanner sc=new Scanner(new File(path+"A-small-practice.in"));
        FileWriter fstream = new FileWriter(path+"A-small-practice.out");
        out = new BufferedWriter(fstream);
        int T=sc.nextInt();
        for(int i=0;i<T;i++)
        {
            long r=sc.nextLong();
            long t=sc.nextLong();
            int cnt=0;
            while (true)
            {
                if((2*r+1)<=t)
                {
                    cnt++;
                    t=t-(2*r)-1;
                    r=r+2;
                }
                else
                    break;
                    
            }            
            
                out.write("Case #"+(i+1)+": "+cnt+"\n");
                //System.out.println("Case #"+(i+1)+": "+cnt+"\n");
        }
    }
    catch(Exception e)
    {
        e.printStackTrace();
    }
    finally
    {
        out.close();
    }        
}
static int dist(int x1,int y1,int x2,int y2)
{
    return (int) Math.ceil(Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
}