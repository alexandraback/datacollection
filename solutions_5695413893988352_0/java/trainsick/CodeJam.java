
import java.util.Scanner;
import java.io.PrintStream;

public class CodeJam {
    
    public static void main(String[] args) {
        new CodeJam().main2();
    }
    
    Scanner sc=new Scanner(System.in);
    PrintStream out=System.out;
    
    void main2() {
        int i,T;
        T=sc.nextInt();
        for (i=1;i<=T;i++) {
            out.printf("Case #%d: ",i);
            problem();
        }
    }
    
    String C,J;
    int mindiff;
    String minC="",minJ="";
    
    void bruteforce(int i, int c, int j) {
        if (i>=C.length()) {
            if (Math.abs(c-j)<mindiff) {
                mindiff=Math.abs(c-j);
                minC="".format("%0"+C.length()+"d",c);
                minJ="".format("%0"+C.length()+"d",j);
            }
            return;
        }
        for (int cc=0;cc<10;cc++) {
            if (C.charAt(i)!='?' && C.charAt(i)!=48+cc) continue;
            for (int jj=0;jj<10;jj++) {
                if (J.charAt(i)!='?' && J.charAt(i)!=48+jj) continue;
                bruteforce(i+1,c*10+cc,j*10+jj);
            }
        }
    } 
    
    void problem() {
        C=sc.next();
        J=sc.next();
        mindiff=0x7fffFFFF;
        bruteforce(0,0,0);
        out.printf("%s %s\n",minC, minJ);
    
    }
    
}
