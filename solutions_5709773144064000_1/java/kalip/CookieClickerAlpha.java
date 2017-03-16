import java.io.*;
import java.util.*;
class CookieClickerAlpha
{
    double C=500,F=4,X=2000;
    long i;
    PrintWriter pr;
    public static void main(String args[])throws IOException
    {
        new CookieClickerAlpha().go();
    }
    public void go2()
    {
        crum(2.0,X/2.0,0);
    }
    public void go()throws IOException
    {
        BufferedReader bf=new BufferedReader(new FileReader("large.in"));
        pr=new PrintWriter(new FileWriter("out.txt"));
        double tmp,r,t,time,L=Integer.parseInt(bf.readLine());
        StringTokenizer st;
        for(i=0;i<L;i++)
        {
            st=new StringTokenizer(bf.readLine());
            C=Double.parseDouble(st.nextToken());
            F=Double.parseDouble(st.nextToken());
            X=Double.parseDouble(st.nextToken());
            r=2.0;
            t=X/2.0;
            time=0;
            while((tmp=(C/r)+(X/(r+F)))<t&&t>0.000001d)
            {
                time+=C/r;
                t=X/(r+F);
                r=r+F;
            }
            System.out.println("Case #"+(i+1)+": "+(time+t));
            pr.println("Case #"+(i+1)+": "+(time+t));
        }
        bf.close();
        pr.close();
    }
    public void crum(double r,double t,double time)
    {
        System.out.println(r+" "+t+" "+time);
        double tmp=(C/r)+(X/(r+F));
        if(tmp<t&&t>0.000001d)
        {
            time+=C/r;
            crum(r+F,X/(r+F),time);
        }
        else
        {
            System.out.println();
            System.out.println("Case #"+(i+1)+": "+(time+t));
            pr.println("Case #"+(i+1)+": "+(time+t));
        }
    }
}