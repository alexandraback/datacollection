package gcj2014.r1c;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.File;
import java.io.PrintWriter;
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

    void run() throws Exception{
        File infile=new File("C-small-attempt0 (1).in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();

        for(int case_i=1;case_i<=T;case_i++) {
            int result = 0;
            int N=sc.nextInt();
            int M=sc.nextInt();
            int K=sc.nextInt();
            if(N<=2 || M<=2){
                result=K;
            }else{
                result=store[N*M][K];
            }
            String outputstr=String.format("Case #%d: %s\n", case_i,result);
            pw.printf(outputstr);
            System.out.printf(outputstr);
        }
        pw.close();
    }
    static int[][] store=new int[21][21];
    static{
        store[9]=new int[]{0,1,2,3,4,4,5,6,7,8};
        store[12]=new int[]{0,1,2,3,4,4,5,6,6,7,8,9,10};
        store[15]=new int[]{0,1,2,3,4,4,5,6,6,7,8,8,9,10,11,12};
        store[18]=new int[]{0,1,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,13,14};
        store[16]=new int[]{0,1,2,3,4,4,5,6,6,7,8,8,8,9 ,10,11,12};
        store[20]=new int[]{0,1,2,3,4,4,5,6,6,7,8,8,8,9 ,9,10,10,11,12,13,14};
    }
}
