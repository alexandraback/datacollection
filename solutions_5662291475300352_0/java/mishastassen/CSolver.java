import java.util.*;
import java.io.*;

class Hiker implements Comparable<Hiker>
{
    long d;
    long m;
    long k;

    Hiker(long dd, long mm, long kk)
    {
        d=dd;
        m=mm;
        k=kk;
    }

    public int compareTo(Hiker b)
    {
        //long dif = (360*k-d)*b.m - (360*b.k-b.d)*m;
        long dif = (360*k-d)*m - (360*b.k-b.d)*b.m;
        if(dif<-1)
            return -1;
        else if(dif==0)
            return 0;
        else
            return 1;
    }
}

class CSolver
{
    static String exampleInput="C-example.txt";

    String solve(Scanner sc) throws IOException
    {
        int res=0;
        int encounters=0;
        PriorityQueue<Hiker> pq=new PriorityQueue<Hiker>();
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            int d=sc.nextInt();
            int h=sc.nextInt();
            int m=sc.nextInt();
            encounters+=h;
            for(int j=0;j<h;j++)
                pq.offer(new Hiker(d,m+j,1));
        }

        res=encounters;
        //System.out.println("#enc: "+encounters);
        for(int rep=2*encounters;rep>=0;rep--)
        {
            /*
            Iterator<Hiker> itr = pq.iterator();
            while(itr.hasNext()) {
            Hiker element = itr.next();
            System.out.print("hiker("+element.d+","+element.m+","+element.k+"), ");
            }
            System.out.println();
            */

            res=Math.min(res,encounters);
            Hiker x=pq.peek();
            for(Hiker a=pq.peek();a.compareTo(pq.peek())==0;)
            {
                Hiker b=pq.poll();
                encounters+=b.k==1?-1:1;
                //System.out.println("hiker("+b.d+","+b.m+","+b.k+") passeert, #enc: "+encounters);
                pq.offer(new Hiker(b.d,b.m,b.k+1));
            }
        }

        return ""+res;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(new File(args.length>=1?args[0]:exampleInput));
        PrintWriter out=null;
        if(args.length>=2)
            out=new PrintWriter(new File(args[1]));
        int numtests=Integer.parseInt(sc.nextLine().trim());
        for(int testid=1;testid<=numtests;testid++)
        {
            String res=(new CSolver()).solve(sc);
            System.out.println("Case #"+testid+": "+res);
            if(out!=null)
                out.write("Case #"+testid+": "+res+"\n");
        }
        sc.close();
        if(out!=null)
            out.close();
    }
}

