import java.util.*;
import java.lang.*;

// Google Code Jam 2012, Round 1A, Problem A

public class Password
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        int A, B;
        double p[];
        double prob, opt;

        for(int i = 0; i < T; i++)
        {
            A = in.nextInt(); B = in.nextInt();
            p = new double[A+1];

            prob = 1.0;
            for(int j = 1; j <= A; j++)
            {
                p[j] = in.nextDouble();
                prob *= p[j];
            }    
            
            // expected key strokes when finishing the rest correctly
            opt = prob*(B-A+1)+(1-prob)*(B-A+1+B+1);

            // expected key strokes when hitting enter;
            opt = Math.min(opt,B+2);

            prob = 1.0;
            for(int back = A; back >= 1; back--)
            {
                opt = Math.min(opt,prob*(B-A+2*back+1)+(1-prob)*(B-A+2*back+1+B+1));

                prob *= p[A-back+1];
            }

            System.out.println("Case #" + (i+1) + ": " + opt);
        }

    }    



}












