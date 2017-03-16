
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;
    static int A, N;
    static int[] other = new int[100];

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("inA.txt"));
        out = new PrintWriter("outA.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int i = 1; i <= T; i++) {
            A = ni();
            N = ni();
            for (int j = 0; j < N; j++) {
                other[j] = ni();
            }
            printf("Case #%d: %s\n", i, proc());
        }


        // End of User Code
        in.close();
        out.close();
    }
    static int[][] dp = new int[100][100];
    static String proc() {
        Arrays.sort(other, 0, N);
        return min(A, 0) + "";
    }
    
    static int min(int A, int ind){
        if(ind == N){
            return 0;
        }
        if(A > other[ind]){
            return min(A + other[ind], ind + 1);
        }else{
            if(A==1){
                return N-ind;
            }
            int k = 1 + min(A + A-1, ind);
            int kk = N - ind;
            return Math.min(k, kk);
        }
    }

    static void printf(String format, Object... args) {
        System.out.printf(format, args);
        out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

  

    static int max(int a, int b) {
        return a > b ? a : b;
    }

  

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
