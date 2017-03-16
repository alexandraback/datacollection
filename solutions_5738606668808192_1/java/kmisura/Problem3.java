import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Problem3 {
    static List<String> solutions;
    static int N;
    static int J;
    
    static List<BigInteger> primes;
    
    static void sieve(int max){
        boolean[] p = new boolean[max];
        Arrays.fill(p, true);
        p[0] = p[1] = false;
        for(int i=2;i<max;i++)
            if(p[i])
                for(int j=2*i;j<max;j+=i)
                    p[j] = false;
        primes = new ArrayList<BigInteger>();
        for(int i=0;i<max;i++)
            if(p[i])
                primes.add(BigInteger.valueOf(i));
    }

    public static void main(String[] args) throws FileNotFoundException {
        sieve(10000000);
        Scanner sc = new Scanner(new File("data/C-large.in"));
        PrintWriter out = new PrintWriter(new File("data/C-large.out"));
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            N = sc.nextInt();
            J = sc.nextInt();
            solutions = new ArrayList<String>();
            boolean[] b = new boolean[N];
            b[0] = true;
            b[N - 1] = true;
            generateSolutions(b, 1);
            out.println("Case #" + t + ":");
            for (String solution : solutions) {
                out.print(solution + " ");
                printDivisors(solution, out);
                out.println();
            }
        }
        sc.close();
        out.close();
    }
    
    static void printDivisors(String s, PrintWriter out){
        for(int base = 2; base <= 10; base++){
            BigInteger bi = new BigInteger(s, base);
            boolean found = false;
            while(!found){
                for(BigInteger p : primes){
                    if(p.compareTo(bi) >= 0)
                        break;
                    if(bi.remainder(p).equals(BigInteger.ZERO)){
                        found = true;
                        out.print(p.toString() + " ");
                        break;
                    }
                }    
            }
        }
    }

    static void generateSolutions(boolean[] b, int idx) {
        if (solutions.size() == J) {
            return;
        }
        if (idx == N - 1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < b.length; i++) {
                sb.append(b[i] ? 1 : 0);
            }
            String s = sb.toString();
            for (int base = 2; base <= 10; base++) {
                BigInteger bi = new BigInteger(s, base);
                if (bi.isProbablePrime(30)) {
                    return;
                }
            }
            
            for(int base = 2; base <=10; base++){
                BigInteger bi = new BigInteger(s, base);
                boolean found = false;
                for(BigInteger p : primes){
                    if(p.compareTo(bi) >= 0)
                        break;
                    if(bi.remainder(p).equals(BigInteger.ZERO)){
                        found = true;
                        break;
                    }
                }
                if(!found)
                    return;
            }
            
            
            solutions.add(s);
            return;
        }
        b[idx] = false;
        generateSolutions(b, idx + 1);
        b[idx] = true;
        generateSolutions(b, idx + 1);
        b[idx] = false;
    }

}
