/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj2012.round1a;

import gcj2012.qual.*;
import gcj2010.round2.*;
import gcj2009.*;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P1().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("A-large.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int N=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc=new Scanner(infile);
        N=sc.nextInt();

        for(int case_i=1;case_i<=N;case_i++) {
            int result = 0;
            int A=sc.nextInt();
            int B=sc.nextInt();
            double[] p=new double[A];
            for(int i=0;i<A;i++){
                p[i]=sc.nextDouble();
            }
            int n1=B-A,n2=B+1;
            double min=n2+1;
            for(int i=A;i>0;i--){
                int extra=2*(A-i);
                double pp=1;
                for(int j=0;j<i;j++){
                    pp=pp*p[j];
                }
                double newmin=n1+1+(1-pp)*n2+extra;
                min=Math.min(min, newmin);
            }
            
            pw.printf("Case #%d: %.6f\n", case_i,min);
            System.out.printf("Case #%d: %.6f\n", case_i,min);
        }
        pw.close();
    }

}
