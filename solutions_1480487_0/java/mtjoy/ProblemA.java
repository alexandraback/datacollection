/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam_2012_r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 *
 * @author Ben
 */
public class ProblemA
{
    static class Pair{
        int index;
        double score;
        double perc;
        public Pair(int index, double score, double perc){
            this.index = index;
            this.score = score;
            this.perc = perc;
        }
    }
    static class PairComparator implements Comparator<Pair>{
        @Override
        public int compare(Pair o1, Pair o2) {
            double result = o1.score - o2.score;
            if(result < 0)
                return -1;
            else if (result == 0)
                return 0;
            else
                return 1;
        }
    }
    static class PairOneComparator implements Comparator<Pair>{
        @Override
        public int compare(Pair o1, Pair o2) {
            return o1.index - o2.index;
        }
    }
    public static void ProblemA()
    {
        PrintWriter fwriter;
        Scanner freader;
        try
        {
            freader = new Scanner(
                    new File("A-small-attempt3.in"));
            fwriter = new PrintWriter(
                    new FileWriter("Aout.txt"));

            int caseCount = freader.nextInt();
            freader.nextLine();

            for(int caseIdx = 0; caseIdx < caseCount; caseIdx++)
            {
                int N = freader.nextInt();
                Pair J [] = new Pair [N];
                double total = 0;
                for(int i = 0; i < N; i++){
                    double d = freader.nextDouble();
                    total += d;
                    J[i] = new Pair(i, d, 0.0);
                }
                freader.nextLine();

                J = solve(N, J, total);
                Arrays.sort(J, new PairOneComparator());

                fwriter.format("Case #%d:", caseIdx + 1);
                for(int i = 0; i < N; i++)
                    fwriter.format(" %f", J[i].perc * 100);
                fwriter.format("\n");

            }

            freader.close();
            fwriter.close();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static Pair[] solve(int N, Pair [] J, double total)
    {
        double remaining = 1.0;
        Arrays.sort(J, new PairComparator());

        while(true)
        {
            double lowest = J[0].score;
            double next = lowest;
            int nlowest = 1;
            for(int i = 1; i < J.length; i++){
                if(J[i].score == lowest){
                    nlowest++;
                }
                else if(J[i].score > lowest){
                    next = J[i].score;
                    break;
                }
            }

            if(next == lowest){
                System.out.println(" everythign the same " + next + " " + remaining);
                //everyting is the same
                double toAdd = remaining/N;
                for(int i = 0; i < N; i++){
                    J[i].perc += toAdd;
                }
                return J;
            }

            double f = (next - lowest) / total;
            System.out.println(f);

            if(f*nlowest > remaining){
                System.out.println(remaining + " , "+ f);
                double toAdd = remaining/nlowest;
                for(int i = 0; i < nlowest; i++)
                    J[i].perc += toAdd;
                return J;
            }
            remaining -= f * nlowest;
            
            for(int i = 0; i < nlowest; i++){
                J[i].score = next;
                J[i].perc += f;
            }
        }
    }
}
