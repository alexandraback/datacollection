package R1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class C {

	private static Scanner reader;
	private static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input.in"));
		writer = new PrintWriter(new FileWriter("output.out"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			writer.printf("Case #%d: ", tc);
			J = reader.nextInt();
			P = reader.nextInt();
			S = reader.nextInt();
			K = reader.nextInt();
			
			solve();
		}
		reader.close();
		writer.close();
	}
	
	static void solve() {
		
		int s0 = 1;
		int p0 = 1;
		LinkedList<int[]> output = new LinkedList<>();
		for(int j = 1; j <= J; j++) {
			for(int p = p0; p <= P; p++) {
				for(int s = s0, cnt = 0; cnt < K && s <= S; cnt++, s++) {
					output.add(new int[] {j, p, s});
					System.out.println(j + " " + p + " " + s);
				}
				if(p % K == 0) {
					p0 += K;
				}
			}
			if(j % K == 0) {
				s0 += K;
			}
		}
		writer.println(output.size());
		for(int[] x : output) {
			writer.println(x[0] + " " + x[1] + " " + x[2]);
		}
			
	}
	
	
	
	static int J, P, S, K;

	static int[] X;
	static int[][] JP, JS, PS;
	static int count;
	static ArrayList<int[]> output;

	static ArrayList<int[]> generate() {
		ArrayList<int[]> T = new ArrayList<>();
		generate(0, new int[3], new int[] {J, P, S}, T);
		return T;
	}
	
	static void generate(int i, int[] a, int[] X, ArrayList<int[]> T) {
		if(i == a.length) {
			T.add(Arrays.copyOf(a, a.length));
		} else {
			for(int j = 1; j <= X[i]; j++) {
				a[i] = j;
				generate(i + 1, a, X, T);
			}
		}
	}
	
}
