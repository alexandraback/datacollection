package CodeJam2013.Round1A;

import CodeJam2013.Qualification.*;
import com.sun.xml.internal.bind.v2.runtime.unmarshaller.XsiNilLoader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ProblemB1 {
static int maxgain=0;
public static void main(String args[]) throws Exception
{
    BufferedWriter out=null;
    try
    {
    String path="C:\\Users\\SAHIL\\Documents\\NetBeansProjects\\GoogleCodeJam\\src\\CodeJam2013\\Round1A\\";

        Scanner sc=new Scanner(new File(path+"B-small-practice.in"));
        FileWriter fstream = new FileWriter(path+"B-small-practice.out");
        out = new BufferedWriter(fstream);
        int T=sc.nextInt();
        for(int i=0;i<T;i++)
        {
            maxgain=0;
            int E=sc.nextInt();
            int R=sc.nextInt();
            int N=sc.nextInt();
            int v[]=new int[N];
           // System.out.println("ERN"+E+" "+R+" "+N);
            for(int j=0;j<N;j++)
            {
                v[j]=sc.nextInt();
            }            
            solve(E,E,R,N,v,0,0);
                out.write("Case #"+(i+1)+": "+maxgain+"\n");
                System.out.println("Case #"+(i+1)+": "+maxgain+"\n");
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
static void solve(int E,int Etemp,int R,int N,int v[],int g,int i)
{
    if(i==v.length)
    {
        if(g>maxgain)
            maxgain=g;
        return;
    }
    for(int j=0;j<=Etemp;j++)
    {
        solve(E,Math.min(Etemp-j+R,E),R,N,v,g+j*v[i],i+1);
    }
}
}