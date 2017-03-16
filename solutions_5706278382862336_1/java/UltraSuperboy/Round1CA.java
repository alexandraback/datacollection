package CodeJam2014;

import java.util.Scanner;
import java.util.TreeSet;

/*
5
1/2
3/4
1/4
2/23
123/31488
*/
public class Round1CA {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		loop:
		for (int casen = 1; casen <= T; casen++) {
			String s = in.nextLine();
			int rwaa = s.indexOf('/');
			long P = Long.parseLong(s.substring(0, rwaa));
			long Q = Long.parseLong(s.substring(rwaa+1));
			long gcd = gcd(P, Q);
			long M = P / gcd;
			long n = Q / gcd;
			long n2 = n;
			int N = 0;
			while (n2 > 1) {
				if (n2 % 2 == 1) {
					System.out.println("Case #" + casen + ": impossible");
					continue loop;
				}
				n2 /= 2;
				N++;
			}
			if (N > 40) {
				System.out.println("Case #" + casen + ": impossible");
				continue loop;
			}
			int gen = 0;
			while (M < n) {
				gen++;
				n /= 2;
			}
			System.out.println("Case #" + casen + ": " + gen);
		}
		
		/*TreeSet<Pair> set1 = new TreeSet<Pair>();
		TreeSet<Pair> set2 = new TreeSet<Pair>();
		TreeSet<Pair> set3 = new TreeSet<Pair>();
		set2.add(new Pair(0, 1));
		set2.add(new Pair(1, 1));
		for (int i = -39; i <= -35; i++) {
			for (Pair aa : set1)
				for (Pair bb : set2)
					set3.add(aa.combine(bb));
			for (Pair aa : set2)
				for (Pair bb : set2)
					set3.add(aa.combine(bb));
			System.out.println(set3);
			set1.addAll(set2);
			set2.clear();
			set2.addAll(set3);
			set3.clear();
		}*/
	}
	
	static long gcd(long a, long b) {
		long c = a % b;
		while (c > 0) {
			a = b;
			b = c;
			c = a % b;
		}
		return b;
	}
	
	/*static class Pair implements Comparable<Pair> {
		int num, den;
		Pair(int a, int b) {
			int gcd = gcd(a, b);
			num = a / gcd;
			den = b / gcd;
		}
		Pair combine(Pair other) {
			int num2 = num * other.den + den * other.num;
			int den2 = 2 * den * other.den;
			return new Pair(num2, den2);
		}
		public String toString() {
			return num + "/" + den;
		}
		@Override
		public int compareTo(Pair other2) {
			long ad = num * other2.den;
			long bc = den * other2.num;
			if (ad < bc)
				return -1;
			else if (ad == bc)
				return 0;
			else
				return 1;
		}
	}*/

}