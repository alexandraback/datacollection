
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Karim
 */
public class DeceitfulWar {

    public static double[] nao;
    public static double[] ken;
    public static int N;
    
    public static int deceitful(){
        int counter=0;
        int f=0;
        int s=N-1;
        for (int i=N-1;i>=f;i--){
            if (nao[i]>ken[s]){
                counter++;
                s--;
            }
            else{
                f++;
                s--;
                i++;
            }
        }
        return counter;
    }
    
    public static int war(){
        int counter=0;
        for (int i=0;i<N;i++){
            double first=nao[i];
            double second=getNext(first);
            if (first > second){
                counter++;
            }
        }
        return counter;
    }
    
    public static double getNext(double x){
        for (int i=0;i<N;i++){
            if (ken[i]>x){
                double temp=ken[i];
                ken[i]=-1;
                return temp;
            }
        }
        for (int i=0;i<N;i++){
            if (ken[i]!=-1){
                double temp=ken[i];
                ken[i]=-1;
                return temp;
            }
        }
        return -1;
    }
    
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner r = new Scanner(new File("D-small.in"));
        PrintWriter out = new PrintWriter("D-small.out");
//        Scanner r=new Scanner(System.in);
        int T=r.nextInt();
        for (int i=0;i<T;i++){
            N=r.nextInt();
            nao=new double[N];
            ken=new double[N];
            for (int j=0;j<N;j++){
                nao[j]=r.nextDouble();
            }
            for (int j=0;j<N;j++){
                ken[j]=r.nextDouble();
            }
            Arrays.sort(nao);
            Arrays.sort(ken);
            int result1=deceitful();
            int result2=war();
//            System.out.println("Case #"+(i+1)+": "+result1+" "+result2);
            out.println("Case #"+(i+1)+": "+result1+" "+result2);
            out.flush();
        }
    }
}
