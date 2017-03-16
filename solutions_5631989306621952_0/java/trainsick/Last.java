
import java.util.Scanner;
import java.io.PrintStream;

public class Last {
    
    public static void main(String[] args) {
        new Last().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    String word;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    void problem() {
        word=sc.next();
        String last="";
        StringBuilder left,right;
        String w2;
        int b;
        int k;
        for (b=(1<<word.length())-1;b>=0;b--) {
            left=new StringBuilder();
            right=new StringBuilder();
            
            for (k=0;k<word.length();k++) {
                if ((b & (1<<k))!=0) left.append(word.charAt(k));
                else right.append(word.charAt(k));
            }
            left.reverse();
            left.append(right);
            w2=new String(left);
            if (w2.compareTo(last)>0) last=w2;
        }
        out.println(last);
    }
    
}
