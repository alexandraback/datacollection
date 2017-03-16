import java.util.*;
import java.math.BigInteger;
//import edu.princeton.cs.algs4.*;


public class B
{
    static int B;
    static long M;
    static boolean [][] A;
    static long [] val;
    static boolean [] need;
    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);

        int nocase = sc.nextInt();
        sc.nextLine();
        
        for(int ind=1; ind<=nocase; ind++)
        {
            B = sc.nextInt();
            M = sc.nextLong();
            long max_m = max_move(B);
            //System.out.println(max_m); 
            if(M > max_m)
            {
                System.out.printf("Case #%d: IMPOSSIBLE\n", ind);
                continue;
            }
            int no = no_moves(max_m);
            val = new long[B];
            need = new boolean[B];
            val[0] = 1;
            val[1] = 1;
            for(int i=2; i<val.length-1; i++)
                val[i]=2*val[i-1];
            for(int i=val.length-2; i>=0; i--)
            {
                if(M>= val[i])
                {
                    need[i] = true;
                    M-=val[i];
                }
            }
            System.out.printf("Case #%d: POSSIBLE\n", ind);
            //System.out.println(Arrays.toString(need));
            for(int i=0; i<need.length-1; i++)
            {
                for(int j=0; j<=i; j++)
                    System.out.print('0');
                for(int j=i+1; j<need.length-1; j++)
                    System.out.print('1');
                if(need[i])
                    System.out.print('1');
                else
                    System.out.print('0');
                System.out.println();
            }
            for(int i=0; i<need.length; i++)
                System.out.print('0');
            System.out.println();
            //System.out.printf("Case #%d: %d\n", ind, soln);
        }

    }


    static long max_move(int N)
    {
        N-=2;
        long m = 1;
        for(int i=0; i<N; i++)
            m*=2;
        return m;
    }

    static int no_moves(long M)
    {
        if(M<=1) return 1;
        else return no_moves(M>>1)+1;
    }

    static ArrayList<Integer> binary(long M, ArrayList<Integer> a)
    {
        if(M<=1) 
        {
            a.add((int)M);
            return a;
        }
        int r = (int)(M%2L);
        binary(M>>1, a);
        a.add(r);
        return a;
    }

}
