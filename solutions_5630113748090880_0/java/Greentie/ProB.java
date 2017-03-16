/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2016.round1a;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 *
 * @author admin
 */
public class ProB implements Problem {

     @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
           int l=Integer.valueOf(in.nextLine());
          int[] height=new int[2501];
           for(int k=0;k<2*l-1;k++){
               for(int j=0;j<l;j++){
                   int x=in.nextInt();
                   height[x]++;
                   height[x]%=2;
                   
               }
              in.nextLine();  
           }
           TreeSet<Integer> set=new TreeSet();
           for(int k=0;k<height.length;k++){
               if(height[k]==1)set.add(k);
           }
           Integer[] a=set.toArray(new Integer[0]);
           String res="";
           for(int k=0;k<a.length;k++){
               res+=" "+a[k];
           }
           out.printf("Case #%d:%s\n", i,res);
        }
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
        Problem B = new ProB();
        String prepath = "F:\\codejam\\B\\";
        //prepath = downpath;
        String testname = "test-B";
        String smallname = "B-small-attempt0";
        String largename = "B-large";
        File sin = new File(prepath + smallname + ".in");
        File lin = new File(prepath + largename + ".in");
        File tin = new File(prepath + testname + ".txt");
        PrintStream testo = new PrintStream(prepath + testname + ".out");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        B.solveSmall(new Scanner(tin), testo);
        B.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
       // B.solveLarge(new Scanner(lin), largeo);
       // System.out.println(prepath + largename + ".out");
    }
}