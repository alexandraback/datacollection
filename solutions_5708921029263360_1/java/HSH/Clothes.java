import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.StringBuilder;
import java.lang.Math;

public class Clothes {

    public Clothes() {

        Scanner s = new Scanner(System.in);

        int trials = s.nextInt();
        int lines = 0;

        
        for (int z = 0; z < trials; z++) {
            s.nextLine();
            int J = s.nextInt();
            int P = s.nextInt();
            int S = s.nextInt();
            int K = s.nextInt();
            lines++;
            
            int smaller = Math.min(S,K);


            System.out.println("Case #" + lines + ": " + J*P*smaller);
            for (int j = 1; j <= J; j++) {
                for (int p = 1; p <= P; p++) {
                    for (int k = j+p-1; k < j+p+smaller-1; k++) {
                        System.out.println(j + " " + p + " " + fix(k, S));
                    }
                }
            }

        }

    }
    
    private static int fix(int x, int mod) {
        int y = x % mod;
        if (y == 0) return mod;
        return y;
    }
    
    public static void main(String args[]) {

        Clothes save = new Clothes();
    }
   

   
}