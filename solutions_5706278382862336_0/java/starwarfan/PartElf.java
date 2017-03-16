package elf;

import java.util.Scanner;

public class PartElf {
	public static long[] pot;
	
	public static void init() {
		pot = new long[40];
		pot[0] = 1;
		for (int i = 1; i < 40; i++) {
			pot[i] = 2 * pot[i - 1];
		}
	}
	
	public static long getGcd(long a, long b) {
		// a > b
		if (a < b) {
			long t = a;
			a = b;
			b = t;
		}
		
		long r = a % b;
		if (r == 0)
			return b;
		
		return getGcd(b, r);
	}
	
	public static int process(Scanner sc) {
		String line = sc.next();
		String [] pq = line.split("/");
		long p = Long.parseLong(pq[0]);
		long q = Long.parseLong(pq[1]);
		
		long gcd = getGcd(p, q);
		p = p / gcd;
		q = q / gcd;
		//System.out.println("p,q" + p + "," + q);
		
		int smallPart = -1;
		for (int i = 0; i < 40; i++) {
			if (q == pot[i]) {
				smallPart = i;
				break;
			}
		}
		
		if (smallPart < 0)
			return -1;
		
		int bigPart = 1;
		for (int i = 0; i < 40; i++) {
			if (p < pot[i]) {
				bigPart = i - 1;
				break;
			}
		}

		//System.out.println("pa,qa" + smallPart + "," + bigPart);
		int res = smallPart - bigPart;
		
		return res;
	}

	public static void main(String[] args) {
		//System.out.println(getGcd(48, 36));
		Scanner sc = new Scanner(System.in);
		init();
		int T = sc.nextInt();
		int cnt = 1;
		while (cnt <= T) {
			int r = process(sc);
			String res = "";
			if (r < 0)
				res = "impossible";
			else
				res += r;
			System.out.println("Case #" + cnt + ": " + res);
			cnt++;
		}
		sc.close();
	}
}
