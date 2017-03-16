
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProbB {
     public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
        for (int i=1;i<=casenum;i++)
        {
            System.out.print("Case #"+i+": ");
            solve(s);
            System.out.println();
        }
    }
        static int hit=0;
         static int missed=0;
     static int x,y;
static class config{
    //int x,y;
    int rem;
    byte[][] r=new byte[200][200];
    public void sss()
    {
        for (int i=0;i<r.length;i++)
        {
            for (int j=0;j<r[i].length;j++)
                System.out.print(r[i][j]);
            System.out.println();
        }
        System.out.println("-----------");
        
    }
    public config()
    {

    }
    public config(config c)
    {
      //  x=c.x;
        //y=c.y;
        //r=(byte[][])c.r.clone();
        for (int i=0;i<c.r.length;i++)
        {
            for (int j=0;j<c.r[i].length;j++)
                r[i][j]=c.r[i][j];
        }
        
        rem=c.rem;
    }
    int centerx=r.length/2;
    
    void //List<config>
            run()
    {
   //     System.out.println("rem:"+rem);
        //sss();
        //List<config> ret=new LinkedList<config>();
        if (rem<=0)
        {
            if (r[x][y]==1) hit++;
            else missed++;
            return;
        }
        
        int i;
        for (i=r[centerx].length-1;i>=0;i--)
        {
            //System.err.println(r[centerx][i]+" "+centerx+" "+i);
            if (r[centerx][i]==1) break;
        }
        if (i==-1)
        {
            config k=new config(this);
            k.r[centerx][0]=1;
            k.rem--;
            k.run();
            return;
            //ret.add(k);
            //return ret;
        }
        //System.out.println("lehet jobbra:"+(r[centerx+1][i+1]==0) +" lehet balra:"+
          //      (r[centerx-1][i+1]==0)
            //    );
        //System.out.println("aaab:"+(centerx+1)+" "+(i+1)+" "+r[centerx+1][i+1]);
        if ( (r[centerx+1][i+1]==0) )
        //if ( (r[centerx+1][i+1]==0) )
        {
           // System.out.println("jobbra:");
            int xx=centerx,yy=i+2;
            //System.out.println("aaab:"+xx+" "+yy);
            while (yy>=0 && r[xx][yy]==0)
            {
                
                xx++;yy--;
                //System.out.println("94:"+xx+" "+yy+" "+r[xx][yy]);
            }
            //if (yy<0) 
            {xx--;yy++;}
            //System.out.println("aaa:"+xx+" "+yy);
            config k=new config(this);
            k.r[xx][yy]=1;
        //    System.out.println(xx+" "+yy);
            k.rem--;
            k.run();
           // System.out.println("up");
            //ret.add(k);
        }

                if ( (r[centerx-1][i+1]==0) )
        {
         //   System.out.println("balra:");
            int xx=centerx,yy=i+2;
            //System.out.println("aaab:"+xx+" "+yy);
            while (yy>=0 && r[xx][yy]==0)
            {
                
                xx--;yy--;
                //System.out.println("94:"+xx+" "+yy+" "+r[xx][yy]);
            }
            //if (yy<0) 
            {xx++;yy++;}
            //System.out.println("aaa:"+xx+" "+yy);
            config k=new config(this);
            k.r[xx][yy]=1;
        //    System.out.println(xx+" "+yy);
            k.rem--;
            k.run();
         //   System.out.println("up");
            //ret.add(k);
        }
                if ( ( (r[centerx-1][i+1]==1) ) &&  ( (r[centerx+1][i+1]==1) ) )
                {
                   config k=new config(this);
            k.r[centerx][i+2]=1;
        
            k.rem--;
            k.run(); 
                }
        
        //return ret;
    }
}
    private static void solve(Scanner s) {
        int n=s.nextInt();
        int xx=s.nextInt();
        int yy=s.nextInt();
        if (Math.abs(xx)>30 || Math.abs(yy)>30 )
            System.out.print(0);
        else
        {
           
           
        config c=new config();
        x=xx+c.centerx;
        y=yy;
        hit=0;
        missed=0;
        
        c.rem=n;
        c.run();
        if ((hit+missed)==0)
            System.out.print(0);
        else
        System.out.print((double)hit/(hit+missed));
        }
    }
     
}
