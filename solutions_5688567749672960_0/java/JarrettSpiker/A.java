import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by jarrett on 02/05/15.
 */
public class A {

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader(new File("read.txt")));
        int numCases = Integer.parseInt(in.readLine());
        for (int i = 0; i < numCases; i++) {
            int input = Integer.parseInt( in.readLine());
            int[] dp = new int[input];
            dp[0] = 1;

            for(int j = 1; j < dp.length; j++) {
                if (j + 1 <= flipInt(j + 1)) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = Math.min(dp[j - 1] + 1, dp[flipInt(j + 1) - 1] + 1);
                }

            }

            System.out.println("Case #" + (i+1) + ": " + dp[input-1]);

        }
    }

    public static int best(int a, int goal, int count){
        if(a == goal){
            return count;
        }
        if(flipInt(a) > goal || flipInt(a) < a){
            return best(a + 1, goal, count + 1);
        }
        return Math.min(best(a+1, goal, count +1), best(flipInt(a), goal, count +1));


    }
    public static int flipInt(int a){
        if(a%10 == 0){
            return a;
        }
        String s = String.valueOf(a);
        String r = new StringBuilder(s).reverse().toString();
        int result = Integer.parseInt(r);
        return result;
    }

}
