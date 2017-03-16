import java.util.*;
import java.io.*;

class ASolver
{
    static String exampleInput="A-example.txt";
    
    static int S=2000000;
    static int[] q=new int[S];

    static int reverse(int a)
    {
        int b=0;
        while(a>0)
        {
            b=10*b+(a%10);
            a/=10;
        }
        return b;
    }

    static void precalc()
    {
        Arrays.fill(q,S+S);
        q[1]=1;
        int[] rij=new int[S+S];
        int from=0,to=0;
        rij[to++]=1;
        rij[to++]=1;
        while(from<to)
        {
            int cur=rij[from++];
            int dis=rij[from++];
            for(int i=0;i<2;i++)
            {
                int next=i==0?cur+1:reverse(cur);
                if(next>=S)
                    continue;
                if(q[next]>dis+1)
                {
                    q[next]=dis+1;
                    rij[to++]=next;
                    rij[to++]=dis+1;
                }
            }
        }
    }


    String solve(Scanner sc) throws IOException
    {
        int n=sc.nextInt();
        return ""+q[n];
    }

    public static void main(String[] args) throws IOException
    {
        precalc();
        Scanner sc=new Scanner(new File(args.length>=1?args[0]:exampleInput));
        PrintWriter out=null;
        if(args.length>=2)
            out=new PrintWriter(new File(args[1]));
        int numtests=Integer.parseInt(sc.nextLine().trim());
        for(int testid=1;testid<=numtests;testid++)
        {
            String res=(new ASolver()).solve(sc);
            System.out.println("Case #"+testid+": "+res);
            if(out!=null)
                out.write("Case #"+testid+": "+res+"\n");
        }
        sc.close();
        if(out!=null)
            out.close();
    }
}

