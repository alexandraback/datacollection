import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class Problem3 {
	public static class Pair {
		long num;
		int type;

		public Pair(long n, int t) {
			num = n;
			type = t;
		}

		public String toString() {
			return "[" + num + ":" + type + "]";
		}
	}

	public static class CacheKey {
		int sa;
		int sb;
		long numA;
		long numB;

		public CacheKey(int a, int b, long na, long nb) {
			sa = a;
			sb = b;
			numA = na;
			numB = nb;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (numA ^ (numA >>> 32));
			result = prime * result + (int) (numB ^ (numB >>> 32));
			result = prime * result + sa;
			result = prime * result + sb;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			CacheKey other = (CacheKey) obj;
			if (sa != other.sa)
				return false;
			if (sb != other.sb)
				return false;
			if (numA != other.numA)
				return false;
			if (numB != other.numB)
				return false;

			return true;
		}

	}

	public static void main(String[] args) throws FileNotFoundException {

		String inputFile = "C-large.in";
		String outputFile = "pro3.out";
		Scanner inputScanner = new Scanner(new FileInputStream("d:\\codejam\\"
				+ inputFile));
		PrintStream ps = new PrintStream(new FileOutputStream("d:\\codejam\\"
				+ outputFile));
		int totalCaseNum = inputScanner.nextInt();
		inputScanner.nextLine();
		// -----------------------------------------------

		// -----------------------------------------------
		for (int caseNum = 1; caseNum <= totalCaseNum; caseNum++) {
			String line = inputScanner.nextLine();
			String prefix = "Case #" + caseNum + ": ";
			StringBuilder output = new StringBuilder(prefix);
			// -----------------------------------------------
			Scanner sc = new Scanner(line);
			int N = sc.nextInt();
			int M = sc.nextInt();
			line = inputScanner.nextLine();
			Scanner scA = new Scanner(line);
			Pair[] streamA = new Pair[N];
			for (int n = 0; n < N; n++) {
				long na = scA.nextLong();
				int ta = scA.nextInt();
				streamA[n] = new Pair(na, ta);
			}

			Pair[] streamB = new Pair[M];
			line = inputScanner.nextLine();
			Scanner scB = new Scanner(line);
			for (int m = 0; m < M; m++) {

				long nb = scB.nextLong();
				int tb = scB.nextInt();
				streamB[m] = new Pair(nb, tb);
			}

			output.append(calc(0, 0, streamA, streamB, new HashMap<CacheKey,Long>()));

			// -----------------------------------------------
			System.out.println(output);
			ps.println(output);
		}
	}

	public static long calc(int sa, int sb, Pair[] streamA, Pair[] streamB,
			Map<CacheKey, Long> cache) {

		if (sa >= streamA.length || sb >= streamB.length) {
			return 0;
		}
		Long l;
		CacheKey key = new  CacheKey(sa, sb, streamA[sa].num,streamB[sb].num);
				
		if ((l = cache.get(key)) != null) {
			return l.longValue();
		}

		long sum = 0;
		long inter = 0;
		if (streamA[sa].type == streamB[sb].type) {
			inter += Math.min(streamA[sa].num, streamB[sb].num);
			streamA[sa].num -= inter;
			streamB[sb].num -= inter;
		}

		long throwA = calc(sa + 1, sb, streamA, streamB,cache);
		long throwB = calc(sa, sb + 1, streamA, streamB,cache);
		sum += inter + Math.max(throwA, throwB);

		if (streamA[sa].type == streamB[sb].type) {
			streamA[sa].num += inter;
			streamB[sb].num += inter;
		}
		cache.put(key, sum);
		return sum;
	}
}
