/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2016.round0;

import googlecodejam2014.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProD implements Problem {

    @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt(); in.nextLine();
        for (int i = 1; i <= count; i++) {
           String list[]=in.nextLine().split(" ");
           int k=Integer.valueOf(list[0]);
            int c=Integer.valueOf(list[1]);
            int s=Integer.valueOf(list[2]);
            StringBuilder sb=new StringBuilder();
            for(int j=1;j<=s;j++){
                sb.append(" ").append(j);
            }
            out.printf("Case #%d:%s\n", i, sb.toString());
        }
    }

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt(); in.nextLine();
      for (int i = 1; i <= count; i++) {
         
            out.printf("Case #%d: %d %d\n", i, 1,1);
        }
    }

  

    public static void main(String[] args) throws FileNotFoundException {
        Problem D = new ProD();
        String prepath = "F:\\codejam\\D\\";
        String testname = "test-D";
        String smallname = "D-small-attempt0";
        String largename = "D-large";
        File tin = new File(prepath + testname + ".txt");
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        D.solveSmall(new Scanner(tin), testo);
        D.solveSmall(new Scanner(sin), smallo);
        //System.out.println(prepath + smallname + ".out");
        //D.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");

    }
}
