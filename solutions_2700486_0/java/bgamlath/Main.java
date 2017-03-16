
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;

    static int N, X, Y;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("inB.txt"));
        out = new PrintWriter("outB.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int i = 1; i <= T; i++) {
            N = ni();
            X = ni();
            Y = ni();
            printf("Case #%d: %s\n", i, proc());
        }


        // End of User Code
        in.close();
        out.close();
    }

    static double proc() {
        long top = Y;
        if(X > 0){
            top = Y + X;
        }else{
            top = Y - X;
        }
        long total = (top + 1)*(top + 2)/2;
//        if(total - top - Y < N){
//            return 1.0;
//        }
//        if(total - top - top + Y >= N){
//            return 0.0;
//        }
        if(Y==top && total > N)
            return 0;
        return get(Y + 1, top, N - (total - (top + top + 1)));
    }
static double get(int min, long max, long rem){
    if(rem < min){
        return 0.0;
    }
    if(rem >=max + min){
        return 1.0;
    }
    double[] bp = new double[(int)rem + 1];
    bp[0] = Math.pow(0.5, rem);
    for(int i = 1; i<bp.length; i++){
        bp[i] = bp[i-1]*(rem - i + 1)/(i);
    }
  double res = 0;

   for(int i = min; i<=rem; i++){
        res += bp[i];
   }
//   for(int j = (int)max + 1; j<=rem; j++){
//       if(rem - j + 1 >=min){
//           res += bp[j];
//       }
//   }
    return res;
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