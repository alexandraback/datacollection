import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}
		
	Scanner in;
	PrintWriter out;
	
	void run() throws FileNotFoundException {
		in = new Scanner(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		//out = new PrintWriter(System.out);
		int testNum = in.nextInt();
		for (int testCount = 0; testCount < testNum; testCount++) {
			BigInteger from = in.nextBigInteger();
			BigInteger to = in.nextBigInteger();
			long result = solve(to) - solve(from.subtract(BigInteger.ONE));
			out.println(String.format("Case #%d: %d", testCount + 1, result));
		}
		out.flush();
	}
	
	long solve(BigInteger p) {
		long sum = 0;
		for (int len = 1; len < 60; len++) {
			if (len == 1) {
				if (p.compareTo(BigInteger.valueOf(1)) >= 0) {
					sum++;
					if (p.compareTo(BigInteger.valueOf(4)) >= 0) {
						sum++;
						if (p.compareTo(BigInteger.valueOf(9)) >= 0)
							sum++;
						else
							return sum;
					} else
						return sum;
				} else 
					return sum;
			} else {
				long cur = len % 2 == 0 ? even(p, len) : odd(p, len);
				if (cur < 0)
					sum -= cur;
				else
					return sum + cur;
			}
		}
		throw new RuntimeException();
	}
	
	long even(BigInteger p, int len) {
		StringBuilder sb = new StringBuilder();
		sb.append('1');
		for (int i = 0; i < len - 2; i++)
			sb.append('0');
		sb.append('1');
		if (p.compareTo(makeSquare(sb)) < 0)
			return 0;
		long t = 0;
		boolean stop = false;
		for (int i = 1; i < len / 2; i++) {
			StringBuilder sb2 = new StringBuilder(sb.toString());
			sb2.setCharAt(i, '1');
			sb2.setCharAt(len - i - 1, '1');
			if (p.compareTo(makeSquare(sb2)) >= 0) {
				t = t * 2 + 1;
				sb = sb2;
			} else {
				t = t * 2;
				stop = true;
			}
		}
		if (stop)
			return t + 1;
		
		sb = new StringBuilder();	
		sb.append('2');
		for (int i = 0; i < len - 2; i++)
			sb.append('0');
		sb.append('2');
		if (p.compareTo(makeSquare(sb)) < 0)
			return t + 1;
		return -(t + 2);
	}
	
	long odd(BigInteger p, int len) {
		StringBuilder sb = new StringBuilder();
		sb.append('1');
		for (int i = 0; i < len - 2; i++)
			sb.append('0');
		sb.append('1');
		if (p.compareTo(makeSquare(sb)) < 0)
			return 0;
		long t = 0;
		boolean stop = false;
		for (int i = 1; i < len / 2; i++) {
			StringBuilder sb2 = new StringBuilder(sb.toString());
			sb2.setCharAt(i, '1');
			sb2.setCharAt(len - i - 1, '1');
			if (p.compareTo(makeSquare(sb2)) >= 0) {
				t = t * 2 + 1;
				sb = sb2;
			} else {
				t = t * 2;
				stop = true;
			}
		}
		
		long value = z(t) + 1;
		sb.setCharAt(len / 2, '1');
		if (p.compareTo(makeSquare(sb)) >= 0) {
			value++;
			sb.setCharAt(len / 2, '2');
			if (Long.bitCount(t) < 2 && p.compareTo(makeSquare(sb)) >= 0)
				value++;
		}
		if (stop)
			return value;
		
		sb = new StringBuilder();	
		sb.append('2');
		for (int i = 0; i < len - 2; i++)
			sb.append('0');
		sb.append('2');
		if (p.compareTo(makeSquare(sb)) < 0)
			return value;
		sb.setCharAt(len / 2, '1');
		if (p.compareTo(makeSquare(sb)) < 0)
			return value + 1;
		return -(value + 2);
	}
	
	long z(long t) {
		long result = 0;
		for (long i = 0; i < t; i++)
			result += (Long.bitCount(i) < 2) ? 3 : 2;
		return result;
	}
	
	BigInteger makeSquare(StringBuilder sb) {
		return new BigInteger(sb.toString()).pow(2);
	}

}
