/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;
import java.math.*;

/**
 *
 * @author admin
 */
public class ProA implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
       int x=in.nextInt();
       in.nextLine();
       for(int i=1;i<=x;i++){
           int r=2*in.nextInt()-1;
           int t=8*in.nextInt();  
           double b=r*r+t;
           b=Math.sqrt(b)-r;
           b/=4;
           b=Math.floor(b);
           out.printf("Case #%d: %d\n",i,(int)b);
           in.nextLine();
       }
    }

    
     public static BigInteger sqrt(BigInteger x) {
        BigInteger k = BigInteger.ONE;
        BigInteger j = x;
        do {
            k = j;
            j = x.divide(k).add(k).divide(BigInteger.valueOf(2));
        } while (k.compareTo(j) > 0);
        return k;
    }
    
    @Override
    public void solveLarge(Scanner in, PrintStream out) {
          int x=in.nextInt();
       in.nextLine();
       for(int i=1;i<=x;i++){
           BigInteger r=in.nextBigInteger().multiply(BigInteger.valueOf(2)).add(BigInteger.ONE.negate());
           BigInteger t=in.nextBigInteger().multiply(BigInteger.valueOf(8));
           BigInteger b=r.pow(2).add(t);
           b=sqrt(b).add(r.negate());     
           b=b.divide(BigInteger.valueOf(4));
           out.printf("Case #%d: %s\n",i,b.toString());
           in.nextLine();
       }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Problem A = new ProA();
       String prepath = "C:\\Documents and Settings\\GreenTie\\My Documents\\NetBeansProjects\\GoogleCodeJam2013-1\\";
        //prepath = downpath;
        String testname = "test";
        String smallname = "A-small-attempt0";
        String largename = "A-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        //A.solveLarge(new Scanner(tin), testo);
        //System.out.println(prepath + testname + ".out");
        //A.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
       A.solveLarge(new Scanner(lin), largeo);
       //System.out.println(prepath + largename + ".out");
    }
}
