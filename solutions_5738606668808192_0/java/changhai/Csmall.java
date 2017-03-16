
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Arrays;


public class Csmall {
    
    static void pr(Object... a) {
        if(true) return;
        for(Object x : a) {
            System.out.print(""+x+" ");
        }
        System.out.println();
    }
    
    static int[] primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
            71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 
            149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
            227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293,
            307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383,
            389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
            467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
            571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647,
            653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743,
            751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839,
            853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
            947, 953, 967, 971, 977, 983, 991, 997
    };
    
    boolean next(char[] cs, int n) {
        for(int i=n-2; i>0; i--) {
            if(cs[i] == '0') {
                cs[i] = '1';
                Arrays.fill(cs, i+1, n-1, '0');
                return true;
            }
        }
        return false;
    }
    
    Object solve(int n, int j) {
        BigInteger[] ps = new BigInteger[primes.length];
        for(int i=0; i<primes.length; i++) {
            ps[i] = BigInteger.valueOf(primes[i]);
        }
        
        char[] cs = new char[n];
        Arrays.fill(cs, '0');
        cs[0] = cs[n-1] = '1';
        
        int already = 0;
        StringBuilder sb = new StringBuilder();
        int[] proof = new int[11];
        
        FIND: while(true) {
            if(already == j) break;
            if(!next(cs, n)) break;
            String s = new String(cs);
            for(int r=2; r <= 10; r++) {
                BigInteger x = new BigInteger(s, r);
                if(x.isProbablePrime(50)) {
                    continue FIND;
                }
                boolean proved = false;
                for(BigInteger p : ps) {
                    if(x.gcd(p).equals(p)) {
                        proof[r] = p.intValue();
                        proved = true;
                        pr(s+" "+r+" "+x+" "+p);
                        break;
                    }
                }
                if(!proved) continue FIND;
            }
            already ++;
            sb.append(s);
            for(int r=2; r<=10; r++) {
                sb.append(" ").append(proof[r]);
            }
            sb.append("\n");
            pr(s+"!!!");
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        String ofile = args[0];
        System.out.println("output file is "+ofile);
        Writer writer = new FileWriter(ofile);
        int n = 16;
        int j = 50;
        
        Csmall problem = new Csmall();
        Object rt = problem.solve(n,j);
        pr(rt);
        writer.write("Case #1:\n");
        writer.write(rt.toString());
        
        writer.close();
    }

}

