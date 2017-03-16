package A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class A2 {
	
	private int[] f;
	
	public A2() {
		f = new int[1000001];
		f[0] = 0;
		for (int i = 1; i < f.length; i++) {
			f[i] = min(f, i);
		}
	}
	
	private int solve(int integer) {
		return f[integer];
	}

	private int min(int[] f, int i) {
		int a = f[i-1] + 1;
		if (rotate(i) >= i) {
			return a;
		}
		int b = f[rotate(i)] + 1;
		if (a < b) {
			return a;
		}
		return b;
	}

	private int rotate(int i) {
		if (i % 10 == 0) {
			return Integer.MAX_VALUE;
		}
		ArrayList<Integer> al = new ArrayList<Integer>();
		while (i > 0) {
			al.add(i % 10);
			i /= 10;
		}
		Collections.reverse(al);
		for (int j = 0; j < al.size(); j++) {
			i += al.get(j) * Math.pow(10, (j));
		}
		return i;
	}

	public static void main(String[] args) throws FileNotFoundException {
		A2 a2 = new A2();
		Scanner s = new Scanner(new File("inA.in"));
		PrintWriter pw = new PrintWriter(new File("outA.out"));
		int c = s.nextInt();
		for (int i = 0; i < c; i++) {
			System.out.println(i);
			if (i == 99) {
				System.out.println(5);
			}
			pw.println("Case #" + (i + 1) + ": " + a2.solve(s.nextInt()));
		}
		pw.close();
	}

}
