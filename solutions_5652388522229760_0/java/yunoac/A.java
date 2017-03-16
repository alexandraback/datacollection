package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	
	private static Scanner reader;
	private static PrintWriter writer;
	
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			long N = reader.nextInt();
			writer.printf("Case #%d: ", tc);
			if(N == 0) {
				writer.println("INSOMNIA");
			} else {
				int m = find(N);
				writer.println(m * N);
			}
		}
		reader.close();
		writer.close();
	}
	
	static int find(long N) {
		BitSet digits = new BitSet();
		int m = 0;
		long cur = 0;
		while(digits.cardinality() != 10) {
			m++;
			cur += N;
			String s = cur + "";
			for(int i = 0; i < s.length(); i++) {
				digits.set(Character.getNumericValue(s.charAt(i)));
			}
			//if(m > 1000) return -1;
		}
		return m;
	}

}
