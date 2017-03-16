
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProbB {
         public static void main(String[] args) throws InterruptedException 
    {
        
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
                for (int i=1;i<=casenum;i++)
                {System.out.print("Case #"+i+": ");
                solve(s);
                System.out.println();
                }
    }

    private static void solve_s(int i, int i0, long x, long y, int i1) {
   
    }
static class pos implements Comparable<pos>
{
long x, y;
long length;
        @Override
        public int compareTo(pos o) {
            int v=new Long(x).compareTo(o.x);
            if (v!=0) return v;
            v=new Long(y).compareTo(o.y);
            if (v!=0) return v;
            return new Long(length).compareTo(o.length);
        }
    
}
//static TreeMap<pos,route> r=new TreeMap<pos,route>();
static TreeSet<pos> r2=new TreeSet<pos>();
    private static void solve(Scanner s) throws InterruptedException {
        r2=new TreeSet<pos>();
        //r=new TreeMap<pos,route>();
        long x=s.nextLong();
        long y=s.nextLong();
        route first=new route();
        first.length=0;
        first.a="";
        first.x=0;
        first.y=0;
        List<route> routes=new ArrayList<route>();
        routes.add(first);
        route act=null;
        while (true)
        {
            act=routes.get(0);
            pos p=new pos();
            p.length=act.length;
            p.x=act.x;
            p.y=act.y;
            routes.remove(0);
            if (r2.contains(p))continue;
            r2.add(p);
        //    System.err.println(act.a+" "+act.x+" "+act.y+" "+act.length);
         //   Thread.sleep(1000);
           //  System.err.println(act.length);
            if (act.x==x /*&& act.y==y*/)
            {
                //System.out.print(act.a);
                //return;
                //continue;
                break;
            }
            
                 for (int ii=0;ii<2;ii++)
        {
            ii*=2;
            route act1=new route();
            act1.x=act.x;
            act1.y=act.y;
            act1.length=act.length+1;
            String l=null;
            switch(ii)
            {
                case 0: l="W";break;
                case 1: l="S";break;
                case 2: l="E";break;
                case 3: l="N";break;
                    
            }
            act1.a=act.a+l;
            if (ii%2==0)
                //act1.x+=Math.pow(2, act1.length-1)*(ii-1);
                act1.x+= (act1.length)*(ii-1);
            else
                act1.y+= (act1.length)*(ii-2);
             //System.err.println("betesz:"+act1.a+" "+act1.x+" "+act1.y+" "+act1.length);
           
            routes.add(act1);
        }
                 
        }
        
        r2.clear();
        routes.clear();
        routes.add(act);
        while (true)
        {
            act=routes.get(0);
            pos p=new pos();
            p.length=act.length;
            p.x=act.x;
            p.y=act.y;
            routes.remove(0);
            if (r2.contains(p))continue;
            r2.add(p);
       //     System.err.println(act.a+" "+act.x+" "+act.y+" "+act.length);
         //   Thread.sleep(1000);
           //  System.err.println(act.length);
            if (act.x==x && act.y==y)
            {
                System.out.print(act.a);
                return;
                //continue;
                //break;
            }
            
                 for (int ii2=0;ii2<2;ii2++)
        {
            //System.err.println("elotte:"+ii);
            int ii=ii2*2+1;
            //System.err.println("utana:"+ii);
            route act1=new route();
            act1.x=act.x;
            act1.y=act.y;
            act1.length=act.length+1;
            String l=null;
            switch(ii)
            {
                case 0: l="W";break;
                case 1: l="S";break;
                case 2: l="E";break;
                case 3: l="N";break;
                    
            }
            act1.a=act.a+l;
            if (ii%2==0)
                //act1.x+=Math.pow(2, act1.length-1)*(ii-1);
                act1.x+= (act1.length)*(ii-1);
            else
                act1.y+= (act1.length)*(ii-2);
             //System.err.println("betesz:"+act1.a+" "+act1.x+" "+act1.y+" "+act1.length);
           
            routes.add(act1);
        }
                 
        }
        
        //solve_s(0,0,x,y,0);
    }

    private static class route {
        int length;
        String a;
        long x,y;
        public route() {
        }
    }
}
