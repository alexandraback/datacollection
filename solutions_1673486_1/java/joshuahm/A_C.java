

import java.io.*;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author joshuahm
 */
public class A_C {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader inFile = new FileReader("A-large.in");
        Scanner in = new Scanner(inFile);
        FileWriter outFile = new FileWriter("A-large.out");
        PrintWriter out = new PrintWriter(outFile);
        //Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int t=0;t<T;t++)
        {
            int A=in.nextInt();
            int B=in.nextInt();
            double[] right= new double[A+1];
            double[] probs= new double[A];
            for(int i=0;i<A;i++)
                probs[i]=in.nextDouble();
            right[0]=1;
            for(int i=1;i<=A;i++)
                right[i]=probs[i-1]*right[i-1];
            double keep;
            double[] back= new double[A];
            double away;
            keep=right[A]*(B-A+1)+(1-right[A])*(B-A+1+B+1);
            for(int i=0;i<A;i++)
                back[i]=((A-i)+(B-i)+1)*right[i]+(1-right[i])*((A-i)+(B-i)+1+B+1);
            double min= 100*A;
            for(int i=0;i<A;i++)
                min= Math.min(min,back[i]);
            away=1+B+1;
            min=Math.min(away, Math.min(min, keep));
            out.println("Case #"+ (t+1) +": "+min);
        }
        out.close();
        in.close();
    }
}
