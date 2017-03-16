import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

//Copied java.math from OpenJDK7

public class fsq {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new FileReader("fsq.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("fsq.out")));

		int cases = in(r.readLine());
		for (int t = 1; t <= cases; ++t) {
			System.out.println(t);
			StringTokenizer tk = new StringTokenizer(r.readLine());
			MutableBigInteger start = new MutableBigInteger(new BigInteger(tk.nextToken()));
			int minSize = Math.max(start.toString().length() / 2, 1);
			MutableBigInteger end = new MutableBigInteger(new BigInteger(tk.nextToken()));
			int maxSize = end.toString().length() / 2 + 3;

			// System.out.println("Start: " + start + " " + minSize);
			// System.out.println("End: " + end + " " + maxSize);

			boolean counting = false;
			int count = 0;

			main: for (int size = minSize; size <= maxSize; ++size) {
				// System.out.println("Size: " + size);
				NumString str = new NumString(new StringBuilder(size), (size == 1 ? 1 : 2));

				str.b.append("1");
				for (int i = 0; i < size - 2; i++)
					str.b.append("0");
				if (size > 1)
					str.b.append("1");
				// for (int i = 0; i < size; i++)
				// start.append("9");
				BigInteger prev = new BigInteger(str.b.toString());
				MutableBigInteger sq = new MutableBigInteger(prev.square());
				do {
					BigInteger big = new BigInteger(str.b.toString());
					BigInteger sum = big.add(prev);
					BigInteger dif = big.subtract(prev);
					sq.add(new MutableBigInteger(sum.multiply(dif)));
					if (!counting && sq.compare(start) >= 0)
						counting = true;
					if (sq.compare(end) > 0) {
						// System.out.println("End: " + sq);
						break main;
					}
					prev = big;
					String s = sq.toString();
					// System.out.println(big);
					boolean broken = false;
					for (int i = 0; i < s.length() / 2; ++i) {
						if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
							broken = true;
							break;
						}
					}
					if (!broken) {
						if (counting)
							count++;
						// if (start.toString().contains("2"))
						// int max = (str.b.length() - 1) / 2;
						// System.out.print(str.b.substring(0, max + 1));
						// System.out.print(" ");
						// System.out.print(s);
						// System.out.println();
					}
				} while ((str = next(str)) != null);
			}

			// System.out.println("Answer: " + count);

			w.print("Case #");
			w.print(t);
			w.print(": ");
			w.println(count);
		}

		r.close();
		w.close();
	}

	public static NumString next(NumString str) {
		StringBuilder b = str.b;
		int max = (b.length() - 1) / 2;
		for (int i = max, mult = (b.length() % 2 == 0 ? 2 : 1);; --i, mult = 2) {
			if (i < 0) {
				return null;
			}
			boolean cont = false;
			char cur = b.charAt(i);
			if (cur == '9' || str.sum + mult >= 10) {
				str.sum -= (cur - '0') * mult;
				cont = true;
				cur = '0';
			} else {
				str.sum += mult;
				cur++;
			}
			b.setCharAt(i, cur);
			b.setCharAt(b.length() - i - 1, cur);
			if (!cont)
				break;
		}
		return str;
	}

	private static final int in(StringTokenizer tk) {
		return in(tk.nextToken());
	}

	private static final int in(String s) {
		return Integer.parseInt(s);
	}
}

class NumString {
	StringBuilder b;

	int sum;

	public NumString(StringBuilder b, int s) {
		this.b = b;
		this.sum = s;
	}
}
