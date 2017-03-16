/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2012.qual;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author scbit
 */
public class P3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        new P3().run();
    }
    PrintWriter pw;

    void run() throws Exception {
        File infile = new File("C-large.in");
        String outfile = "result";
        pw = new PrintWriter(outfile);
        int N = 0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        //N=Integer.parseInt(br.readLine());
        Scanner sc = new Scanner(infile);
        N = sc.nextInt();

        for (int case_i = 1; case_i <= N; case_i++) {
            int result = 0;
            int A=sc.nextInt();
            int B=sc.nextInt();
            for(int n=A;n<=B;n++){
                int d=calcnum(n);
                int m=n;
                for(int i=1;i<d;i++){
                    int gewei=m%10;
                    m=m/10;
                   
                    if(gewei==0) continue;
                    for(int ii=1;ii<d;ii++){
                        gewei=gewei*10;
                    }
                    m=m+gewei;
                    if(m==n) break;
                    if(m>n && m <=B) result++;
                }
            }
            
            
            
            pw.printf("Case #%d: %s\n", case_i, result);
            System.out.printf("Case #%d: %s\n", case_i, result);
        }
        pw.close();
    }
    int calcnum(int num){
        int t=num;
        int c=0;
        
        while(t>0){
            t=t/10;
            c++;
        }
        return c;
        
    }
}
