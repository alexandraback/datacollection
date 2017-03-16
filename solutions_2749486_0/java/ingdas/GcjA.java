/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcja;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 *
 * @author ingdas
 */
public class GcjA {
    public static Scanner in = new Scanner(System.in);
    public static HashMap<ArrayList<Integer>,String> sol = new HashMap();
    public static HashSet<ArrayList<Integer>> last = new HashSet();
    public static Integer nextJump = 1;
   
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<Integer> nul = new ArrayList<Integer>();
        nul.add(0);nul.add(0);
        sol.put(nul, "");
        last.add(nul);
        ArrayList<Integer> test = new ArrayList<Integer>();
        test.add(0);
        test.add(0);
        Integer cases = in.nextInt();
        for (Integer i = 0; i < cases; i++) {
            System.out.print("Case #"+(i+1)+": ");
            solve();
        }
    }

    private static void solve() {
        Integer x = in.nextInt();
        Integer y = in.nextInt();
        ArrayList<Integer> co = new ArrayList<Integer>();
        co.add(x);
        co.add(y);
        solve(co);

    }

    private static void solve(ArrayList<Integer> co) {
        while (!sol.containsKey(co)){
            HashSet<ArrayList<Integer>> nLast = new HashSet<ArrayList<Integer>>();
            for(ArrayList<Integer> x : last){
                String s = sol.get(x);
                
                ArrayList<Integer> n = new ArrayList(x);
                n.set(1, n.get(1)+nextJump);
                if(!sol.containsKey(n)){
                    sol.put(n, s+"N");
                    nLast.add(n);
                }
                
                
                n = new ArrayList(x);
                n.set(1, n.get(1)-nextJump);
                if(!sol.containsKey(n)){
                sol.put(n, s+"S");
                nLast.add(n);
                }
                
                n = new ArrayList(x);
                n.set(0, n.get(0)+nextJump);
                if(!sol.containsKey(n)){
                sol.put(n, s+"E");
                nLast.add(n);
                }
                
                n = new ArrayList(x);
                n.set(0, n.get(0)-nextJump);
                if(!sol.containsKey(n)){
                sol.put(n, s+"W");
                nLast.add(n);
                }
            }
            last = nLast;
            nextJump ++;
        }
        System.out.println(sol.get(co));
    }
    
}
