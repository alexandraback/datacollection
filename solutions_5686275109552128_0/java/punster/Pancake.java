/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pancake;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author kiss
 */
public class Pancake {
    static final String WORKDIR = "C:\\proj\\codejam\\2015\\qual_b\\";
    
    static int idealNumLeaves(int n) {
        return ((int)Math.sqrt(n));
    }
    static int leaf(int n, int numLeaves) {
        return (n/numLeaves + ((n%numLeaves)==0?0:1));
    }
    static int savings(int n, int numLeaves) {
        if (numLeaves == 1) { return 0; }
        return leaf(n,numLeaves-1)-leaf(n,numLeaves)-1;
    }
    static int canYou(int[] plates, int idx, int target, int numSplits) {
        if (idx < 0) { return 0; }
        if (plates[idx] <= target) {
            return 0;
        }
        if (numSplits == 0) { return -1; }
        for (int i=1; i <= numSplits; i++) {
            if (leaf(plates[idx],i+1) <= target ) {
                int temp = canYou(plates,idx-1,target,numSplits-i);
                return ((temp == -1) ? -1 : temp+i);
            }
        }
        return -1;
    }

    static int solve(Scanner cin) {
       int num = cin.nextInt();
       int [] plates = new int[num];
       for (int i=0; i < num; i++) {
           plates[i] = cin.nextInt();
       }
       java.util.Arrays.sort(plates);
       if (plates[num-1] <= 3) {
           return (plates[num-1]);
       }
       int temp = idealNumLeaves(plates[num-1]);
       int temp2 = leaf(plates[num-1], temp);
       if ((plates.length == 1) || 
               (plates[num-2] <= temp2)) {
           return temp+temp2-1;
       }
       int best = plates[num-1];
       for (int i=idealNumLeaves(plates[num-1]); i > 1; i--) {
           int currLeaf = leaf(plates[num-1],i);
           int maxsavings = savings(plates[num-1], i);
           for (int j=0; j<maxsavings; j++) {
               int cost = canYou(plates,num-2,currLeaf+j,maxsavings-j-1);
               if ((cost != -1) && (cost+currLeaf+j+i-1 < best)) {
                   best = cost+currLeaf+j+i-1;
               }
           }
       }
       return best;
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
