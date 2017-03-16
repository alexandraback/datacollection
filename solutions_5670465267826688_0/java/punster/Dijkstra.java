/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dijkstra;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author kiss
 */
public class Dijkstra {

    static final String WORKDIR = "C:\\proj\\codejam\\2015\\qual_c\\";
    

    static class Quat {
        char v;
        boolean isNeg;
         Quat() {
            v = '1'; isNeg = false;
        }
    }
    static void multQ(Quat x, char y, boolean swap) {
        if (x.v == '1') {
            x.v = y;
        } else if (x.v == y) {
            x.v = '1';
            x.isNeg = !x.isNeg;
        } else { // diff 
            if (x.v == 'i') {
                if (y == 'j') {
                    x.v = 'k'; 
                } else {
                    x.v = 'j'; x.isNeg = !x.isNeg;
                }
            } else if (x.v == 'j') {
                 if (y == 'k') {
                    x.v = 'i'; 
                } else {
                    x.v = 'k'; x.isNeg = !x.isNeg;
                }
            } else if (x.v == 'k') {
                if (y == 'i') {
                    x.v = 'j'; 
                } else {
                    x.v = 'i'; x.isNeg = !x.isNeg;
                }
            }
            if (swap) {
                x.isNeg = !x.isNeg;
            }
        }
        
    }
    static boolean multComp(Quat x, char y, boolean swap, char comp) {
        multQ(x,y,swap);
        return (!x.isNeg && (comp == x.v));
    }
    static String repeat(String pat, int patrep) {
        StringBuilder foo = new StringBuilder(pat);
        for (int i=1; i < patrep; i++) {
            foo.append(pat);
        }
 //       System.out.println("Before:" +foo);
        String s = foo.toString();
  //      String t = s.replaceAll("(.)\\1{3}", "");
   //     System.out.println("After:" +s);
   //     System.out.println("After:" +t);
        return s;
    }

    
    static boolean canReduce(String sb) {
        ArrayList<Integer> is = new ArrayList<>();
        Quat q = new Quat();
        for (int i=0; i < sb.length()-2; i++) {
            if (multComp(q, sb.charAt(i), false, 'i')) {
                is.add(i);
            }
        }
        if (is.isEmpty()) { return false; }
        ArrayList<Integer> ks = new ArrayList<>();
        q = new Quat();
        for (int i=sb.length()-1; i > 1; i--) {
            if (multComp(q, sb.charAt(i), true, 'k')) {
                ks.add(i);
            }
        }
        if (ks.isEmpty()) { return false; }
        for (Integer tryi : is) {
            for (Integer tryk : ks) {
                q = new Quat();
                for (int i=tryi+1; i < tryk; i++ ) {
                    multQ(q,sb.charAt(i),false);
                }
                if ((q.v == 'j') && !q.isNeg) {
                    System.out.println(tryi + " " + tryk);
                    return true;
                }
            }
        }
        return false;
    }
    static String solve(Scanner cin) {
       int patlen = cin.nextInt();
       int patrep = cin.nextInt();
       String pat = cin.next();
       if ((patlen < 2) || (patlen*patrep < 3)) {
           return "NO";
       }
       return canReduce(repeat(pat,patrep))? "YES" : "NO";
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner cin = new Scanner(new BufferedReader(new FileReader(WORKDIR+args[0])));
            PrintWriter cout = new PrintWriter(  new FileWriter(WORKDIR+args[0]+".out"));
            int numTests = cin.nextInt();
            for (int i=1; i <=numTests; ++i) {
                cout.println("Case #" + i + ": " + solve(cin));
            }
            cin.close();
            cout.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
   
   
}
