/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj2012.qual;

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
public class P2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P2().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("B-large.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();
        
        for(int case_i=1;case_i<=T;case_i++) {
            int result = 0;
            int N=sc.nextInt();
            int S=sc.nextInt();
            int p=sc.nextInt();
            int[] ti=new int[N];
            for(int i=0;i<N;i++){
                ti[i]=sc.nextInt();
            }
            int threshold1=3*p-2;
            int threshold2=3*p-4;
            if(p==0) threshold1=0;
            if(p<=1) threshold2=100000;
            for(int i=0;i<N;i++){
                if(ti[i]>=threshold1) result++;
                else if(ti[i]>=threshold2){
                    if(S>0){
                        S--;
                        result++;
                    }
                }
            }
            pw.printf("Case #%d: %d\n", case_i,result);
            System.out.printf("Case #%d: %d\n", case_i,result);
        }
        pw.close();
    }

}
