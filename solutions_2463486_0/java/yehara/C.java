package gcj2013.qual;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
    
    static PrintWriter out;
    static long[] memo = new long[10000001];

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/qual/C-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        init();
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            long A = s.nextLong();
            long B = s.nextLong();
            long res = solve(A, B);
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static void init() {
        for(int i=1 ; i <= 10000000; i++) {
            if(isp(i) && isp((long)i*i)) {
                memo[i] = memo[i-1] + 1;
            } else {
                memo[i] = memo[i-1];
            }
        }
    }
    
    static boolean isp(long p) {
        String s = Long.toString(p);
        String r = new StringBuilder(s).reverse().toString();
        return s.equals(r);
    }
    
    static long rootFloor(long n) {
        if(n == 0) return 0;
        long s = (long)Math.floor(Math.sqrt(n));
        if(!(s*s <= n)) return s-1;
        if(!((s+1)*(s+1) > n)) return s+1;
        return s;
    }
    static long solve(long a, long b) {
        return memo[(int)rootFloor(b)] - memo[(int)rootFloor(a-1)];
    }
}
