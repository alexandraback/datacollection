package gcj2013.round1b;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
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
        File infile=new File("A-small-attempt0 (1).in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            int result = 0;
            int A=sc.nextInt();
            int N=sc.nextInt();
            int[] motes=new int[N];
            for(int i=0;i<N;i++){
                motes[i]=sc.nextInt();
            }
            Arrays.sort(motes);
            if(A==1){
                result=motes.length;
            }else{
                int max=N;
                for(int i=0;i<=N;i++){
                    int t=i+check(motes,i,A);
                    if(t<max){
                        max=t;
                    }
                }
                result=max;
            }
            
            String outputstr=String.format("Case #%d: %s\n", case_i,result);
            pw.printf(outputstr);
            System.out.printf(outputstr);
        }
        pw.close();
    }

    int check(int[] motes,int cuti,int A){
        int r=0;
        int end=motes.length-cuti;
        int a=A;
        for(int i=0;i<end;i++){
            while(a<=motes[i]){
                a=next(a);
                r++;
            }
            a=a+motes[i];
        }
        return r;
        
    }
    int next(int A){
        return A+A-1;
    }
}
