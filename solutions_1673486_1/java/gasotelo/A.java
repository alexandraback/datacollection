/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ronda1A2012;

import java.io.*;
import java.text.DecimalFormat;

/**
 *
 * @author G
 */
public class A {

    static File input=new File("A-large.in");
    static DecimalFormat df=new DecimalFormat("0.000000");
    public static void main(String...args)throws Exception{
        System.setOut(new PrintStream("A.out"));
        BufferedReader br=new BufferedReader(new FileReader(input));
        final int T=Integer.parseInt(br.readLine());
        for(int caso=1;caso<=T;caso++){
            String[]j=br.readLine().split(" +");
            int A=Integer.parseInt(j[0]),B=Integer.parseInt(j[1]);
            j=br.readLine().split(" +");
            double[] prob=new double[A];
            double[] probAcumulada=new double[A+1];
            probAcumulada[0]=1.0;
            for(int e=0;e<A;e++){
                prob[e]=Double.parseDouble(j[e]);
                probAcumulada[e+1]=probAcumulada[e]*prob[e];
            }
            double min=B+2;
            for(int e=0;e<=A;e++){
                double exp=(A-e+B-e+1)*probAcumulada[e]+(A-e+2*B-e+2)*(1-probAcumulada[e]);
                if(exp<min)min=exp;
            }
            System.out.println("Case #"+caso+": "+df.format(min));
        }
        System.out.close();
    }
}
