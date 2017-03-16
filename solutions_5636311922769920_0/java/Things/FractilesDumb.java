
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class FractilesDumb {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner scan = new Scanner(new File("fractiles.in"));
        PrintWriter writer = new PrintWriter(new File("fractiles.out"));
        
        
        int cases = scan.nextInt();
        
        for (int i = 0; i < cases; i++) {
            System.out.println(i);
            int k = scan.nextInt();
            int c = scan.nextInt();
            int s = scan.nextInt();
            int req = (int)Math.ceil((double)k / c);
            if ((s < req)) {
                writer.write(String.format("Case #%d: %s%n", i+1, "IMPOSSIBLE"));
                continue;
            }
            ArrayList<Long> ans = new ArrayList<Long>();
            //BigInteger secSize = BigInteger.valueOf(k)
            long secSize = (long)Math.pow(k, c-1);
            for (long j = 0; j < s; j++) {
                ans.add(j*secSize + 1);
            }
            String result = "";
            for (Long ii : ans) {
                result += (ii) + " ";
            }
            writer.write(String.format("Case #%d: %s%n", i+1, result.trim()));
        }
        writer.close();
    }
    
    // 0-based indices
    // index1 is original index
    // index2 is index after stuff happens
    static boolean revealsIndex(long index1, int k, int c, long index2) {
        if (c==0) {
            return false;
        }
        int secSize = (int)Math.pow(k, c-1);
        if (index2 < index1 * secSize && index2 >= (index1 - 1) * (secSize)) {
            return true;
        }
        else {
            return (index2-index1+1) % k == 0 || revealsIndex(index1, k, c-1, index2 % secSize);
        }
    }
    
    static class IndexSet {
        
    }
}
