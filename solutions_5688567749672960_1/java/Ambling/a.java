

import java.util.*;

public class a {
	
	static List<Integer> toInts(long n) {
		List<Integer> ints = new ArrayList<>();
		long left = n;
		while (left > 0) {
			ints.add((int) (left % 10));
			left /= 10;
		}
		return ints;
	}
	
	static long toInt(List<Integer> ints) {
		long re = 0;
		for (int i: ints) {
			re *= 10;
			re += i;
		}
		return re;
	}
	
	static long find(long n) {
//		System.out.println("n: " + n);
		if ( n <= 12 ) return n;
		else {
			List<Integer> ints = toInts(n);
			
			int num = ints.size();
			int divider = num / 2 + num % 2;
			List<Integer> one = ints.subList(divider, num);
			List<Integer> two = ints.subList(0, divider);
			Collections.reverse(two);
			
			long ione = toInt(one);
			long itwo = toInt(two);
			
			if (itwo == 0) return find(n-1)+1;
			
			int change = (ione == 1)?0:1;
			
			long re = 0;
			re += ione - 1 + itwo - 1 + change;
			long next = (long)Math.pow(10, num-1) - 1;
			return re + 2 + find(next);
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO
			long n = in.nextLong();
			
			long cnt = find(n);
			System.out.printf("Case #%d: %d\n", t, cnt);
		}
	}
}
