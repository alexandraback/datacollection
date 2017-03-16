import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        int curCase = 1;

        sc.nextLine();

        while (numCases > 0) {
            String line = sc.nextLine();
            Scanner s = new Scanner(line).useDelimiter("/");
            long p = s.nextLong();
            long q = s.nextLong();
           
            int gens = 1;
            while (true) {
                if ( isPower2(p,q) ) {
                    if ( ((double) p/(double) q) >= 0.5 ) {
                        System.out.format("Case #%d: %d\n", curCase, gens);
                        break;
                    }
                    else {
                        //loop
                        q /= 2;
                        gens++;
                    }
                }
                else {
                    //impossible
                    System.out.format("Case #%d: impossible\n", curCase);
                    break;
                }

            }

            curCase++;
            numCases--;
        }
    }
    public static boolean isPower2(long p, long q) {
        long d = GCD(p,q);
        p /= d;
        q /= d;
        if(q == 1) { return true; }
        if(q == 0) { return false; }
        if(q % 2 != 0) { return false; }
        return isPower2(p,q/2);
    }
    
    public static long GCD(long a, long b) { return b==0 ? a : GCD(b,a%b); }
}
