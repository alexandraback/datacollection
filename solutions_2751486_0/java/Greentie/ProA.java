/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2013;

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
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {
            String s=in.nextLine();
            String[] a=s.split(" ");
            String t=change(a[0].trim());
            String se=build(Integer.valueOf(a[1]));
            
            out.printf("Case #%d: %d\n", i,serch(t,se));
        }
    }
    
    
   public String change(String S){
       
       String temp="";
       for(int i=0;i<S.length();i++)
       {
           if(S.charAt(i)=='a'||S.charAt(i)=='e'||S.charAt(i)=='i'||S.charAt(i)=='o'||S.charAt(i)=='u')temp+="0";
           else temp+='1';
       }
       return temp;
   }
   
   public String build(int l){
       String temp="";
       for(int i=0;i<l;i++)temp+=1;
       return temp;
   }
   
   public int serch(String t,String s){
       int count=0;
       for(int i=0;i<t.length();i++){
           for(int j=i+1;j<t.length()+1;j++){
               String a=t.substring(i,j);

               if(a.indexOf(s)!=-1)count++;
           }
       }
       return count;
   }
   

    @Override
    public void solveLarge(Scanner in, PrintStream out) {
        int x = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= x; i++) {

            out.printf("Case #%d: %d\n", i, i);
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
        PrintStream testo = new PrintStream(prepath + testname + ".out.txt");
        PrintStream smallo = new PrintStream(prepath + smallname + ".out");
        PrintStream largeo = new PrintStream(prepath + largename + ".out");
        //A.solveSmall(new Scanner(tin), testo);
        //System.out.println(prepath + testname + ".out");
        A.solveSmall(new Scanner(sin), smallo);
        System.out.println(prepath + smallname + ".out");
        //A.solveLarge(new Scanner(lin), largeo);
        //System.out.println(prepath + largename + ".out");
    }
}
