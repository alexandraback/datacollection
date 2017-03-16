
import java.util.Scanner;
import java.io.PrintStream;

public class Last2 {
    
    public static void main(String[] args) {
        new Last2().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    String word;
    boolean[] isleft;
    int firstleft;
    
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    
    void problem() {
        char c=127;
        int i;
        word=sc.next();
        isleft=new boolean[word.length()];
        firstleft=word.length();
        while (true) {
            c=nextlargest(c);
            if (c==0) break;
            for (i=firstleft-1;i>=0;i--) {
                if (word.charAt(i)==c) {
                    firstleft=i;
                    isleft[i]=true;
                }
            }
        }
        StringBuilder answer=new StringBuilder();
        for (i=word.length()-1;i>=0;i--) 
            if (isleft[i]) answer.append(word.charAt(i));
        for (i=0;i<word.length();i++) 
            if (!isleft[i]) answer.append(word.charAt(i));
        out.println(answer);
    }
    
    char nextlargest(char c) {
        char a=0,b;
        int i;
        for (i=0;i<word.length();i++) {
            b=word.charAt(i);
            if (b<c && b>a) a=b;
        }
        return a;
    }
    
    
    
}
