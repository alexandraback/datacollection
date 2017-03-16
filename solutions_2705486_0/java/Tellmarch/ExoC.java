package exoC;

import exoA.*;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoC {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2013/1B/ExoC/";
        String input = base + "s1.in";
        String output = base + "s1.out";
        String dict = base + "garbled_email_dictionary.txt";

        readDict(dict);

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        String msg = sc.nextLine();
        int n = msg.length();
        char[] letters = msg.toCharArray();

        // res[i][k] : min number needed, starting from position i (with a new word), with no change before k values.
        int res[][] = new int[n][6];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 6; k++) {
                res[i][k] = -1;
            }
        }

        int res0 = aux(letters, n, 0, dic, 0, res);
        pw.print(res0);
    }

    private static int aux(char[] letters, int n, int i, Node nd, int k, int[][] res) {
        //System.out.println(i + " -> " + nd.letter);
        if (i == n) {
            if (nd == dic || nd.full) {
                //System.out.println("ok");
                return 0;
            } else {
                //System.out.println("Bouh");
                return 10000;
            }
        }

        if (nd == dic && res[i][k] != -1) {
            //System.out.println("i know ! for " + i + " and " + k);
            return res[i][k];
        }

        int res0 = 10000;

        if (nd.full) {
            //System.out.println("new word");
            res0 = Math.min(res0, aux(letters, n, i, dic, k, res));
        }

        if (nd.links[letters[i] - o] != null) {
            //System.out.println("continue");
            res0 = Math.min(res0, aux(letters, n, i + 1, nd.links[letters[i] - o], Math.max(0, k - 1), res));
        }
        
        //changing a letter
        if (k == 0) {
            for(int p= 0;p<26;p++) {
                if(nd.links[p] != null) {
                    res0 = Math.min(res0, 1 + aux(letters, n, i + 1, nd.links[p], 4, res));
                }
            }
        }
        
        if (nd == dic) {
            //System.out.println("storing for " + i + " and " + k);
            res[i][k] = res0;
        }
        return res0;
    }

    private static void readDict(String dict) {
        try {
            Scanner sc = new Scanner(new FileReader(dict));
            String m = "";
            for (int k = 0; k < 521196; k++) {
                m = sc.nextLine();
                insert(m);
            }
            System.out.println(m);
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoC.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    static class Node {

        char letter;
        Node[] links;
        boolean full;

        Node(char letter, boolean full) {
            this.links = new Node[26];
            this.letter = letter;
            this.full = full;
        }
    }
    static Node dic = new Node('\0', false);
    static int o = 'a';

    static void insert(String w) {
        int l = w.length();
        char[] letters = w.toCharArray();
        Node curNode = dic;

        for (int i = 0; i < l; i++) {
            int d = letters[i] - o;
            if (curNode.links[d] == null) {
                curNode.links[d] = new Node(letters[i], false);
            }
            curNode = curNode.links[d];
        }
        curNode.full = true;
    }
}
