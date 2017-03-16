

import java.io.*;
import java.util.*;
import java.math.*;

public class Energy {

    static Scanner in;
    static BufferedWriter out;

    static int max;

    static int E;
    static int R; 
    static int N; 

    static int[] v;

    public static void main(String[] args) throws IOException {
        
        in = new Scanner(new File("Energy.in"));
        out = new BufferedWriter(new FileWriter("Energy.out"));

        int length = in.nextInt();

        for (int test = 0; test < length; test++) {
            max = 0;

            E = in.nextInt();
            R = in.nextInt();
            N = in.nextInt();
            v = new int[N];
            for (int i = 0; i < N; i++) {
                v[i] = in.nextInt();
            }

            dfs(E, 0, 0);


            out.write("Case #" + (test + 1) + ": " + max + "\n");
        }

        in.close();
        out.close();
    }

    public static void dfs(int cur, int activity, int gain) {
        if (activity == v.length) {
            if (gain > max)
                max = gain;
        } else {
            /*
            // spend all
            dfs(R, activity+1, gain + (cur*v[activity]));

            if (E - cur < R && cur+R-E < cur) {
                // spend the waste
                dfs(E, activity+1, gain + (cur+R-E)*v[activity]);
            } else {
                //  none
                dfs(cur+R, activity+1, gain);
            }
            */
            for (int i = 0; i <= cur; i++) {
                dfs(Math.min(E, cur-i+R), activity+1, gain + i*v[activity]);
            }
        }
    }

}    