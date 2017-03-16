import java.math.*;
import java.util.*;

public class C {
	static final BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);

	static char a[] = new char[200];
	static int lng = 1;
	static BigInteger curnum = BigInteger.ONE, lastnum = BigInteger.ZERO;

	public static void main(String[] args) {
		for (int i = 1; i < 200; i++)
			a[i] = '0';
		a[0] = '1';
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();

		BigInteger answer[][] = new BigInteger[2][n];
		Bound bounds[] = new Bound[2 * n];
		for (int i = 0; i < n; i++) {
			BigInteger tmp1 = long_sqrt(in.nextBigInteger(), false);
			BigInteger tmp2 = long_sqrt(in.nextBigInteger(), true);
		//	System.out.println(tmp1 + " " + tmp2);
			bounds[2 * i] = new Bound(tmp1, i, false);
			bounds[2 * i + 1] = new Bound(tmp2, i, true);
		}
		Arrays.sort(bounds);
		for (int pi = 0; pi < 2 * n;) {
//			System.out.println(pi + " " + curnum);
			while (pi < 2 * n && bounds[pi].lessOrEqualsToA()) {
//				System.out.println("$");
				if (bounds[pi].is_end)
					answer[1][bounds[pi].num] = bounds[pi].equalsToA() ? curnum : lastnum;
				else
					answer[0][bounds[pi].num] = lastnum;//bounds[pi].equalsToA() ? lastnum : curnum;
				pi++;
			}
			next();
		}

		for (int i = 0; i < n; i++)
			System.out.println("Case #" + (i + 1) + ": " + answer[1][i].subtract(answer[0][i]));
	}

	static void next() {
		curnum = curnum.add(BigInteger.ONE);
		lastnum = lastnum.add(BigInteger.ONE);
		if (lng == 1) {
			switch (a[0]) {
				case '1':
					a[0] = '2';
					break;
				case '2':
					a[0] = '3';
					break;
				case '3':
					a[0] = a[1] = '1';
					lng = 2;
					break;
				default:
					break;
			}
			return;
		}

		if (is_terminal()) {
			lng++;
			for (int i = 1; i < lng - 1; i++)
				a[i] = '0';
			a[0] = '1'; a[lng - 1] = '1';
			return;
		}

		if (only_ones()) {
			a[0] = '2'; a[lng - 1] = '2';
			for (int i = 1; i < lng - 1; i++)
				a[i] = '0';
			return;
		}

		if (is_bracked_by_twos()) {
			a[lng / 2] = '1';
			return;
		}

		if (lng % 2 == 0) {
			add_one_to(lng / 2 - 1);
		} else {
			int tmp = 0;
			for (int i = 0; i < lng / 2; i++)
				if (a[i] == '1')
					tmp++;
			if (tmp <= 2 && (a[lng / 2] == '0' || a[lng / 2] == '1')) {
				a[lng / 2]++;
				return;
			}
			if (a[lng / 2] == '2') {
				add_one_to(lng / 2 - 1);
				a[lng / 2] = '0';
				return;
			}
			add_one_to(lng / 2);
		}
	}

	static boolean is_terminal() {
		if (a[0] != '2' || a[lng - 1] != '2')
			return false;
		int right_bound = lng / 2;
		for (int i = 2; i < right_bound; i++)
			if (a[i] != '0')
				return false;
		if (lng % 2 == 1 && a[right_bound] != '1')
			return false;
		return true;
	}

	static boolean only_ones() {
		for (int i = 0; i < lng / 2; i++)
			if (a[i] != '1')
				return false;
		if (lng % 2 == 1 && a[lng / 2] != '2')
			return false;
		return true;
	}

	static boolean is_bracked_by_twos() {
		return a[0] == '2' && a[lng - 1] == '2';
	}

	static void add_one_to(int pos) {
		a[pos]++;
		for (int i = pos; i > 0; i--)
			if (a[i] == '2') {
				a[i] = '0';
				a[i - 1]++;
			} else
				break;
		int left_bound = lng / 2;
		for (int i = lng - 1; i >= left_bound; i--)
			a[i] = a[lng - i - 1];
	}

	static class Bound implements Comparable<Bound>{
		public BigInteger val;
		public int num;
		public boolean is_end;
		public char[] char_repr;

		Bound(BigInteger _val, int _num, boolean _is_end) {
			val = _val; num = _num; is_end = _is_end;
			char_repr = new char[200];
			for (int i = 0; i < 200; i++)
				char_repr[i] = '0';

			char _char_repr[] = val.toString().toCharArray();
			for (int i = 0; i < _char_repr.length / 2; i++) {
				char tmp = _char_repr[i];
				_char_repr[i] = _char_repr[_char_repr.length - i - 1];
				_char_repr[_char_repr.length - i - 1] = tmp;
			}

			for (int i = 0; i < _char_repr.length; i++)
				char_repr[i] = _char_repr[i];

/*			System.out.println("#######");
			for (int i = 0; i < char_repr.length; i++)
				System.out.print(char_repr[i]);
			System.out.println();
			System.out.println("#######");*/
		}

		public int compareTo(Bound b) {
			return val.compareTo(b.val);
		}

		public boolean equals(Bound b) {
			return false;
		}

		public boolean lessOrEqualsToA() {
			for (int i = 199; i >= 0; i--)
				if (a[i] < char_repr[i])
					return false;
				else if (a[i] > char_repr[i])
					return true;
			return true;
		}

		public boolean equalsToA() {
			for (int i = 0; i < 200; i++)
				if (a[i] != char_repr[i])
					return false;
			return true;
		}
	}

	static BigInteger long_sqrt(BigInteger n, boolean is_end) {
		if (n.compareTo(BigInteger.ONE) == 0)
			return BigInteger.ONE;
		BigInteger left = BigInteger.ONE, right = n, med, res = BigInteger.ONE;
		while (left.compareTo(right) <= 0) {
			med = left.add(right).divide(TWO);
			int tmp = med.multiply(med).compareTo(n);
			if (tmp == 0)
				return med;
			if (tmp < 0) {
				res = med;
				left = med.add(BigInteger.ONE);
			} else
				right = med.subtract(BigInteger.ONE);
		}
		if (!is_end)
			res = res.add(BigInteger.ONE);
		return res;
	}
}
