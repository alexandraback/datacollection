
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static BufferedReader dict;
    static PrintWriter out;
    static StringTokenizer stk;

static String[] dic = new String[521196];
static  String ss;
    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("inC.txt"));
        dict = new BufferedReader(new FileReader("dict"));
        out = new PrintWriter("outC.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code
        for(int i =0; i<dic.length; i++){
        
            dic[i] = dict.readLine();
  
        }

        int T = ni();

        for (int i = 1; i <= T; i++) {
            ss = in.readLine();
            printf("Case #%d: %s\n", i, proc());
        }

        dict.close();
        // End of User Code
        in.close();
        out.close();
    }

    static String proc() {
        int[] dp = new int[ss.length() + 1];
        Arrays.fill(dp, 4000);
        dp[0] = 0;
        for(int i = 0; i< ss.length(); i++){
            for(int j = 0; j< dic.length; j++){
                if(dic[j].length() <= i + 1){
                    dp[i + 1] = Math.min(dp[i + 1-dic[j].length()] + changes(dic[j], i), dp[i+1]);
                }
            }
        }
        return dp[dp.length-1] + "";
    }
    static int changes(String s, int ind){
        int count = 0;
        for(int i = 0 ; i<s.length(); i++){
            if(s.charAt(i)!= ss.charAt(ind - s.length() + 1 + i))
                count ++;
        }
        return count;
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

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
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
