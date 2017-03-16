
import java.util.Scanner;
import java.io.PrintStream;

public class Fractile {
    
    public static void main(String[] args) {
        new Fractile().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    static int K,C,S;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    void problem() {
        K=sc.nextInt();
        C=sc.nextInt();
        S=sc.nextInt();
        int size=(K+C-1)/C;
        if (S<(K+C-1)/C) {
            out.println("IMPOSSIBLE");
            return;
        }
        long[] answer=new long[size];
        int i,j,k=0;
        KBaseNumber m=new KBaseNumber();
        for (i=0;i<size;i++) {
            for (j=0;j<C;j++) {
                m.digit[j]=k<K ? k : 0;
                //if (k<K-1) 
                    k++;
            }
            answer[i]=m.toLong();
        }
        //check answer - for small inputs
        for (long x : answer) out.printf("%d ",x+1);
        out.println();
    }
    
    static class KBaseNumber {
        int[] digit;
        
        KBaseNumber() {
            digit=new int[C];
        }
        
        long toLong() {
            long r=0;
            int i;
            for (i=digit.length-1;i>=0;i--) {
                r=r*K+digit[i];
            }
            return r;
        }
        
    }
}
