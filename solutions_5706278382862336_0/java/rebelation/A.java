import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    long gcd(long x, long y) {
        long t;
        while (y != 0) {
            t = x % y; x = y; y = t;
        }
        return x;
    }

    boolean isP(long v){
        if(v == 1)
            return false;
        else if(v == 2)
            return true;
        int lim = (int)sqrt(v);
        for(int i = 2; i <= lim; i++)
            if(v % i == 0)
                return false;
        return true;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        loop:
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            String[] pq = sc.next().split("/");
            long p = Long.parseLong(pq[0]);
            long q = Long.parseLong(pq[1]);
            long pqg = gcd(p, q);
            p /= pqg;
            q /= pqg;
            if(q > 2 && isP(q)){
                System.out.println("impossible");
                continue;
            }
            long cur = 1;
            for(int i = 0; i < 40; i++){
                cur *= 2;
                long g = gcd(cur, q);
                long tq = q/g;
                long tc = cur/g;
                long rest = p * tc - tq;
                if(rest < 0)
                    continue;
                if(Long.bitCount(tq) != 1)
                    continue;
                System.out.println(i+1);
                continue loop;
            }
            System.out.println("impossible");
        }
    }
}
