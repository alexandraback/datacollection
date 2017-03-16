import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.List;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/9/2016.
 */
public class JamCoin {

    public static class Solver {
        private List<Integer> primes;
        public Solver() {
            primes = Sieve.sieve_of_eratosthenes(1<<18);
        }
        public long[][] solve(int size, int nbCoin) {
            int max = (1<<(size-2)) -1;
            int cur = 0;
    //        System.out.println(toBase(5,2)+ " " + toBase(5,10)+ " " +  Integer.parseInt("101",2));
            int nbFound = 0;
            long[][] res = new long[nbCoin][];
            while(nbFound<nbCoin&&cur<=max) {
                long[] candidate = new long[10];
                long s =  toBinary(cur,size);
                boolean ok = true;
                candidate[0] = s;
                for (int i=2;i<=10;i++) {
                    long div = getDivisor(s, i);
                    if (div>0) {
                        candidate[i-1] = div;
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    res[nbFound] = candidate;
                    nbFound++;
                }
                cur ++;
            }

            return res;
        }

        private long toBinary(long cur, int size) {
            return 1l<<size-1 | 1l |  cur<<1;
        }

        public long getDivisor(long bin, int base) {
            long n =Long.parseLong(Long.toBinaryString(bin),base);
            for (int i:this.primes) {
                if (i>=n) break;
                if (n%i==0) {
                    return i;
                }
            }
            return -1;
        }

        private long toBase(long bin, int base) {
            int n = 1;
            long l = 0;
            while(bin>0) {
                if (1 == (1 & bin)) {
                    l += n;
                }
                n *=base;
                bin = bin>>1;
            }
            return l;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("jamcoin/C-small-attempt3.in"));
        PrintStream printStream =  new PrintStream("C:\\Users\\benoi_000\\workspace\\codeJam2016\\process\\jamcoin\\C-small-attempt4.text" );
        //scanner = new Scanner(Thread.currentThread().getContextClassLoader().getResourceAsStream("jamcoin/test.txt"));
         //printStream =  System.out;
        int nb = scanner.nextInt();
        scanner.nextLine();
        for (int i=0;i<nb;i++) {
            int n = scanner.nextInt();
            int j = scanner.nextInt();
            printStream.println("Case #"+(i+1)+":");
            long res[][] = new Solver().solve(n,j);
            for(long[] r:res) {
                boolean first =true;
                for (long a:r) {
                    if (first) {
                        String s = Long.toBinaryString(a);
                        printStream.print(s);
                        first = false;
                    } else {
                        printStream.print(' ');
                        printStream.print(a);
                    }
                }
                printStream.println();
            }

        }
    }


    public static class PrimeGen {

        public static void main(String args[]) {


        }
    }
}
