
import java.io.*;
import java.util.*;
import java.math.*;

public class GCJ_C {
	static final String FILENAME = "C-large";
	static final int n = 32, J = 500;
	static final long[] TWO = new long[] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648L, 4294967296L, 8589934592L, 17179869184L, 34359738368L, 68719476736L, 137438953472L, 274877906944L, 549755813888L, 1099511627776L, 2199023255552L, 4398046511104L, 8796093022208L, 17592186044416L, 35184372088832L, 70368744177664L, 140737488355328L, 281474976710656L, 562949953421312L, 1125899906842624L, 2251799813685248L, 4503599627370496L, 9007199254740992L, 18014398509481984L, 36028797018963968L, 72057594037927936L, 144115188075855872L, 288230376151711744L, 576460752303423488L, 1152921504606846976L, 2305843009213693952L, 4611686018427387904L};
	static final long[] PRIME = new long[] {2, 3, 5, 7};
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
