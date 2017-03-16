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
public class ProB implements Problem {

     @Override
    public void solveSmall(Scanner in, PrintStream out) {
        int count = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= count; i++) {
           char[] input =in.nextLine().toCharArray();
           int result=process(input);
            out.printf("Case #%d: %s\n", i,result);
        }
    }
    
    private int process(char[] s){

     String stack="";
     char front='+';
     for(int i=s.length-1;i>-1;i--){
         if(!(front==s[i]))stack=stack+s[i];  
         front=s[i];    
     }

     return stack.length();
    }
    


    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int count = in.nextInt(); 
        in.nextLine();
      for (int i = 1; i <= count; i++) {
            char[] input =in.nextLine().toCharArray();
           int result=process(input);
            out.printf("Case #%d: %s\n", i,result);
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
       // B.solveSmall(new Scanner(tin), testo);
        //B.solveSmall(new Scanner(sin), smallo);
       //  System.out.println(prepath + smallname + ".out");
        B.solveLarge(new Scanner(lin), largeo);
        System.out.println(prepath + largename + ".out");
    }
}