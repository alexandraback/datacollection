
import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ_C {
	static final String FILENAME = "C-small";
	static final int n = 16, J = 50;
	static final long[] TWO = new long[] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648L};
	static final long[] PRIME = new long[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
	static final int PNUM = 4;
	static final BigInteger[] PRS = new BigInteger[PNUM];
	static PrintWriter out;
	static final BigInteger[][] POW = new BigInteger[11][n];
	public static void main(String[] args) throws IOException {
		// construct POW
		for (int b = 2; b <= 10; b++) {
			BigInteger k = BigInteger.ONE;
			for (int e = 0; e < n; e++) {
				POW[b][e] = k;
				k = k.multiply(new BigInteger(Integer.toString(b)));
			}
		}
		// construct PRS
		for (int i = 0; i < PNUM; i++) PRS[i] = new BigInteger(Long.toString(PRIME[i]));
		
		out = new PrintWriter(new BufferedWriter(new FileWriter(FILENAME+".out")));
		out.println("Case #1:");
		long coin = TWO[n-1]-1;
		long nfound = 0;
		while (nfound < J) {
			coin += 2;
			if (coin > TWO[n]) {
				out.println("FAILURE");
				out.close();
				return;
			}
			long[] a = test(coin);
			if (a != null) {
				nfound++;
				System.out.println(nfound + " " + coin);
				out.print(Long.toBinaryString(coin));
				for (int i = 0; i < 9; i++) out.print(" " + a[i]);
				out.println();
			}
		}
		out.close();
    }
	static long[] test(long num) {
		long[] ans = new long[9];
		for (int b = 2; b <= 10; b++) {
			BigInteger k = BigInteger.ZERO;
			for (int i = 0; i < n; i++) {
				if ((num & TWO[i]) > 0) {
					k = k.add(POW[b][i]);
				}
			}
			boolean g = false;
			for (int p = 1; p < PNUM && !g; p++) {
				if (k.remainder(PRS[p]).equals(BigInteger.ZERO)) {
					g = true;
					ans[b-2] = PRIME[p];
				}
			}
			if (!g) return null;
		}
		return ans;
	}
}
