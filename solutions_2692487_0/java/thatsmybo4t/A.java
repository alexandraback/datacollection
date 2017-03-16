package A2;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		int T, A, N;
		int resultado;
		int[] otherMoles;

		T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			resultado = 0;
			A = sc.nextInt();
			N = sc.nextInt();
			otherMoles = new int[N];
			for (int j = 0; j < N; j++) {
				otherMoles[j] = sc.nextInt();
			}
			resultado = resolve(A, N, otherMoles);
			System.out.println("Case #" + i + ": " + resultado);
			otherMoles = null;
		}
	}

	private static int resolve(int a, int n, int[] otherMoles) {
		Arrays.sort(otherMoles);
		int resultado = 0;
		int melhorSolucao = n;
		int pos = 0;
		while (pos < otherMoles.length) {
			while (pos < n && a > otherMoles[pos]) {
				a += otherMoles[pos];
				pos++;
			}
			if (resultado + n - pos < melhorSolucao){
				melhorSolucao = resultado + n - pos;
			}
			if (pos < n){
				if (a == 1){
					return n - pos;
				}
				while (a <= otherMoles[pos]){
					a = a*2 -1;
					resultado++;
				}
			}
		}

		return melhorSolucao;
	}

}
