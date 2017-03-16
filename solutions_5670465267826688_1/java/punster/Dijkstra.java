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
/*    static StringBuilder repeat(String pat, long patrep) {
        StringBuilder foo = new StringBuilder(pat);
        for (long i=1; i < patrep; i++) {
            foo.append(pat);
        }
 //       System.out.println("Before:" +foo);
  //      String s = foo.toString();
  //      String t = s.replaceAll("(.)\\1{3}", "");
   //     System.out.println("After:" +s);
   //     System.out.println("After:" +t);
        return foo;
    }
*/
    
    static boolean canReduce(String sb, long patrep) {
        long i_idx = -1;
        Quat q = new Quat();
        for (long i=0; i < ((patrep>4?4:patrep) * sb.length())-2; i++) {
            if (multComp(q, sb.charAt((int)(i%sb.length())), false, 'i')) {
                i_idx = i;
                break;
            }
        }
        if (i_idx == -1) { return false; }
        long k_idx = -1;
        q = new Quat();
        long total_len = patrep*sb.length();
        long last_idx = (patrep>4) ? (patrep-4)*sb.length() : 2;
        for (long i=total_len-1; i >= last_idx; i--) {
            if (multComp(q, sb.charAt((int)(i%sb.length())), true, 'k')) {
                k_idx = i;
                break;
            }
        }
        if (k_idx == -1) { return false; }
        q = new Quat();
        long j_len = (k_idx - 1 - i_idx)%(4*sb.length());
        for (long i=i_idx+1; i < i_idx+1+j_len; i++ ) {
            multQ(q,sb.charAt((int)(i%sb.length())),false);
        }
        return ((q.v == 'j') && !q.isNeg);
    }
    static String solve(Scanner cin) {
       int patlen = cin.nextInt();
       long patrep = cin.nextLong();
       String pat = cin.next();
       if ((patlen < 2) || (patlen*patrep < 3)) {
           return "NO";
       }
       return canReduce(pat,patrep)? "YES" : "NO";
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
