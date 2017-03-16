
import java.util.*;

/*
 *	
 *	A.java
 *	Written by Andy Huang: 8:55:54 PM Apr 27, 2012
 */
public class A {
	static void solve() {
		int a = in.nInt();
		int b = in.nInt();
		double prob[] = new double[a];
		for (int i = 0; i < a; i++)
			prob[i] = in.nDouble();
		int mask = (1 << a) - 1;
		int orig = mask;
		double kprob[] = new double[mask + 1];
		int kval[] = new int[mask + 1];
		int dp1[] = new int[mask + 1];
		int dp2[] = new int[mask + 1];
		int opt4 = b + 2;
		while(mask >= 0){
			kprob[mask] = 1;
			for(int i = 0; i < a; i++){
				if ((1 << i & mask) >= 1){
					kprob[mask] *= prob[a - i - 1];
				}
				else
					kprob[mask] *= (1 - prob[a - i - 1]);
			}
			kval[mask] = b - a + 1;
			if (mask != orig)
				kval[mask] += b + 1;
			if (a >= 2){
				if ((mask | 1) == orig)
					dp1[mask] = b - a + 3;
				else
					dp1[mask] = 1 + b - a + 1 + 1 + b + 1;
			}
			if (a >= 3){
				if ((mask | 3) == orig)
					dp2[mask] = 2 + b - a + 2 + 1;
				else
					dp2[mask] = 2 + b - a + 2 + 1 + b + 1;
			}
			mask--;
		}
//		pln(Arrays.toString(kprob));
//		pln(Arrays.toString(kval));
//		pln(Arrays.toString(dp1));
//		pln(Arrays.toString(dp2));
//		pln(opt4);
		double best = Double.MAX_VALUE;
		if (opt4 < best)
			best = opt4;
		double sum = 0;
		for (int i = 0; i < kprob.length; i++)
			sum += kprob[i] * kval[i];
		if (sum < best)
			best = sum;
		sum = 0;
		for (int i = 0; i < kprob.length; i++)
			sum += kprob[i] * dp1[i];
		if (a >= 2 && sum < best)
			best = sum;
		sum = 0;
		for (int i = 0; i < kprob.length; i++)
			sum += kprob[i] * dp2[i];
		if (a >= 3 && sum < best)
			best = sum;
		out.appendln(best);
	}

	public static void main(String[] args) {
		in = new Input();
		out = new Output();
		int test = in.nInt();
		int z = 1;
		while(test-- > 0){
			out.append("Case #");
			out.append(z);
			out.append(": ");
			solve();
			z++;
		}
		out.print();
	}

	static Output out;
	static Input in;

	static void pln(Object o) {
		System.out.println(o);
	}

	static void pf(Object o) {
		System.out.print(o);
	}

}

final class Input {
	private java.io.BufferedReader reader;
	private java.util.StringTokenizer tokenizer;

	public Input() {
		reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new java.util.StringTokenizer(reader.readLine());
			}
			catch (java.io.IOException e) {
				throw new RuntimeException("I/O Error");
			}
		}
		return tokenizer.nextToken();
	}

	public String nLine() {
		try {
			return reader.readLine();
		}
		catch (java.io.IOException e) {
			throw new RuntimeException(e);
		}
	}

	public long nLong() {
		return Long.parseLong(next());
	}

	public int nInt() {
		return Integer.parseInt(next());
	}

	public double nDouble() {
		return Double.parseDouble(next());
	}

}

final class Output {
	public StringBuilder buffer;
	private java.io.PrintWriter out;
	
	Output() {
		buffer = new StringBuilder();
		try {
			out = new java.io.PrintWriter(new java.io.File("output.txt"));
		}
		catch (java.io.IOException e) {
		}
	}

	Output(int size) {
		buffer = new StringBuilder(size);
	}

	void print() {
		out.print(buffer.toString());
		out.close();
	}

	void flush() {
		out.flush();
	}

	<T> void append(T obj) {
		buffer.append(obj);
	}

	<T> void appendln(T obj) {
		append(obj);
		append('\n');
	}

	void delete(int index) {
		buffer.deleteCharAt(index);
	}

}