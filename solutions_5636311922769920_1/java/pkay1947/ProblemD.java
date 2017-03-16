import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class ProblemD {


    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt() ;
        String[] ar = new String[n];
        for (int i = 1 ; i <= n ; i++) {
    			   int K = in.nextInt();
             int C = in.nextInt();
             int S = in.nextInt();
             ar[i-1] = "";
             if (S == K) {
               int j = 1;
               while (j <= K) {
                  ar[i-1] += " " + j;
                  j++;
               }
             } else {
               ar[i-1] = "IMPOSSIBLE";
             }
        }
        for (int i = 1 ; i <= n ; i++) {
    			   System.out.println("Case #" + i + ": " + ar[i-1].trim());
        }
		    in.close();
    }
}
