

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author joshuahm
 */
public class B_A {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader inFile = new FileReader("A-large.in");
        Scanner in = new Scanner(inFile);
        FileWriter outFile = new FileWriter("A-large.out");
        PrintWriter out = new PrintWriter(outFile);
        //Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int t=0;t<T;t++)
        {   
            int N = in.nextInt();
            int[] S = new int[N];
            double sum=0;
            for(int i=0;i<N;i++)
            {
                S[i] = in.nextInt();
                sum+=S[i];
            }
            double x=2*sum/N;         
            
            double[] per = new double[N];
            for(int i=0;i<N;i++)
            {
                per[i]=(x-S[i])/sum*100;
            }
            double negsum=0;
            int negcount=0;
            boolean[] isnegative=new boolean[N];
            Arrays.fill(isnegative, false);
            for(int i=0;i<N;i++)
                if(per[i]<0)
                {
                    negsum+=per[i];
                    negcount++;
                    isnegative[i]=true;
                    per[i]=0;
                }
            if(negcount>0)
                for(int i=0;i<N;i++)
                    if(!isnegative[i])
                        per[i]+=negsum/(N-negcount);
            out.print("Case #"+ (t+1) +": ");
            for(int i=0;i<N;i++)
                out.print(per[i]+" ");
            out.println("");
        }
        out.close();
        in.close();
    }
}
