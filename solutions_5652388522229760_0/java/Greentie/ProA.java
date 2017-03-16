/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2016.round0;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProA implements Problem {

        @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
            int number=Integer.valueOf(in.nextLine());
            String result="INSOMNIA";
            if(number!=0)
                result=String.valueOf(getLastNumb(number));
            out.printf("Case #%d: %s\n", i,result);
        }
    }
    
    private long getLastNumb(long x){
        int[] c=new int[10];
        long num=0;
        do{
            num+=x;
            long q=num,r=0;
            do{
                r=q%10;
                if( c[(int)r]==0) c[(int)r]++;
                q=q/10;
            }while(q!=0);
            
            
        }while(!isAllNonzero(c));
        return num;
    }
    
    private boolean isAllNonzero(int[] c){
        int prod=1;
        for(int i=0;i<c.length;i++){
            prod*=c[i];
            if(prod==0)return false;
        }
        return true;
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {

            out.printf("Case #%d: %d %d\n", i, 1, 1);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem A = new ProA();
        String prepath = "F:\\codejam\\A\\";
        //prepath = downpath;
        String testname = "test-A";
        String smallname = "A-small-attempt0";
        String largename = "A-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        A.solveSmall(new Scanner(tin), testo);
        System.out.println(prepath + testname + ".out");
        A.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
        // A.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}
