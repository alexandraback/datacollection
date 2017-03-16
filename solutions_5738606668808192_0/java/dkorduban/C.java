import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class C {
	private static final int MAX_DIVISOR = 10000;
	Random rnd = new Random(132123);
	
	public static void main(String[] args) {
		new C().run();
	}

	private void run() {
		Scanner scanner = new Scanner(System.in);
		int tc = scanner.nextInt();
		for (int t = 1; t <= tc; ++t) {
			int n = scanner.nextInt();
			int k = scanner.nextInt();
			System.out.printf("Case #%d:\n", t);
			ArrayList<ArrayList<Object>> ans = f(n, k);
			for (Iterator<ArrayList<Object>> iterator = ans.iterator(); iterator.hasNext();) {
				ArrayList<Object> a = (ArrayList<Object>) iterator.next();
				System.out.print(a.get(0));
				for (int i = 1; i < a.size(); ++i) {
					System.out.print(" ");
					System.out.print(a.get(i));
				}
				System.out.println();
			}
		}
		scanner.close();
	}
	
	ArrayList<ArrayList<Object>> f(int n, int k) {
		ArrayList<ArrayList<Object>> result = new ArrayList<ArrayList<Object>>();
		HashSet<String> jamcoins = new HashSet<String>();
		for (int i = 0; i < k; ++i) {
			result.add(findJamcoin(n, jamcoins));
		}
		return result;
	}

	private ArrayList<Object> findJamcoin(int n, HashSet<String> alreadyGenerated) {
		ArrayList<Object> ret = new ArrayList<Object>();
		int[] witnesses = new int[11];
		while (true) {
			String s = generateCandidate(n);
			if (alreadyGenerated.contains(s)) {
				continue;
			}
			boolean bad = false;
			for (int i = 2; i <= 10; ++i) {
				if (isPrime(s, i)) {
					bad = true;
					break;
				}
			}
			if (bad) {
				continue;
			}
			for (int i = 2; i <= 10; ++i) {
				witnesses[i] = findSmallWitness(s, i);
				if (witnesses[i] == 0) {
					bad = true;
					break;
				}
			}
			if (bad) {
				continue;
			}
			ret.add(s);
			for (int i = 2; i <= 10; ++i) {
				ret.add(witnesses[i]);
			}
			alreadyGenerated.add(s);
			break;
		}
		return ret;
	}

	private int findSmallWitness(String s, int r) {
		BigInteger x = new BigInteger(s, r);
		// if n >= 16 then x > MAX_DIVISOR
		for (int i = 2; i < MAX_DIVISOR; ++i) {
			if (x.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
				return i;
			}
		}
		return 0;
	}

	private boolean isPrime(String s, int r) {
		BigInteger x = new BigInteger(s, r);
		return x.isProbablePrime(50);
	}

	private String generateCandidate(int n) {
		char[] s = new char[n];
		s[0] = s[n-1] = '1';
		for (int i = 1; i < n-1; ++i) {
			s[i] = rnd.nextBoolean() ? '1' : '0';
		}
		return new String(s);
	}

}
