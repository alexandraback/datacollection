import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    final String LINE_SPR = System.getProperty("line.separator");
    final int BIG_MOD = 1000000007;
    List<Long> denos = new ArrayList<Long>();
    int c;
    long v;

    void run() throws Exception {
        int nt = ni();
        for(int t = 0; t < nt; t++) {
            denos.clear();
            String[] nums = ns().split(" ");
            c = Integer.parseInt(nums[0]);
            int d = Integer.parseInt(nums[1]);
            v = Long.parseLong(nums[2]);
            //System.out.println("Case " + t + ":");

            String[] ds = ns().split(" ");
            for(String str : ds) 
                denos.add(Long.parseLong(str));
            /*
            System.out.println("C:D:V => " + c + ":" + d + ":" + v);
            System.out.println("Denos => " + denos);
            */

            gcjPrint(Long.toString(calc(0, 0, 0, false)), t + 1);
        }
    }

    long calc(long count, long curmax, int denoind, boolean debug) {
        if(debug)
            System.out.println("c:cur:den => " + count + ":" + curmax + ":" + denoind);
        if(curmax >= v)
            return count;

        long tmpmax;

        if(denoind >= denos.size() || denos.get(denoind) != curmax + 1) {
            if(debug)
                System.out.println("added coin: " + (curmax + 1));
            count++;
        } else {
            denoind++;
        }

        // (curmax + 1)円硬貨を持っている
        curmax = curmax + (curmax + 1) * c;
        if(debug)
            System.out.println("new max: " + curmax);

        // 限界まで伸ばす
        while(denoind < denos.size() && denos.get(denoind) <= curmax) {
            curmax = curmax + denos.get(denoind) * c;
            if(debug)
                System.out.println("new max: " + curmax);
            denoind++;
        }

        return calc(count, curmax, denoind, debug);
    }


    /*
     * Templates
     */
    void dumpObjArr(Object[] arr, int n) {
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i]);
            if(i < n - 1)
                System.out.print(" ");
        }
        System.out.println("");
    }

    void dumpObjArr2(Object[][] arr, int m, int n) {
        for(int j = 0; j < m; j++) 
            dumpObjArr(arr[j], n);
    }

    int ni() throws Exception {
        return Integer.parseInt(br.readLine().trim());
    }

    long nl() throws Exception {
        return Long.parseLong(br.readLine().trim());
    }

    String ns() throws Exception {
        return br.readLine();
    }

    boolean isPrime(int n) {
        for(int i=2;i<n;i++) {
            if(n%i==0)
                return false;
        }
        return true;
    }

    int getPrime(int n) {
        List<Integer> primes = new ArrayList<Integer>();
        primes.add(2);
        int count = 1;

        int x = 1;
        while(primes.size() < n) {
            x+=2;
            int m = (int)Math.sqrt(x);
            for(int p : primes) {
                if(p > m) {
                    primes.add(x);
                    break;
                }

                if(x % p == 0) 
                    break;
            }
        }

        return primes.get(primes.size() - 1);
    }

    void gcjPrint(String str, int t) {
        System.out.println("Case #" + t + ": " + str);
    }

    public static void main(String[] args) throws Exception {
        new Main().run();
    }
}




