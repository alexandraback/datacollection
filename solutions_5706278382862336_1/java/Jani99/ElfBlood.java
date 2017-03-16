package gcj_1C_A;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class ElfBlood {
	
	long P;
	long Q;
	int firstTrueElf;
	
	ElfBlood(long p, long q) {
		P = p;
		Q = q;
		firstTrueElf = -1;
	}
	
	void normalize() {
		long p = P;
		long q = Q;
		long gcd = 1;
		while (p != q) {
			if (p > q) {
				p %= q;
				if (p == 0) {
					gcd = q;
					break;
				}
			} else {
				q %= p;
				if (q == 0) {
					gcd = p;
					break;
				}
			}
		}
		P /= gcd;
		Q /= gcd;
	}
	
	void checkAncestors() {
		normalize();
		if (! isPow2(Q)) {
			return;
		}
		int minP = getMinPow2(P);
		int maxP = getMaxPow2(P);
		int maxQ = getMaxPow2(Q);
		
		if (maxQ-minP <= 40) {
			firstTrueElf = maxQ-maxP;
		}
	}
	
	boolean isPow2(long n) {
		while (n > 0) {
			if (n == 2) {
				return true;
			}
			if (n % 2 == 1) {
				return false;
			}
			n /= 2;
		}
		return true;
	}
	
	int getMaxPow2(long n) {
		int r = 0;
		while (n > 1) {
			n /= 2;
			r += 1;
		}
		return r;
	}
	
	int getMinPow2(long n) {
		int r = 0;
		while (n % 2 != 0) {
			n /= 2;
			++r;
		}
		return r;
	}
	
	public static void main(String[] args) {
		
		Scanner scanner = null;
		
		try {
			scanner = new Scanner(new FileReader(args[0]));
		} catch (FileNotFoundException e) {
			System.err.println("file not found:" + args[0]);
		}
		
		scanner.useDelimiter("[\\s/]");
		
		int T = scanner.nextInt();
		
		for (int i=0; i<T; ++i) {
			long P = scanner.nextLong();
			long Q = scanner.nextLong();
			
			ElfBlood elfBlood = new ElfBlood(P, Q);
			elfBlood.checkAncestors();
			
			if (elfBlood.firstTrueElf > 0) {
				System.out.println("Case #" + (i+1) + ": " + elfBlood.firstTrueElf);
			} else {
				System.out.println("Case #" + (i+1) + ": impossible");
			}
		}
	}

}
