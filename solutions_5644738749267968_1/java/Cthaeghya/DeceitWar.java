import java.util.*;
import java.io.*;

public class DeceitWar
{

    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        
        int t = in.nextInt();
        
        for (int count = 0; count < t; count++) {
            
            int blocks = in.nextInt();
            
            double[] n = new double[blocks];
            for (int i = 0; i < blocks; i++)
                n[i] = in.nextDouble();
            double[] k = new double[blocks];
            for (int i = 0; i < blocks; i++)
                k[i] = in.nextDouble();
            Arrays.sort(n);
            Arrays.sort(k);
            
            System.out.println("Case #" + (count+1) + ": " + score(k, n, blocks, 0,0) + " " + (blocks - score(n, k, blocks, 0, 0)));
            
        }
        
    }
    
    public static int score (double[] n, double[] k, int blocks, int burned, int score) {

        if (burned >= blocks)
            return score;
        
        if (k[burned] > n[score]) {
            return score(n, k, blocks, burned+1, score+1);
        } else {
            return score(n, k, blocks, burned+1, score);
        }
        
    }

}