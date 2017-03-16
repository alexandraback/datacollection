package gcj2013.round1b;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import java.io.File;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
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
        P2 p=new P2();
//        p.initbig();
        p.init();
        p.run();
    }
    PrintWriter pw;
    int maxN=2850;
    BigInteger[][] zuhebig=new BigInteger[maxN+2][maxN+2];
    void initbig(){
        for(int i=0;i<maxN+2;i++){
            zuhebig[i][0]=BigInteger.ONE;
            zuhebig[i][i]=BigInteger.ONE;
        }
        for(int i=1;i<maxN+2;i++){
            if(i%100==0) System.out.println(i);
            for(int j=1;j<i;j++){
                
                zuhebig[i][j]=zuhebig[i-1][j-1].add(zuhebig[i-1][j]);
            }
        }
    }
    double[][] zuhe=new double[maxN+2][maxN+2];
    void init(){
        for(int i=0;i<maxN+2;i++){
            zuhe[i][0]=1;
            zuhe[i][i]=1;
        }
        for(int i=1;i<maxN+2;i++){
            for(int j=1;j<i;j++){
                zuhe[i][j]=(zuhe[i-1][j-1]+zuhe[i-1][j]);
            }
        }
    }
    void run() throws Exception{
        File infile=new File("B-large (3).in");
        String outfile="result";
        pw=new PrintWriter(outfile);
        int T=0;
        //BufferedReader br=new BufferedReader(new FileReader(infile));
        Scanner sc=new Scanner(infile);
        T=sc.nextInt();
        int[] data=new int[2000];
        gen(data);
        for(int case_i=1;case_i<=T;case_i++) {
            double result = 0;
            int N=sc.nextInt();
            int X=sc.nextInt();
            int Y=sc.nextInt();
            int level=0;
            while(true){
                if(N>=data[level]) {
                    level++;
                }else{
                    break;
                }
            }
            int sum=Math.abs(X)+Math.abs(Y);
            if(sum<=(2*(level-1))){
                result=1;
            }else if(sum>=(2*(level+1))){
                result=0;
            }else{
                int remain=N-data[level-1];
                int max=4*level+1;
                int cn=max/2+1;
                if(remain<=(max/2)){
                    if(Y>=remain){
                        result=0;
                    }else{
                        result=calc(remain,Y);
                    }
                }else{
                    int less=0;
                    int remain2=max-remain-1;
                    less=(remain-remain2)/2;
                    if(Y<less){
                        result=1;
                    }else if(X==0){
                        result=0;
                    }else{
                        result=calc(remain,Y);
                    }
                    
                }
                
            }
            
            String outputstr=String.format("Case #%d: %s\n", case_i,result);
            pw.printf(outputstr);
            System.out.printf(outputstr);
        }
        pw.close();
    }

    private void gen(int[] data) {
        for(int i=0;i<data.length;i++){
            data[i]=(2*i+1)*(2*i+2)/2;
        }
    }
    double calc(int m,int n){
        double d=0;
        int end=m-n;
        for(int i=0;i<end;i++){
            d=d+(zuhe[m][i]);
        }
        BigDecimal dd=new BigDecimal(d);
        BigDecimal two=new BigDecimal("2");
        for(int i=0;i<m;i++){
            dd=dd.divide(two);
        }
        return dd.doubleValue();
    }
//    double calc(int m,int n){
//        BigInteger d=new BigInteger("0");
//        int end=m-n;
//        for(int i=0;i<end;i++){
//            d=d.add(zuhebig[m][i]);
//        }
//        BigDecimal dd=new BigDecimal(d);
//        BigDecimal two=new BigDecimal("2");
//        for(int i=0;i<m;i++){
//            dd=dd.divide(two);
//        }
//        return dd.doubleValue();
//    }

}
