
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ehsan
 */
public class War {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(new File("/home/ehsan/Downloads/dlarge.in"));
        //Scanner in = new Scanner(new File("/home/ehsan/Documents/Copy/Programming/CodeJam/CJamApril14/src/test"));
        int n_tests = in.nextInt();
        Game[] games = new Game[n_tests];
        for (int t = 0; t < n_tests; t++) {
            int N = in.nextInt();
            games[t] = new Game(N);
            for (int j = 0; j < N; j++) {
                games[t].wn[j] = in.nextDouble();                
            }
            for (int j = 0; j < N; j++) {
                games[t].wk[j] = in.nextDouble();                
            }
            Arrays.sort(games[t].wk);
            Arrays.sort(games[t].wn);            
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("/home/ehsan/results.txt"));
        
        for (int t = 0; t < n_tests; t++) {
            System.out.println("Case #" + (t + 1) + ": " + games[t].dwar() + " " + games[t].war());
            bw.write("Case #" + (t + 1) + ": " + games[t].dwar() + " " + games[t].war() + "\n");
        }
        bw.close();
    }
    
    static class Game {
        double[] wn, wk;
        Game(int N) {
            wn = new double[N];
            wk = new double[N];
        }
        int war() {
            int pt = 0;
            double[] n = Arrays.copyOf(wn, wn.length);
            double[] k = Arrays.copyOf(wk, wk.length);
            for (int i = 0; i < n.length; i++) {
                int pos_n = 0;
                while(n[pos_n] < 0) pos_n++;
                double nplays = n[pos_n];
                int pos_k = 0;
                for (pos_k = 0; pos_k < n.length; pos_k++)
                    if (k[pos_k] > nplays) break;
                if (pos_k < n.length) k[pos_k] = -k[pos_k];
                else {pt++;}
                n[pos_n] = -n[pos_n];
            }
            return pt;
        }
        int dwar() {
            LinkedList<Double> ln = new LinkedList<Double>();
            LinkedList<Double> lk = new LinkedList<Double>();
            for (int i = 0; i < wn.length; i++) {
                ln.addFirst(wn[i]);
                lk.addFirst(wk[i]);
            }
            int pt = 0;
            while ( !ln.isEmpty() ) {
                double naomi = ln.getLast();
                double kevin = lk.getLast();
                if (naomi > kevin) {
                    pt++;
                    ln.removeLast();
                    lk.removeLast();
                }
                else {
                    ln.removeLast();
                    lk.removeFirst();
                }
            }
            return pt;
        }
    }
    
    
}
