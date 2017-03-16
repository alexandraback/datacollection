//package Qualification;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.File;
import java.util.*;
import java.math.*;
import java.util.regex.*;

/**
 *
 * @author Jurek
 */
public class A {
    
    public static boolean testWin(char[] in, char win) {
        for(int i = 0; i < in.length; i++) {
            if(in[i] != win && in[i] != 'T') {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        long start = System.currentTimeMillis ();            
        
        // =====================================================================
        // Operation
        // =====================================================================       
        
        Scanner in = new Scanner(System.in);
        char[][] board = new char[4][4];
        int kases = in.nextInt();
        String line;
        
        boolean notFinished = false;        
        for(int kase = 1; kase <= kases; kase++) {
            notFinished = false;
            
            // Read in
            in.nextLine();
            for(int i = 0; i < 4; i++) {
                line = in.nextLine();
                for(int j = 0; j < 4; j++) {
                    board[i][j] = line.charAt(j);
                    if(board[i][j] == '.') {
                        notFinished = true;
                    }
                }
            }     
            
            // Check winner
            boolean xWin = false;
            boolean oWin = false;
            for(int i = 0; i < 4; i++) {
                char[] column = new char[4];
                for(int j = 0; j < 4; j++) {
                    column[j] = board[j][i];
                }
                if(testWin(board[i], 'X') || testWin(column, 'X')) {
                    xWin = true;
                    break;
                }
                if(testWin(board[i], 'O') || testWin(column, 'O')) {
                    oWin = true;
                    break;
                }
            }
            char[] diagonal1 = new char[4];
            char[] diagonal2 = new char[4];
            for(int i = 0; i < 4; i++) {
                diagonal1[i] = board[i][i];
                diagonal2[i] = board[i][4 - i - 1];
            }
            if (testWin(diagonal1, 'X') || testWin(diagonal2, 'X')) {
                xWin = true;
            }
            if (testWin(diagonal1, 'O') || testWin(diagonal2, 'O')) {
                oWin = true;
            }
   
            // Print
            //for(int i = 0; i < 4; i++) {
            //    pl(Arrays.toString(board[i]));
            //}
            
            pr("Case #" + kase + ": ");
            if(xWin) {
                pl("X won");
            } else if(oWin) {
                pl("O won");
            } else if(notFinished) {
                pl("Game has not completed");
            } else {
                pl("Draw");
            }
            
            //pl();
            
        }
        
        // =====================================================================
        // Output
        // =====================================================================
        long end = System.currentTimeMillis ();
        
        //pl("============" + (end - start) + " ms");
        //pl("");
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }
    
    public static void pl() {
        System.out.println("");
    }

    public static void pl(ArrayList<Object> i) {
        System.out.println(Arrays.toString(i.toArray()));
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
