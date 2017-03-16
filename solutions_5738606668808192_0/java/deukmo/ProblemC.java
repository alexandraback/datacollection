import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC {
    private static final String FILENAME = "C-small-attempt0";
    
    private static ArrayList<Long> primes = new ArrayList<Long>();

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        for (long n = 2; n <= 111111L; n++) {
        	boolean isPrime = true;
        	for (int i = 0; i < primes.size(); i++) {
        		if (n % primes.get(i) == 0) {
        			isPrime = false;
        			break;
        		}
        	}
        	if (!isPrime) continue;
        	primes.add(n);
        }

        long start = System.currentTimeMillis();
        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	output.print("Case #" + t + ": \n");

        	int N = input.nextInt();
        	int J = input.nextInt();

        	long[] nBase = new long[11];
        	boolean legitimate = true;
        	int jCnt = 0;

        	int max = (int) Math.pow(2, (N - 2));
        	for (int i=0; i<max; i++) {
        		int n = (1 << (N - 1)) | (i << 1) | 1;
        		legitimate = true;
        		for (int b=2; b<=10; b++) {
        			nBase[b] = getNBase(n, b);
        			if (primes.indexOf(nBase[b]) != -1 || getDivisor(nBase[b]) == 0) {
        				legitimate = false;
        				break;
        			}
        		}
        		if (!legitimate) continue;

        		output.print(getBinaryString(n));
        		for (int b=2; b<=10; b++) {
        			output.print(" " + getDivisor(nBase[b]));
        		}
        		output.print("\n");

        		if (++jCnt == J) break;
        	}
        }
        System.out.print("Total duration: " + (System.currentTimeMillis() - start) + "ms\n");

        input.close();
        output.close();
	}

	public static long getNBase(int n, int base) {
		long r = 0;
		int idx = 0;
		while (n > 0) {
			r = r + (n & 1) * (long) Math.pow(base, idx++);
			n = n >> 1;
		}
		return r;
	}
	
	public static long getDivisor(long n) {
		for (int i = 0; i < primes.size(); i++) {
			if (n % primes.get(i) == 0) return primes.get(i);
		}
		return 0;
	}

	public static String getBinaryString(int n) {
		String r = "";
		while (n > 0) {
			r = (((n & 1) == 0) ? "0" : "1") + r;
			n = n >> 1;
		}
		return r;
	}
}
