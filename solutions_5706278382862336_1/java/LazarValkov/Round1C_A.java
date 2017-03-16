import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Lazar on 26/04/2014.
 */
public class Round1C_A {
    private Scanner in;
    private PrintWriter out;

    public void run() throws Exception{
        String fileName = "PartElf_large";
        try {
            in = new Scanner(new File("InputFiles\\" + fileName + ".in"));
            out = new PrintWriter("OutputFiles\\" + fileName + ".out");
        }
        catch(Exception e)
        {
            throw new RuntimeException(e);
        }
        int T = in.nextInt();
        for(int i=0; i<T; i++){
            solve(i+1);
        }

        out.flush();
        out.close();
    }

    private void solve(int TestCase){
        String fraction = in.next();
        int pos = fraction.indexOf('/');
        long P = Long.parseLong(fraction.substring(0, pos));
        long Q = Long.parseLong(fraction.substring(pos+1));
        
        long commonDelimiter = getGCD(P, Q);
        P = P/commonDelimiter;
        Q = Q/commonDelimiter;


        int earliestElfParent = earliestElfParent(P, Q, 40);
        if(earliestElfParent==-1) {
            out.println(String.format("Case #%d: impossible", TestCase));
            return;
        }
        long parents_Q = Q;
        long parents_P = 2*Q - (P*(long)Math.pow(2, earliestElfParent));

        long commonDelimiter1 = getGCD(parents_Q, parents_P);
        parents_Q /= commonDelimiter1;
        parents_P /= commonDelimiter1;


        int generationsLeft = 40-earliestElfParent;

        while(parents_P != 0 && parents_P != 1){


            int eep = earliestElfParent(parents_P, parents_Q, generationsLeft);
            if(eep==-1) {
                out.println(String.format("Case #%d: impossible", TestCase));
                return;
            }

            parents_P = 2*parents_Q - (parents_P*(long)Math.pow(2, eep));

            commonDelimiter1 = getGCD(parents_Q, parents_P);
            parents_Q /= commonDelimiter1;
            parents_P /= commonDelimiter1;
            generationsLeft -= eep;
        }
        out.println(String.format("Case #%d: %d", TestCase, earliestElfParent));
    }


    // Call when Q > P
    private int earliestElfParent(long P, long Q, int maxGenerations){
        if(!isPowerOfTwo(Q))
            return -1;
        long logQ = getLogarithm(Q);
        if(logQ > maxGenerations)
            return -1;
        int gen = 0;
        while(P * Math.pow(2, gen) < Q)
            gen++;
        return gen;
    }




    /*Stack overflow*/
    private long getLogarithm(long x){
        if(x==0)
            return 0;
        return (long)( Math.log(x)/Math.log(2));
    }


    private boolean isPowerOfTwo(long x)
    {
        return (x != 0) && ((x & (x - 1)) == 0);
    }

    private long getGCD(long x, long y){
        if(y==0)
            return x;
        else
            return getGCD(y, x % y);
    }

    public static void main(String[] args) throws Exception{
        new Round1C_A().run();
    }
}
