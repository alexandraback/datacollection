
import java.util.Scanner;
import java.io.PrintStream;

public class Digit {
    
    public static void main(String[] args) {
        new Digit().main2();
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

    int[] count;
    int[] ans;

    
    int prune(int n, String s) {
        for (char c : s.toCharArray()) {
            count[c]-=n;
        }
        return n;
    }
    
    void isempty() {
        for (int i=48;i<58;i++) {
            if (count[i]!=0) out.println("NOT EMPTY");
        }
    }
    
    void problem() {
        String letters=sc.next();
        StringBuilder digits=new StringBuilder();
        count=new int[128];
        ans=new int[10];
        for (char c : letters.toCharArray()) {
            if (c<128) count[c]++;
        }
        ans[0]=prune(count['Z'],"ZERO");
        ans[2]=prune(count['W'],"TWO");
        ans[4]=prune(count['U'],"FOUR");
        ans[6]=prune(count['X'],"SIX");
        ans[8]=prune(count['G'],"EIGHT");
        ans[1]=prune(count['O'],"ONE");
        ans[3]=prune(count['H'],"THREE");
        ans[5]=prune(count['F'],"FIVE");
        ans[7]=prune(count['S'],"SEVEN");
        ans[9]=prune(count['I'],"NINE");
        
        isempty();
        
        for (int i=0;i<10;i++) {
            for (int j=0;j<ans[i];j++)
                digits.append((char)(i+48));
        }
        out.printf("%s\n",digits);
    
    }
    
}
/*
"*ZERO", "T*WO", "FO*UR", "SI*X", "EI*GHT", "*ONE",  "T*HREE",  
"*FIVE",  "*SEVEN", , "N*INE"
*/
