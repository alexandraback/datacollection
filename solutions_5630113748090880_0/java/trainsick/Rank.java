
import java.util.Scanner;
import java.io.PrintStream;
import java.util.Arrays;

public class Rank {
    
    public static void main(String[] args) {
        new Rank().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    int N;
    int[] all;
    int[] missing;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    void problem() {
        N=sc.nextInt();
        int allsize=(2*N-1)*N;
        int i,i0,j;
        all=new int[allsize];
        missing=new int[N];
        for (i=0;i<allsize;i++) all[i]=sc.nextInt();
        i=j=i0=0;
        Arrays.sort(all);
        while (true) {
            i0=i;
            if (i0>=allsize) break;
            while (i<allsize && all[i0]==all[i]) i++;
            int count=i-i0;
            if ((count & 1)==1) missing[j++]=all[i0]; 
        }
        for (int x : missing) out.printf("%d ",x);
        out.println();
    }
    
}
