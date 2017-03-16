import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by sergey on 11.05.14.
 */
public class Solution {
    Scanner in;
    PrintStream out;

    Solution(){
        in = new Scanner(System.in);
        out = new PrintStream(System.out);
    }
    public static void main(String args[]){
        new Solution().run();
    }

    private void run() {
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.printf("Case #%d: ", i + 1);
            solveCase();
        }
    }
    long gcd(long a, long b){
        long tmp;
        if(b == 0) return a;
        if( a < b){
            tmp = a;
            a = b;
            b = tmp;
        }
        return gcd(b, a % b);
    }
    boolean isp2(long n){
        return ((n & (-n)) == n);
    }

    private void solveCase() {
        StringBuffer line = new StringBuffer(in.next());
//        System.err.println(line);
        int pos = line.indexOf("/");
        long P = Long.parseLong(line.substring(0, pos));
        long Q = Long.parseLong(line.substring(pos + 1));
        long gcd = gcd(P, Q);
        long two40 = (long) Math.pow(2, 40);
        P /=  gcd;
        Q /= gcd;
        if(! isp2(Q)){
            out.println("impossible");
            return;
        }
        int gen = 40;
        while( Q != two40){
            Q *= 2;
            P *= 2;
        }
        long sum = 0;
        while( sum < P ){
            sum = 2*sum + 1;
            gen--;
        }
        out.println(Integer.toString(gen + 1));
    }
}
