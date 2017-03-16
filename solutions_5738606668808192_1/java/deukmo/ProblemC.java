import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC {
    private static final String FILENAME = "C-large";
    
    private static ArrayList<BigDecimal> primes = new ArrayList<BigDecimal>();

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        long start = System.currentTimeMillis();
        boolean isPrime = true;
        for (int n = 2; n <= 100000; n++) {
        	isPrime = true;
        	for (int i = 0; i < primes.size(); i++) {
        		if (new BigDecimal(n).remainder(primes.get(i)).longValue() == 0) {
        			isPrime = false;
        			break;
        		}
        	}
        	if (!isPrime) continue;
        	primes.add(new BigDecimal(n));
        }

        System.out.print("Primes duration: " + (System.currentTimeMillis() - start) + "ms\n");

        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	output.print("Case #" + t + ": \n");

        	int N = input.nextInt();
        	int J = input.nextInt();

        	BigDecimal[] nBase = new BigDecimal[11];
        	boolean legitimate = true;
        	long divisor;
        	String divisors = "";
        	int jCnt = 0;

        	int max = (int) Math.pow(2, (N - 2));
        	for (int i=0; i<max; i++) {
        		long n = (1L << (N - 1)) | ((long)i << 1) | 1;
        		legitimate = true;
        		divisors = "";
        		for (int b=2; b<=10; b++) {
        			nBase[b] = getNBase(n, b);
        			divisor = getDivisor(nBase[b]);
        			if (divisor == 0) {
        				legitimate = false;
        				break;
        			}
        			divisors += " " + divisor;
        		}
        		if (!legitimate) continue;

        		output.println(getBinaryString(n) + divisors);

        		if (++jCnt == J) break;
        	}
        }
        System.out.print("Total duration: " + (System.currentTimeMillis() - start) + "ms\n");

        input.close();
        output.close();
	}

	public static BigDecimal getNBase(long n, int base) {
		BigDecimal r = new BigDecimal(0);
		BigDecimal pow = new BigDecimal(1);
		BigDecimal bbase = new BigDecimal(base);
		while (n > 0) {
			if ((n & 1) == 1) {
				r = r.add(pow);
			}
			pow = pow.multiply(bbase);
			n = n >> 1;
		}
		return r;
	}
	
	public static long getDivisor(BigDecimal n) {
		for (int i = 0; i < primes.size(); i++) {
			if (n.remainder(primes.get(i)).longValue() == 0) return primes.get(i).longValue();
		}
		return 0;
	}

	public static String getBinaryString(long n) {
		String r = "";
		while (n > 0) {
			r = (((n & 1) == 0) ? "0" : "1") + r;
			n = n >> 1;
		}
		return r;
	}
}
