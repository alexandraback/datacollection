/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj2012.round1b;

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
public class PA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new PA().run();
    }
    PrintWriter pw;

    void run() throws Exception{
        File infile=new File("A-small-attempt0.in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            
            int N=sc.nextInt();
            double[] s=new double[N];
            int sum=0;
            for(int i=0;i<N;i++){
                s[i]=sc.nextInt();
                sum+=s[i];
            }
            for(int i=0;i<N;i++){
                s[i]=s[i]/sum;
            }
            double p=2;
            int num=N;
            double thres=p/N;
            for(int i=0;i<N;i++){
                if(s[i]>=thres){
                    p=p-s[i];
                    num--;
                }
            }
            double r1=p/num;
            StringBuilder result=new StringBuilder();
            for(int i=0;i<N;i++){
                if(s[i]>=r1){
                    result.append(" 0");
                }else{
                    result.append(String.format(" %.6f", (r1-s[i])*100));
                }
            }
            pw.printf("Case #%d:%s\n", case_i,result.toString());
            System.out.printf("Case #%d:%s\n", case_i,result.toString());
        }
        pw.close();
    }

}
