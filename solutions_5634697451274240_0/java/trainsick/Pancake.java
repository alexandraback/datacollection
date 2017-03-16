
import java.util.Scanner;
import java.io.PrintStream;

public class Pancake {
    
    public static void main(String[] args) {
        new Pancake().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    void main2() {
        int T,i;
        String stack;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            stack=sc.next();
            out.printf("Case #%d: %d\n",i,changeCount(stack+"+"));
        }
    }
    
    int changeCount(String s) {
        int changes=0, i;
        for (i=1;i<s.length();i++) {
            if (s.charAt(i-1)!=s.charAt(i)) changes++;
        }
        return changes;
    }
}
