package one_a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ManageYourEnergy {

	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
		BufferedWriter bw = new BufferedWriter(new FileWriter("output"));
		int cases = s.nextInt();
		for (int i = 0; i != cases; i++) {
			int e = s.nextInt();
			int r = s.nextInt();
			int n = s.nextInt();
			int V[] = new int[n];
			for (int j = 0; j != n; j++)
				V[j] = s.nextInt();
			int y = foo(e, r, n, V);
			String str = "Case #" + (i+1) + ": " + y;
			System.out.println(str);
			bw.write(str+'\n');
		}
		bw.close();
		s.close();
	}

	private static int foo(int e, int r, int n, int[] V) {
		int A[][] = new int[n][e+1];
		for (int i = 0; i != e+1; i++)
			A[n-1][i] = i*V[n-1];
		for (int i = n-2; i != -1; i--) {
			A[i][0] = A[i+1][r];
			for (int j = 1; j != e+1; j++) {
				A[i][j] = Math.max(A[i+1][Math.min(j+r, e)], V[i] + A[i][j-1]);
			}
		}
		return A[0][e];
	}

}
