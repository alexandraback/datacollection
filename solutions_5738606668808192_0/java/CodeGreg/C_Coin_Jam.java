import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;

public class C_Coin_Jam {

    static List<BigInteger> primes;

    public static void main(String[] args) {
        primes = new ArrayList<>();
        for (int x = 2; x < (1 << 16); ++x) {
            boolean valid = true;
            for (BigInteger p : primes)
                if (x % p.intValue() == 0) {
                    valid = false;
                    break;
                }
            if (valid)
                primes.add(BigInteger.valueOf(x));
        }
        
        System.out.println("primes: " + primes.size());
        
        try {
            Scanner s = new Scanner(new BufferedReader(new FileReader("large.in")));
            Writer w = new BufferedWriter(new FileWriter("large.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                int N = s.nextInt();
                int J = s.nextInt();
        
                Set<BigInteger> prev = new TreeSet<>();
        
                boolean[] number = new boolean[N];
                BigInteger[] divs = new BigInteger[11];
                
                w.write("Case #" + (t + 1) + ": " + "\n");
                while (J > 0) {
                    number[0] = true;
                    number[N-1] = true;
                    for (int i = 1; i < N-1; ++i) {
                        number[i] = (Math.random() >= 0.5);
//                        System.out.println("number[" + i + "]: " + number[i]);
                    }
                    
                    BigInteger num = BigInteger.ZERO;

                    boolean valid = true;
                    
                    for (int base = 2; valid && base <= 10; ++base) {
                        num = BigInteger.ZERO;
                        BigInteger coef = BigInteger.ONE;
                        for (int i = 0; i < N; ++i) {
                            if (number[i])
                                num = num.add(coef);
                            coef = coef.multiply(BigInteger.valueOf(base));
                        }
                        
//                        System.out.println("Base " + base + ", num " + num);
                        valid = false;
                        for (int p = 0; p < primes.size() && primes.get(p).compareTo(num) < 0; ++p)
                            if (num.divideAndRemainder(primes.get(p))[1].equals(BigInteger.ZERO)) {
                                valid = true;
                                divs[base] = primes.get(p);
                                break;
                            }
                    }
                    
//                    System.out.println("NUM: " + num);
                    
                    if (valid && !prev.contains(num)) {
                        w.write(num.toString());
                        for (int base = 2; base <= 10; ++base) {
                            w.write(" " + divs[base]);
                        }
                        w.write("\n");
                        J--;
                        prev.add(num);
                    }
                }
            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(C_Coin_Jam.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}